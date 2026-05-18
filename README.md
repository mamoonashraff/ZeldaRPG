# ZeldaRPG - Text Based RPG Game in C++

## About

ZeldaRPG is a console-based Role Playing Game built entirely in C++
using core Object Oriented Programming principles. The player explores
4 unique rooms, battles enemies, collects weapons and spells, and
faces an Ancient Dragon as the final boss.
Developed as a 2nd Semester OOP Project at IST (Institute of Space Technology).

## Gameplay

- Explore 4 unique rooms
- Fight enemies including Goblin, Dark Knight, and Ancient Dragon
- Collect weapons, potions, and spells
- Cast spells using mana system
- Save and load your game progress

## How to Play

### Controls

- W - Move to next room
- A - Attack enemy
- P - Pick item
- B - View bag
-H - Hero stats
-S - Save game
- L - Load game
- Z - Cast spell
- X - Show spells
- Q - Quit game

### Rules

- Defeat all enemies to progress
- Collect items to become stronger
- Learn spells to defeat the Dragon
- Save your progress with S command

## OOP Concepts Used

### Inheritance

- Character  Hero
- Character  Enemy  Dragon
- Item  Weapon
- Item  Potion
- Item  Spell

### Polymorphism

- attackTarget() overridden in Hero, Enemy, Dragon
- Display() overridden in Weapon, Potion, Spell
- displayStats() overridden in Hero, Enemy, Dragon

### Abstraction

- Character  pure virtual attackTarget()
- Item  pure virtual use() and Display()

### Composition

- Hero has Inventory
- Room has Items and Enemy
- Map has Rooms
- GameEngine has Hero, Map, Inventory

### Encapsulation

- All data members are private
- Access through public getter functions

### File Handling

- Game save/load system using savegame.txt

## Project Structure

ZeldaRPG/
- Character.h  Base class for all characters
- Item.h  Base class for all items
- Weapon.h  Weapon item
- Potion.h  Healing potion
- Spell.h Magic spell
- Hero.h  Player character
- Enemy.h  Enemy character
- Dragon.h  Final boss
- Inventory.h  Hero's bag system
- Room.h  Game room
- Map.h  Game world
- GameEngine.h  Game controller
- main.cpp  Entry point
- savegame.txt  Save file

---

## How to Compile & Run

bash
g++ main.cpp -o ZeldaRPG
./ZeldaRPG

Or open in Dev C++ and press **F11**

---

## Technologies Used

- Language: C++
- IDE: Dev C++ 5.11
- Compiler: TDM-GCC 4.9.2 64-bit
- Version Control: Git & GitHub

---

## What I Learned

- Designing class hierarchies using Inheritance
- Runtime Polymorphism with virtual functions
- Memory management with pointers and dynamic allocation
- File I/O for game save/load system
- Building a complete project from scratch

---

## Author

**Mamoon Ashraf**
BS Computer Science 2nd Semester
Institute of Space Technology (IST), Islamabad, Pakistan
mamoonashraf831@gmail.com
[GitHub](https://github.com/mamoonashraff)
