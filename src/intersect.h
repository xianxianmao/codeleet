#pragma once
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;
namespace Intersect
{
	class Solution {
	public:
		vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
		{
			sort(nums1.begin(), nums1.end());
			sort(nums2.begin(), nums2.end());
			int j = 0;
			vector<int> Result;
			for (int i = 0; i < nums1.size();)
			{
				if (j >= nums2.size())
					break;

				if (nums1[i] < nums2[j])
				{
					i++;
				}
				else if(nums1[i]> nums2[j])
				{
					j++;
				}
				else
				{
					Result.push_back(nums1[i]);
					j++;
					i++;
				}
			}
			return  Result;
		}
	};
}

void TestIntersectArray()
{
	vector<int> Values = { 1,2,3,4};
	vector<int> Values2 = {  };
	Intersect::Solution TestSolution;
	vector<int> Result = TestSolution.intersect(Values, Values2);
	for (int i = 0; i < Result.size(); ++i)
	{
		cout << Result[i] << "    ";
	}
}

