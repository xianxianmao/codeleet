/*
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
*/
#pragma once
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;
namespace MaxProfit
{
	class Solution {
	public:
		int maxProfit(vector<int>& prices) {
			vector<int> BuyValues(prices.size(), 0);
			vector<int> SaleValues(prices.size(), 0);
			if (prices.size() == 0)
				return 0;
			for (int i = 0; i < prices.size(); ++i)
			{
				if (i == 0)
				{
					BuyValues[0] = -prices[0];
					SaleValues[0] = 0;
				}
				else
				{
					int TryBuy = -99999999;
					for (int j = 0; j < i; ++j)
					{
						if (TryBuy < SaleValues[j] - prices[i])
						{
							TryBuy = SaleValues[j] - prices[i];
						}
					}
					BuyValues[i]= TryBuy;

					int TrySale = -99999999;
					for (int j = 0; j < i; ++j)
					{
						if (TrySale < BuyValues[j] + prices[i])
						{
							TrySale = BuyValues[j] + prices[i];
						}
					}
					SaleValues[i] = TrySale;
				}
			}

			int MavBuyValue = *max_element(BuyValues.begin(), BuyValues.end());
			int MaxSaleValue = *max_element(SaleValues.begin(), SaleValues.end());
			int Profit = (max)(MavBuyValue, MaxSaleValue);
			if (Profit < 0)
			{
				return 0;
			}
			else
			{
				return Profit;
			}
		}
	};
}

void TestMaxProfit()
{
	vector<int> Values = { 1,1000,10001 };
	MaxProfit::Solution TestSolution;
	int MaxProfit = TestSolution.maxProfit(Values);
	cout << MaxProfit << endl;
}