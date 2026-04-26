#ifndef WEAPON_H
#define WEAPON_H

#include"Item.h"
class Weapon:public Item{
	private:
		int damage;
		string type;
	public:
		Weapon(string n,int dmg,string t):Item(n,3)
		{
			damage=dmg;
			type=t;
		}
		int getDamage()
		{
			return damage;
		}
		string getType()
		{
			return type;
		}
		void use() override{
			cout<<name<<"equipped! Damage: "<<damage<<endl;
		}
		void Display() override{
			cout<<"["<<name<<" | DMG: "<<damage<<"]";
		}
};
#endif
