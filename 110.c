/*************************************************************************
	> File Name: 110.c
	> Author: 
	> Mail: 
	> Created Time: Fri 23 Nov 2018 10:15:23 AM CST
 ************************************************************************/
//平衡二叉树
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//思路: 获得左右子树深度.并判断是否平衡
//改进: 如果发现某个子树不平衡.将其赋值为-2 (为了不重复计算)

/*
#include<math.h>
int _max(int a, int b) {
    return a > b ? a : b;
}

int dep(struct TreeNode* root) {
    if (root == NULL) return 0;
    return _max(dep(root->left), dep(root->right)) + 1;
}
bool isBalanced(struct TreeNode* root) {
    if (root == NULL) return true;
    if (root->left == NULL && root->right == NULL) return true;
    if (isBalanced(root->left) && isBalanced(root->right) && (abs(dep(root->left) - dep(root->right)) <= 1)) return true;
    return false;
}

*/
/*
//思路
int getHeight(struct TreeNode *root) {
    if(root == NULL) return 0;
    int l = getHeight(root->left), r = getHeight(root->right);
    return (l > r ? l : r) + 1;
}

bool isBalanced(struct TreeNode* root) {
    if (root == NULL) return true;
    int l = getHeight(root->left), r = getHeight(root->right);
    if (abs(l - r) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}
*/

//思路改进:
int getHeight(struct TreeNode *root) {
    if(root == NULL) return 0;
    int l = getHeight(root->left);
    if(l < 0) return -2;//说明不平衡
    int r = getHeight(root->right);//如果能遍历右子树. 说明做的深度大于等于1
    if (abs(l - r) > 1) return -2;
    return (l > r ? l : r) + 1;
}

bool isBalanced(struct TreeNode* root) {
    if (root == NULL) return true;
    return getHeight(root) > 0;
}
