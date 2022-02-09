#include <iostream>
using namespace std;

#ifndef WEAPON_H	//	if weapon_h is not defined
#define WEAPON_H	//	then define weapon_h

class Weapon
{
public:
	//accessor
	int getAmmo();

	//mutator
	void setAmmo(int newAmmo);

	//facilitator
	bool Fire();

private:
	int ammo = 0;
};

#endif 

