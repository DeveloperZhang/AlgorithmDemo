//
//  LinkList.h
//  LinkListDemp
//
//  Created by Vicent on 2019/1/8.
//  Copyright © 2019 VicentZ. All rights reserved.
//

#ifndef LinkList_h
#define LinkList_h

#include <stdio.h>

typedef int ElemType;

typedef struct Node {
    ElemType data;
    struct Node *next;
}Node,*LinkListC;

void testLinkList(void);

#endif /* LinkList_h */
