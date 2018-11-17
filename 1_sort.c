/*************************************************************************
	> File Name: 1.c
	> Author: 
	> Mail: 
	> Created Time: Thu 08 Nov 2018 06:12:34 PM CST
 ************************************************************************/

#define swap(a, b) {\
    __typeof(a) __temp = a; a = b; b = __temp;\
}
void fast_sort(int *num, int l, int r) {
    if (r <= l) return ;
    int x = l, y = r, z;
    swap(num[l], num[(l + r) >> 1]);
    z = num[l];
    while (x < y) {
        while (x < y && num[y] >= z) --y;
        if (x < y) num[x++] = num[y];
        while (x < y && num[x] <= z) ++x;
        if (x < y) num[y--] = num[x];
    }
    num[x] = z;
    fast_sort(num, l, x - 1);
    fast_sort(num, x + 1, r);
    return ;
}
int *twoSum(int *nums, int numsSize, int target) {
    int *temp_num = (int *)malloc(sizeof(int) * numsSize);
    memcpy(temp_num, nums, sizeof(int) * numsSize);
    fast_sort(nums, 0, numsSize - 1);
    int p = 0, q = numsSize - 1;
    while (nums[p] + nums[q] != target) {
        if (nums[p] + nums[q] < target) ++p;
        else --q;
    }
    int *ret = (int *)malloc(sizeof(int) * 2);
    int ans = 2;
    for (int i = 0; i < numsSize && ans; i++) {
        if (temp_num[i] == nums[p] || temp_num[i] == nums[q]) {
            ret[2 - ans] = i;
            ans--;
        }
    }
    return ret;
}
