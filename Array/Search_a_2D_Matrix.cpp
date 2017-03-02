#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	bool searchMatrix(vector<vector<int> >& matrix, int target) {
		if (!matrix.size() || !matrix[0].size()) {
			return false;
		}
		int col = matrix[0].size() - 1;
		int row = 0;
		while (row < matrix.size() && col >= 0) {
			if (matrix[row][col] == target) {
				return true;
			}else if (matrix[row][col] < target) {
				row++;
			}else {
				col--;
			}
		}
		return false;
	}
};
int main(int argc, char *argv[]) {
	
}
/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

	Integers in each row are sorted from left to right.
	The first integer of each row is greater than the last integer of the previous row.
	For example,

	Consider the following matrix:

	[
		[1,   3,  5,  7],
		[10, 11, 16, 20],
		[23, 30, 34, 50]
	]
	Given target = 3, return true.

题意:从一个排好序的二维数组中寻找一个数,找到了就返回true,否则返回false,二维数组每一行有序,每一列有序,即最小值为左上角,最大值为右下角
分析:从右上角开始找:	如果数组中的数和target一致,则返回,
					如果数组中的数大于target,则说明当前列所有值都不满足,往左移动比较,
					如果数组中的数小于target,则说明当前行所有的值不满足,往下移动比较,
					直到找到返回true,或者没有可以搜索的范围,返回false
*/