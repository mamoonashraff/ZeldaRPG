#ifndef SPELL_H
#define SPELL_H

#include"Item.h"

class Spell : public Item 
{
    private:
        int manaCost;
        int damage;
        string element;

    public:
        Spell(string n,int mana,int dmg,string elem):Item(n, 0) 
			{
            manaCost=mana;
            damage=dmg;
            element=elem;
        	}

        int getManaCost() 
		{ 
			return manaCost; 
		}
        int getDamage()   
		{ 
			return damage;   
		}
        string getElement() 
		{
			return element;  
		}
        void use() override 
		{
            cout << name<<" spell cast! "<<"Damage: "<<damage<<" Mana cost: "<<manaCost<<endl;
        }

        void Display() override 
		{
            cout <<"["<<name<<" | DMG: "<<damage<<" | MANA: "<<manaCost<<" | "<< element<<"]";
        }
};

#endif
