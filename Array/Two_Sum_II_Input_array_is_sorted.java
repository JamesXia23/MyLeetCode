class Two_Sum_II_Input_array_is_sorted {
	public static void main(String[] args) {
		
	}
	public int[] twoSum(int[] numbers, int target) {
		int left = 0;
		int right = numbers.length-1;
		int[] res = new int[2];
		while (left < right) {
			if (numbers[left] + numbers[right] < target) {
				left++;
			}else if (numbers[left] + numbers[right] > target) {
				right--;
			}else {
				res[0] = ++left;
				res[1] = ++right;
				break;
			}
		}
		return res;
	}
}

/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution and you may not use the same element twice.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

题意：2Sum的变形题：而且还要简单一点，因为数组是有序的，且有且只有一组答案，下标从1开始
思路：两个指针，左指针l从0位置向右遍历，右指针r从末尾向前遍历当：
				l+r<target:l++
				l+r>target:r--
				l+r==target:return ++l,++r
*/