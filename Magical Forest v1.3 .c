/*
Update:
-Added Level Generator fuction that Generates random level.

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>;
#include <stdlib.h>;
#include <string.h>;
#include <time.h>

struct Mage
{
	int health;
	int damage;
	char level[10];

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

struct Achievements {
	char FirstKill[50];
	int Purchase; // For first purchase
	int Ppurchase; // For potion purchase
	char FirstPurchase[50];
	char LegendaryPurchase[60];
	char PotionPurchase[50];
	char Elevel[50];
	char Dlevel[50];
	char Clevel[50];
	char Blevel[50];
	char Alevel[50];
}a;

void main_menu();
void Magical_shop();
void Display_Inventory();
void Attack();
void Heal();
void DisplayFirstBattle();
void DisplayAchievements();
void PlayerHUD();
void DisplaySecondBattle();
void DisplayThirdBattle();
void LevelGenerator();
int main()
{
	//Currency
	c.crystals = 100;
	//Inventory
	Inventory.Basic_wand = 0;
	Inventory.Premium_wand = 0;
	Inventory.Legendary_wand = 0;
	Inventory.potion25hp = 0;
	Inventory.potion50hp = 0;
	Inventory.potion75hp = 0;
	//Achievements
	strcpy(a.FirstKill, "Not achieved");
	strcpy(a.FirstPurchase, "Not achieved");
	strcpy(a.PotionPurchase, "Not achieved");
	strcpy(a.LegendaryPurchase, "Not achieved");
	strcpy(a.Elevel, "Not achieved");
	strcpy(a.Dlevel, "Not achieved");
	strcpy(a.Clevel, "Not achieved");
	strcpy(a.Blevel, "Not achieved");
	strcpy(a.Alevel, "Not achieved");
	a.Ppurchase = 0;
	a.Purchase = 0;
	//Level
	strcpy(mage.level, "F");

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
		printf("2. Level Generator\n");
		printf("3.Go to Magical shop \n");
		printf("4. Check Inventory\n");
		printf("5. Check Achievements\n");
		printf("6.Check Player's Information\n");
		printf("7. Exit the game\n");
		scanf_s("%d", &option);
		switch (option)
		{
		case 1:
			DisplayFirstBattle();
			break;
		case 2:
			LevelRandomizer();
			break;
		case 3:
			Magical_shop();
			break;
		case 4:
			Display_Inventory();
			break;
		case 5:
			DisplayAchievements();
			break;
		case 6:
			PlayerHUD();
			break;
		case 7:
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
			printf("4. Exit\n");
			scanf_s("%d", &selection);

			switch (selection)
			{
			case 1:
				if (c.crystals >= 25) {
					printf("You bought 25 hp potion\n ");
					c.crystals = c.crystals - 25;
					Inventory.potion25hp = Inventory.potion25hp + 1;
					printf("Now you have %d \n", c.crystals);
					if (a.Purchase == 0) {
						strcpy(a.FirstPurchase, "Achieved");
						printf("ACHIEVEMENT 'FIRST PURCHASE': you completed your first purchase\n "); //Achievement implementation
						a.Purchase = a.Purchase + 1;
					}
					else {

					}
					if (a.Ppurchase == 0) {
						strcpy(a.PotionPurchase, "Achieved");
						a.Ppurchase = a.Ppurchase + 1;
						printf("ACHIEVEMENT 'FIRST POTION': you bought your first potion ");//Achievement implementation
					}
					else {

					}
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
					if (a.Purchase == 0) {
						strcpy(a.FirstPurchase, "Achieved");
						printf("ACHIEVEMENT 'FIRST PURCHASE': you completed your first purchase\n ");//Achievement implementation
						a.Purchase = a.Purchase + 1;
					}
					else {

					}
					if (a.Ppurchase == 0) {
						strcpy(a.PotionPurchase, "Achieved");
						a.Ppurchase = a.Ppurchase + 1;
						printf("ACHIEVEMENT 'FIRST POTION': you bought your first potion ");//Achievement implementation
					}
					else {

					}
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
					if (a.Purchase == 0) {
						strcpy(a.FirstPurchase, "Achieved");
						printf("ACHIEVEMENT 'FIRST PURCHASE': you completed your first purchase\n ");//Achievement implementation
						a.Purchase = a.Purchase + 1;
					}
					else {

					}
					if (a.Ppurchase == 0) {
						strcpy(a.PotionPurchase, "Achieved");
						a.Ppurchase = a.Ppurchase + 1;
						printf("ACHIEVEMENT 'FIRST POTION': you bought your first potion ");//Achievement implementation
					}
					else {

					}
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
			printf("4. Exit\n");
			scanf_s("%d", &selection);
			switch (selection)
			{
			case 1:
				if (c.crystals >= 50) {
					printf("You bought a Basic wand\n");
					c.crystals = c.crystals - 50;
					Inventory.Basic_wand = Inventory.Basic_wand + 1;
					printf("Now you have %d crystals\n", c.crystals);
					if (a.Purchase == 0) {
						strcpy(a.FirstPurchase, "Achieved");
						printf("ACHIEVEMENT 'FIRST PURCHASE': you completed your first purchase\n ");//Achievement implementation
						a.Purchase = a.Purchase + 1;
					}
					else {

					}
				}
				else {
					printf("You don't have enough crystals to buy a wand\n");
				}
				printf("Press 4 if you would like to exit the wand section\n");
				scanf_s("%d", &selection);
				break;
			case 2:
				//level implementation
				if (strcpy(mage.level, "E") || strcpy(mage.level, "D") || strcpy(mage.level, "C") || strcpy(mage.level, "B") || strcpy(mage.level, "A")) {
					if (c.crystals >= 100) {
						printf("You bought a Premium Wand\n");
						c.crystals = c.crystals - 100;
						Inventory.Premium_wand = Inventory.Premium_wand + 1;
						printf("Now you have %d crystals\n", c.crystals);
						if (a.Purchase == 0) {
							strcpy(a.FirstPurchase, "Achieved");
							printf("ACHIEVEMENT 'FIRST PURCHASE': you completed your first purchase\n ");//Achievement implementation
							a.Purchase = a.Purchase + 1;
						}
						else {

						}
					}
					else {
						printf("You don't have enough crystals to buy a wand\n");
					}
				}
				else {
					printf("You haven't reached E level yet\n");
				}
				printf("Press 4 if you would like to exit the wand section \n");
				scanf_s("%d", &selection);
				break;
			case 3:
				// level implementation
				if (strcpy(mage.level, "D") || strcpy(mage.level, "C") || strcpy(mage.level, "B") || strcpy(mage.level, "A")) {
					if (c.crystals >= 200) {
						printf("You bought a Legendary Wand\n");
						c.crystals = c.crystals - 200;
						Inventory.Legendary_wand = Inventory.Legendary_wand + 1;
						printf("Now you have %d crystals", c.crystals);
						if (a.Purchase == 0) {
							strcpy(a.FirstPurchase, "Achieved");
							printf("ACHIEVEMENT 'FIRST PURCHASE': you completed your first purchase\n ");//Achievement implementation
							a.Purchase = a.Purchase + 1;
						}
						else {

						}
						strcpy(a.LegendaryPurchase, "Achieved");
						printf("ACHIEVEMENT 'LEGENDARY PURCHASE': you bought Legendary sword ");//Achievement implementation
					}
					else {
						printf("You don't have enought crystals to buy a wand\n");
					}
				}
				else {
					printf("You need to read 'D' level in order to buy a Legendary sword");
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
			printf("ACHIEVEMENT 'FIRST KILL': You killed your first monster\n");//Achievement implementation
			strcpy(a.FirstKill, "Achieved");
			printf("You reached E level\n");
			strcpy(mage.level, "E");
			printf("ACHIEVEMENT'E level': You reached E level\n");
			break;
		}

	} while (1);
}
void DisplayAchievements() {

	printf("First kill: %s \n First Purchase: %s \n LegendaryPurchase:%s \n", a.FirstKill, a.FirstPurchase, a.LegendaryPurchase);
	printf("Potion purchase: %s \n E level: %s \n D level: %s\n ", a.PotionPurchase, a.Elevel, a.Dlevel);
	printf("C level: %s \n B level: %s\n A level: %s\n", a.Clevel, a.Blevel, a.Alevel);


}
void PlayerHUD() {
	mage.health = 50;
	mage.damage = 15;
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
	printf("Player's HUD:\n");
	printf("Health: %d\n",mage.health);
	printf("Damage: %d\n",mage.damage);
	printf("Level: %s\n",mage.level);
}
void DisplaySecondBattle() {
	int choice;
	mage.health = 50;
	monster.health = 100;
	printf(" C level monster decided to attack you\n");

	printf("Your mission to kill C class monster\n");
	printf("Reward:200 crystals\n");
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
			c.crystals = c.crystals + 200;
			break;
		}
	} while (1);
}



void DisplayThirdBattle() {
	int choice;
	mage.health = 50;
	monster.health = 150;
	printf(" A level monster decided to attack you\n");

	printf("Your mission to kill C class monster\n");
	printf("Reward:300 crystals\n");
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
			c.crystals = c.crystals + 300;
			break;
		}
	} while (1);
}
void LevelGenerator() {

	srand(time(0));
	int randomizer;

	randomizer = rand(2);

	switch (randomizer){
		case 0:
			DisplayFirstBattle();
			break;
		case 1:
			DisplaySecondBattle();
			break;
		case 2:
			DisplayThirdBattle();
	default:
		break;
	}

}
