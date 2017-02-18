/*
Given a non-negative number represented as an array of digits, plus one to the number.
The digits are stored such that the most significant digit is at the head of the list.
一个数加1,这道题目很简单，就是考的加法进位问题。
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		if (!digits.size()) {
			digits.push_back(1);
			return digits;
		}
		if(digits[digits.size()-1] != 9){
			digits[digits.size()-1]++;
			return digits;
		}
		int i, j;
		for(i = digits.size()-1; i >= 0; i--){
			//从最低位起到第一个非9的数为止,全部位数全部置0,第一个非9位加1
			if(digits[i] != 9){
				digits[i]++;
				break;
			}
			digits[i] = 0;
		}
		if(i == -1)//如果最高位也需要进位则首位插入1
			digits.insert(digits.begin(), 1);
		return digits;
	}
};
int main(int argc, char *argv[]) {
	vector<int> digits;
	digits.push_back(9);
	digits.push_back(9);
	digits.push_back(9);
	digits.push_back(9);
	digits.push_back(9);
	Solution s;
	digits = s.plusOne(digits);
	for(int i = 0; i < digits.size(); i++){
		cout << digits[i];
	}
	cout << endl;
	return 0;
}