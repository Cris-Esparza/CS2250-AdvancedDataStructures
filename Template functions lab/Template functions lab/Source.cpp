#include <iostream>
using namespace std;

template <class T>
T minValue(T a, T b)
{
    if (a < b)
        return a;
    else
        return b;
}

int main() {
    int c = 25;
    int d = 14;

    cout << minValue(c, d) << endl;

    string a = "Hello";
    string b = "Apple";

    cout << minValue(a, b) << endl;
}