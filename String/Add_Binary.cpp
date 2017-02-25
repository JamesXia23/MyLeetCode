#include <iostream>

using namespace std;
class Solution {
public:
	string addBinary(string a, string b) {
		//去除前导0
		while (a[0] == '0' && a.size() > 1) {
			a.erase(a.begin());
		}
		while (b[0] == '0' && b.size() > 1) {
			b.erase(b.begin());
		}
		int lenA = a.size();
		int lenB = b.size();

		if (!lenA) {
			return b;
		}
		if (!lenB) {
			return a;
		}
		string c;
		int carry = 0;
		while (lenA > 0 && lenB > 0) {
			int numA = a[lenA-1] - '0';
			int numB = b[lenB-1] - '0';
			int tmpRes = (numA + numB + carry) % 2;
			carry = (numA + numB + carry) / 2;
			c.insert(c.begin(), tmpRes+'0');
			lenA--;
			lenB--;
		}
		while (lenA > 0) {
			if (!carry) {
				while (lenA > 0) {
					c.insert(c.begin(), a[--lenA]);
				}
				return c;
			}else {
				int numA = a[lenA-1] - '0';
				int tmpRes = (numA + carry) % 2;
				carry = (numA + carry) / 2;
				c.insert(c.begin(), tmpRes+'0');
				lenA--;
			}
		}
		while (lenB > 0) {
			if (!carry) {
				while (lenB > 0) {
					c.insert(c.begin(), b[--lenB]);
				}
				return c;
			}else {
				int numB = b[lenB-1] - '0';
				int tmpRes = (numB + carry) % 2;
				carry = (numB + carry) / 2;
				c.insert(c.begin(), tmpRes+'0');
				lenB--;
			}
		}
		if (carry) {
			c.insert(c.begin(), '1');
		}
		return c;
	}
};
int main(int argc, char *argv[]) {
	string a = "100";
	string b = "110010";
	
	Solution s;
	
	string c = s.addBinary(a, b);
	cout << c << endl;
}
/*
Given two binary strings, return their sum (also a binary string).
For example, a = "11" b = "1" Return "100".
题目翻译: 对于给定的两个二进制数字所表达的字符串，我们求其相加所得到的结果， 根据上例便可
得到答案.
题目分析: 我认为这道题所要注意的地方涵盖以下几个方面:
1. 对字符串的操作.
2. 对于加法，我们应该建立一个进位单位，保存进位数值.
3. 我们还要考虑两个字符串如果不同长度会怎样.
4. int 类型和char类型的相互转换.
时间复杂度:其实这就是针对两个字符串加起来跑一遍，O(n) n代表长的那串字符串长度.
*/