#pragma once
#include <iostream>
using namespace std;

#ifndef WEAPON_H
#define WEAPON_H

class Weapon
{
public:
	Weapon(string startingWeapon = "PISTOL", int startingAmmo = 0);
	bool Fire();

private:
	string weaponName;
	int ammo;

};

#endif
