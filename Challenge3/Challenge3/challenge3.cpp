#include <iostream>
#include <string>
using namespace std;
/*
int num;
int sum = 1;

int PromptForInteger();

int main()
{
  while(num >= 0)
  {
    PromptForInteger();
    sum += num;
  }
  cout << "Total Sum: " << sum << endl;

    return 0;
}

int PromptForInteger()
{
    cout << "Please enter an integer:" << endl;
    cin >> num;
    return num;
}
*/


string phrase;
string word;

bool ConcatenateNewString(string& phrase)
{
    cout << "Please enter a string:" << endl;
    cin >> phrase;
    if (phrase != ".")
    {
        cout << word << endl;
        word += phrase;
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    while (phrase != ".")
    {
        ConcatenateNewString(phrase);
    } 
    cout << word << endl;;
    return 0;
}