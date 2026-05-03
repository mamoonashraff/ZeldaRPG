#ifndef MAP_H
#define MAP_H

#include"Room.h"
#include"Weapon.h"
#include"Potion.h"
#include"Enemy.h"

class Map {
    private:
        Room*rooms[4];
        int totalRooms;
        int currentRoom;

    public:
        Map() {
            totalRooms=4;
            currentRoom=0;

            rooms[0]=new Room("Dark Cave");
            rooms[1]=new Room("Forest Path");
            rooms[2]=new Room("Haunted Castle");
            rooms[3]=new Room("Boss Lair");

            rooms[0]->addItem(new Weapon("Iron Sword",25,"sword"));
            rooms[0]->setEnemy(new Enemy("Goblin",60,15,2,"sword",20));

            rooms[1]->addItem(new Potion("Health Potion",50));

            rooms[2]->addItem(new Weapon("Magic Staff",40,"magic"));
            rooms[2]->setEnemy(new Enemy("Dark Knight",100,25,8,"magic",35));

            rooms[3]->setEnemy(new Enemy("Tony",200,40,10,"sword",100));
        }

        Room* getCurrentRoom() 
		{
            return rooms[currentRoom];
        }

        bool moveNext() 
		{
            if(currentRoom<totalRooms-1) 
			{
                currentRoom++;
                return true;
            }
            cout<<"No more rooms ahead!"<<endl;
            return false;
        }

        bool isLastRoom() 
		{
            return currentRoom==totalRooms-1;
        }

        int getCurrentRoomNumber() 
		{
            return currentRoom+1;
        }

        int getTotalRooms() 
		{
            return totalRooms;
        }

        ~Map() 
		{
            for(int i=0;i<totalRooms;i++) 
			{
                delete rooms[i];
            }
        }
};
#endif
