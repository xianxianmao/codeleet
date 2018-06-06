/*
����һ�����������һ��Ŀ��ֵ���ҳ������к�ΪĿ��ֵ����������

����Լ���ÿ������ֻ��Ӧһ�ִ𰸣���ͬ����Ԫ�ز��ܱ��ظ����á�

ʾ��:

���� nums = [2, 7, 11, 15], target = 9

��Ϊ nums[0] + nums[1] = 2 + 7 = 9
���Է��� [0, 1]
*/
#pragma once
#include <vector>
#include <unordered_map>
#include <iostream>

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

    // ע�⣺[3,3] , 6 
	class Solution1
	{
	public:
		vector<int> twoSum(vector<int>& nums, int target)
		{
			unordered_multimap<int, int> MapValueToIndex; // ��ֹ�ظ�����
			for (vector<int>::size_type i = 0; i < nums.size(); ++i)
			{
				MapValueToIndex.insert(std::make_pair(nums[i], i));
			}
			for (int i = 0; i < nums.size(); ++i)
			{
				int first = nums[i];
				int second = target - first;
				auto FindResultRange = MapValueToIndex.equal_range(second);
				for (auto FindResult = FindResultRange.first; FindResult != FindResultRange.second; ++FindResult)
				{
					if (FindResult->second != i)
					{
						return{ i, FindResult->second };
					}
				}
			}
			return{};
		}
	};

	static const auto io_speed_up = []()
	{
		std::ios::sync_with_stdio(false);
		cin.tie(nullptr);
		return 0;
	}();

	class Solution2
	{
	public:
		vector<int> twoSum(vector<int>& nums, int target)
		{
			unordered_map<int, int> MapValueToIndex; // ��ֹ�ظ�����
			for (int i = 0; i < nums.size(); ++i)
			{
				const int first = nums[i];
				const int second = target - nums[i];
				auto FindResult = MapValueToIndex.find(second);
				if (FindResult != MapValueToIndex.end())
				{
					return{ i,FindResult->second };
				}
				else
				{
					MapValueToIndex[nums[i]] = i;
				}
			}
			return{};
		}
	};

}

void Test1TwoSum()
{

}