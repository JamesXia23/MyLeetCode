#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		stack<int> unfindNums;
		vector<int> res;
		unordered_map<int, int> numsMap;
		
		//遍历数组,找寻每一个数的最近大数
		for (int i = 0; i < nums.size(); i++) {
			while (!unfindNums.empty() && nums[i] > unfindNums.top()) {
				numsMap[unfindNums.top()] = nums[i];
				unfindNums.pop();
			}
			unfindNums.push(nums[i]);
		}
		//栈中剩下的数都是没有最近大数的
		while (!unfindNums.empty()) {
			numsMap[unfindNums.top()] = -1;
			unfindNums.pop();
		}
		
		for (int i = 0; i < findNums.size(); i++) {
			res.push_back(numsMap[findNums[i]]);
		}
		return res;
	}
};
int main(int argc, char *argv[]) {
	
}

/*
You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
	For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
	For number 1 in the first array, the next greater number for it in the second array is 3.
	For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
	For number 2 in the first array, the next greater number for it in the second array is 3.
	For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
Note:
All elements in nums1 and nums2 are unique.
The length of both nums1 and nums2 would not exceed 1000.

题意:给定一个数组nums,以及他的子集findNums,找出子集中每一个元素在原数组nums中从左往右数第一个比它大元素是什么
思路:维护一个栈,用来保存那些还没有找到右边第一个比他大的元素的集合,遍历原数组,一开始栈为空,将第0个元素压入栈,之后的数有两种情况:
	1.栈不空,且当前元素大于栈顶,则代表栈顶的元素找到了右边第一个比他大的数,弹出栈顶,建立[栈顶,当前元素]键值对,继续判断1,直到有一项不满足,执行2
	2.栈空或者当前元素小于等于栈顶,直接入栈
	直到所有元素遍历完成,栈中剩下的数即为没有下一个数比他大的数,建立[栈顶,-1]键值对,依次出栈
	最后遍历子集数组,依次在表中找到对应项即可
	
	注意一个细节:栈中元素肯定是递增的,不然,如果栈中某个数大于他下面的数,那这个数就是他下面的数的最近大数了,则下面那个数就不会出现在栈中了
*/