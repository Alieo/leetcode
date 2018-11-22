/*************************************************************************
	> File Name: 104.c
	> Author: 
	> Mail: 
	> Created Time: Thu 22 Nov 2018 10:33:30 AM CST
 ************************************************************************/
//二叉树的最大深度
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 //递归求最大深度: 递归只需要考虑一个叉(一个根节点和他的左右子树), 其余的无需考虑
int max(int a, int b) {
    return a > b ? a : b;
}

int maxDepth(struct TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 1;
        else return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
