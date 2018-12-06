/*************************************************************************
	> File Name: 141.c
	> Author: 
	> Mail: 
	> Created Time: 2018年10月27日 星期六 18时40分37秒
 ************************************************************************/
/*环形链表
*   给定一个链表，判断链表中是否有环。

    进阶：
        你能否不使用额外空间解决此题？
* */
//思路: 快慢指针同时遍历链表. 若有相遇, 则有环.
//注意: fast是否为空, 为空则无法使用fast->next;
bool hasCycle(struct ListNode *head) {
    if (head == NULL) return false;
    struct ListNode *slow = head, *fast= head->next;
    while (slow != fast && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast == NULL || fast->next == NULL) return false;
    return true;
}

