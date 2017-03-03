#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		int i;
		//前k个数建立大小为k的小根堆
		//第i元素的父亲是(i-1)/2
		//第i元素的左孩子是i*2+1,右孩子是i*2+2
		//左孩子为奇数,右孩子为偶数,虽然没什么关系
		//从最后一个叶子的父亲开始从后往前遍历,调整
		for(i = ((k-1)-1)/2; i >= 0; i--){
			adjustArray(nums, i, k);
		}
		//遍历,如果数组元素大于堆顶元素,更新小根堆
		for(i = k; i < nums.size(); i++){
			if(nums[i] > nums[0]){//调整
				nums[0] = nums[i];
				adjustArray(nums, 0, k);
			}
		}
		return nums[0];
	}
	void adjustArray(vector<int>& nums, int parent, int k){
		int min = parent;
		int child = parent * 2 + 1;
		while(child < k){//不断向下调整
			if (nums[child] < nums[min]) {
				min = child;
			}
			if (child+1 < k && nums[child+1] < nums[min]) {
				min = child+1;
			}
			if (min == parent) {
				break;
			}
			int temp = nums[min];
			nums[min] = nums[parent];
			nums[parent] = temp;
			
			parent = min;
			child = parent * 2 + 1;
		}
	}
};
int main(int argc, char *argv[]) {
	vector<int> v;
	int k = 4;
	Solution s;
	
	v.push_back(5);
	v.push_back(2);
	v.push_back(4);
	v.push_back(1);
	v.push_back(3);
	v.push_back(6);
	v.push_back(0);
	int res = s.findKthLargest(v, k);
	for(int i = 0; i < k; i++){
		cout << v[i] << " ";
	}
	cout << endl << res << endl;
	
	return 0;
}
/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.

思路:使用前k个数做一个小根堆,然后遍历数组,数组中的元素与堆顶比较,比堆顶小的忽略,比堆顶大的,弹出堆顶,加入堆调整,直到数组遍历完成后,堆顶元素就是第k大的元素
*/

