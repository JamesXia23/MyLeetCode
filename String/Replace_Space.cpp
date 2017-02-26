#include <iostream>

using namespace std;
class Solution {
public:
	void replaceSpace(char *str,int length) {
		int count = 0;
		for(int i = 0; i < length; i++){
			if(str[i] == ' '){
				count++;
			}
		}
		int finalLen = count * 2 + length;
		for(int i = finalLen - 1; i >= 0; i--){
			if(str[length-1] != ' '){
				str[i] = str[length-1];
			}else{
				str[i--] = '0';
				str[i--] = '2';
				str[i] = '%';
			}
			length--;
		}
	}
};
int main(int argc, char *argv[]) {
	char a[100] = "We Are Happy";
	Solution s;
	s.replaceSpace(a, 12);
	cout << a << endl;
}
/*
请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/