#pragma once
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;
namespace IsValidSudoku
{
	class Solution {
	public:
		bool isSetCorrect(vector<char>& CharacterSet)
		{
			int HashArray[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
			for (int i = 0; i < CharacterSet.size(); ++i)
			{
				if(CharacterSet[i]=='.')
					continue;

				if (HashArray[CharacterSet[i] - '0'] != -1)
					return false;
				else
				{
					HashArray[CharacterSet[i] - '0']++;
				}
			}
			return true;
		}
		bool isValidSudoku(vector<vector<char>>& board) {
			bool Result = true;
			for (int i = 0; i < board.size(); ++i)
			{
				vector<char> tmp(board[i].begin(), board[i].end());
				Result &= isSetCorrect(tmp);
			}

			for (int i = 0; i < board.size(); ++i)
			{
				vector<char> tmp;
				for (int j = 0; j < 9; ++j)
				{
					tmp.push_back(board[j][i]);
				}
				Result &= isSetCorrect(tmp);
			}

			for (int i = 0; i < 9; i += 3)
			{
				for (int j = 0; j < 9; j += 3)
				{
					vector<char> tmp;
					for(int m=0;m<3;++m)
						for (int n = 0; n < 3; ++n)
						{
							tmp.push_back(board[i + m][j + n]);
						}
					Result &= isSetCorrect(tmp);
				}
			}


			return Result;
		}
	};
}

void TestSudoku()
{
	vector<vector<char>> Values;
	Values.push_back({ '8', '3', '.', '.', '7', '.', '.', '.', '.' });
	Values.push_back({ '6', '.', '.', '1', '9', '5', '.', '.', '.' });
	Values.push_back({ '.', '9', '8', '.', '.', '.', '.', '6', '.' });
	Values.push_back({ '8', '.', '.', '.', '6', '.', '.', '.', '3' });
	Values.push_back({ '4', '.', '.', '8', '.', '3', '.', '.', '1' });
	Values.push_back({ '7', '.', '.', '.', '2', '.', '.', '.', '6' });
	Values.push_back({ '.', '6', '.', '.', '.', '.', '2', '8', '.' });
	Values.push_back({ '.', '.', '.', '4', '1', '9', '.', '.', '5' });
	Values.push_back({ '.', '.', '.', '.', '8', '.', '.', '7', '9' });
	IsValidSudoku::Solution TestSolution;
	bool Result = TestSolution.isValidSudoku(Values);
	cout << Result << endl;
}

