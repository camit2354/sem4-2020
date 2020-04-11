#include <stdio.h>
#include <stdlib.h>
struct tree
{
    struct tree* left;
    int data;
    int mark;
    struct tree* right;
    int Right_Left;//for where to come or where to go in pointer reversal right 1 and left 0
}*root=NULL;
int count=0;
struct reverse
{
    struct tree* prev;
    struct tree* current;
}*reversal;
struct tree* create();
void function(struct tree* root);
 void preorder(struct tree *t);
int main()
{
    printf("Welcome To Making The Tree\n");
    root=create();
    reversal=(struct reverse*)malloc(sizeof(struct reverse));
    reversal->prev=NULL;
    reversal->current=root;
    printf("The Reversal Current Root data:%d\n",reversal->current->data);
    preorder(root);
    printf("The Value Of Count Is:%d\n",count);
    function(root);
    preorder(root);
return(0);
}
struct tree* create()
{
    struct tree *p;
    int x;
    printf("Enter data(-1 for no node):");
    scanf("%d",&x);
    if(x==-1)
	return NULL;
    p=(struct tree*)malloc(sizeof(struct tree));
    p->data=x;
    count++;
    printf("Enter left child of %d:\n",x);
    p->left=create();
    printf("Enter right child of %d:\n",x);
    p->right=create();
    return p;
}
void preorder(struct tree *t)
{
  if(t!=NULL)
  {
    printf("The Data Is:%d\t",t->data);
    printf("The Marked Value Is:%d\n",t->mark);
    preorder(t->left);
    preorder(t->right);
  }
  if(root==NULL)
     printf("The Tree Is Empty\n");
}
void function(struct tree* root)
{
    struct tree* node,*nex_revptr=NULL;
    int flag=count;
    node=root;
    while(flag>0)
    {   
         if(node->right!=NULL)
          {     
              if(node->right->mark==0)
              {
                node->Right_Left=1;
                nex_revptr=node->right;
                node->right=reversal->prev;
                reversal->prev=node;
                reversal->current=nex_revptr;
                 node=reversal->current;
                // printf("The Node line 93 Data Is:%d\n",node->data);
                if(node->left==NULL && node->right==NULL)
                {
                    node->mark=1;
                    flag=flag-1;
                    // printf("The Node line 96 Data Is:%d\n",node->data);
                     reversal->current=reversal->prev;
                    if(reversal->current->Right_Left==0)
                   { reversal->prev=reversal->current->left;
                      reversal->current->left=node;
                   }
                    else if(reversal->current->Right_Left==1)
                    {  reversal->prev=reversal->current->right;
                       reversal->current->right=node;
                    }   
                     node=reversal->current;             
                }
                // printf("The Node line 107 Data Is:%d\n",node->data);
              }        
          }
        if((node->right==NULL||node->right->mark==1)&&node->left!=NULL&&node->left->mark!=1)
          {
              node->Right_Left=0;
              nex_revptr=node->left;
            //   printf("The Node is :%d\n",node->data);
            //   printf("The Node left Is:%d\n",node->left->data);
              node->left=reversal->prev;
              reversal->prev=node;
              reversal->current=nex_revptr;
              node=reversal->current;
            //   printf("The Node line 118 Data Is:%d\n",node->data);
              if(node->left==NULL && node->right==NULL &&node->mark==0)
              {
                  node->mark=1;
                  flag=flag-1;
                  reversal->current=reversal->prev;
                    if(reversal->current->Right_Left==0)
                   { reversal->prev=reversal->current->left;
                   reversal->current->left=node;
                   }
                    else if(reversal->current->Right_Left==1)
                    {
                      reversal->prev=reversal->current->right;
                      reversal->current->right=node;
                    }     
                node=reversal->current;                
              }
            //   printf("The Node line 133 Data Is:%d\n",node->data);                     
          }
        if((node->left==NULL||node->left->mark==1)&&(node->right==NULL||node->right->mark==1))
          {
            //   printf("The Node line 137 Data Is:%d\n",node->data);
              if(node!=root)
              {
                  if(node->mark!=1)
                 {  node->mark=1;
                  flag=flag-1;
                 }
                  reversal->current=reversal->prev;
                    if(reversal->current->Right_Left==0)
                  {  reversal->prev=reversal->current->left;
                  reversal->current->left=node;
                  }
                    else if(reversal->current->Right_Left==1)
                    {
                      reversal->prev=reversal->current->right;
                      reversal->current->right=node;
                    }     
                node=reversal->current;
              }
             if(node==root)
              {
                     if(node->left!=NULL&&node->left->mark==0)
                       { 
                        reversal->current=node;
                        reversal->prev=NULL;
                       }
                      else
                      {
                        node->mark=1;
                        flag=flag-1;
                      }                 
              }
                // printf("The Node line 149 revesal->current Data Is:%d\n",reversal->current->data);
                // if(reversal->prev!=NULL)
                // printf("The Node line 149 revesal->prev Data Is:%d\n",reversal->prev->data);
                // printf("The Last Count AT the end Of LOOp is :%d\n",flag);        
          }
    }

}