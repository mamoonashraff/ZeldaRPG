#ifndef ROOM_H
#define ROOM_H

#include"Item.h"
#include"Enemy.h"

class Room 
{
    private:
        string description;
        Item*items[5];
        int itemCount;
        Enemy*enemy;
        bool visited;

    public:
        Room(string desc) 
		{
            description=desc;
            itemCount=0;
            enemy=nullptr;
            visited=false;
            for(int i=0; i<5; i++)
			{
                items[i]=nullptr;
            }
        }
        void addItem(Item* item) 
		{
            if(itemCount<5) 
			{
                items[itemCount]=item;
                itemCount++;
            }
        }
        void setEnemy(Enemy*e) 
		{
            enemy=e;
        }
        void display() {
            cout<<"\n=============================="<<endl;
            cout<<"Location: "<<description<<endl;
            cout<<"=============================="<<endl;

            if(itemCount > 0)
			{
                cout<<"Items here:"<<endl;
                for(int i=0;i<itemCount; i++) 
				{
                    if(items[i] !=nullptr) 
					{
                        cout<<"  "<<i + 1<<". ";
                        items[i]->Display();
                        cout << endl;
                    }
                }
            } else 
			{
                cout<<"No items here."<<endl;
            }

            if(enemy != nullptr && enemy->isAlive()) 
			{
                cout<<"Enemy: " << enemy->getName()<<" (HP: "  << enemy->gethealth()<<")"<<endl;
            } else 
			{
                cout<<"No enemies here."<<endl;
            }
        }
        Item* pickItem(int index) {
            if(index < 0 || index >= itemCount) 
			{
                cout << "No item found!" << endl;
                return nullptr;
            }
            if(items[index] == nullptr) {
                cout << "Item already picked!" << endl;
                return nullptr;
            }
            Item* picked = items[index];
            items[index] = nullptr;
            cout << picked->getName() << " picked up!" << endl;
            return picked;
        }
        Enemy*getEnemy()
		{ 
			return enemy;   
		}
        bool hasEnemy()     
		{
			return enemy!=nullptr && enemy->isAlive(); 
		}
        bool isVisited()
		{
			return visited;     
		}
        void setVisited()
		{ 
			visited = true;
		}
        int getItemCount() 
		{ 
			return itemCount;
		}
        string  getDesc()
		{	
			return description; 
		}
};
#endif
