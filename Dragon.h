#ifndef DRAGON_H
#define DRAGON_H

#include"Enemy.h"

class Dragon:public Enemy 
{
    private:
        int fireDamage;

    public:
        Dragon(string n,int hp,int atk,int def,int fire):Enemy(n,hp,atk,def,"magic",200) 
		{
            fireDamage = fire;
        }
        void breathFire(Character& target) {
            cout<<name<<" breathes FIRE! "<<fireDamage<<" damage!"<<endl;
            target.takeDamage(fireDamage);
        }

        void attackTarget(Character& target) override 
		{
            int choice=rand()%2;
            if(choice==0) 
			{
                cout<<name<<" attacks for "<< attackPower<<" damage!"<<endl;
                target.takeDamage(attackPower);
            } 
			else 
			{
                breathFire(target);
            }
        }

        void DisplayStats() override {
            cout<<"===== DRAGON STATS ====="<<endl;
            cout<<"Name      : "<<name<<endl;
            cout<<"HP        : "<<health<<"/"<<maxHealth<<endl;
            cout<<"ATK       : "<<attackPower<<endl;
            cout<<"DEF       : "<<defense<<endl;
            cout<<"Fire DMG  : "<<fireDamage<<endl;
            cout<<"Weakness  : "<<weakness<<endl;
            cout<<"Reward    : "<<goldReward<<" gold"<<endl;
            cout<<"========================"<<endl;
        }
};
#endif
