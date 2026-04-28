#ifndef INVENTORY_H
#define INVENTORY_H

#include"Item.h"
#include"Weapon.h"
#include"Potion.h"

class Inventory 
{
    private:
        Item*items[10];
        int count;

    public:
        Inventory() 
		{
            count=0;
            for(int i=0; i<10;i++) 
			{
                items[i]=nullptr;
            }
        }

        bool addItem(Item* item)
		{
            if(count >= 10) 
			{
                cout<<"Bag is full! Cannot pick item."<<endl;
                return false;
            }
            items[count]=item;
            count++;
            cout<<item->getName()<<" added to bag!"<<endl;
            return true;
        }

        Item*removeItem(int index) 
		{
            if(index<0||index>=count) 
			{
                cout<<"Invalid item!"<<endl;
                return nullptr;
            }
            Item*removed=items[index];
            for(int i=index; i<count-1;i++)
			{
                items[i]=items[i + 1];
            }
            items[count-1]=nullptr;
            count--;
            return removed;
        }
        void display() 
		{
            cout<<"===== BAG ====="<< endl;
            if(count==0)
			{
                cout<<"Bag is empty!"<<endl;
            } else
			{
                for(int i=0;i<count;i++) 
				{
                    cout << i + 1 << ". ";
                    items[i]->Display();
                    cout << endl;
                }
            }
            cout<<"Items: "<<count<<"/10"<<endl;
            cout<<"==============="<<endl;
        }

        void useItem(int index) 
		{
            if(index < 0 || index>=count) 
			{
                cout<<"Invalid item!"<<endl;
                return;
            }
            items[index]->use();
        }

        int getCount()
		{
			return count;
		}
        Item*getItem(int index)  
		{
			return items[index];
		}
};
#endif
