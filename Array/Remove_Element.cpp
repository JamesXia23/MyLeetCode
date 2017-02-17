/*Given an array and a value, remove all instances of that value in place and return the new length. The order of elements can be changed. It doesn't matter what you leave beyond the new length.
在一个数组里面移除指定value，并且返回新的数组长度。
这题唯一需要注意的地方在于 in place ，不能新建另一个数组。
方法很简单，使用两个游标i，j，遍历数组，如果碰到了value，使用j记录位置，同时递增i，直到下一个非value出现，将此时i对应的值复制到j的位置上，增加j，重复上述过程直到遍历结束。这时候j就是新的数组长度。

我的思路:两个游标i,j作用,i用来遍历数组,记录扫过的元素,j表示当前位置可以存放最后数组的下一个元素,从头开始,每次扫描到a[i]不等于给定的元素时,将其放入第j位置,因为是从头开始的,所以不用担心会有i没扫到的被j覆盖了
*/
#include <iostream>
using namespace std;

class Solution {
public:
	/* a:数组 n:数组长度 elem:删除元素 返回:数组长度*/
	int removeElement(int a[], int n, int elem) {
		if(n == 0){
			return 0;
		}
		int i = 0;//遍历下标a[i],原数组
		int j = 0;//a[j],虚概念,指最后留下的元素,相当于有一个虚的数组,从头开始存储a[i]中应该留下来的元素
		for(i = 0; i < n; i++){
			//当i位置不为elem时,说明该元素应该存在于最后的数组中
			if(a[i] != elem){
				a[j++] = a[i];//j每次都会指向一个可以放元素的空位
			}
		/*	//当碰到了elem,j不动,i继续走
			if(a[i] == elem){
				continue;
			}
			//否则此时a[i]不是elem,j仍然停留在elem处,将a[i]拷贝至a[j]处
			a[j] = a[i];
			//然后j前移
			j++; */
		}
		return j;
	}
};

int main(){
	int a[7] = {2, 2, 1, 3, 2, 2, 4};
	Solution s;
	int n = s.removeElement(a, 7, 2);
	cout << n << endl;
	
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}