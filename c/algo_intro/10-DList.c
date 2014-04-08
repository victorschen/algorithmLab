//DList.c
//双链表的操作
#include <stdio.h>
#include <stdlib.h>
struct DLNode 
{
    int data;
    struct DLNode* pre;
    struct DLNode* next;
};

int dlink_head_insert(struct DLNode *head, int x);
int dlink_tail_insert(struct DLNode *head, int x);
int dlink_delete(struct DLNode *head, int x);
int dlink_nh_head_insert(struct DLNode **head, int x);
int dlink_nh_tail_insert(struct DLNode **head, int x);
int dlink_nh_delete(struct DLNode **head, int x);

int main(void)
{
    /*
     * 测试无头双链表操作
     * 测试用例如下：
    struct DLNode *head = NULL;
    dlink_nh_tail_insert(&head, 5);
    dlink_nh_tail_insert(&head, 7);
    dlink_nh_tail_insert(&head, 4);
    dlink_nh_tail_insert(&head, 2);
    dlink_nh_tail_insert(&head, 1);
    dlink_nh_tail_insert(&head, 6);
    dlink_nh_delete(&head, 6);
    */

    struct DLNode *head = (struct DLNode *)malloc(sizeof(struct DLNode));
    head->next = head->pre = head;
    //dlink_head_insert(head, 5);
    //dlink_head_insert(head, 7);
    //dlink_head_insert(head, 4);
    //dlink_head_insert(head, 2);
    //dlink_head_insert(head, 1);
    //dlink_head_insert(head, 6);

    dlink_tail_insert(head, 5);
    dlink_tail_insert(head, 7);
    dlink_tail_insert(head, 4);
    dlink_tail_insert(head, 2);
    dlink_tail_insert(head, 1);
    dlink_tail_insert(head, 6);

    dlink_delete(head, 6);

    struct DLNode *p = head->next;
    while(p != head)
    {
        printf("\t%d", p->data);
        p = p->next;
    }
    
    return 0;
}

//带头节点的双链表头插法
int dlink_head_insert(struct DLNode *head, int x)
{
    struct DLNode *node = (struct DLNode*)malloc(sizeof(struct DLNode));
    if(node == NULL)
        return -1;
    node->data = x;
    node->next = head->next;
    head->next->pre = node;
    head->next = node;
    node->pre = head;
    return 0;
}

//带头节点的双链表尾插法
int dlink_tail_insert(struct DLNode *head, int x)
{
    struct DLNode *node = (struct DLNode*)malloc(sizeof(struct DLNode));
    if(node == NULL)
        return -1;
    node->data = x;
    node->next = head;
    node->pre = head->pre;
    head->pre->next = node;
    head->pre = node;
    return 0;
}
    
//带头节点的双链表删除节点
int dlink_delete(struct DLNode *head, int x)
{
        struct DLNode *p = head->next;
        while(p != head && p->data != x)
        p = p->next;
    if(p == head)
    {
        printf("不存在元素%d", x);
        return -1;
    }
    if(p->data == x)
    {
        p->pre->next = p->next;
        p->next->pre = p->pre;
        free(p);
    }
    return 0;
}

//不带头节点的双链表头插法
int dlink_nh_head_insert(struct DLNode **head, int x)
{
    struct DLNode *node = (struct DLNode *)malloc(sizeof(struct DLNode));
    if(node == NULL)
        return -1;
    node->data = x;
    node->next = *head;
    if(*head)  //如果链表不为空
        (*head)->pre = node;
    *head = node;
    node->pre = NULL;
    return 0;
}

//不带头节点的双链表尾插法
int dlink_nh_tail_insert(struct DLNode **head, int x)
{
    struct DLNode *p = *head;
    struct DLNode *node = (struct DLNode *)malloc(sizeof(struct DLNode));
    if(node == NULL) 
        return -1;
    node->data = x;
    if(p == NULL)  //如果链表为空
    {
        p = node;
        node->next = NULL;
        node->pre = NULL;
        *head = node;
        return 0;
    }
    while(p->next)
        p = p->next;
    node->pre = p;
    p->next = node;
    node->next = NULL;
    return 0;
}

//不带头节点的双链表删除节点
int dlink_nh_delete(struct DLNode **head, int x)
{
    struct DLNode *p = *head;
    while(p && p->data != x)
        p = p->next;
    //如果链表中不存在x
    if(p == NULL)
    {
        printf("链表中无此元素%d", x);
        return -1;
    }
    //如果待删除节点不是第一个节点
    if(p->pre != NULL)
        p->pre->next = p->next;
    else //待删是第一个节点
        *head = p->next;

    //如果待删除节点是最后一个节点
    if(p->next != NULL)
        p->next->pre = p->pre;
    free(p);
    return 0;
}

