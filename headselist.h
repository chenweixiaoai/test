#ifndef HEADSELIST_H
#define HEADSELIST_H

typedef struct person {
    char name[32];
    char sex;
    int age;
    int score;
}DATATYPE;

typedef struct node {
    DATATYPE data;
    struct node *next;
}LinkNode;

typedef struct list {
    LinkNode *head;
    int clen;
}LinkList;


LinkList *CreateLinkList();
int InsertHeadLinkList(LinkList *list, DATATYPE *data);
int ShowLinkList(LinkList *list);
LinkNode *FindLinkList(LinkList *list, char *name);
int DeleteLinkList(LinkList *list, char *name);
int ModifyLinkList(LinkList *list, char *name, DATATYPE* data);
int DestroyLinkList(LinkList **list);
int InsertTailLinkList(LinkList *list, DATATYPE *data);
int LinkListGetSize(LinkList *list);










#endif // HEADSELIST_H
