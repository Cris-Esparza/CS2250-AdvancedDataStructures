#include "Weapon.h"
bool fired;

//accessor
int Weapon::getAmmo()
{
	return ammo;
}

//mutator
void Weapon::setAmmo(int newAmmo)
{
	ammo = newAmmo;
}

//facilitator
bool Weapon::Fire()
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
