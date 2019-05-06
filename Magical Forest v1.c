#include <stdio.h>;
#include <stdlib.h>;

struct Mage
{
	int health;

	int damage;

}mage;

struct Monster {
	int health;
	int damage;

}monster;
struct Inventory {
	int Basic_wand;
	int Premium_wand;
	int Legendary_wand;
	int potion25hp;
	int potion50hp;
	int potion75hp;
}Inventory;

struct Currency {
	int crystals;
}c;

void main_menu();
void Magical_shop();
void Display_Inventory();
void Attack();
void Heal();
void DisplayFirstBattle();
int main()
{
	c.crystals = 100;
	Inventory.Basic_wand = 0;
	Inventory.Premium_wand = 0;
	Inventory.Legendary_wand = 0;
	Inventory.potion25hp = 0;
	Inventory.potion50hp = 0;
	Inventory.potion75hp = 0;

	printf("Magical Forest\n");
	printf("You are newly graduated Mage, who is ready to go adventurers and become a S class Mage\n");
	printf("Since you only graduated you are only F class adventurer.Don't worry at least you have mission to start off\n");
	main_menu();

	system("PAUSE");
	return 0;
}
void main_menu() {
	int option = 0;
	do {
		printf("Main menu:\n");
		printf("1.Play  the first level\n");
		printf("2.Go to Magical shop \n");
		printf("3. Check Inventory\n");
		printf("4. Exit the game\n");
		scanf_s("%d", &option);
		switch (option)
		{
		case 1:
			DisplayFirstBattle();
			break;
		case 2:
			Magical_shop();
			break;
		case 3:
			Display_Inventory();
			break;
		case 4:
			exit(0);
			break;


		}
	} while (1);

}
void Magical_shop() {
	int option = 0;
	int selection = 0;
	int decision = 0;

	do {
		printf("Welcome to the shop!\n");
		printf("Currently you have %d crystals", c.crystals);
		printf("Would you like to buy potion or wand?\n");
		printf("Potions- 1, Wands -2, Exit the shop -3\n");
		scanf_s("%d", &option);

		switch (option)
		{
		case 1:
			printf("1.Potion 25 hp - 25 crystals\n");
			printf("2. Potion 50 hp - 50 crystals \n");
			printf("3. Photion 75 hp - 75 cristals\n");
			scanf_s("%d", &selection);

			switch (selection)
			{
			case 1:
				if (c.crystals >= 25) {
					printf("You bought 25 hp potion\n ");
					c.crystals = c.crystals - 25;
					Inventory.potion25hp = Inventory.potion25hp + 1;
					printf("Now you have %d \n", c.crystals);
				}
				else {
					printf("Sorry you don't have enough crystals to buy a potion");
				}
				printf("Press 4 if you would like to exit the potion section\n");
				scanf_s("%d", &selection);
				break;
			case 2:
				if (c.crystals >= 50) {
					printf("You bought 50 hp potion\n");
					c.crystals = c.crystals - 50;
					Inventory.potion50hp = Inventory.potion50hp + 1;
					printf("Now you have %d\n", c.crystals);
				}
				else {
					printf("Sorry you don't have enough crystals to buy a potion\n");
				}
				printf("Press 4 if you would like to exit the potion section\n");
				scanf_s("%d", &selection);
				break;
			case 3:
				if (c.crystals >= 75) {
					printf("You bought 75 hp potion\n");
					c.crystals = c.crystals - 75;
					Inventory.potion75hp = Inventory.potion75hp + 1;
					printf("Now you have %d crystals\n", c.crystals);
				}
				else {
					printf("Sorry you dont't have enough crystals to buy a potion\n");
				}
				printf("Press 4 if you would like to exit the potion section");
				scanf_s("%d", &selection);
			case 4:
				return;
			}
		case 2:
			printf("1. Basic wand- 50 crystals\n");
			printf("2. Premium wand- 100 crystals\n");
			printf("3. Legendary wand - 200 crystals\n");
			scanf_s("%d", &selection);
			switch (selection)
			{
			case 1:
				if (c.crystals >= 50) {
					printf("You bought a Basic wand\n");
					c.crystals = c.crystals - 50;
					Inventory.Basic_wand = Inventory.Basic_wand + 1;
					printf("Now you have %d crystals\n", c.crystals);
				}
				else {
					printf("You don't have enough crystals to buy a wand\n");
				}
				printf("Press 4 if you would like to exit the wand section\n");
				scanf_s("%d", &selection);
				break;
			case 2:
				if (c.crystals >= 100) {
					printf("You bought a Premium Wand\n");
					c.crystals = c.crystals - 100;
					Inventory.Premium_wand = Inventory.Premium_wand + 1;
					printf("Now you have %d crystals\n", c.crystals);
				}
				else {
					printf("You don't have enough crystals to buy a wand\n");
				}
				printf("Press 4 if you would like to exit the wand section \n");
				scanf_s("%d", &selection);
				break;
			case 3:
				if (c.crystals >= 200) {
					printf("You bought a Legendary Wand\n");
					c.crystals = c.crystals - 200;
					Inventory.Legendary_wand = Inventory.Legendary_wand + 1;
					printf("Now you have %d crystals", c.crystals);
				}
				else {
					printf("You don't have enought crystals to buy a wand\n");
				}
				printf("Press 4 if you would like to exit the want section\n");
				scanf_s("%d", &selection);
				break;
			case 4:
				return;
			}

		case 3:
			return;
		}
	} while (1);
}
void Display_Inventory() {
	printf("Your inventory:\n");
	printf("Basic wand:%d, Premium wand:%d, Legendary wand:%d", Inventory.Basic_wand, Inventory.Premium_wand, Inventory.Legendary_wand);
	printf("25 hp Potion:%d, 50 hp Potion:%d, 75 hp potion:%d", Inventory.potion25hp, Inventory.potion50hp, Inventory.potion75hp);
}
void Attack() {
	mage.damage = 15;
	monster.damage = 10;
	if (Inventory.Basic_wand >= 1) {
		mage.damage = mage.damage + 5;
	}
	else if (Inventory.Premium_wand >= 1)
	{
		mage.damage = mage.damage - 5 + 10;
	}
	else if (Inventory.Legendary_wand >= 1) {
		mage.damage = mage.damage - 15 + 15;
	}
	monster.health = monster.health - mage.damage;
	mage.health = mage.health - monster.damage;

	printf("Mage inflicted %d damage on Monster, now Monster has %d health \n", mage.damage, monster.health);
	printf("While Monster inflicted %d damage on you, Now you have %d health \n ", monster.damage, mage.health);
}
void Heal() {
	int option = 1;
	printf("Which potion you want to use\n");
	printf("1- 25 hp Potion\n");
	printf("2- 50 hp Potion\n");
	printf("3- 75 hp Potion\n");
	scanf_s("%d", &option);
	switch (option)
	{
	case 1:
		if (Inventory.potion25hp >= 1) {
			printf("You used 25 hp potion\n");
			mage.health = mage.health + 25;
			printf("Now you have %d health\n", mage.health);

		}
		else {
			printf("You don't have that potion in your Inventory\n");
		}
	case 2:
		if (Inventory.potion50hp >= 1) {
			printf("You used 50 hp potion\n");
			mage.health = mage.health + 50;
			printf("Now you have %d health\n", mage.health);
		}
		else {
			printf("You don't have that potion in your Inventory\n");
		}
	case 3:
		if (Inventory.potion75hp >= 1) {
			printf("You used 75 hp potion\n");
			mage.health = mage.health + 75;
			printf("Now you have %d health\n", mage.health);
		}
		else {
			printf("You don't have that potion in your Inventory\n");
		}
	default:
		break;
	}


}
void DisplayFirstBattle() {
	int choice;
	mage.health = 50;
	monster.health = 50;
	printf("Your first mission is to the Magical Forest.\n");
	printf("Where monsters like to lurk\n");
	printf("Your mission to kill E class monster\n");
	printf("Reward:100 crystals\n");
	do {

		printf("1.Attack, 2.Heal, 3. Run \n ");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			Attack();
			break;
		case 2:
			Heal();
			break;
		case 3:
			return;
		default:
			break;
		}
		if (mage.health <= 0) {
			printf("Monster won\n");
			break;
		}
		else if (monster.health <= 0) {

			printf("You won");
			printf("You got 100 crystals reward for killing the monster\n");
			c.crystals = c.crystals + 100;
			break;
		}

	} while (1);
}
