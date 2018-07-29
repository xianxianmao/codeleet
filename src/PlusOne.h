#pragma once
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;
namespace PlusOne
{
	class Solution {
	public:
		vector<int> plusOne(vector<int>& digits) {
			int n = digits.size();
			vector<int> Result;
			bool bInc = true;
			for (int i = n - 1; i >= 0; --i)
			{
				if (bInc)
				{
					int Num = digits[i] + 1;
					if (Num >= 10)
					{
						Num = Num % 10;
						bInc = true;
					}
					else
					{
						bInc = false;
					}
					Result.push_back(Num);
				}
				else
				{
					Result.push_back(digits[i]);
					bInc = false;
				}
			}
			if (bInc)
			{
				Result.push_back(1);
			}
			reverse(Result.begin(), Result.end());
			return Result;
		}
	};
}

void TestPlusOne()
{
	vector<int> Values = { 0 };
	PlusOne::Solution TestSolution;
	vector<int> Result = TestSolution.plusOne(Values);
	for (int i = 0; i < Result.size(); ++i)
	{
		cout << Result[i] << "    ";
	}
}

