#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct nodetag
{
    char pname;
    int priority;
    struct nodetag *next;
}nodetype;

typedef struct pqtag
{
   nodetype *arr[10];
}pqtype;

void initialize(pqtype *pqptr)
{
   for(int i=0;i<10;i++)
   {
       pqptr->arr[i]=NULL;
   }
}

nodetype *makenode(char pname,int priority)
{
  nodetype *newptr=(nodetype *)malloc(sizeof(nodetype));
  newptr->pname=pname;
  newptr->priority=priority;
  newptr->next=NULL;

  return newptr;
}


void insert(nodetype *newptr,pqtype *pqptr)
{ int i=newptr->priority;
  nodetype *ptr=pqptr->arr[i];

    if(ptr==NULL)
    {
        ptr=newptr;
    }
    else
    {
       while(ptr->next!=NULL)
       {
           ptr=ptr->next;

       }
       ptr->next=newptr;
    }  


}

char delete(pqtype *pqptr)
{  int i=0;
   char retpname;
   nodetype *fptr=NULL;
  while (pqptr->arr[i]==NULL)
  {
    i++;
  }

  retpname=pqptr->arr[i]->pname;
  fptr=pqptr->arr[i];
  pqptr->arr[i]=pqptr->arr[i]->next;
  free(fptr);
  

}