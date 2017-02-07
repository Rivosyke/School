#include "functions.hpp"

void reverse(string str)
{
	if (str.length() == 1)
	{
		cout << str;
	}
	else
	{
		cout << "Iteration" << endl;
		cout << str.at(str.length() - 1);
		reverse(str.substr(0,(str.length()-2)));
	}
}
