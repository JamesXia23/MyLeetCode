/*
Given an index k, return the kth row of the Pascal's triangle.
For example, given k = 3, Return [1,3,3,1].
不同于上一题，这里我们仅仅需要得到的第k层的集合，但只能使用O(k)的空间。所以不能用前面二维数组的方式，只能使用一位数组滚动计算。
在第一题里面，我们知道，帕斯卡三角的计算公式是这样的，A[k][n] = A[k-1][n-1] + A[k-1][n]。
假设现在数组存放的第3层的数据，[1, 3, 3, 1]，如果我们需要计算第4层的数据，如果我们从前往后计算，
譬如A[4][2]= A[3][1] + A[3][2]，也就是4，但是因为只有一个数组，所以需要将4这个值覆盖到2这个位置，
那么我们计算A[4][3]的时候就会出现问题了，因为这时候A[3][2]不是3，而是4了。
为了解决这个问题，我们只能从后往前计算，仍然是上面那个例子，我们实现计算A[4][3] = A[3][2] + A[3]
[3]，也就是6，我们将6直接覆盖到3这个位置，但不会影响我们计算A[4][2]，因为A[4][2] = A[3][1] + A[3]
[2]，已经不会涉及到3这个位置了。
理解了如何计算，代码就很简单了：
我的思路:递推公式a[i][0] = 1,a[i][n-1]=1,a[i][j]=a[i-1][j-1]+a[i-1][j],即需要计算的只与上一行的同列以及前一列有关,与上一行之后的列无关,因此可以从后往前计算
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> vals;
		int i, j;
		vals.resize(rowIndex + 1, 1);
		for(i = 0; i < rowIndex; i++){
			for(j = i; j >= 1; j--){
				vals[j] = vals[j] + vals[j - 1];
			}
		}
		return vals;
	}
};
int main(int argc, char *argv[]) {
	Solution s;
	vector<int> vals = s.getRow(7);
	
	for(int i = 0; i < vals.size(); i++)
		cout << vals[i] << " ";
		
	cout << endl;
	
	return 0;
}