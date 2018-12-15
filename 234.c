/*************************************************************************
	> File Name: 234.c
	> Author: 
	> Mail: 
	> Created Time: Thu 13 Dec 2018 10:38:22 AM CST
 ************************************************************************/

//错误思路１：如果翻转后的链表和原链表一模一样，则他是回文链表（整个链表做翻转）
//思路２：找到中心点，让中心点之后的链表进行翻转，链表从头和中心点一起向后走，若都相等，则是回文链
bool isPalindrome(struct ListNode* head) { 
    if (head == NULL || head->next == NULL) return true; 
    struct ListNode *fast = head, *slow = head; 
    while (fast->next != NULL && fast->next->next != NULL) { 
        slow = slow->next; 
        fast = fast->next->next; 
    } 
    struct ListNode *last = slow->next, *temp; 
    while (last->next != NULL) { 
        temp = last->next; 
        last->next = temp->next; 
        temp->next = slow->next; 
        slow->next = temp; 
    } 
    while (slow->next != NULL) { 
        if (slow->next->val != head->val) return false; 
        head = head->next; 
        slow = slow->next; 
    } 
    return true; 
}

