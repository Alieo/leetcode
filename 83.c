/*************************************************************************
	> File Name: 83.c
	> Author: 
	> Mail: 
	> Created Time: 2018年10月27日 星期六 18时18分47秒
 ************************************************************************/
/*删除排序链表中的重复元素
*
* 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

    示例 1:

        输入: 1->1->2
        输出: 1->2
    示例 2:

        输入: 1->1->2->3->3
        输出: 1->2->3
* */

//思路: 用两个链表实现. 一个存输入链. 一个存输出链. 因为是排序链表. 所以输入链是按顺序存数的. 如果输出链的当前节点的data == 要插入的值. 则输入链++(访问输入链当前节点的next)
//思路2: 用一个链表实现. 如果输出链的当前节点的data != 要插入的值. 则入链. 否则不入链
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;
    struct ListNode *p = head, *q;
    while (p) {
        q = p->next;
        if (q != NULL && p->val == q->val) p->next = q->next;
        else p = q;
    }
    return head;
}
