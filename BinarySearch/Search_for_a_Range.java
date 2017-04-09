class Search_for_a_Range {
	public static void main(String[] args) {
		
	}
	public int[] searchRange(int[] nums, int target) {
		if (nums == null) {
			return null;
		}
		int[] res = new int[]{-1, -1};
		int left = 0;
		int right = nums.length-1;
		
		//找最左
		while (left <= right) {
			int mid = left + (right-left) / 2;
			if (nums[mid] < target) {
				left = mid + 1;
			}else if (nums[mid] > target) {
				right = mid - 1;
			}else {
				res[0] = mid;
				right = mid - 1;
			}
		}
		
		//找最右
		left = 0;
		right = nums.length-1;
		while (left <= right) {
			int mid = left + (right-left) / 2;
			if (nums[mid] < target) {
				left = mid + 1;
			}else if (nums[mid] > target) {
				right = mid - 1;
			}else {
				res[1] = mid;
				left = mid + 1;
			}
		}
		
		return res;
	}
}

/*
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

题意：给定一个有序数组和一个待搜索数，返回待搜索数在数组中出现位置的范围
思路：使用二分查找寻找target，使用一个变量记录target出现的最左位置，找到一个target，则将right置为mid-1，继续找最后left>right时就得到了最左位置
	同样的方式找到最右的位置
*/