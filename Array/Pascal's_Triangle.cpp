/*
Given numRows, generate the first numRows of Pascal's triangle.
For example, given numRows = 5, Return
[
[1],
[1,1],
[1,2,1],
[1,3,3,1],
[1,4,6,4,1]
]
要得到一个帕斯卡三角，我们只需要找到规律即可。
第k层有k个元素
每层第一个以及最后一个元素值为1
对于第k（k > 2）层第n（n > 1 && n < k）个元素A[k][n]，A[k][n] = A[k-1][n-1] + A[k-1][n]
知道了上面的规律，就很好做了，我们使用一个二维数组来存储整个三角，代码如下：
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int> > vals;
		vals.resize(numRows);
		int i, j;
		
		for(i = 0; i < numRows; i++){
			vals[i].push_back(1);	//首位1
			for(j = 1; j <= i - 1; j++){
				vals[i].push_back(vals[i-1][j-1] + vals[i-1][j]);
			}
			if(i != 0)//第二行开始
				vals[i].push_back(1);//末位1
		}
		return vals;
	}
};
int main(int argc, char *argv[]) {
	Solution s;
	vector<vector<int> > v = s.generate(6);
	
	for(int i = 0; i < v.size(); i++){
		for (int j = 0; j <= i; j++){
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}