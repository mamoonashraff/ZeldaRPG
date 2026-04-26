#ifndef POTION_H
#define POTION_H

#include"Item.h"
class Potion:public Item{
	private:
		int healAmount;
	public:
		Potion(string n,int heal):Item(n,1)
		{
			healAmount=heal;
		}
    	int getHeal()
		{
			return healAmount; 
		}
    	void use()override{
    	    cout<<name<<" used! Heals "<<healAmount<<" HP."<<endl;
    	}
    	void Display()override{
    	    cout<<"["<<name<<" | HEAL:"<<healAmount<< "]";
		}
};
#endif
