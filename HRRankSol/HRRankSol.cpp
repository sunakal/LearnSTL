#include "pch.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main() {
	
	vector<string>fList;
	map <string, int>vote_CountMap;
	string cName;
	int max = 0;
	int maxCount = 1;
	int count;
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cin >> cName;
		if (vote_CountMap.find(cName) == vote_CountMap.end())
			vote_CountMap.insert(make_pair(cName,1));
		else
			vote_CountMap[cName]++;
		
	}
	for (auto elem : vote_CountMap)
	{
		if (elem.second > (count / 2))
		{
			if (!fList.empty())
				fList.clear();
			max = elem.second;
			fList.push_back(elem.first);
			break;
		
		}
		else if (elem.second >= max)
		{
			if (elem.second == max)
			{
				maxCount++;
				fList.push_back(elem.first);
			}
			else
			{
				if(!fList.empty())
					fList.clear();
				max = elem.second;
				maxCount = 1;
				fList.push_back(elem.first);
			}
		}

	}
	if (maxCount > 1)
		sort(fList.begin(), fList.end());
	cout << "Winner is " << fList.front();

	return 0;
}
