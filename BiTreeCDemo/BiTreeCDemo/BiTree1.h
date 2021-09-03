//
//  BiTree1.h
//  BiTreeDemo
//
//  Created by Vicent on 2019/1/9.
//  Copyright © 2019 VicentZ. All rights reserved.
//

#ifndef BiTree1_h
#define BiTree1_h

#include <stdio.h>

typedef int Status;

typedef char ElemType;

typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void testC(void);
#endif /* BiTree1_h */
