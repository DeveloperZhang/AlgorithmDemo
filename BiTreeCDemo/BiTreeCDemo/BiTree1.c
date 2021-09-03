//
//  BiTree1.c
//  BiTreeDemo
//
//  Created by Vicent on 2019/1/9.
//  Copyright © 2019 VicentZ. All rights reserved.
//

#include "BiTree1.h"

#include <stdio.h>
#include <stdlib.h>

void createBiTree(BiTree *t) {
    ElemType ch;
    scanf("%c",&ch);
    if (ch == '#') {
        *t = NULL;
        return;
    } else {
        *t = (BiTree)malloc(sizeof(BiTNode));
        (*t)->data = ch;
        createBiTree(&(*t)->lchild);
        createBiTree(&(*t)->rchild);
    }
}

//前序遍历
void preOrderTraverse(BiTree t) {
    if (t==NULL) {
        return;
    }
    printf("%c",t->data);
    preOrderTraverse(t->lchild);
    preOrderTraverse(t->rchild);
}

//中序遍历
void inOrderTraverse(BiTree t) {
    if (t==NULL) {
        return;
    }
    preOrderTraverse(t->lchild);
    printf("%c",t->data);
    preOrderTraverse(t->rchild);
}

//后序遍历
void postOrderTraverse(BiTree t) {
    if (t==NULL) {
        return;
    }
    preOrderTraverse(t->lchild);
    preOrderTraverse(t->rchild);
    printf("%c",t->data);
}

void testC() {
    BiTree t;
    createBiTree(&t);
//    inOrderTraverse(t);
//    preOrderTraverse(t);
    postOrderTraverse(t);
}
