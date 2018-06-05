/*
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。

你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/
#pragma once
#include <vector>
#include <unordered_map>
using namespace std;
namespace TwoSum
{
	class Solution0 /*Brute Force*/ {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			for (int i = 0; i < nums.size(); ++i)
			{
				for (int j = i + 1; j < nums.size(); ++j)
				{
					if (nums[i] + nums[j] == target)
					{
						return{ i,j };
					}
				}
			}
		}
	};

	class Solution1
	{
	public:
		vector<int> twoSum(vector<int>& nums, int target) 
		{
			unordered_multimap<int,int> MapValueToIndex; // 防止重复数字
			for (vector<int>::size_type i = 0; i < nums.size(); ++i)
			{
				MapValueToIndex.insert(std::make_pair(nums[i], i));
			}
			for (int i = 0; i < nums.size(); ++i)
			{
				int first = nums[i];
				int second = target - first;
				auto FindResult = MapValueToIndex.find(second);
				if (FindResult != MapValueToIndex.end() && FindResult->first!= first)
				{
					return{ i, FindResult->second };
				}
			}
			return{};
		}
	}
}

void TestTwoSum()
{

}