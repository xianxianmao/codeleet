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
			unordered_multimap<int,int> MapValueToIndex; // ��ֹ�ظ�����
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