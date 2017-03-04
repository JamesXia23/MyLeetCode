#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	void sortColors(vector<int>& nums) {
		if (nums.size() <= 1) {
			return ;
		}
		int zeroArea = -1, twoArea = nums.size(), index = 0;
		while (index < twoArea) {
			if (nums[index] == 0) {
				swap(nums[++zeroArea], nums[index++]);
				
			}else if (nums[index] == 2) {
				swap(nums[--twoArea], nums[index]);
			}else {
				index++;
			}
		}
	}
};
int main(int argc, char *argv[]) {
	vector<int> nums;
	Solution s;
	
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(2);
	nums.push_back(0);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(0);
	nums.push_back(2);
	nums.push_back(1);
	
	s.sortColors(nums);
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
}

/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

经典荷兰国旗问题,一个数组只有三种数0,1,2组成,将此数组进行排序

思路:	首先在数组前面设定一个区域为0区(长度为0,虚概念),数组后面设定一个区域为2区(同0区)
		遍历数组,当遇到1时,i++继续遍历
		遇到0时,将0与0区的后一个数交换(必定为1,除非这个数就是0区最后一个数),然后0区范围向后移动,i++
		遇到2时,将2与2区的前一个数交换,然后2区向前进一位,i不动(因为换过来的数可能为0),继续遍历
		当遍历到2区,停止
*/