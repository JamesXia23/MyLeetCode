#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> kSort(vector<int>& nums, int k) {
		vector<int> res;
		int lastParent = ((k-1)-1) / 2;
		
		//下沉建堆
		for (int i = lastParent; i >= 0; i--) {
			createHeap(nums, i, k);	
		}
		for (int i = k; i < nums.size(); i++) {//将堆顶弹出,剩余的数依次入堆
			res.push_back(nums[0]);
			nums[0] = nums[i];
			createHeap(nums, 0, k);
		}
		for (int i = k-1; i >= 0; i--) {//只剩下堆中的k个数需要排序了
			res.push_back(nums[0]);
			nums[0] = nums[i];
			createHeap(nums, 0, i);
		}
		
		return res;
	}
	void createHeap(vector<int> &nums, int parent, int heapLen){
		if (!heapLen) {
			return ;
		}
		int child = parent * 2 + 1;//左孩子
		while (child < heapLen) {
			if (child + 1 < heapLen && nums[child+1] < nums[child]) {//child变为右孩子
				child++;
			}
			if(nums[(child-1)/2] < nums[child]) {//父结点仍然最小,不必调整了
				return ;
			}
			swap(nums[child], nums[(child-1)/2]);//交换调整
			child = child * 2 + 1;
		}
	}
};
int main(int argc, char *argv[]) {
	vector<int> nums;
	Solution s;
	
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(4);
	nums.push_back(3);
	nums.push_back(6);
	nums.push_back(5);
	nums.push_back(8);
	nums.push_back(7);
	nums.push_back(10);
	nums.push_back(9);
	
	vector<int> res = s.kSort(nums, 2);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
}
/*
已知一个几乎有序的数组,几乎有序的意思是,假如将把数组排好序,每个元素移动的距离不超过k,同时k相对于整个数组来说很小,用什么排序算法最好
思路:
	每个元素移动的距离不超过k,也就是说a[0]-a[k-1]中一定有最小值,那么只要建立一个大小为k的小根堆,堆顶就是最小值,然后堆顶弹出,增加下一个元素,调整可得第二小值,以此类推,直到数组只剩下k-1个元素,则直接在本堆调整即可
*/