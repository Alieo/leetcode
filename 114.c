/*************************************************************************
	> File Name: 114.c
	> Author: 
	> Mail: 
	> Created Time: Fri 23 Nov 2018 10:18:28 AM CST
 ************************************************************************/
//求路径总和
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//判断左右子树中有没有一条路 == (sum - root->val)
bool hasPathSum(struct TreeNode* root, int sum) {
    if (root == NULL) return false;
    if (root->left == NULL && root->right == NULL) return root->val == sum;
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}
