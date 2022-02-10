#include "Weapon.h"

Weapon::Weapon(string startingWeapon, int startingAmmo)
{
	weaponName = startingWeapon;
	ammo = startingAmmo;
}

bool Weapon :: Fire()
{
	if (ammo >= 1)
	{
		cout << "FIRE" << endl;
		ammo = ammo - 1;
		return true;
	}
	else
	{
		cout << "CLICK" << endl;
		return false;
	}
}