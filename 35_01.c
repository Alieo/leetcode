/*************************************************************************
	> File Name: 35_01.c
	> Author: 
	> Mail: 
	> Created Time: Sat 10 Nov 2018 12:35:38 AM CST
 ************************************************************************/
//找第一个1
int check(int *num, int mid, int target) {
    if (num[mid] >= target) return 1;
    return 0;
}
int searchInsert(int* nums, int numsSize, int target) {
    int l = 0, r = numsSize, mid, ans;
    while (l < r) {
        mid = (l + r) >> 1;
        if (check(nums, mid, target) == 1) r = mid;
        else l = mid + 1;
    }
    if (l == numsSize) ans = numsSize;
    if (l == 0) ans = 0;
    if (l == r) ans = l;
    return ans;
}
