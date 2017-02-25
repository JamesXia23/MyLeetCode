#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int> > fourSum(vector<int>& nums, int target){
		vector<vector<int> > res;
		if(nums.size() < 4){
			return res;
		}
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 3; i++) {
			if (i > 0 && nums[i] == nums[i-1]) {//控制第一个数不重复
				continue;
			}
			for (int j = i + 1; j < nums.size() - 2; j++) {
				if(j > 1 && nums[j] == nums[j-1]){//控制第二个数不重复
					continue;
				}
				int left = j + 1, right = nums.size() - 1;
				while (left < right) {
					int tmpSum = nums[i] + nums[j] + nums[left] + nums[right];
					if (tmpSum < target) {
						left++;
					}else if (tmpSum > target) {
						right--;
					}else {
						vector<int> tmpRes;
						tmpRes.push_back(nums[i]);
						tmpRes.push_back(nums[j]);
						tmpRes.push_back(nums[left]);
						tmpRes.push_back(nums[right]);
						res.push_back(tmpRes);
						//控制第三个和第四个数不重复
						while (left < right && nums[left] == nums[left+1]) {
							left++;
						}
						while (left < right && nums[right] == nums[right-1]) {
							right--;
						}
						//移动
						left++;
						right++;
					}
				}
			}
		}
		return res;
	}
};
int main(int argc, char *argv[]) {
	vector<int> v;
	int target = 2;
	Solution s;
	
	v.push_back(2);
	v.push_back(1);
	v.push_back(0);
	v.push_back(-1);
//	v.push_back(-2);
//	v.push_back(2);
	
	vector<vector<int> > res = s.fourSum(v, target);
	
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
/*
Given an array S of n integers, are there elements a, b, c and d in S such that a+b+c+d = target?
Find all unique quadruplets in the array which gives the sume of target.
Note:
1. Elements in quadruplets (a, b, c, d) must be in non-descending order. (ie, a<=b<=c<=d)
2. The solution must not contain duplicates quadruplets.
4Sum
题目翻译：
给定一个整型数字数组num和一个目标值target，求出数组中所有的组合满足条件：
num[a]+num[b]+num[c]+num[d] = target.
并且要满足的条件是：
1. num[a] <= num[b] <= num[c] <= num[d]
2. 答案中的组合没有重复的.
题目分析：
这道题和3Sum几乎同出一辙，只不过是要求四个数字的和，在时间复杂度上要比3Sum高一个数量级。对于两点要求的处理：
1. 首先要对整个数组进行排序，这样得到的答案自然是排序好的.
2. 对于重复答案的处理和3Sum是一摸一样的。
For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
	[-1,  0, 0, 1],
	[-2, -1, 1, 2],
	[-2,  0, 0, 2]
]
*/