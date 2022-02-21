#include <iostream>
#include <string>
using namespace std;

void PrintMenu();
int PromptForInput(int min, int max, string error);
void Encrypt(string& encryption, int shift);
void Decrypt(string& message, int shift);
void Brute();
void DecryptPrompt(string& encryptio, int& shift);
void EncryptPrompt(string& message, int& shift);
void DecryptMessage();
void EncryptMessage();

int main()
{
	cout << "Welcome to the Tali-banned Encrypter!" << endl;
	cout << "Make a selection from the menu and then follow the prompts." << endl;

	int menuOpt;
	int shift;
	string message;
	string encryption;
	
	// Repeart the menu until user selects quit
	do
	{
		PrintMenu();
		menuOpt = PromptForInput(1, 4, "Invalid choice, Please make a menu selection (1-4):");
		switch (menuOpt)
		{
		case 1:
			EncryptPrompt(message, shift);
			EncryptMessage();
			Encrypt(message, shift);
			break;
		case 2:
			DecryptPrompt(encryption, shift);
			DecryptMessage();
			Decrypt(encryption, shift);
			break;
		case 3:
			Brute();
			break;
		} 
	} while (menuOpt != 4);
	//handles quit application input
	cout << "Thank you Caesar!  See ya!" << endl;
	char a;
	cin.ignore();
	cin.get(a);
	return 0;
}

void PrintMenu()
{
	cout << "*************************************" << endl;
	cout << "* 1 - Encrypt a message" << endl;
	cout << "* 2 - Decrypt a message" << endl;
	cout << "* 3 - Brute - force decrypt a message" << endl;
	cout << "* 4 - Quit" << endl;
	cout << "*************************************" << endl;
	cout << "Please make a menu selection (1-4):" << endl;
}

int PromptForInput(int min, int max, string error)
{
	int input;

	//repeatedly ask user for shift value and validate
	do
	{
		// Request shift value from user
		cin >> input;
		cin.ignore();

		// test for valid input
		if (input < min || input > max)
		{
			cout << error << endl;
		}
	} while (input < min || input > max);

	// Return valid shift value
	return input;
}

void Encrypt(string& encryption, int shift)
{
	string message;
	message = encryption;
	for (int i = 0; i < message.size(); ++i)
	{
		if (isalpha(message[i]))		//ignores space and non alphabet
		{
			if ((message[i] + shift) > 'z')		//moves lowercase z to a
			{
				int ch = (message[i] + shift) - 'z';
				encryption[i] = '`' + ch;
			}
			else if (message[i] + shift > 'Z' && message[i] <= '`')		//mover uppercase Z to A
			{
				int ch = (message[i] + shift) - 'Z';
				encryption[i] = '@' + ch;
			}
			else		//handles characters in between A-Z and a-z
			{
				encryption[i] += shift;
			}
		}
	}
	
	cout << encryption << endl;
}

void Decrypt(string& message, int shift)
{
	string encryption;
	encryption = message;
	for (int i = 0; i < encryption.size(); ++i)
	{
		if (isalpha(encryption[i]))		//ignores spaces and non alphabet 
		{
			if (islower(encryption[i]))		//moves  lowercase a to z
			{
				 message[i] = ((encryption[i] - 'a') - shift + 26) % 26 + 'a';
			}
			else if (isupper(message[i]))		//moves uppercase A to Z
			{
				message[i] = ((encryption[i] - 'A') - shift + 26) % 26 + 'A';
			}
			else		//handles characters in between a-z and A-Z
			{
				message[i] = encryption[i] - shift;
			}
		}
	}
	
	cout << message << endl;
}

void Brute()
{
	string encryption;
	int shift = 1;
	cout << "Please enter the message to decrypt:" << endl;
	getline(cin, encryption);
	DecryptMessage();
	while (shift <= 25)
	{
		Decrypt(encryption, 1);
		shift++;
	}
}

void DecryptPrompt(string& encryption, int& shift)
{
	cout << "Please enter the message to decrypt:" << endl;
	getline(cin, encryption);
	cout << "Please enter the shift value (1-25):" << endl;
	shift = PromptForInput(1, 25, "Invalid choice, Please enter the shift value (1-25):");
}

void EncryptPrompt(string& message, int& shift)
{
	cout << "Please enter the message to encrypt:" << endl;
	getline(cin, message);
	cout << "Please enter the shift value (1-25):" << endl;
	shift = PromptForInput(1, 25, "Invalid choice, Please enter the shift value (1-25):");
}

void DecryptMessage()
{
	cout << "Decrypted as:" << endl;
}

void EncryptMessage()
{
	cout << "Encrypted as:" << endl;
}

