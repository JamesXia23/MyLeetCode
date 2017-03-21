#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
	bool isValid(string s) {
		stack<char> st;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
				st.push(s[i]);
			}else if(st.empty()){
				return false;
			}else if (st.top() == '(' && s[i] == ')' || 
					  st.top() == '{' && s[i] == '}' || 
					  st.top() == '[' && s[i] == ']' ) {
				st.pop();
			}else {
				return false;
			}
		} 
		if (st.empty()) {
			return true;
		}
		return false;
	}
};
int main(int argc, char *argv[]) {
	string s = "]";
	Solution so;
	
	cout << so.isValid(s) << endl;
}

/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
题意:括号匹配
*/