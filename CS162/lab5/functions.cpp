#include "functions.hpp"

void reverse(string str)
{
	if (str.length() == 1)
	{
		cout << str;
        cout << '\n';
	}
	else
	{
		cout << str.at(str.length() - 1);
		reverse(str.substr(0,(str.length()-1)));
	}
}

int sumArray(int array[], int elements)
{
    if (elements == 1)
    {
        return array[elements - 1];
    }
}
