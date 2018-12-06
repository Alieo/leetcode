/*************************************************************************
	> File Name: 203.c
	> Author: 
	> Mail: 
	> Created Time: Thu 06 Dec 2018 04:29:43 PM CST
 ************************************************************************/
//移除链表元素. 
//思路: 从头遍历到尾, 若node->val == val, 则删除.
//注意: 用虚拟头结点可便于操作链表表头.
struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head == NULL) return NULL;
    struct ListNode ret, *cur, *del;
    ret.next = head;
    cur = &ret;
    while (cur->next) {
        del = cur->next;
        if (del->val == val) {         
            cur->next = del->next;
            free(del);
        } else {
            cur = cur->next;
        }
    }
    return ret.next;
}

