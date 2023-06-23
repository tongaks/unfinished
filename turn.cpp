#include <iostream>
#include "main.h"

void examplebattle() {
	int option;
	string player_name;
	system("clear");
	cout << "Player name: ";
	cin >> player_name;
	
	Character player(player_name, 100, 89);
	Character enemy("bahoo", 100, 12);

	while (player.isAlive == true && enemy.isAlive == true) {
		cout << endl << "Player health: " << player.charHealth << endl << "Enemy health: " << enemy.charHealth << endl; 
		cout << "What would " << player_name << " do?" << endl;
		cout << "1) Attack 2) Heal" << endl << "> ";

		cin >> option;

		switch (option) {
			case 1:
				player.CharAttack(enemy.charName, player.charDamage, enemy.charHealth);
				break;
			default:
				break;
		}

		enemy.CharAttack(player.charName, enemy.charDamage, player.charHealth);
		player.Reward(player_name);
	}
}

int main(){
	examplebattle();
	return 0;
}