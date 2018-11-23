/*************************************************************************
	> File Name: 100.c
	> Author: 
	> Mail: 
	> Created Time: Fri 23 Nov 2018 10:11:06 AM CST
 ************************************************************************/
//相同的树

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL || q == NULL) {
        if (p == NULL && q == NULL) return true;
        else return false;
    }
    if (p->val == q->val) {
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    } else return false;
  
}
