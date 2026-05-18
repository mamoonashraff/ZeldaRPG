#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include<fstream>
#include"Hero.h"
#include"Map.h"
#include"Inventory.h"
#include"Dragon.h"
#include"Spell.h"
#include<cstdlib>

class GameEngine 
{
    private:
        Hero*player;
        Map*gameMap;
        Inventory*bag;
        bool gameOver;
        bool gameWon;

    public:
        GameEngine() 
		{
            gameOver=false;
            gameWon=false;

            string name;
            cout<<"=============================="<<endl;
            cout<<"   Welcome to ZeldaRPG!       "<<endl;
            cout<<"=============================="<<endl;
            cout<<"Enter your hero name: ";
            cin>>name;

            player=new Hero(name,100,30,5);
            gameMap=new Map();
            bag=new Inventory();

            cout<<"\nWelcome, "<<name<<"! Your adventure begins..."<<endl;
        }

        void displayStatus() 
		{
            cout<<"\n------------------------------"<<endl;
            cout<<"Room "<<gameMap->getCurrentRoomNumber()<<" of "<<gameMap->getTotalRooms()<<endl;
            cout<<"Hero HP: "<<player->gethealth()<<"  Gold: "<<player->getGold()<<endl;
            cout<<"------------------------------"<<endl;
        }

        void displayCommands() 
		{
            cout<<"\nCommands:"<<endl;
            cout<<"  W = Next room"<<endl;
            cout<<"  A = Attack enemy"<<endl;
            cout<<"  P = Pick item"<<endl;
            cout<<"  B = View bag"<<endl;
            cout<<"  H = Hero stats"<<endl;
            cout<<"  S = Save game"<<endl;
   			cout<<"  L = Load game"<<endl;
   			cout<<"  Z = Cast spell"<<endl;
    		cout<<"  X = Show spells"<<endl;
            cout<<"  Q = Quit game"<<endl;
        }

        void fightEnemy() 
		{
            Room*room=gameMap->getCurrentRoom();
            Enemy*enemy=room->getEnemy();

            if(enemy == nullptr || !enemy->isAlive()) 
			{
                cout<<"No enemy here!"<<endl;
                return;
            }

            cout<<"\n--- BATTLE START ---" <<endl;
            while(player->isAlive() && enemy->isAlive()) 
			{
                player->attackTarget(*enemy);
                cout<<enemy->getName()<<" HP: "<<enemy->gethealth()<<endl;

                if(!enemy->isAlive()) {
                    cout<<enemy->getName()<<" defeated!"<<endl;
                    player->addGold(enemy->getGoldReward());

                    if(gameMap->isLastRoom()) 
					{
                        gameWon=true;
                        gameOver=true;
                    }
                    break;
                }

                Dragon*dragon=dynamic_cast<Dragon*>(enemy);
				if(dragon != nullptr) 
				{
    			dragon->attackTarget(*player);
				} 
				else 
				{
    				enemy->attackTarget(*player);
				}

                if(!player->isAlive())
				{
                    cout<<"Hero defeated! Game Over!"<<endl;
                    gameOver=true;
                    break;
                }
            }
            cout<<"--- BATTLE END ---"<<endl;
        }

        void pickItem() 
		{
            Room*room=gameMap->getCurrentRoom();

            if(room->getItemCount() == 0) 
			{
                cout<<"No items here!"<<endl;
                return;
            }

            room->display();
            cout<<"Enter item number to pick: ";
            int choice;
            if(!(cin >> choice))
			{
        	cin.clear();
       		cin.ignore(1000, '\n');
        	cout << "Invalid input! Enter a number." << endl;
        	return;
    		}

    		if(choice < 1||choice>room->getItemCount()) 
			{
        		cout << "Invalid choice! Enter number between 1 and "<< room->getItemCount() << endl;
        		return;
    		}

            Item*item=room->pickItem(choice-1);
            if(item !=nullptr) 
			{
                bag->addItem(item);

                Weapon*w=dynamic_cast<Weapon*>(item);
                if(w!=nullptr) 
				{
                    player->equipWeapon(w);
                }
                Spell*s=dynamic_cast<Spell*>(item);
				if(s != nullptr) 
				{
    				player->learnSpell(s);
				}
            }
        }
        void castSpellMenu() 
		{
    		Room*room=gameMap->getCurrentRoom();
    		Enemy*enemy=room->getEnemy();

    		if(enemy == nullptr || !enemy->isAlive()) 
			{
        		cout<<"No enemy to cast spell on!"<<endl;
        		return;
    		}

    		player->showSpells();
    		if(player->getSpellCount() == 0) 
			{
        		cout<<"No spells learned yet!"<<endl;
        		return;
    		}

    		cout<<"Enter spell number: ";
    		int choice;
    		if(!(cin >> choice)) 
			{
        		cin.clear();
        		cin.ignore(1000, '\n');
        		cout << "Invalid input! Enter a number."<<endl;
        		return;
    		}

    		if(choice<1||choice>player->getSpellCount()) 
			{
        		cout<<"Invalid spell number!"<<endl;
        		return;
    		}

    		player->castSpell(choice-1,*enemy);

    		cout<<enemy->getName()<<" HP: "<< enemy->gethealth()<<endl;

    		if(!enemy->isAlive()) 
			{
        		cout<<enemy->getName()<<" defeated!"<<endl;
        		player->addGold(enemy->getGoldReward());
        	if(gameMap->isLastRoom()) 
				{
            		gameWon=true;
            		gameOver=true;
        		}
    		}
		}

        void moveNext() 
		{
            Room*current=gameMap->getCurrentRoom();

            if(current->hasEnemy()) 
			{
                cout<<"Defeat the enemy first!"<<endl;
                return;
            }

            if(gameMap->moveNext()) 
			{
                cout<<"\nMoving to next room..."<<endl;
                gameMap->getCurrentRoom()->display();
            }
        }
        void saveGame() 
		{
    			ofstream file("savegame.txt");
    			if(file.is_open()) 
				{
    	    	player->saveToFile(file);
    		    file<<gameMap->getCurrentRoomNumber()<<endl;
        		file.close();
        		cout<<"Game saved successfully!"<<endl;
    		} 
			else
			{
        		cout<<"Could not save game!"<<endl;
    		}
		}
		void loadGame() 
		{
   				ifstream file("savegame.txt");
    			if(file.is_open()) 
				{
        		player->loadFromFile(file);
        		int roomNum;
        		file>>roomNum;
        		file.close();
        		
        		delete gameMap;
        		gameMap=new Map();

        		for(int i=1; i<roomNum; i++) 
				{
         	   	gameMap->moveNext();
        		}
        		cout<<"Game loaded successfully!"<<endl;
        		cout<<"Welcome back, "<<player->getName()<<"!"<<endl;
        		cout<<"HP: "<<player->gethealth()<<"  Gold: "<<player->getGold()<<endl;
        		gameMap->getCurrentRoom()->display();
   				}
		 		else 
				{
        		cout<<"No save file found!"<<endl;
   				}
		}

        void run() 
		{
            gameMap->getCurrentRoom()->display();
            displayStatus();

            while(!gameOver) 
			{
        		displayCommands();
        		cout<<"\nEnter command: ";
        
        		char cmd;
        		if(!(cin>>cmd)) 
				{
           		 	cin.clear();
            		cin.ignore(1000,'\n');
            		cout<<"Invalid input!"<<endl;
            		continue;
        		}

                if(cmd=='W') 
				{ 
					moveNext();
				}
                else if(cmd=='A') 
				{ 
					fightEnemy();           
				}
                else if(cmd=='P') 
				{ 
					pickItem();             
				}
                else if(cmd=='B') 
				{
					 bag->display();         
				}
                else if(cmd=='H') 
				{ 
					player->DisplayStats();
			 	}
			 	else if(cmd=='S') 
				{ 
					saveGame();             
				}
				else if(cmd=='L') 
				{ 
					loadGame();             
				}
                else if(cmd =='Z') 
				{
				 castSpellMenu(); 
				}
				else if(cmd =='X') 
				{ 
					player->showSpells(); 
				}
				else if(cmd=='Q') 
				{
                    cout<<"Thanks for playing!"<<endl;
                    gameOver=true;
                }
                else 
				{
                    cout<<"Invalid command!"<<endl;
                }

                if(!gameOver) displayStatus();
            }

            if(gameWon) 
			{
                cout<<"\n=============================="<<endl;
                cout<<"  CONGRATULATIONS! YOU WIN!   "<<endl;
                cout<<"  Total Gold: " << player->getGold()<<endl;
                cout<<"=============================="<<endl;
            } 
			else 
			{
                cout<<"\n=============================="<<endl;
                cout<<"        GAME OVER!            "<<endl;
                cout<<"=============================="<<endl;
            }
        }

        ~GameEngine() 
		{
            delete player;
            delete gameMap;
            delete bag;
        }
};
#endif
