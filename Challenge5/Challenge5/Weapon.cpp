#include "Weapon.h"

Weapon::Weapon(string defaultWeapon, int startingAmmo)
{
	cout << "Created Weapon " << defaultWeapon << " with ammo " << startingAmmo << endl;
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