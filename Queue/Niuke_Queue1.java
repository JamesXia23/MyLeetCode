import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Iterator;

public class Niuke_Queue1 {
	/**
	 * 给定一个数组array,以及一个滑动窗口大小n,滑动窗口从0位置开始移动,求出每个滑动窗口的中最大值并放入另一个数组
	 * 思路:定义一个双端队列q,用来存放数组的下标,从头开始遍历数组,队列更新规则:
	 * 		1.如果队列为空,i直接入队
	 *      2.如果队列不为空,比较对尾元素与array[i],如果array[i]<队尾,i直接入队
	 *      3.如果对尾元素<array[i],对尾出队,继续步骤2
	 *      在遍历过程中不断检测是否到达n,第一次到n时,队头下标所指向元素肯定是窗口最大值,
	 *      而后每遍历一次就会出现一个新窗口,并且每次都会将大于等于当前遍历元素的值放入队列中,
	 *      如果队头元素已经不在窗口内,就弹出队头,如果在窗口内就就队头元素插入结果队列
	 */
	private static ArrayDeque<Integer> arrayDeque;
	private static ArrayList<Integer> arrayList;
	private static ArrayList<Integer> res;

	public static void main(String[] args) {
		arrayDeque = new ArrayDeque<Integer>();
		arrayList = new ArrayList<Integer>();
		arrayList.add(4);
		arrayList.add(3);
		arrayList.add(5);
		arrayList.add(4);
		arrayList.add(3);
		arrayList.add(3);
		arrayList.add(6);
		arrayList.add(7);
		System.out.println(arrayList);
		res = new ArrayList<Integer>();
		getMax(3);
		System.out.println(res);
	}
	public static void getMax(int window){
		for (int i = 0; i < arrayList.size(); i++) {
			while (!arrayDeque.isEmpty() && arrayList.get(i) >= arrayList.get(arrayDeque.getLast())) {
				arrayDeque.pollLast();//删除最后一位
			}
			arrayDeque.add(i);//插入对尾,push是插入到队头
			if (i >= window-1) {//到了每次都要判断窗口的时候
				while(arrayDeque.getFirst() <= i-window){//队头失效
					arrayDeque.pop();
				}
				res.add(arrayList.get(arrayDeque.getFirst()));
			}
		}
	}
}
