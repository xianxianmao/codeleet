#pragma once
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
namespace InverseString
{
	class Solution {
	public:
		string reverseString(string s) {
			int i = 0;
			int j = s.length()-1;
			while (i < j)
			{
				swap(s[i++], s[j--]);
			}
		return s;
		}
	};
}

void TestInverseString()
{
	string str = "helloworld";
	
	InverseString::Solution TestSolution;
	cout << TestSolution.reverseString(str) << endl;
}


