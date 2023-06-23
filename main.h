#include <string>
#include <stdio.h>
#include <iostream>
#include <random>
#include <fstream>

using namespace std;

class Character {
public:
	int charHealth, charDamage, goldCount;
	string charName;
	bool isTurn;

	bool isAlive = true;
	Character(string name, int health, int damage)
		: charName(name), charHealth(health), charDamage(damage) {}

	void Update(string& name) {
			ofstream writeFile(name + ".txt");
			writeFile << goldCount;
			writeFile.close();
		}

	void Reward(string& name) {
		goldCount += rand() % 100;
		cout << "You got " <<  goldCount << " gold coins!" << endl;
		Update(name);
	}

	void CharAttack(string& name, int damage, int& health) {
		if (charHealth <= 0) {
			isAlive = false;
			cout << charName << " has been defeated" << endl;
		} else { 
			health -= damage;
			cout << charName  << " deals " << damage << " to " << name << endl; 
		}
	}

	int CharHeal(int healPoints) {
		return charHealth += healPoints;
	}
};