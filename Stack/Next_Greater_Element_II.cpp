#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
//class Solution {
//public:
//	vector<int> nextGreaterElements(vector<int>& nums) {
//		stack<pair<int, int> > unfindNums;
//		vector<int> res(nums.size(), -1);
//		
//		int len = nums.size();
//		//完成数组扩容
//		for (int i = 0; i < len; i++) {
//			nums.push_back(nums[i]);
//		}
//		for (int i = 0; i < nums.size(); i++) {
//			while (!unfindNums.empty() && nums[i] > unfindNums.top().second) {
//				res[unfindNums.top().first] = nums[i];
//				unfindNums.pop();
//			}
//			if (i < len) {
//				unfindNums.push(pair<int, int>(i, nums[i]));
//			}
//		}
//		return res;
//	}
//};
class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		stack<int> unfindNums;	//下标栈
		vector<int> res(nums.size(), -1);
		
		int len = nums.size();

		for (int i = 0; i < len*2; i++) {
			int num = nums[i%len];	//得到数组中的值
			while (!unfindNums.empty() && num > nums[unfindNums.top()]) {
				res[unfindNums.top()] = num;
				unfindNums.pop();
			}
			if (i < len) {
				unfindNums.push(i);
			}
		}
		return res;
	}
};
int main(int argc, char *argv[]) {
	
}
/*
Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

Example 1:
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number; 
The second 1's next greater number needs to search circularly, which is also 2.
题意:数组是一个循环数组,也就是说最后一个数的下一个数的第0个数,则数组中除了最大值,其余都可以找到右边第一个比他大的数(最近大数)
我的思路:将数组扩容为两倍,按照第一题的思路处理前n个数,然后遍历后n个数的时候,不再将他们入栈,其余处理相同
注意:本题没有子集数组,而是直接输入每个数的最近大数
	栈中要插入的是一种新的数据结构pair(键值对)[元素在原数组中的下标,数组值],因为本题中元素可重复,所以不能再使用map
	
最优思路:与我的思路类似,不过数组不必真正扩容,遍历到下标>=n的数时,直接对下标模n就得到了原数组中的值,不必真正扩容,然后栈中直接存下标,再通过下标去原数组中找值即可
*/