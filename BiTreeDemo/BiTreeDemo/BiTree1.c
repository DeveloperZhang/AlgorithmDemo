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
    
    scanf("%d",&ch);
    
    if(ch=='#')      //#代表这个节点没有子树。
        *t=NULL;
    else
    {
        *t=(BiTree)malloc(sizeof(BiTNode));          //malloc生成一个内存空间并且强制转化为BiTree类型，类似new的作用。
        (*t)->data=ch; /* 生成根结点 */
        createBiTree(&(*t)->lchild); /* 构造左子树 */
        createBiTree(&(*t)->rchild); /* 构造右子树 */      //函数参数的传递是单向值传递，当我们是需要改变一个指针的值时，就需要用二重指针做参。
        //如果我们只传递进去一个一个指向节点的指针，调用结束后，这个指针的值是不会改变的。
    }
}

void testC() {
    BiTree *t = NULL;
    createBiTree(t);
    printf("");
}
