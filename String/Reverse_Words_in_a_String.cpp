#include <iostream>

using namespace std;
class Solution {
public:
	void reverseWords(string &s) {
		if (s.empty()) {
			return ;
		}
		int start = -1, count = 0;//记录空格数
		while (s[0] == ' ') {//去前导0
			s.erase(s.begin());
		}
		while (s[s.length()-1] == ' ') {//去后导0
			s.erase(s.end()-1);
		}
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ' ') {
				count++;
				if (count > 1) {
					s.erase(i, 1);
					i--;//i复位
					count--;
				}
				continue;
			}
			if (s[i] != ' ' && start == -1) {
				start = i;
			}
			if ((s[i+1] == ' ' || i == s.length()-1) && start != -1) {
				reverseString(s, start, i);
				start = -1;
				count = 0;
			}
		}
		reverseString(s, 0, s.length()-1);
	}
	void reverseString(string &s, int start, int end){
		if (start >= end) {
			return ;
		}
		while (start < end) {
			char temp = s[start];
			s[start++] = s[end];
			s[end--] = temp;
		}
	}
};
int main(int argc, char *argv[]) {
	Solution s;
	string str = "+---...2x+--x--+x-+-x2...---+";
	s.reverseWords(str);
	cout << str;
}
/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Clarification:
	.What constitutes a word?
	A sequence of non-space characters constitutes a word.
	.Could the input string contain leading or trailing spaces?
	Yes. However, your reversed string should not contain leading or trailing spaces.
	.How about multiple spaces between two words?
	Reduce them to a single space in the reversed string.
	
将字符串单词的位置逆序
思路: 将字符串中所有单词逆序(包括单词后的标点),然后整个字符串逆序
		需要去除前导空格,后续空格,超过一个的连续空格只保留一个
*/