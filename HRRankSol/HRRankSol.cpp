// HRRankSol.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <deque>

using namespace std;
string getshiftedString(string str, int lShift, int rShift);
int main()
{
	string repStr = "abcde";
	string outStr = getshiftedString(repStr, 2, 1);
	cout << outStr<<endl;
    std::cout << "Hello World!\n"; 
	return 0;
}

string getshiftedString(string str, int lShift, int rShift)
{

	if (lShift > 0)
	{
		char front = str.front();
		for (int i = 0; i<str.length(); i++)
		{
			str[i] = str[i +1];
		}
		str[str.length()-1] = front;
		lShift--;
		cout << "lshift  : : " << str<<endl;
		str = getshiftedString(str, lShift, rShift);
	}

	else if (rShift > 0)
		{
			char last = str.back();
			for (int i = str.length()-1; i > 0; i--)
			{
				str[i] = str[i - 1];
			}
			str[0] = last;
			rShift--;
			cout << "rshift  ::  " << str<<endl;
			str = getshiftedString(str, lShift, rShift);
	}
	return str;
	// TODO: insert return statement here
}
