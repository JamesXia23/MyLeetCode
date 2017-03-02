#include <iostream>

using namespace std;
class Solution {
public:
	string reverseVowels(string s) {
		if(s.length() <= 1)
			return s;
		
		int left = 0, right = s.length()-1;
		while (left < right) {
			if (!isVowel(s[left])) {
				left++;
				continue;
			}
			if (!isVowel(s[right])) {
				right--;
				continue;
			}
			char temp = s[left];
			s[left++] = s[right];
			s[right--] = temp;
		}
		return s;
	}
	bool isVowel(char c){
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
			c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
			return true;
		}
		return false;
	}
};
int main(int argc, char *argv[]) {
	string str = "yi";
	Solution s;
	
	cout << s.reverseVowels(str);
}

/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".

反转所有元音字母,a e i o u
*/