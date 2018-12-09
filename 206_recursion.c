/*************************************************************************
	> File Name: 206_recursion.c
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Dec 2018 04:46:02 PM CST
 ************************************************************************/

/*思路2(递归): 将旧链表的尾部作为新链表的头. 
*/

struct ListNode* reverseList(struct ListNode* head) {
    
    if (head == NULL || head->next == NULL) return head;
    struct ListNode* tail = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return tail;
    
}
