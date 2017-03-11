#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int getMinLen(vector<int> &nums) {
		if (nums.size() <= 1) {
			return 0;
		}
		int max = nums[0], right = -1;
		int min = nums[nums.size()-1], left = -1;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] >= max) {
				max = nums[i];
			}else {
				right = i;
			}
		}
		for (int i = nums.size()-1; i >= 0; i--) {
			if (nums[i] <= min) {
				min = nums[i];
			}else {
				left = i;
			}
		}
		cout << left << endl;
		cout << right << endl;
		return right - left + 1;
	}
};
int main(int argc, char *argv[]) {
	vector<int> nums;
	Solution s;
	
	nums.push_back(1);
	nums.push_back(5);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(2);
	nums.push_back(7);
	
	cout << s.getMinLen(nums) << endl;
}

/*
求需要排序的最短子数组的长度
例如:
	[1,5,4,3,2,6,7]
	需要排序子数组为[5,4,3,2]
	所以长度为4
	
思路:
	先从左到右遍历数组,遍历过程中,记录数组最大值,并且记录遍历过程中,当前位置的值小于最大值的情况,此时我们只关心最右发生这种情况的下标,则排序后最大值应该在当前位置或者之后,将下标作为右界
	再从右往左遍历数组,遍历过程中,记录数组最小值,并且记录遍历过程中,当期位置的值大于最大值的情况,此时我们之关心最左发生这种情况的下标,则排序后最小值应该在当前位置或者之前,将下标作为左界
	
*/