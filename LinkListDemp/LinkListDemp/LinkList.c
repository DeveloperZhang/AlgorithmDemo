//
//  LinkList.c
//  LinkListDemp
//
//  Created by Vicent on 2019/1/8.
//  Copyright © 2019 VicentZ. All rights reserved.
//

#include "LinkList.h"
#include <stdlib.h>

LinkListC linkedListInit() {
    Node *l;
    l = (Node *)malloc(sizeof(Node));
    if (l == NULL) {
        printf("申请内存空间失败");
    }
    l->next = NULL;
    return l;
}

//头插法
LinkListC LinkedListCreatH() {
    printf("头插法");
    LinkListC l = linkedListInit();
    for (int i = 0; i < 5; i++) {
        Node *p;
        p = (Node *)malloc(sizeof(Node));
        p->data = i;
        p->next = l->next;
        l->next = p;
    }
    return l->next;
}

//尾插法
LinkListC LinkedListCreatT() {
    printf("尾插法");
    LinkListC l = linkedListInit();
    LinkListC r = l;
    for (int i = 1; i < 4; i++) {
        Node *p;
        p = (Node *)malloc(sizeof(Node));
        p->data = i;
        r->next = p;
        r = p;
    }
    r->next = NULL;
    return l->next;
}

//插入
LinkListC insertLinkList(LinkListC l, int index, ElemType x) {
    Node *pre;
    pre = l;
    for (int i = 1; i < index; i++) {
        pre = pre->next;
    }
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = x;
    p->next = pre->next;
    pre->next = p;
    return l;
}

int deletelinkList(LinkListC l, ElemType x) {
    Node *p,*pre;
    p = l->next;
    pre = p;
    while (p->data!=x) {
        pre = p;
        p = p->next;
        if (p==NULL) {
            return 0;
        }
    }
    pre->next = p->next;
    free(p);
    return 1;
}

int length(LinkListC l) {
    Node *p;
    int length = 0;
    p = l;
    while (p!=NULL) {
        length++;
        p = p ->next;
    }
    return length;
}

void printLink(LinkListC l) {
    printf("\n打印LinkList,长度为%d:,数据为:\n",length(l));
    while (l != NULL) {
        printf("%d,",l->data);
        l = l->next;
    }
}

//单链表反转
LinkListC reverseLinkList(LinkListC head) {
    Node *next = NULL,*pre = NULL;
    while (head != NULL) {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}

LinkListC reverseLinkList2(LinkListC head) {
    Node *newHead;
    if (head==NULL||head->next==NULL) {
        return head;
    }
    newHead = reverseLinkList2(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

void testLinkList() {
//    LinkListC linkList = LinkedListCreatH();
    LinkListC linkList = LinkedListCreatT();
    printLink(linkList);
//    linkList = insertLinkList(linkList,2,10);
//    printLink(linkList);
//    int result = deletelinkList(linkList,10);
//    if (result == 1) {
//        printLink(linkList);
//    } else {
//        printf("删除error!");
//    }
    linkList = reverseLinkList2(linkList);
    printLink(linkList);
    
}
