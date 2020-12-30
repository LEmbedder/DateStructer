#include "MergeSqList.h"

void MergeSqList_1(SqList La, SqList Lb, SqList* Lc)
{
    int La_len, Lb_len;
    int i,k,j;
    ElemType ai, bj;

    InitList(Lc);

    // 获取La、Lb的长度
    La_len = ListLength(La);
    Lb_len = ListLength(Lb);
    i = j = 1;
    k = 0;
    // La Lb都有元素
    while(i < La.length && j < Lb.length) {
        GetElem(La,i,&ai);
        GetElem(Lb,j,&bj);

        // 比较遍历到的元素，先将比较小的元素加入顺序表Lc
        if(ai <= bj) {
            ListInsert(Lc, ++k, ai);
            i++;
        } else {
            ListInsert(Lc, ++k, bj);
            j++;
        }

    }

    // 如果Lb已遍历完，但La还未遍历完，将La中剩余元素加入Lc
    while(i <= La_len) {
        GetElem(La, i++, &ai);
        ListInsert(Lc, ++k, ai);
    }

    // 如果La已遍历完，但Lb还未遍历完，将Lb中剩余元素加入Lc
    while(j <= Lb_len) {
        GetElem(Lb, j++, &bj);
        ListInsert(Lc, ++k, bj);
    }
}

void MergeSqList_2(SqList La, SqList Lb, SqList* Lc)
{
    ElemType *pa, *pb, *pc;
    ElemType *pa_last, *pb_last;

    pa = La.elem;                        // 指向La第一个元素
    pb = Lb.elem;                        // 指向Lb第一个元素

    // 没有使用InitList创建Lc
    (*Lc).listsize = (*Lc).length = La.length + Lb.length;
    pc = (*Lc).elem = (ElemType*) malloc((*Lc).listsize * sizeof(ElemType));
    if (pc == NULL) {
        exit(OVERFLOW);
    }

    pa_last = La.elem + La.length - 1;    // 指向La最后一个元素
    pb_last = Lb.elem + Lb.length - 1;    // 指向Lb最后一个元素

    // 如果La及Lb均未遍历完
    while(pa <= pa_last && pb <= pb_last) {
        if(*pa <= *pb) {
            *pc++ = *pa++;
        } else {
            *pc++ = *pb++;
        }
    }

    // 如果Lb已遍历完，但La还未遍历完，将La中剩余元素加入Lc
    while(pa <= pa_last) {
        *pc++ = *pa++;
    }

    // 如果La已遍历完，但Lb还未遍历完，将Lb中剩余元素加入Lc
    while(pb <= pb_last) {
        *pc++ = *pb++;
    }
}