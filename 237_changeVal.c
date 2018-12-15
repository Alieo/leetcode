/*************************************************************************
	> File Name: 237_changeVal.c
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Dec 2018 11:11:08 AM CST
 ************************************************************************/

//思路: 交换值：node与node->next的值换位置。然后将node->next 指向 node->next->next, free掉中间那个。
void deleteNode(struct ListNode* node) {
    struct ListNode *delete = node->next;
    node->val = node->next->val;
    node->next = node->next->next;
    free(delete);
    return ;
}
