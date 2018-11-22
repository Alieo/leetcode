/*************************************************************************
	> File Name: 101.c
	> Author: 
	> Mail: 
	> Created Time: Thu 22 Nov 2018 10:46:17 AM CST
 ************************************************************************/
//对称二叉树
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool fun(struct TreeNode *p, struct TreeNode *q) {
    if (p == NULL || q == NULL) {
        if (p == NULL && q == NULL) return true;
        else return false;   
    }
    
    if (p->val != q->val) return false;
    if (!fun(p->left, q->right)) return false;
    if (!fun(p->right, q->left)) return false;
    return true;
    //下面这行注释可以替代上面三行
    //return p->val == q->val && fun(p->left, q->right) && fun(p->right, q->left); 
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) return true;
    if (fun(root->left, root->right)) return true;
    else return false;
}
