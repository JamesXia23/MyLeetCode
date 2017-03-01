#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	bool isPalindrome(string s) {
		int left = 0, right = s.length()-1;
		bool isPalindrome = true;
		while (left < right) {
			if (!isalpha(s[left]) && !isnumber(s[left])) {
				left++;
				continue;
			}
			if (!isalpha(s[right]) && !isnumber(s[right])) {
				right--;
				continue;
			}
			if (tolower(s[left]) != tolower(s[right])) {
				return false;
			}
			left++;
			right--;
		}
		return isPalindrome;
	}
};
int main(int argc, char *argv[]) {
//	string str = "A man, a plan, a canal: Panama";
	string str = "0P";
//	string str = " a1A  ";
//	string str = "";
	Solution s;
	
	cout << s.isPalindrome(str) << endl;
}
/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
Note: Have you consider that the string might be empty? This is a good question to ask during an interview.
For the purpose of this problem, we define empty string as valid palindrome.

判断回文串,忽略大小写,忽略所有非字母数字,空串也是回文串
*/