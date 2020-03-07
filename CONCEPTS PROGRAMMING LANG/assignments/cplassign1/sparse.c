#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define ROWMAX 10
#define COLMAX 10

typedef struct nodetag
{
    int data;
    int row;
    int col;
    struct nodetag *right;       
    struct nodetag *down;
}nodetype;

typedef struct sparsetag
{
    nodetype *rowptrs[ROWMAX];
    nodetype *colptrs[COLMAX];
    
}sparsetype;

void assign(nodetype *newptr ,sparsetype *sptr)
{ int i=newptr->row;
  int j=newptr->col;

  nodetype *rptr=sptr->rowptrs[i];
  nodetype *cptr=sptr->colptrs[j];

  nodetype *ptr1=NULL,*ptr2=NULL;

  if(rptr==NULL)
  {
      rptr=newptr;
       if(cptr=NULL)
       {
           cptr=newptr;
       }
       else
       {  ptr1=cptr;
          ptr2=ptr1;

          while((ptr1->row<i)&&(ptr1!=NULL))
          {
              ptr1=ptr1->down;

          }

          while (ptr2->down!=ptr1)
          {
              ptr2=ptr2->down;
          }
          
          ptr2->down=newptr;
          newptr->down=ptr1;

          ptr1=NULL;
          ptr2=NULL;
        
       }
      
       
  }
   else
       {
             ptr1=rptr;
             ptr2=ptr1;

          while((ptr1->col<j)&&(ptr1!=NULL))
          {
              ptr1=ptr1->down;

          }

          while (ptr2->right!=ptr1)
          {
              ptr2=ptr2->right;
          }
          
          ptr2->right=newptr;
          newptr->right=ptr1;

          ptr1=NULL;
          ptr2=NULL;
        
        
       }
       

}



