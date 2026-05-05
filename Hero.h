#ifndef HERO_H
#define HERO_H
#include<fstream>
#include"Character.h"
#include"Weapon.h"
#include"Potion.h"

class Hero : public Character{
	private:
		int mana;
		int gold;
		int level;
		Weapon*equippedWeapon;
	public:
		Hero(string n,int hp,int atk,int def):Character(n,hp,atk,def)
		{
			mana=100;
			gold=0;
			level=1;
			equippedWeapon=nullptr;
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
