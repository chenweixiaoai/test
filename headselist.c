#include "headselist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
LinkList *CreateLinkList()
{
    LinkList *ll = malloc(sizeof(LinkList));

    if (NULL == NULL)
    {
        perror("linklist create error");
        return NULL;
    }

    ll->clen = 0;
    ll->head = NULL;

    return ll;

}
int InsertHeadLinkList(LinkList *list,DATATYPE *data)
{
    LinkNode *newnode = malloc(sizeof(LinkNode));
    if (NULL == newnode)
    {
        perror("insert newnode error");
        return -1;
    }

    memcpy(&newnode->data,data,sizeof(DATATYPE));
    newnode->next = NULL;

    if (NULL == list->head)
    {
        list->head = newnode;
    }
    else
    {
        newnode->next = list->head;
        list->head = newnode;
    }

    list->clen++;

    return 0;
}

int ShowLinkList(LinkList *list)
{
    LinkNode *temp = list->head;

    if (temp == NULL)
    {
        printf("can't find the list");
        return -1;
    }

    while(temp)
    {

        printf("name:%s sex:%s age:%d score:%d\n",temp->data.name,temp->data.sex,temp->data.age,temp->data.score);

        temp = temp->next;
    }

    return 0;
}

int LinkListGetSize(LinkList *list)
{
    return list->clen;
}

LinkNode *FindLinkList(LinkList *list,char *name)
{
    LinkNode* temp = list->head;
    if (NULL == temp)
    {
        printf("can;t find the list");
        return NULL;
    }

    while(temp)
    {
        if (0 == strcmp(name,temp->data.name))
        {
            return temp;
        }
        else
        {
            temp = temp->next;
        }
    }

    return NULL;
}

int DeleteLinkList(LinkList *list,char *name)
{
    LinkNode *temp = list->head;
    LinkNode *prev = NULL;
    while(temp)
    {
        if (0 != strcmp(name,temp->data.name))
        {
            prev = temp;
        }
        else
        {
            if (NULL == prev)
            {
                list->head = list->head->next;
            }
            else
            {
                prev->next = temp->next;

            }
            free(temp);
            list->clen--;
            break;
        }

     temp = temp->next;
    }

    return 0;
}

int ModifyLinkList(LinkList *list,char *name,DATATYPE *data)
{
    LinkNode *node = FindLinkList(list,name);
    if (NULL == node)
    {
        perror("can't find the node");
        return -1;
    }
    memcpy(&node->data.name,name,sizeof(DATATYPE));

    return 0;
}

int DestoryLinkList(LinkList **list)
{
    LinkNode *temp = (*list)->head;

    while(temp)
    {
        (*list)->head = (*list)->head->next;
        free(temp);
        temp = (*list)->head;
    }
    free(*list);
    *list = NULL;
    return 0;
}

int InserTailLinkList(LinkList *list,DATATYPE *data)
{
   if (NULL == list)
   {
       InsertHeadLinkList(list,data);
       return 0;
   }
   else
   {
       LinkNode *tail = malloc(sizeof(LinkNode));
       LinkNode *temp = list->head;
       if (NULL == tail)
       {
           perror("create tail fail");
           return 0;
       }

       memcpy(&tail->data,data,sizeof(DATATYPE));

       while(temp)
       {
           if (NULL == temp->next)
           {
               temp->next = tail;
               tail->next = NULL;
               list->clen++;
               break;
           }
           temp = temp->next;
       }

   }

   return 0;
}




























