#include<stdio.h>

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *Linklist;

// 判断链表是否为回文链表
bool ishuiwenLinklist(Linklist head) {
    if (head == NULL || head->next == NULL) {
        return true;  // 空链表或只有一个节点的链表视为回文链表
    }

    // 快慢指针找到链表的中点
    Linklist slow = head, fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 从链表的中点开始，使用两个指针分别向链表头和链表尾移动，比较节点数据是否相等
    slow = slow->next;  // slow指针越过中点
    Linklist p1 = slow, p2 = head;
    while (p1 != NULL) {
        if (p1->data != p2->data) {
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    return true;
}

int main(){

}
