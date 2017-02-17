/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
For example, Given input array A = [1,1,2],
Your function should return length = 2, and A is now [1,2].

这道题目与前一题Remove Element比较类似。但是在一个排序好的数组里面删除重复的元素。
首先我们需要知道，对于一个排好序的数组来说， A[N + 1] >= A[N] ，我们仍然使用两个游标i和j来处理，假设现在i = j + 1，如果A[i] == A[j]，那么我们递增i，直到A[i] != A[j]，这时候我们再设置A[j + 1] = A[i]，同时递增i和j，重复上述过程直到遍历结束

我的思路:两个游标i,j作用,i用来遍历数组,记录扫过的元素,j表示当前位置是当前最终数组的最后一位,j+1表示当前位置可以存放最后数组的下一个元素,第一个元素肯定属于最终数组,所以从第二个元素开始,每次扫描到a[i]不等于a[j](最终数组的最后一个元素)时,就加入最终数组
*/

#include <iostream>

using namespace std;

class Solution{
public:
	int removeDuplication(int a[], int n){
		if(n == 0)
			return 0;
		int i;
		int j;//a[j]最后存储的元素,第一个元素一定是,先存入a[j]
		for(i = 1,j = 0; i < n; i++){
			//遍历a[i],当a[i]与a[j]的最后一个元素不相等时,放入a[j]
			if(a[j] != a[i]){
				a[++j] = a[i];
			}//j永远都是真实数组最后一个元素的下标
			/*
		//如果a[i] = a[j],说明找到了一个重复数,继续加1,直到不再是重复数
			if(a[i] == a[j]){
				continue;
			}
		//当a[i] != a[j]时,有两种情况,一种是a[j]-a[i-1]之间存在重复,一种是a[i] = a[j+1]即i和j一直都在同步移动,没有遇到重复的情况,两种情况处理的方式相同,将j++,然后a[j] = a[i]
			a[++j] = a[i];
			*/
		}
		return j + 1;
	}
};
int main(int argc, char *argv[]) {
	int a[12] = {1, 1, 2, 3, 4, 4, 4, 4, 5, 5, 6, 6};
	Solution s;
	int n = s.removeDuplication(a, 12);
	cout << n << endl;
	
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}