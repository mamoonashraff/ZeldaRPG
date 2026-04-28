#include<iostream>
#include"Hero.h"
#include"Enemy.h"
#include"Inventory.h"
#include"Room.h"
using namespace std;

int main() 
{
    cout<<"=============================="<<endl;
    cout<<"      ZeldaRPG - Day 3        "<<endl;
    cout<<"=============================="<<endl;

    // Create Hero
    Hero hero("Mamoon", 100, 30, 5);
    Inventory bag;

    // Create Items
    Weapon sword("Iron Sword", 25, "sword");
    Potion potion("Health Potion", 50);

    // Create Enemies
    Enemy goblin("Goblin", 60, 15, 2, "sword", 20);
    Enemy tony("Tony", 200, 40, 10, "sword", 50);

    // Create Rooms
    Room room1("Dark Cave (Starting Room)");
    Room room2("Forest Path (Jungle Trail)");
    Room room3("Boss Lair (Tony's Domain!)");

    // Setup Room 1
    room1.addItem(&sword);
    room1.setEnemy(&goblin);

    // Setup Room 2
    room2.addItem(&potion);

    // Setup Room 3
    room3.setEnemy(&tony);

    // ===== ROOM 1 =====
    room1.display();

    cout<<"\nPicking up sword..." <<endl;
    Item* pickedSword = room1.pickItem(0);
    if(pickedSword != nullptr) 
	{
        bag.addItem(pickedSword);
        hero.equipWeapon(&sword);
    }

    cout<<"\nFighting Goblin!"<<endl;
    while(hero.isAlive() && goblin.isAlive()) 
	{
        hero.attackTarget(goblin);
        if(!goblin.isAlive()) 
		{
            cout<<"Goblin defeated!"<<endl;
            hero.addGold(goblin.getGoldReward());
            break;
        }
        goblin.attackTarget(hero);
    }

    // ===== ROOM 2 =====
    room2.display();

    cout<<"\nPicking up potion..."<<endl;
    Item* pickedPotion = room2.pickItem(0);
    if(pickedPotion != nullptr)
	{
        bag.addItem(pickedPotion);
    }

    cout<<"\nChecking bag:"<<endl;
    bag.display();

    // ===== ROOM 3 =====
    room3.display();
    hero.DisplayStats();

    cout<<"\nFinal fight with Tony!"<<endl;
    while(hero.isAlive() && tony.isAlive()) 
	{
        hero.attackTarget(tony);
        cout<<"Tony HP: "<<tony.gethealth()<<endl;
        if(!tony.isAlive()) 
		{
            cout<<"\nTony defeated! You WIN!"<<endl;
            hero.addGold(tony.getGoldReward());
            break;
        }
        tony.attackTarget(hero);
        cout<<"Hero HP: "<<hero.gethealth()<<endl;
        if(!hero.isAlive()) 
		{
            cout<<"\nHero defeated! Game Over!"<<endl;
            break;
        }
    }

    cout<<"\n=============================="<<endl;
    cout<<"         GAME COMPLETE!       "<<endl;
    cout<<"=============================="<<endl;

    return 0;
}
