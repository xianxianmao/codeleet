#pragma once
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
namespace IsPalindrome
{
	class Solution {
	public:
		bool isPalindrome(string s) {
			for (int i = 0; i < s.length(); ++i)
			{
				if ('A' <= s[i] && s[i] <= 'Z')
				{
					s[i] = s[i] - 'A' + 'a';
				}
			}
			int FPos = 0;
			int EndPos = s.length() - 1;
			while (FPos < EndPos)
			{
				if (!(('0' <= s[FPos] && s[FPos] <= '9') ||( 'a' <= s[FPos] && s[FPos] <= 'z' ) ||( 'A' <= s[FPos] && s[FPos] <= 'Z')))
				{
					FPos++;
					continue;
				}
				else if (!(('0' <= s[EndPos] && s[EndPos] <= '9') || ('a' <= s[EndPos] && s[EndPos] <= 'z') || ('A' <= s[EndPos] && s[EndPos] <= 'Z')))
				{
					EndPos--;
					continue;
				}
				else if (s[FPos] == s[EndPos])
				{
					FPos++;
					EndPos--;
					continue;
				}
				else if (s[FPos] != s[EndPos])
				{
					return false;
				}
			}
			return true;
		} 
	};
}

void TestIsPalindromeg()
{
	string str = "race a car";

	IsPalindrome::Solution TestSolution;
	cout << TestSolution.isPalindrome(str) << endl;
}



