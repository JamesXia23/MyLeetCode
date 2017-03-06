#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int res = 0;
		for(auto i : nums){
			res ^= i;
		}
		return res;
	}
};
int main(int argc, char *argv[]) {
	
}
/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

给定一个数组,其中只有一个数只出现过一次,其余均出现两次,求这个数
思路:利用一个数同时亦或一个数两次,值不变,一个数与0亦或得这个数,将整个数组亦或,得出的值就是只出现一次的数
*/