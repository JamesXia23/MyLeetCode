#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int maximumGap(vector<int>& nums) {
		if (nums.size() < 2) {
			return 0;
		}
		if (nums.size() == 2) {
			return abs(nums[0] - nums[1]);
		}
		int maxNum = nums[0], minNum = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] > maxNum) {
				maxNum = nums[i];
			}
			if (nums[i] < minNum) {
			    minNum = nums[i];
			}
		}
		if(maxNum == minNum)
		    return 0;
		double myGap = (maxNum-minNum)*1.0/nums.size();
		vector<vector<int> > tong(nums.size()+1);
		for (int i = 0; i < nums.size(); i++) {		
			
			if (nums[i] == maxNum) {
				tong[nums.size()].push_back(maxNum);
			}else {//每个桶只需要留最大和最小即可
				int myIndex = (nums[i] - minNum) / myGap;
				if(tong[myIndex].empty()){
					tong[myIndex].push_back(nums[i]);
					tong[myIndex].push_back(nums[i]);
					
				}else {
					tong[myIndex][0] = min(nums[i], tong[myIndex][0]);
					tong[myIndex][1] = max(nums[i], tong[myIndex][1]);
				}
			}
		}
//		for (int i = 0; i < tong.size(); i++) {
//			cout << "桶" << i << ": ";
//			for (int j = 0; j < tong[i].size(); j++) {
//				cout << tong[i][j] << " ";
//			}
//			cout << endl;
//		}
		int leftNum = -1, maxDiff = -1;
		for (int i = 0; i < nums.size()+1; i++) {
			if (!tong[i].size() && leftNum == -1) {
				leftNum = tong[i-1][1];//取桶最大值
			}else if(leftNum != -1 && tong[i].size()){
				maxDiff = max(tong[i][0] - leftNum, maxDiff);//取二者间大值作为新的最长距离
				leftNum = -1;
			}
		}
		
		return maxDiff;
	}
};
int main(int argc, char *argv[]) {
	vector<int> nums;
	Solution s;
	
//	nums.push_back(7);
//	nums.push_back(9);
//	nums.push_back(3);
//	nums.push_back(4);
//	nums.push_back(2);
//	nums.push_back(1);
//	nums.push_back(8);
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(100);
//	nums.push_back(1);
	cout << s.maximumGap(nums) << endl;
}
/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

题意:给定一个未排序数组,在O(N)时间,O(N)空间找出数组中相差最大的两个数的差
思路:来自桶排序的思想,首先,找出数组最大小值max,min,然后分出N+1个桶,每个桶代表一个区间,分别是:
	[min,(max-min)/N),[(max-min)/N,2(max-min)/N),...,[(N-1)(max-min)/N,N),[N]最大值自己在一个桶中
	因为N+1个桶,N个数,所以至少有一个空桶,比较空桶两端的数,即可知道最大距离.
*/