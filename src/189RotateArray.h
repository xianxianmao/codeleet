#pragma once
#pragma once
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;
namespace RotateArray
{
	class Solution {
	public:
		void rotate(vector<int>& nums, int k) 
		{
			if (nums.size() == 0)
				return;
			if (k % nums.size() == 0)
				return;

			k = k % nums.size();
			reverse(nums.begin(), nums.begin() + nums.size() - k);
			reverse(nums.begin() + nums.size() - k, nums.end());
			reverse(nums.begin(), nums.end());
		}
	};
}

void TestRotateArray()
{
	vector<int> Values = { 0,1,2,3,4,5};
	RotateArray::Solution TestSolution;
    TestSolution.rotate(Values,2);
	for (int i = 0; i < Values.size(); ++i)
	{
		cout << Values[i] << "    ";
	}
}
