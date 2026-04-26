#include<iostream>
#include"Character.h"
#include"Weapon.h"
#include"Potion.h"
using namespace std;

int main() 
{
    cout<<"=============================="<<endl;
    cout<<"   ZeldaRPG - Day 1 Test      "<<endl;
    cout<<"=============================="<<endl;

    // Item test
    Weapon sword("Iron Sword", 25, "sword");
    Potion potion("Health Potion", 50);

    cout<<"\nItems created:"<<endl;
    sword.Display();
    cout<<endl;
    potion.Display();
    cout<<endl;

    cout<<"\nUsing items:"<<endl;
    sword.use();
    potion.use();

    cout<<"\nDay 1 complete! Classes work!"<<endl;

    return 0;
}
