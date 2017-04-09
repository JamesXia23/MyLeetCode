public class Niuke_BinarySearch1 {
	public static void main(String[] args) {
		int[] array = new int[]{0, 1, 2, 3, 4, 5, 6, 7};
		int n = array.length - 1;
		
		if(array[0] > n || array[n] < 0){
			System.out.println(-1);
			return ;
		}
		int left = 0, right = n, res = -1;
		while(left <= right) {
			int mid = left + (right - left) / 2;
			System.out.println("mid:" + mid + "   array[mid]:" + array[mid]);
			if(array[mid] == mid){
				res = mid;
				right = mid - 1;
			}else if (array[mid] > mid) {
				right = mid - 1;
			}else {
				left = mid + 1;
			}
		}
		System.out.println(res);
	}
}

/**
 * 给定一个严格有序数组array（无重复值），找出其中数组值等于下标值的情况，返回最左出现这种情况的下标，不存在返回-1
 * 
 * 思路：首先判断array[0]>n-1，如果成立，则已经不可能有那种情况发生因为array中所有数均大于n-1，返回-1
 * 		同理，如果array[n-1]<0，则数组中所有数都小于0，返回-1
 * 		如果上述均不成立，
 * 		令mid = (n-1)/2，判断array[mid] == mid?,如果成立，使用变量记录mid的值，然后对前半部分进行搜索
 * 						如果array[mid] > mid，因为下标递增幅度为1，而数值递增幅度大于等于1，所以mid之后的下标不可能再追上数值了，故对前半部分进行搜索
 * 						如果array[mid] < mid，同理，对后半部分进行二分搜索，直到无法再二分为止。
 */
