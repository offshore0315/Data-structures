#include<stdio.h>

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *Linklist;

// �ж������Ƿ�Ϊ��������
bool ishuiwenLinklist(Linklist head) {
    if (head == NULL || head->next == NULL) {
        return true;  // �������ֻ��һ���ڵ��������Ϊ��������
    }

    // ����ָ���ҵ�������е�
    Linklist slow = head, fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // ��������е㿪ʼ��ʹ������ָ��ֱ�������ͷ������β�ƶ����ȽϽڵ������Ƿ����
    slow = slow->next;  // slowָ��Խ���е�
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
