#include <stdio.h>
#include <stdlib.h>

typedef struct nodetag
{
    int data;
    int mark; 
    struct nodetag *right; 
    struct nodetag *left; 
}node;


typedef struct markertag
{
    node *prev ,*curr;
}markertype;

node* search(node *root, int x)
{
    if(root==NULL || root->data==x) 
        return root;
    else if(x>root->data)
        return search(root->right, x);
    else
        return search(root->left,x);
}

//function to create a node
node* new_node(int x)
{
    node *p;
    p = malloc(sizeof(node));
    p->data = x;
    p->mark = 0;
    p->left = NULL;
    p->right = NULL;

    return p;
}

node* insert(node *root, int x)
{
    //searching for the place to insert
    if(root==NULL)
        return new_node(x);
    else if(x>root->data) // x is greater. Should be inserted to right
        root->right = insert(root->right, x);
    else // x is smaller should be inserted to left
        root->left = insert(root->left,x);
    return root;
}

void preorder(node *root)
{
    if(root!=NULL) // checking if the root is not null
    {
          printf(" %d ", root->data); // printing data at root
        preorder(root->left); // visiting left child       
        preorder(root->right);// visiting right child
    }
}



void mark(node *root)
{
       markertype *marker = (markertype *)malloc(sizeof(markertype));
       marker->prev = NULL;
       marker->curr = root;

       preorder(root);   
       printf("\n");

     while(marker->curr!=NULL)
     {
        node *ptr = marker->curr;

        if(ptr->mark == 1)
        {
            if((marker->prev)->data > (marker->curr)->data)
            {
                node *ahead =marker->curr->left;

                if(ahead->data < marker->curr->data)
                {
                    node *temp;
                    temp = marker->curr->left;
                    marker->curr->left = marker->prev;
                    marker->prev = marker->curr;
                    marker->curr =temp;

                }
                else
                {
                      node *temp;
                    temp = marker->curr->left;
                    marker->curr->left = marker->prev;
                    marker->prev = marker->curr;
                    marker->curr =temp;
                }
                

            }
            else
            {
                node *ahead = marker->curr->right;

                if(ahead->data < marker->curr->data)
                {
                    node *temp;
                    temp = marker->curr->right;
                    marker->curr->right = marker->prev;
                    marker->prev = marker->curr;
                    marker->curr =temp;

                }
                else
                {
                    node *temp;
                    temp = marker->curr->right;
                    marker->curr->right = marker->prev;
                    marker->prev = marker->curr;
                    marker->curr =temp;
                }
                
            }
            

        }
        else
        {

            if( ptr->left !=NULL  && ptr->right != NULL) 
            {
                                        
                    (marker->curr)->mark =1;
                    node *temp;
                    temp = marker->curr;
                    marker->curr = ptr->left;
                    ptr->left = marker->prev;
                    marker->prev =temp;           
            
            
            }
            else if(ptr->left !=NULL  &&  ptr->right == NULL )
            {
                                    
                    (marker->curr)->mark =1;                
                    node *temp;
                    temp = marker->curr;
                    marker->curr = ptr->left;
                    ptr->left = marker->prev;
                    marker->prev =temp;
            
                
            
            }
            else if(ptr->left ==NULL && ptr->right != NULL )
            {                  
                    (marker->curr)->mark =1;                
                    node *temp;
                    temp = marker->curr;
                    marker->curr = ptr->right;
                    ptr->right = marker->prev;
                    marker->prev =temp;                           


            
            }
            else
            {

                if(marker->prev == NULL)
                {
                    (marker->curr)->mark =1;
                }
                else
                {

                        if(marker->prev->data > marker->curr->data)
                        {
                            if((marker->prev)->right == NULL)
                            {
                                (marker->curr)->mark =1;
                                node *temp;
                                temp = marker->curr;
                                marker->curr = (marker->prev)->left;
                                (marker->prev)->left = temp;
                            }
                            else
                            {
                                (marker->curr)->mark =1;
                                node *temp;
                                temp = marker->curr;
                                marker->curr = (marker->prev)->right;
                                (marker->prev)->right = temp;
                                                            
                                
                            }
                            

                        }
                        else
                        {
                                (marker->curr)->mark =1;
                                node *temp;
                                temp = (marker->curr);
                                (marker->curr) = (marker->prev)->right;
                                (marker->prev)->right = temp;

                        }

                }
            }
                       
            
        }
        

       
            
           
        
        
     }

      preorder(root);   
       printf("\n");

}



int main()
{
   
     node *root;
    root = new_node(50);
    insert(root,40);
    insert(root,30);
    insert(root,20);
    insert(root,10);
    insert(root,55);
    insert(root,65);
    insert(root,45);
    insert(root,35);
    insert(root,70);
    insert(root, 75);
    insert(root, 25);

   mark(root);

    return 0;
}
