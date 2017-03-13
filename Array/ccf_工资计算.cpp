#include <iostream>
using namespace std;
int main() {
	double salary;
	cin >> salary;
	
	double s3500 = 3500;
	double s5000 = s3500 + 1500 * 0.97;
	double s8000 = s5000 + 3000 * 0.9;
	double s12500 = s8000 + 4500 * 0.8;
	double s38500 = s12500 + 26000 * 0.75;
	double s58500 = s38500 + 20000 * 0.7;
	double s83500 = s58500 + 25000 * 0.65;
	
	if (salary <= s3500) {
		cout << salary << endl;
	} else if (salary <= s5000) {
		cout << (salary - s3500) / 0.97 + 3500 << endl;
	} else if (salary <= s8000) {
		cout << (salary - s5000) / 0.9 + 5000 << endl;
	} else if (salary <= s12500) {
		cout << (salary - s8000) / 0.8 + 8000 << endl;
	} else if (salary <= s38500) {
		cout << (salary - s12500) / 0.75 + 12500 << endl;
	} else if (salary <= s58500) {
		cout << (salary - s38500) / 0.7 + 38500 << endl;
	} else if (salary <= s83500) {
		cout << (salary - s58500) / 0.65 + 58500 << endl;
	} else {
		cout << (salary - s83500) / 0.55 + 83500 << endl;
	}
	return 0;
}


/*
问题描述
　　小明的公司每个月给小明发工资，而小明拿到的工资为交完个人所得税之后的工资。假设他一个月的税前工资（扣除五险一金后、未扣税前的工资）为S元，则他应交的个人所得税按如下公式计算：
　　1） 个人所得税起征点为3500元，若S不超过3500，则不交税，3500元以上的部分才计算个人所得税，令A=S-3500元；
　　2） A中不超过1500元的部分，税率3%；
　　3） A中超过1500元未超过4500元的部分，税率10%；
　　4） A中超过4500元未超过9000元的部分，税率20%；
　　5） A中超过9000元未超过35000元的部分，税率25%；
　　6） A中超过35000元未超过55000元的部分，税率30%；
　　7） A中超过55000元未超过80000元的部分，税率35%；
　　8） A中超过80000元的部分，税率45%；
　　例如，如果小明的税前工资为10000元，则A=10000-3500=6500元，其中不超过1500元部分应缴税1500×3%=45元，超过1500元不超过4500元部分应缴税(4500-1500)×10%=300元，超过4500元部分应缴税(6500-4500)×20%=400元。总共缴税745元，税后所得为9255元。
　　已知小明这个月税后所得为T元，请问他的税前工资S是多少元。
输入格式
　　输入的第一行包含一个整数T，表示小明的税后所得。所有评测数据保证小明的税前工资为一个整百的数。
输出格式
　　输出一个整数S，表示小明的税前工资。
样例输入
9255
样例输出
10000
评测用例规模与约定
　　对于所有评测用例，1 ≤ T ≤ 100000。
*/