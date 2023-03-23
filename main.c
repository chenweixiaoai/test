#include <stdio.h>
#include <dirent.h>
#include "headselist.h"


int main()
{
    DATATYPE data[]={
        {"zhangsan",'f',20,90},
        {"lisi",'m',21,89},
        {"wangmazi",'f',22,96},
        {"liubei",'m',30,70},
        {"zhangfei",'f',20,80},
    };

    LinkList * ll = CreateLinkList();

    InsertHeadLinkList(ll,&data[0]);
    InsertHeadLinkList(ll,&data[1]);
    InsertTailLinkList(ll,&data[2]);

    LinkNode * temp = FindLinkList(ll,"lisi");
    if(NULL == temp)
    {
        printf("can't find\n");
    }
    else
    {
         printf(" find it\n");
    }
    ShowLinkList(ll);

    DeleteLinkList(ll,"lisi");
    printf("--------del---------\n");
     ShowLinkList(ll);

     DestroyLinkList(&ll);


    printf("Hello World!\n");



    return 0;
}

