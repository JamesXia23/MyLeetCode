class Untitled {
	public static void main(String[] args) {
		int[] nums = new int[]{3,4,3,2,1};
		System.out.println(findPeakElement(nums));
	}
	public static int findPeakElement(int[] nums) {
		if(nums.length == 1 || nums[0] > nums[1]){
			return 0;
		}
		int right = nums.length-1;
		if (nums[right] > nums[right-1]) {
			return right;
		}
		int left = 0;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			//需要再次排除0和n-1
			if(mid == 0)
				mid++;
			else if(mid == nums.length-1){
				mid--;
			}
			if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
				return mid;
			}
			if (nums[mid] < nums[mid-1]) {
				right = mid - 1;
			}else {
				left = mid + 1;
			}
		}
		return 0;//没有用，因为绝对有返回
	}
}

/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

Note:
Your solution should be in logarithmic complexity.
题意：给定一个无序数组，且相邻两个数均不相等，找到数组的一个极大值点(num[i-1]<num[i]>num[i+1])，假设num[-1]和num[n]为负无穷
思路：先检查num[0]>num[1]?若为真，则return 0
		再检查num[n-1]>num[n-2]?若为真，则return n-1
		如果均为假，则可将数组看成是由两边向中间增大的趋势
			此时检查num[(n-1)/2]，如果num[(n-1)/2]大于它的两边，则直接返回即可
			如果num[(n-1)/2-1]<num[(n-1)/2]<num[(n-1)/2+1],则说明从(n-1)/2向右为增大趋势，应该找寻数组的后半部分
			如果num[(n-1)/2-1]>num[(n-1)/2]>num[(n-1)/2+1],则说明从(n-1)/2向左为增大趋势，应该找寻数组的左半部分
			如果num[(n-1)/2-1]>num[(n-1)/2]<num[(n-1)/2+1],两边都有增大趋势，随便找一边
*/