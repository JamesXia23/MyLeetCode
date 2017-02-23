#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		if (nums.size() < 3) {
			return 0;
		}
		sort(nums.begin(), nums.end());
		int i, min = INT_MAX, sum = 0;
		for (i = 0; i < nums.size() - 2; i++) {
			int left = i + 1;
			int right = nums.size() - 1;
			while (left < right) {
				int tmpSum = nums[i] + nums[left] + nums[right];
				if (tmpSum > target) {
					if (tmpSum - target < min) {
					 	sum = tmpSum;
						min = tmpSum - target;
					}
					right--;
				}else if(tmpSum < target){
					if (target - tmpSum < min) {
						sum = tmpSum;
						min = target - tmpSum;
					}
					left++;
				}else {
					return sum;
				}
			}
		}
		return sum;
	}
};
int main(int argc, char *argv[]) {
	vector<int> v;
	Solution s;
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(0);
	
	int res = s.threeSumClosest(v, 100);
	cout << res << endl;
	
	return 0;
}
/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/