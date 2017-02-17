/*
Follow up for "Remove Duplicates": What if duplicates are allowed at most twice?
For example, Given sorted array A = [1,1,1,2,2,3],
Your function should return length = 5, and A is now [1,1,2,2,3]
紧接着上一题，同样是移除重复的元素，但是可以允许最多两次重复元素存在。
仍然是第一题的思路，但是我们需要用一个计数器来记录重复的次数，如果重复次数大于等于2，我们会按照第一题的方式处理，如果不是重复元素了，我们将计数器清零。

我的思路:与上题类似,只是需要加个计数器,计数器超过2个的元素不放入a[j](最终数组)
*/

#include <iostream>

using namespace std;
class Solution{
public:
	int removeDuplicates(int a[], int n) {
		if(n == 0){
			return 0;
		}
		int i, j;
		int count = 0;//用来记录重复次数
		for(i = 1, j = 0; i < n; i++){
			cout << "j = " << j << " i = " << i;
			if(a[i] == a[j]){
				count++;
				if (count < 2) {//不超过2个的重复放入a[j]
					a[++j] = a[i];
				}
			}else {
				a[++j] = a[i];//不重复的放入a[j]
				count = 0;
			}
		}
		return j + 1;
	}
};
int main(int argc, char *argv[]) {
	int a[14] = {1, 1, 2, 2, 3, 4, 4, 4, 4, 5, 5, 6, 6, 6};
	Solution s;
	int n = s.removeDuplicates(a, 14);
	cout << n << endl;
	
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}