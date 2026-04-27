#include <iostream>
#include "Hero.h"
#include "Enemy.h"
using namespace std;
int main() 
{
    cout<<"=============================="<<endl;
    cout<<"      ZeldaRPG - Day 2        "<<endl;
    cout<<"=============================="<<endl;

    Hero hero("Mamoon", 100, 30, 5);

    Weapon sword("Iron Sword", 25, "sword");
    hero.equipWeapon(&sword);

    Enemy tony("Tony", 60, 15, 2, "sword", 20);

    cout<<"\n";
    hero.DisplayStats();
    cout<<"\n";
    tony.DisplayStats();

    cout<<"\n=============================="<<endl;
    cout<<"         BATTLE START!       "<<endl;
    cout<<"=============================="<<endl;

    int round=1;

    while(hero.isAlive() && tony.isAlive()) {
        cout<<"\n--- Round " <<round<<" ---"<< endl;

        hero.attackTarget(tony);
        cout <<"Tony HP: "<<tony.gethealth()<<endl;

        if(!tony.isAlive()) 
		{
            cout << "\nTony defeated! "<<endl;
            hero.addGold(tony.getGoldReward());
            break;
        }
        tony.attackTarget(hero);
        cout<<"Hero HP: "<<hero.gethealth()<<endl;

        if(!hero.isAlive()) 
		{
            cout<<"\nHero defeated! Game Over! "<<endl;
            break;
        }
        round++;
    }
    cout<<"\n=============================="<<endl;
    cout<<"       BATTLE COMPLETE!       "<<endl;
    cout<<"==============================" <<endl;

    return 0;
}
