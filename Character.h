#ifndef CHARACTER_H
#define CHARACTER_H

#include<iostream>
#include<string>
using namespace std;
class Character{
	protected:
		string name;
		int health;
		int maxHealth;
		int attackPower;
		int defense;
	public:
		Character(string n,int hp ,int atk,int def)
		{
			name=n;
			health=hp;
			maxHealth=hp;
			attackPower=atk;
			defense=def;
		}
		string getName()
		{
			return name;
		}
		int gethealth()
		{
			return health;
		}
		bool isAlive()
		{
			return health>0;
		}
		void takeDamage(int dmg)
		{
			int actual=dmg-defense;
			if(actual<1)
			actual=1;
			health-=actual;
			if(health<0)
			health=0;
		}
		virtual void DisplayStats()
		{
			cout<<"["<<name<<"]"
				<<"HP: "<<health<<"/"<<maxHealth
				<<"ATK: "<<attackPower
				<<"DEF: "<<defense<<endl;
		}
		virtual void attackTarget(Character& target)=0;
		virtual ~Character(){}
};
#endif
