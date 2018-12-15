/*************************************************************************
	> File Name: 237.c
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Dec 2018 11:08:28 AM CST
 ************************************************************************/

//思路二:交换节点。node与node->next交换。
void deleteNode(struct ListNode* node) {
    struct ListNode *delete = node->next;
    *node = *delete;
    free(delete);
    return ;
}
