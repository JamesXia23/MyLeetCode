#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> res;
		if (nums.empty()) {
			return res;
		}
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			int index = (nums[i] - 1) % n;//模n是因为该数有可能已经被前面的数加过n了
			nums[index] += n;
		}
		for (int i = 0; i < n; i++) {
			if (nums[i] <= n) {
				res.push_back(i+1);
			}
		}
		return res;
	}
};
int main(int argc, char *argv[]) {
	vector<int> nums;
	Solution s;
	nums.push_back(4);
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(8);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);
	
	vector<int> res = s.findDisappearedNumbers(nums);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
}

/*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]

题意:给定一个n个数的数组,数组中的元素为1-n,但是有些数字出现了两次,有些出现一次,在o(n)时间,o(1)空间内找出缺少的数字

思路:
	将所有出现过的数字对应下标的元素加n,然后再次遍历一遍数组,找出小于等于n的数即可
	类似,遍历数组时,将出现过的元素对应下标的数置为负数,再次遍历数组,找出正数即可
*/