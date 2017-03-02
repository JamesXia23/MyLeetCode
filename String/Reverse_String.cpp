#include <iostream>

using namespace std;
class Solution {
public:
	string reverseString(string s) {
		if(s.length() <= 1){
			return s;
		}
		int left = 0, right = s.length() - 1;
		while (left < right) {
			char temp = s[left];
			s[left++] = s[right];
			s[right--] = temp;
		}
		return s;
	}
};
int main(int argc, char *argv[]) {
	string str = "a";
	Solution s;
	cout << s.reverseString(str);
	return 0;
}

/*
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".

字符串反转
*/