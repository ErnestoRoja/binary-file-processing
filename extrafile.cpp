#include <iostream>
#include "extrafile.h"
using namespace std;

extrafile::extrafile(string name, string className, short length, int shieldCapacity, float warpSpeed, unsigned int weaponCount)
{
	_name = name;
	_class = className;
	_length = length;
	_shieldCapacity = shieldCapacity;
	_warpSpeed = warpSpeed;
	_weaponCount = weaponCount;
}

string extrafile::getName()
{
	return _name;
}

string extrafile::getClass()
{
	return _class;
}

short extrafile::getLength()
{
	return _length;
}

unsigned int extrafile::getShieldCapacity()
{
	return _shieldCapacity;
}

float extrafile::getWarpSpeed()
{
	return _warpSpeed;
}

unsigned int extrafile::getWeaponCount()
{
	return _weaponCount;
}

Weapon::Weapon(string weaponName, unsigned int weaponPower, float weaponPowerConsumption)
{
	_weaponName = weaponName;
	_weaponPower = weaponPower;
	_weaponPowerConsumption = weaponPowerConsumption;
}

unsigned int Weapon::getPower()
{
	return _weaponPower;
}

void Weapon::weaponDisplay()
{
	cout << _weaponName << ", " << _weaponPower << ", " << _weaponPowerConsumption << endl;
}

unsigned int extrafile::getStrongestWeapon()
{
	unsigned int maxPower = 0;
	for (unsigned int i = 0; i < _weaponCount; i++)
	{
		if (maxPower < weapons.at(i).getPower())
		{
			maxPower = weapons.at(i).getPower();
		}
	}
	return maxPower;
}

int extrafile::getTotalPower()
{
	int totalPower = 0;
	for (unsigned int i = 0; i < _weaponCount; i++)
	{
		totalPower += weapons.at(i).getPower();
	}
	return totalPower;
}

void extrafile::displayShip()
{
	cout << "Name: " << _name << endl;
	cout << "Class: " << _class << endl;
	cout << "Length: " << _length << endl;
	cout << "Shield capacity: " << _shieldCapacity << endl;
	cout << "Maximum Warp: " << _warpSpeed << endl;
	cout << "Armaments: " << endl;

	if (_weaponCount == 0)
	{
		cout << "Unarmed" << endl;
	}
	else
	{
		int totalPower = 0;
		for (unsigned int i = 0; i < _weaponCount; i++)
		{
			weapons.at(i).weaponDisplay();
			totalPower += weapons.at(i).getPower();
		}
		cout << "Total firepower: " << totalPower << endl;
	}
}