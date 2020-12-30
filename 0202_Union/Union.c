#include "Union.h"


void Union(SqList* La, SqList Lb)
{
    int La_len, Lb_len;
    int i;
    ElemType e;

    // 求顺序表长度
    La_len = ListLength(*La);
    Lb_len = ListLength(Lb);

    for(i = 1; i <= Lb_len; i++) {
        // 取Lb中第i个元素赋给e
        GetElem(Lb, i, &e);

        // 若e不在La中则插入
        if (!LocateElem(*La, e, equal)) {
            ListInsert(La, ++La_len, e);
        }
    }
}


Status equal(ElemType e1, ElemType e2)
{
    return e1 == e2 ? TRUE : FALSE;
}