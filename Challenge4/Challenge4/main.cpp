#include "Weapon.h"

using namespace std;

int main()
{
	int newClip;
	bool fired = false;
	
	// Create a single weapon
	Weapon weapon;

	/*cout << weapon.getAmmo() << endl;
	weapon.setAmmo(6);
	cout << "there are " << weapon.getAmmo() << " bullets in the clip" << endl;
	weapon.Fire();
	cout << "there are " << weapon.getAmmo() << " bullets in the clip" << endl;*/

	// Add 2 bullets to the clip using setAmmo
	// TODO
	weapon.setAmmo(2);

	// Print the number of bullets in the clip, "There are <ammo> bullets in the clip"
	// TODO
	cout << "There are " << weapon.getAmmo() << " bullets in the clip" << endl;

	// Ask the user for how many bullets they want to have in the clip, "How many bullets do you want in the clip?"
	// TODO
	cout << "How many bullets do you want in the clip?" << endl;

	// Read in a number from the user
	// TODO
	cin >> newClip;

	// Put that number of bullets in the clip using setAmmo
	// TODO
	weapon.setAmmo(newClip);

	// Print the number of bullets in the clip, "There are <ammo> bullets in the clip"
	// TODO
	cout << "There are " << weapon.getAmmo() << " bullets in the clip" << endl;

	// Using a loop, fire the weapon until the gun is empty.
	// Print the returned value from the fire method call as either "TRUE" or "FALSE"
	// TODO
	while (weapon.getAmmo() > 0)
	{
		weapon.Fire();
	}

	// Fire the empty gun
	// Print the returned value from the fire method call as either "TRUE" or "FALSE"
	// TODO
	if (weapon.getAmmo() == 0)
	{
		weapon.Fire();
	}
	

	return 0;
}