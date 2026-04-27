#ifndef ENEMY_H
#define ENEMY_H

#include"Character.h"

class Enemy:public Character 
{
	protected:
        string weakness;
        int goldReward;
    public:
        Enemy(string n, int hp,int atk,int def,string weak,int gold)
		:Character(n, hp, atk, def) 
		{
            weakness=weak;
            goldReward=gold;
        }
        string getWeakness()
		{ 
			return weakness;
		}
        int getGoldReward()
		{ 	
			return goldReward;
		}
        void attackTarget(Character& target) override 
		{
            cout<<name<<" attacks for "<<attackPower<<" damage!"<<endl;
            target.takeDamage(attackPower);
        }

        void DisplayStats() override 
		{
            cout<<"===== ENEMY STATS ====="<<endl;
            cout<<"Name    : "<<name<<endl;
            cout<<"HP      : "<<health<<"/"<<maxHealth<<endl;
            cout<<"ATK     : "<<attackPower<<endl;
            cout<<"DEF     : "<<defense<<endl;
            cout<<"Weakness: "<<weakness<<endl;
            cout<<"Reward  : "<<goldReward<<" gold"<<endl;
            cout<<"======================="<<endl;
        }
};
#endif
