#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		int sum = nums.size() * (nums.size()+1) / 2;//n个数的和
		for (int i = 0; i < nums.size(); i++) {
			sum -= nums[i];
		}
		return sum;
	}
};
class Solution1 {
public:
	int missingNumber(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		int res = nums.size();
		for (int i = 0; i < nums.size(); i++) {
			res ^= nums[i];
			res ^= i;
		}
		return res;
	} 
};
int main(int argc, char *argv[]) {
	vector<int> nums;
	Solution1 s;
	
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);
	cout << s.missingNumber(nums);
	return 0;
}

/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

题意:给出一个数组,数组中含n个不相同的数,0<=a[i]<=n,找出其中确少的那个数
解法1:使用等差数列求出0+1+...+n的值,在逐个减去数组的值,结果就是缺少的数
解法2:使用亦或的原理,数组中所有数亦或一次,然后再与下标亦或一次,剩下的值就是解
*/