#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "extrafile.h"
using namespace std;

unsigned int readData(string fileName, vector<extrafile>& spaceShips)
{
	ifstream file(fileName, ios_base::binary);
	unsigned int counter = 0;
	unsigned int count = 0;
	file.read((char*)&count, sizeof(count));

	for (unsigned int i = 0; i < count; i++)
	{
		int length;
		file.read((char*)&length, sizeof(length));
		char* buffer = new char[length];
		file.read(buffer, length);
		string shipName = buffer;
		delete[] buffer;

		file.read((char*)&length, sizeof(length));
		char* buffer2 = new char[length];
		file.read(buffer2, length);
		string shipClass = buffer2;
		delete[] buffer2;

		short shipLength;
		file.read((char*)&shipLength, sizeof(shipLength));

		int shieldCapacity;
		file.read((char*)&shieldCapacity, sizeof(shieldCapacity));

		float warpSpeed;
		file.read((char*)&warpSpeed, sizeof(warpSpeed));

		unsigned int weaponCount;
		file.read((char*)&weaponCount, sizeof(weaponCount));

		extrafile addedShips(shipName, shipClass, shipLength, shieldCapacity, warpSpeed, weaponCount);
		
		if (weaponCount > 0)
		{
			for (unsigned int i = 0; i < weaponCount; i++)
			{
				file.read((char*)&length, sizeof(length));
				char* buffer = new char[length];
				file.read(buffer, length);
				string weaponName = buffer;
				delete[] buffer;

				int weaponPower; 
				file.read((char*)&weaponPower, sizeof(weaponPower));

				float weaponConsumption;
				file.read((char*)&weaponConsumption, sizeof(weaponConsumption));

				Weapon shipWeapon(weaponName, weaponPower, weaponConsumption);
				addedShips.weapons.push_back(shipWeapon);
				
			}
		}
		spaceShips.push_back(addedShips);
		counter++;
	}
	return counter;
}


int main()
{
	cout << "Which file(s) to open?\n";
	cout << "1. friendlyships.shp" << endl;
	cout << "2. enemyships.shp" << endl;
	cout << "3. Both files" << endl;
	int option;
	cin >> option;

	bool exit = false;
	vector<extrafile> spaceShips;
	unsigned int shipCount = 0;

	//Opening appropriate file(s)
	while (!exit)
	{
		switch (option)
		{
			case 1:
			{
				shipCount = readData("friendlyships.shp", spaceShips);
				exit = true;
				break;
			}
			case 2:
			{
				shipCount = readData("enemyships.shp", spaceShips);
				exit = true;
				break;

			}
			case 3:
			{
				shipCount = readData("friendlyships.shp", spaceShips) + readData("enemyships.shp", spaceShips);
				exit = true;
				break;
			}
			default:
			{
				cout << "Enter a valid option please!" << endl;
				exit = true;
				break;
			}
		}
	}

	cout << "1. Print all ships" << endl;
	cout << "2. Starship with the strongest weapon" << endl;
	cout << "3. Strongest starship overall" << endl;
	cout << "4. Weakest ship (ignoring unarmed)" << endl;
	cout << "5. Unarmed ships" << endl;

	cin >> option;

	/* Work your magic here */
	unsigned int target = 0;

	switch (option)
	{
	case 1:
		for (unsigned int i = 0; i < shipCount; i++)
		{
			spaceShips.at(i).displayShip();
			cout << endl;
		}
		break;
	case 2:
		for (unsigned int i = 1; i < shipCount; i++)
		{
			if (spaceShips.at(i).getStrongestWeapon() > spaceShips.at(target).getStrongestWeapon())
			{
				target = i;
			}
			if (i == shipCount - 1)
			{
				spaceShips.at(target).displayShip();
			}
		}
		break;
		
	case 3:
		for (unsigned int i = 1; i < shipCount; i++)
		{
			if (spaceShips.at(i).getTotalPower() > spaceShips.at(target).getTotalPower())
			{
				target = i;
			}
			if (i == shipCount - 1)
			{
				spaceShips.at(target).displayShip();
			}
		}
		break;
	case 4:
		for (unsigned int i = 1; i < shipCount; i++)
		{
			if (spaceShips.at(i).getTotalPower() < spaceShips.at(target).getTotalPower() && spaceShips.at(i).getWeaponCount() > 0)
			{
				target = i;
			}
			if (i == shipCount - 1)
			{
				spaceShips.at(target).displayShip();
			}
		}
		break;
	case 5:
		for (unsigned int i = 1; i < shipCount; i++)
		{
			if (spaceShips.at(i).getWeaponCount() == 0)
			{
				spaceShips.at(i).displayShip();
				cout << endl;
			}
		}
		break;
	default: 
		cout << "Enter a valid option please!" << endl;
		break;
	}
	return 0;
}