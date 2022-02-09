#include "Weapon.h"

Weapon::Weapon(string startingWeapon, int startingAmmo)
{
	weaponName = startingWeapon;
	ammo = startingAmmo;
	cout << "Created Weapon " << weaponName << " with ammo " << ammo << endl;
}


bool Weapon :: Fire()
{
	if (ammo >= 1)
	{
		cout << "FIRE" << endl;
		ammo = ammo - 1;
		cout << "TRUE" << endl;
		return true;
	}
	else
	{
		cout << "CLICK" << endl;
		cout << "FALSE" << endl;
		return false;
	}
}