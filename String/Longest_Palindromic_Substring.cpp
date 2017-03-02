#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	string longestPalindrome(string s) {
		if(s.length() <= 1) {
			return s;
		}
		string newStr = process(s);
		int length = newStr.length();
		vector<int> p(length, 1);//以i为中心点的最长回文子序列的半径,包括中间点,所以p[i]-1就是源字符串中以i为中点的最长回文子序列的长度
		int id = 0, max = 0;//id为上一个求出的最长回文子序列中间元素的下标, max为上一个求出的最长回文子序列的右边界,子序列不包括newStr[max],一般是#后面的一个数的下标
		for (int i = 1; i < length; i++) {
			int j = id * 2 - i;//j为i基于id的对称点
			if (i < max) {//说明i在max的左侧,即i的最长回文子序列有一部分是id的最长回文子序列的子串
				//p[j] < (max - i),说明i的最长回文子序列就等于j的最长回文子序列,故p[i] = p[j]
				//否则,说明从p[i]-p[max]都是回文子串的右部分的一部分,ps:如果max-i+1严格大于p[j],那p[i]就等于max-i+1,等于的话则可以继续扩展
				p[i] = p[j] < (max - i) ? p[j] : (max - i);//max - i + 1,max与i之间的距离,包括i
			}
			while(newStr[i+p[i]] == newStr[i-p[i]]){//i+p[i],以i为中心的最长回文子序列的右边界下一个端点,i-p[i],左边界的上一个端点
				p[i]++;
			}
			if (i+p[i] > max) {//i+p[i],以i为中心的最长回文子序列的右边界,子序列不包含此右边界,向后移动id,同时保持max的范围能最大,则可以省略更多比较
				max = p[i];
				id = i;
			}
		}
		int maxLen = 0, maxMid = 0;
		for (int i = 1; i < length; i++) {
			if (p[i] > maxLen) {
				maxLen = p[i];
				maxMid = i;
			}
		}
//		int left = maxMid - maxLen + 2;//最长回文子串第一个非#字符
//		int readLeft = left / 2 - 1;//源字符串下标
		//总结起来,readLeft = (maxMid - maxLen) / 2
		return s.substr((maxMid - maxLen) / 2, maxLen - 1);
	}
	string process(string s){
		string newStr = "^#";
		for (int i = 0; i < s.length(); i++) {
			newStr.insert(newStr.end(), s[i]);
			newStr += "#";
		}
		newStr += "$";
		return newStr;
	}
};
int main(int argc, char *argv[]) {
	Solution s;
	string str = "abcba";
	string newStr = s.longestPalindrome(str);
	cout << newStr << endl;
}
/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:
Input: "babad"
Output: "bab"

Note: "aba" is also a valid answer.
Example:
Input: "cbbd"
Output: "bb"

求最长回文子序列:http://www.tuicool.com/articles/n6NfIrN 超级详细
*/