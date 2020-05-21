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
          printf("\n data : %d , marked_status : %d\n ", root->data,root->mark); // printing data at root
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
         if(marker->prev != NULL)
         printf("\n before ===)   prev->data :%d  curr->data %d",marker->prev->data,marker->curr->data);
        else
        { printf("\n before ===)   prev->data :NULL  curr->data %d",marker->curr->data);
        }
        
       
        node *ptr = marker->curr;

        if(ptr->mark == 1)
        {
            if((marker->prev)->data > (marker->curr)->data)
            {
                 if(marker->curr->right == NULL)
                 {
                    node *temp;
                    temp = marker->curr->left;
                    marker->curr->left = marker->prev;
                    marker->prev = marker->curr;
                    marker->curr =temp; 

                    

                 }
                 else
                 {
                      node *temp1,*temp2;
                      temp1 = marker->prev;
                      temp2 = marker->curr->left;
                       marker->curr = marker->curr->right;
                      marker->curr->right = temp2;
                      marker->curr->left = temp1;
                      marker->prev = temp1;


                     
                 }
                                

            }
            else
            {
                
                    node *temp;
                    temp = marker->prev;
                     marker->prev = marker->curr;
                     marker->curr->left = temp;
                    marker->curr = marker->curr->right;                  
                    

            }
            

        }
        else
        {

            if( ptr->left !=NULL  && ptr->right != NULL) 
            {
                                        
                    (marker->curr)->mark =1;
                    node *temp;
                    temp = marker->curr;
                    marker->curr = marker->curr->left;
                   temp->left= marker->prev;
                    marker->prev =temp;           
            
            
            }
            else if(ptr->left !=NULL  &&  ptr->right == NULL )
            {
                                    
                    (marker->curr)->mark =1;                
                    node *temp;
                    temp = marker->curr;
                    marker->curr = marker->curr->left;
                    temp->left = marker->prev;
                    marker->prev =temp;
            
                
            
            }
            else if(ptr->left ==NULL && ptr->right != NULL )
            {                  
                    (marker->curr)->mark =1;                
                    node *temp;
                    temp = marker->curr;
                    marker->curr = marker->curr->right;
                    temp->right = marker->prev;
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
                                node *temp1,*temp2;
                                temp1 = marker->prev->left;
                                temp2 = marker->curr;
                                marker->curr = (marker->prev)->right;
                                marker->prev->left =temp2;
                                marker->prev->right = temp1;
                                
                                                            
                                
                            }
                            

                        }
                        else
                        {
                                (marker->curr)->mark = 1;
                                node *temp;
                                temp = (marker->curr);
                                (marker->curr) = (marker->prev)->right;
                                (marker->prev)->right = temp;

                        }

                }
            }
                       
            
        }
        
            
       
        
     }

       printf("\n root data : %d ,root->left :%p root->right :%p \n ", root->data,root->left,root->right);
       printf("\n left data : %d ,left->left :%p left->right:%p\n ", root->left->data,root->left->left,root->left->right);
       printf("\n right data : %d ,right->left%p : right->right :%p\n ", root->right->data,root->right->left,root->right->right);
       printf("\n left left data : %d ,left left ->left:%p left left ->right:%p \n ", (root->left)->left->data,(root->left)->left->left,(root->left)->left->right);


        preorder(root->right);   
       printf("\n");
     
           
        

     


}



int main()
{
   
     node *root;
    root = new_node(50);
    insert(root,40);
    insert(root,60);
    insert(root,30);
    // insert(root,20);
    // insert(root,10);
    // insert(root,55);
    // insert(root,65);
    // insert(root,45);
    // insert(root,35);
    // insert(root,70);
    // insert(root, 75);
    // insert(root, 25);

   mark(root);
    // preorder(root);   
    //    printf("\n");

    return 0;
}
