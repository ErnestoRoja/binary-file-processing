#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Weapon
{
private:
	string _weaponName;
	unsigned int _weaponPower;
	float _weaponPowerConsumption;

public:
	Weapon(string weaponName, unsigned int weaponPower, float weaponPowerConsumption);
	unsigned int getPower();
	void weaponDisplay();
};

class extrafile
{
private:
	string _name, _class;
	short _length;
	int _shieldCapacity;
	float _warpSpeed;
	unsigned int _weaponCount;

public:
	extrafile(string name, string className, short length, int shieldCapacity, float warpSpeed, unsigned int weaponCount);
	string getName();
	string getClass();
	short getLength();
	unsigned int getShieldCapacity();
	float getWarpSpeed();
	unsigned int getWeaponCount();
	int getTotalPower();
	unsigned int getStrongestWeapon();
	void displayShip();
	vector<Weapon> weapons;
};