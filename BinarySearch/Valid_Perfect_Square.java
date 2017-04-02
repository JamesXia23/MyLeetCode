class Valid_Perfect_Square {
	public static void main(String[] args) {
//		for (int i = 1; i < 1000; i++) {
//			System.out.println(isPerfectSquare(i) == (Math.pow((int)Math.sqrt(i*1.0), 2) == i));
//		}
//		long a = 2147483648L;
		System.out.println(isPerfectSquare(808201));
	}
//	public static boolean isPerfectSquare(int num) {
//		if (num < 1) {
//			return false;
//		}
//		if (num == 1) {
//			return true;
//		}
//		long left = 1;
//		long right = num / 2;//缩小范围
//		
//		while (left <= right) {
//			long mid = left + (right - left) / 2;
//			long temp = mid * mid;
//			
//			if (temp < num) {
//				left = mid+1;
//			}else if (temp > num) {
//				right = mid-1;
//			}else {
//				return true;
//			}
//		}
//		return false;
//	}
	public boolean isPerfectSquare(int num) {
		if (num < 1) {
			return false;
		}
		long res = 0;
		int factor = 1;
		while (res < num) {
			res += factor;
			factor += 2;
		}
		if (res == num) {
			return true;
		}else {
			return false;
		}
	}
}

/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False

题意：判断一个数是否为平方数
思路：可以用二分搜索，不过这次搜索的条件是mid*mid==num，注意mid*mid有可能溢出
另一种解法：纯数学解法，完全平方数是一系列奇数之和
		1 = 1
		4 = 1 + 3
		9 = 1 + 3 + 5
		16 = 1 + 3 + 5 + 7
		25 = 1 + 3 + 5 + 7 + 9
		36 = 1 + 3 + 5 + 7 + 9 + 11
		....
		1+3+...+(2n-1) = (2n-1 + 1)n/2 = n*n
		从1遍历相加，直到大于等于num为止
*/