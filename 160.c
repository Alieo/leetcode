/*************************************************************************
	> File Name: 160.c
	> Author: 
	> Mail: 
	> Created Time: 2018年10月27日 星期六 18时47分27秒
 ************************************************************************/
/*相交链表
 *  编写一个程序，找到两个单链表相交的起始节点。

    例如，下面的两个链表：
        A:          a1 → a2
                            ↘
                                c1 → c2 → c3
                            ↗            
        B:     b1 → b2 → b3
        在节点 c1 开始相交。

    注意：

        如果两个链表没有交点，返回 null.
        在返回结果后，两个链表仍须保持原有的结构。
        可假定整个链表结构中没有循环。
        程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
*
* */
//思路: 获取ab链表的长度. a->length > b->length ? a : b;假如a->len < b->len. 让b的虚拟节点->next指向与a->len同等长度的链表的head. 之后让ab同时往前走. 如果a->data == b->data 记录下第一个数, 则是答案. else 一直走. 

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) return NULL;
    struct ListNode *p1 = headA, *p2 = headB, *ans = NULL;
    int length1 = 0, length2 = 0, sub = 0;
    while (p1) {
        length1++;
        p1 = p1->next;
    }
    while (p2) {
        length2++;
        p2 = p2->next;
    }
    p1 = headA; p2 = headB;
    if (length1 > length2) {
        sub = length1 - length2;
        while (sub--) {
            p1 = p1->next;
        }
    } else {
        sub = length2 - length1;
        while (sub--) {
            p2 = p2->next;
        }
    } 
    while (p1 && p2) {
        if (p1->val == p2->val) { 
            ans = p1;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    
    return ans;
}
