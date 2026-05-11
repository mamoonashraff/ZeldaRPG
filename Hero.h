#ifndef HERO_H
#define HERO_H
#include<fstream>
#include"Character.h"
#include"Weapon.h"
#include"Potion.h"
#include"Spell.h"

class Hero : public Character{
	private:
		int mana;
		int gold;
		int level;
		Weapon*equippedWeapon;
		Spell*spells[5];
		int spellCount;
	public:
		Hero(string n,int hp,int atk,int def):Character(n,hp,atk,def)
		{
			mana=100;
			gold=0;
			level=1;
			equippedWeapon=nullptr;
			spellCount =0;
			for(int i=0;i<5;i++) 
			{
   				spells[i]=nullptr;
			}
		}
		int getMana()
		{
			return mana;
		}
		int getGold()
		{
			return gold;
		}
		int getLevel()
		{
			return level;
		}
		
		void equipWeapon(Weapon*w)
		{
			equippedWeapon=w;
			cout<<name<<" equipped "<<w->getName()<<"!"<<endl;
		}
		void learnSpell(Spell*s) 
		{
   			if(spellCount>=5) 
			   {
        			cout<<"Cannot learn more spells!"<<endl;
        			return;
   				}
    		spells[spellCount]=s;
    		spellCount++;
    		cout<<name<<" learned "<<s->getName()<<"!"<<endl;
		}

		void castSpell(int index,Character& target) 
		{
    		if(index<0||index>=spellCount) 
			{
     		   cout<<"Invalid spell!"<<endl;
        		return;
    		}
    		if(spells[index]==nullptr) 
			{
        		cout<<"No spell found!"<<endl;
     	   		return;
    		}
   	 		if(mana<spells[index]->getManaCost()) 
				{
      			  cout<<"Not enough mana!"<<endl;
        			return;
   				}
    			mana-=spells[index]->getManaCost();
    			cout<<name<<" casts "<<spells[index]->getName()<<"!"<<endl;
   				target.takeDamage(spells[index]->getDamage());
    			cout<<"Mana remaining: "<<mana<<endl;
		}

		void showSpells() 
		{
   	 		cout<<"===== SPELLS ====="<<endl;
    		if(spellCount==0) 
			{
        		cout<<"No spells learned!"<<endl;
    		} 
			else 
			{
        		for(int i=0;i<spellCount; i++) 
				{
           			cout<<i+1<<". ";
            		spells[i]->Display();
            		cout<<endl;
        		}
    		}
    		cout<<"Mana: "<<mana<<endl;
    		cout<<"=================="<<endl;
		}
		void addGold(int amount)
		{
            gold += amount;
            cout<<"+"<<amount<<" gold! Total: "<<gold<<endl;
        }
        void attackTarget(Character& target) override
		{
			int dmg=attackPower;
			
			if(equippedWeapon != nullptr)
			{
				dmg +=equippedWeapon->getDamage();
			}
			cout<<name<<" attack for "<<dmg<<" damage! "<<endl;
			target.takeDamage(dmg);
		}
		void saveToFile(ofstream& file) 
		{
    		file<<name<< endl;
    		file<<health<<endl;
    		file<<gold<<endl;
    		file<<level<<endl;
		}

		void loadFromFile(ifstream& file) 
		{
  			file>>name;
    		file>>health;
    		file>>gold;
   			file>>level;
		}
		void DisplayStats() override
		{
            cout<<"===== HERO STATS ====="<<endl;
            cout<<"Name  : "<<name<<endl;
            cout<<"Level : "<<level<<endl;
            cout<<"HP    : "<<health<<"/"<<maxHealth<<endl;
            cout<<"ATK   : "<<attackPower<<endl;
            cout<<"DEF   : "<<defense<<endl;
            cout<<"Mana  : "<<mana<<endl;
            cout<<"Gold  : "<<gold<<endl;
            if(equippedWeapon != nullptr)
                cout<< "Weapon: "<<equippedWeapon->getName()<<endl;
            else
                cout<<"Weapon: None"<<endl;
            cout<<"====================="<<endl;
        }
};
#endif
