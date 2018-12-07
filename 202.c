/*************************************************************************
	> File Name: 202.c
	> Author: 
	> Mail: 
	> Created Time: Thu 06 Dec 2018 03:17:12 PM CST
 ************************************************************************/
//思路: 快慢指针链表判环的思想. 如果呈环状, 说明不可能会出现1.
//本题考的是思维发散.
int add(int n) {
    int temp = 0, ans = 0;
    while (n) {
        temp = n % 10;
        ans += (temp * temp);
        n /= 10;
    }
    return ans;
}

bool isHappy(int n) {
    int slow = n, fast = add(n);
    while (fast != 1) {
        slow = add(slow);
        fast = add(add(fast));
        if (slow == fast) return false;
    }
    return true;
}
