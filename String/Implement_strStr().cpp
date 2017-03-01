#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	//暴力破解
//	int mystrStr(string haystack, string needle) {
//		if (needle.empty()) {
//			return 0;
//		}
//		for (int i = 0; i < haystack.length(); i++) {
//			int j = i, k = 0;
//			while (	j < haystack.length() && 
//					k < needle.length() && 
//					haystack[j] == needle[k]) {
//				j++;
//				k++;
//			}
//			if (k == needle.length()) {
//				return i;
//			}
//		}
//		return -1;
//	}
	//KMP算法
	//next数组的意义是,当next[i]=k时,表示parttern[i]前面的i个数中,前k个字符和后k个字符相同,匹配时,当parttern[i]和array[j]失配,从parttern[i]移动到parttern[k],再与array[j]进行比较
	//求next数组next[0]=-1,next[1]=0,往后如果next[i]=k,即parttern[0]-parttern[k-1]=parttern[i-k]-parttern[i-1]求next[i+1]时,
	//那么只有两种情况,parttern[k]=parttern[i],此时parttern[0]-parttern[k]=parttern[i-k]-parttern[i],则next[i+1]=next[i]+1=k+1
	//				 parttern[k]!=parttern[i],此时将k置为next[k]假设为j,则有p[0]-p[j-1]=p[k-j]-p[j-1]=p[i-j]-p[i-1],则比较p[j]是否等于p[i],情况又和上述情况一致了.
	void getNext(string ptn, vector<int> &next){
		int len = ptn.length();
		int i = 0, k = -1;
		next[i] = k;
		
		while (i+1 < len) {//已知next[i],求next[i+1]
			if (k == -1 || ptn[i] == ptn[k]) {//k == -1,表示已经匹配到最前面了,代表的意义是,没有用了,模式串要从头开始与从原串的第i+1个字符起的字符进行比较了,所以next[i]=-1+1=0
				next[++i] = ++k;
			}else {
				k = next[k];
			}
		}
	}
	int mystrStr(string haystack, string needle){
		if(needle.empty()){
			return 0;
		}
		vector<int> next;
		next.resize(needle.length());
		getNext(needle, next);
		int i = 0, k = 0;
		
		while (i < haystack.length()) {
			if (k == -1 || haystack[i] == needle[k]) {
				i++;
				k++;
			}else {
				k = next[k];
			}
			if(k == needle.length()){//匹配完成
				return i - needle.length();
			}
		}
		return -1;//匹配失败
	}
};
	
int main(int argc, char *argv[]) {
	string haystack = "a", needle = "a";
	Solution s;
	
	cout << s.mystrStr(haystack, needle) << endl;
}

/*
Implement strStr().
Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
ܵ实现strstr()函数
1.暴力破解 O(n*m)
2.kmp O(n*m)
*/