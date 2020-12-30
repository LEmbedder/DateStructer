/**
 * @file SqList.c
 * @author Lembedder (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2020-12-30
 *
 * @copyright Copyright (c) 2020
 *
 */
#include "SqList.h"


Status InitList(SqList* L)
{
    L->elem = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if (L->elem == NULL) {
        // 分配内存失败
        exit(OVERFLOW);
    }
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;

    return OK;
}

Status DestroyList(SqList* L)
{
    if (L == NULL || L->elem == NULL)
        return ERROR;
    free(L->elem);
    L->elem = NULL;
    L->length = 0;
    L->listsize = 0;

    return OK;
}

Status ClearList(SqList* L)
{
    L->length = 0;

    return OK;
}
Status ListEmpty(SqList L)
{
    return L.length == 0 ? TRUE : FALSE;
}

int ListLength(SqList L)
{
    return L.length;
}

Status GetElem(SqList L, int i, ElemType* e)
{
    if(i < 1 || i > L.length) {
        return ERROR;                    //i值不合法
    }
    *e = L.elem[i - 1];

    return OK;
}

int LocateElem(SqList L, ElemType e, Status(Compare)(ElemType, ElemType))
{
    int i;
    ElemType* p;

    // 确保顺序表结构存在
    if(L.elem == NULL) {
        return ERROR;
    }

    i = 1;
    p = L.elem;
    // 遍历顺序表
    while(i <= L.length && !Compare(*p++, e)) {
        ++i;
    }

    if (i <= L.length)
        return i;
    else
        return 0;

}

Status PriorElem(SqList L, ElemType cur_e, ElemType* pre_e)
{
    int i = 0;

    // 确保顺序表结构存在，且最少包含两个元素
    if(L.elem == NULL || L.length < 2) {
        return ERROR;
    }

    for (i = 0; i < L.length; i++) {
        if (L.elem[i] == cur_e)
            break;
    }
    if (i == 0 || i >= L.length)
        return ERROR;
    else
    {
        *pre_e = L.elem[i - 1];
    }

    return OK;
}

Status NextElem(SqList L, ElemType cur_e, ElemType* next_e)
{
    int i = 0;

    // 确保顺序表结构存在，且最少包含两个元素
    if(L.elem == NULL || L.length < 2) {
        return ERROR;
    }

    for (i = 0; i < L.length; i++) {
        if (L.elem[i] == cur_e)
            break;
    }
    if (i == 0 || i >= L.length)
        return ERROR;
    else
        *next_e = L.elem[i + 1];

    return OK;
}
/**
 * @brief
 *
 * @param L
 * @param i 教材中i的含义是元素位置，从1开始计数
 * @param e
 * @return Status
 */
Status ListInsert(SqList* L, int i, ElemType e)
{
    ElemType *newbase;
    ElemType *p, *q;

    // 确保顺序表结构存在
    if (L == NULL || L->elem == NULL) {
        return ERROR;
    }

    // i值越界
    if (i < 1 || i > L->length + 1) {
        return ERROR;
    }

    if (L->length >= L->listsize) {
        newbase = realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType));
        if (newbase == NULL)
            exit(OVERFLOW);
        L->elem = newbase;
        L->listsize += LISTINCREMENT;
    }
    // q为插入位置
    q = &L->elem[i - 1];

    // 1.右移元素，腾出位置
    for(p = &L->elem[L->length - 1]; p >= q; --p) {
        *(p + 1) = *p;
    }
    // 2.插入e
    *q = e;
    // 3.表长增1
    L->length++;

    return OK;
}

Status ListDelete(SqList* L, int i, ElemType* e)
{
    ElemType *q;

    // 确保顺序表结构存在
    if (L == NULL || L->elem == NULL) {
        return ERROR;
    }

    // i值越界
    if (i < 1 || i > L->length + 1) {
        return ERROR;
    }

    // q为删除位置
    q = &L->elem[i - 1];

    *e = *q;

    // 1.右移元素，腾出位置
    for(; q < &(L->elem[L->length-1]); ++q) {
        *q = *(q+1);
    }

    // 3.表长增1
    L->length--;

    return OK;
}

void ListTraverse(SqList L, void (Visit)(ElemType))
{
    int i;
    for(i = 0; i < L.length; i++) {
        Visit(L.elem[i]);
    }

    printf("\n");
}