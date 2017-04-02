class Sqrtx {
	public static void main(String[] args) {
		
	}
//	public int mySqrt(int x) {
//		if (x < 1) {
//			return 0;
//		}
//		int left = 1, right = x;
//		while (left <= right) {
//			int mid = left + (right - left) / 2;
//			long res = (long)mid * mid;
//			if (res < x) {
//				left = mid + 1;
//			}else if (res > x) {
//				right = mid - 1;
//			}else {
//				return mid;
//			}
//		}
//		return right;
//	}
	public int mySqrt(int x) {
		if (x < 1) {
			return 0;
		}
		long res = 0, factor = 1;
		int count = 0;
		while (res < x) {
			res += factor;
			factor += 2;
			count++;
		}
		if (res == x) {
			return count;
		}else {
			return count - 1;
		}
	}
}
/*
Implement int sqrt(int x).

Compute and return the square root of x.
题意：算出一个整数的近似根（(int)sqrt(x)）
思路：还是可以用二分搜索，假如mid*mid==num，mid==sqrt(num)，一直没找到则说明最后left=right+1,循环才会跳出，此时right = (int)sqrt(num)
另一个思路：还是数学方法，完全平方数是一系列奇数之和
	1 = 1	1*1
	4 = 1 + 3	2*2
	9 = 1 + 3 + 5	3*3
	16 = 1 + 3 + 5 + 7	4*4
	25 = 1 + 3 + 5 + 7 + 9 5*5
	36 = 1 + 3 + 5 + 7 + 9 + 11 6*6
	....
	1+3+...+(2n-1) = (2n-1 + 1)n/2 = n*n
	可以用一个变量记录累加的次数，当累加和等于num时，sqrt(num) = 累加次数，
								如果累加和大于num，则sqrt=累加次数-1，因为(累加次数-1)^2<num<累加次数^2
*/