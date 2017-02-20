#include <iostream>

using namespace std;
class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		for(int i = n + m - 1; i >= 0; i--){
			if (m - 1 < 0) {//A数组移动完成,剩下将B数组移动即可
				while (n - 1 >= 0) {
					A[i--] = B[--n];
				}
			}else if(n - 1 < 0){//因为A数组中本来就是有序的,既然B数组完成了,A数组就不用再动了
				break;
			}else {
				 A[i] = A[m - 1] > B[n - 1] ? A[--m] : B[--n];
			}
			//上面else是比较高级的写法
//			else if (A[m - 1] > B[n - 1]) {
//				A[i] = A[m - 1];
//				m--;
//			} else {
//				A[i] = B[n - 1];
//				n--;
//			}
		}
	}
};
int main(int argc, char *argv[]) {
	Solution s;
//	int A[10] = {1, 3, 4, 5, 7};
//	int B[5] = {2, 4, 6, 8, 9};
//	s.merge(A, 5, B, 5);
	int A[1];
	int B[1] = {1};
	s.merge(A, 0, B, 1);
	for (int i = 0; i < 1; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}

/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.
Note: You may assume that A has enough space (size that is greater or equal to m + n) to hold
additional elements from B. The number of elements initialized in A and B are m and n respectively.
A和B都已经是排好序的数组，我们只需要从后往前比较就可以了。
因为A有足够的空间容纳A + B，我们使用游标i指向m + n - 1，也就是最大数值存放的地方，从后往前遍历
A，B，谁大就放到i这里，同时递减i。
*/