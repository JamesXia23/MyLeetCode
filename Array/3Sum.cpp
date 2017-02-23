#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int> > threeSum(vector<int>& nums) {
		vector<vector<int> > res;
		if (nums.size() < 3) {
			return res;
		}
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; i++) {
			//对第一个数去重
			if (i > 0 && nums[i] == nums[i-1]) {
				continue;
			}
			int left = i + 1;
			int right = nums.size() - 1;
			
			int target = -nums[i];
			while (left < right) {
				int sum = nums[left] + nums[right];
				if (sum > target) {
					right--;
				}else if(sum < target){
					left++;
				}else {
					vector<int> temp;
					temp.push_back(nums[i]);
					temp.push_back(nums[left]);
					temp.push_back(nums[right]);
					res.push_back(temp);
					//对第二三个数去重
					while(left + 1 < right && nums[left] == nums[left+1]){
						left++;
					}
					while (right - 1 > left && nums[right] == nums[right-1]) {
						right--;
					}
					
					//移动
					left++;
					right--;
				}
			}
		}
		return res;
	}
};
int main(int argc, char *argv[]) {
	vector<int> v;
	Solution s;
//	v.push_back(-1);
	v.push_back(0);
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(-1);
//	v.push_back(-4);
	vector<vector<int> > res = s.threeSum(v);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all
unique triplets in the array which gives the sum of zero.
Note: Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c) The solution set
must not contain duplicate triplets.
题目翻译：
给定一个整型数组num，找出这个数组中满足这个条件的所有数字： num[i]+num[j]+num[k] = 0. 并且所有
的答案是要和其他不同的，也就是说两个相同的答案是不被接受的。
题目的两点要求：
1. 每个答案组里面的三个数字是要从小到大排列起来的。
2. 每个答案不可以和其他的答案相同。
题目分析：
1. 每一个答案数组triplet中的元素是要求升序排列的。
2. 不能包含重复的答案数组。
解题思路：
1. 根据第一点要求： 因为要求每个答案数组中的元素是升序排列的，所以在开头我们要对数组进行排序。
2. 根据第二点要求： 因为不能包含重复的答案数组，所以我们要在代码里面做一切去掉重复的操作，对于数组，这样的操作是相同的。
时间复杂度分析：
对于这道题，因为是要找三个元素，所以怎样都要O(n2)的时间复杂度.
归根结底，其实这是two pointers的想法，定位其中两个指针，根据和的大小来移动另外一个。解题中所要注意的就是一些细节问题.

我的思路:首先还是要对数组进行排序,从小到大排序,遍历数组,因为三个数相加为0,则取得第i数n后,另外两个数的和为-n,定义两个指针,一个指向i+1,一个指向数组末尾,如果两个数相加大于-n,这说明太大了右指针需要前移,如果小于-n,则说明太小了,左指针需要右移,等于则存入
*/