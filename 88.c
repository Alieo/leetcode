/*************************************************************************
	> File Name: 88.c
	> Author: 
	> Mail: 
	> Created Time: Sat 10 Nov 2018 05:03:33 PM CST
 ************************************************************************/

//开额外空间
/*
void merge(int* nums1, int m, int* nums2, int n) {
    int *temp = (int *)malloc(sizeof(int) * (m + n));
    int x = 0, y = 0, loc = 0;
    while (x < m || y < n) {
        if (y >= n || (x < m && nums1[x] < nums2[y])) temp[loc++] = nums1[x++];
        else temp[loc++] = nums2[y++];
    }
    memcpy(nums1, temp, sizeof(int) * (m + n));
}
*/
//不开额外空间
void merge(int* nums1, int m, int* nums2, int n) {
    int x = m - 1, y = n - 1, loc = m + n - 1;
    while (x >= 0 || y >= 0) {
        if (y < 0 || (x >= 0 && nums1[x] > nums2[y])) nums1[loc--] = nums1[x--];
        else nums1[loc--] = nums2[y--];
    }
}
