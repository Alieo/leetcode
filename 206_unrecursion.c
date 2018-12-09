/*************************************************************************
	> File Name: 206.c
	> Author: 
	> Mail: 
	> Created Time: Fri 07 Dec 2018 04:47:38 oldM CST
 ************************************************************************/



/*
思路1(非递归): 将旧链表的节点从头遍历, 依次放入新链表中. 新链表采用头插法, 虚拟指针. 最后返回新链表.
*/

struct ListNode* reverseList(struct ListNode* head) {

    if (head == NULL || head->next == NULL) return head;
    struct ListNode ret;
    struct ListNode* old = head, *New_h;
    ret.next = NULL; New_h = &ret;
    while (old) {
        struct ListNode* temp = old->next;        
        old->next = New_h->next;
        New_h->next = old;
        old = temp;
    }
    return New_h->next;

}
