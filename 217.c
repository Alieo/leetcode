/*************************************************************************
	> File Name: 217.c
	> Author: 
	> Mail: 
	> Created Time: Mon 19 Nov 2018 10:26:00 AM CST
 ************************************************************************/
//删除重复元素
#include<math.h>
typedef struct Node {
    int val;
    struct Node *next;
} Node;
typedef struct Hash {
    Node **data;
    int size;
} Hash;
Node *init_node(int val, Node *head) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->next = head;
    n->val = val;
    return n;
}
Hash *init_hash(int n) {
    Hash *h = (Hash *)malloc(sizeof(Hash));
    h->size = n << 1;
    h->data = (Node **)calloc(sizeof(Node *), h->size);
    return h;
}
int func(int val) {
    return val & 0x7fffffff;
}
int insert_repeat(Hash *h, int val) {
    int hash = func(val);
    int pos = hash % h->size;
    Node *p = h->data[pos];
    while (p) {
        if (p->val == val) return abs(p->val) + 2;
        p = p->next;    
    }
    h->data[pos] = init_node(val, h->data[pos]);
    return 1;
}

void clear_node(Node *n) {
    if (n == NULL) return ;
    Node *p = n, *q;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    return ;
}
void clear_hash(Hash *h) {
    if (h == NULL) return;
    for (int i = 0; i < h->size; i++) {
        clear_node(h->data[i]);
    }
    free(h->data);
    free(h);
    return ;
}
bool containsDuplicate(int* nums, int numsSize) {
    
    Hash *h = init_hash(numsSize);
    int times;
    for (int i = 0; i < numsSize; i++) {
        if (insert_repeat(h, nums[i]) > 1) return true;
    }
    clear_hash(h);
    return false;
}
