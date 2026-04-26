#ifndef ITEM_H
#define ITEM_H

#include<iostream>
#include<string>
using namespace std;

class Item{
	protected:
  	  string name;
  	  int weight;

	public:
    	Item(string n, int w) 
		{
        	name=n;
        	weight=w;
    	}
    	string getName() 
		{ 
			return name; 
		}
    	virtual void Display() 
		{
    	    cout<<"["<<name<<"]";
    	}
    	virtual void use()=0;
    	virtual ~Item() {}
};
#endif
