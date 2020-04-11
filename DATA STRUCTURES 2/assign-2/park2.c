#include<stdio.h>
#include<string.h>
#define max_vehicle 3


typedef struct mapped_tree_node_tag
{
     int wing_id;
     int flat_id;
     int dedicated_parking_wing;
     int compact_spot_index;
     int large_spot_index;
     char vehicle_number[9];
     struct mapped_tree_node_tag *left ,*right;


     int key;
     int height;    

}mapped_tree_node_type;

typedef struct vehicle_map_info_tag
{
      char vehicle_number[9];
      mapped_tree_node_type *ptr;

}vehicle_map_info_type;

typedef struct flat_info_tag
{
    int wing_id;
    int flat_id; 

     int  no_of_two_wheelers;
     int no_of_four_wheelers;
      int total_no_of_vehicles;
      
    vehicle_map_info_type vehicle_map_arr[max_vehicle];
      struct flat_info_tag *left ,*right;

     int key;
     int height;


}flat_info_type;




int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 

int height_mapped_tree(mapped_tree_node_type *nodeptr) 
{ 
    if (nodeptr == NULL) 
        return 0; 
    return nodeptr->height; 
} 

int height_file_info_tree(flat_info_type *nodeptr) 
{ 
    if (nodeptr == NULL) 
        return 0; 
    return nodeptr->height; 
} 


mapped_tree_node_type *rightRotate_mapped_tree(mapped_tree_node_type *y) 
{ 
    mapped_tree_node_type *x = y->left; 
    mapped_tree_node_type *T2 = x->right; 
  
    // Perform rotation 
    x->right = y; 
    y->left = T2; 
  
    // Update heights 
    y->height = max(height(y->left), height(y->right))+1; 
    x->height = max(height(x->left), height(x->right))+1; 
  
    // Return new root 
    return x; 
} 
  
// A utility function to left rotate subtree rooted with x 
// See the diagram given above. 
mapped_tree_node_type *leftRotate_mapped_tree(mapped_tree_node_type *x) 
{ 
    mapped_tree_node_type *y = x->right; 
    mapped_tree_node_type *T2 = y->left; 
  
    // Perform rotation 
    y->left = x; 
    x->right = T2; 
  
    //  Update heights 
    x->height = max(height(x->left), height(x->right))+1; 
    y->height = max(height(y->left), height(y->right))+1; 
  
    // Return new root 
    return y; 
} 
  
// Get Balance factor of node N 
int getBalance_mapped_tree(mapped_tree_node_type *N) 
{ 
    if (N == NULL) 
        return 0; 
    return height(N->left) - height(N->right); 
} 

flat_info_type *rightRotate_flat_info_tree(flat_info_type *y) 
{ 
    flat_info_type *x = y->left; 
    flat_info_type *T2 = x->right; 
  
    // Perform rotation 
    x->right = y; 
    y->left = T2; 
  
    // Update heights 
    y->height = max(height(y->left), height(y->right))+1; 
    x->height = max(height(x->left), height(x->right))+1; 
  
    // Return new root 
    return x; 
} 
  
// A utility function to left rotate subtree rooted with x 
// See the diagram given above. 
flat_info_type *leftRotate_flat_info_tree(flat_info_type *x) 
{ 
    flat_info_type *y = x->right; 
    flat_info_type *T2 = y->left; 
  
    // Perform rotation 
    y->left = x; 
    x->right = T2; 
  
    //  Update heights 
    x->height = max(height(x->left), height(x->right))+1; 
    y->height = max(height(y->left), height(y->right))+1; 
  
    // Return new root 
    return y; 
} 
  
// Get Balance factor of node N 
int getBalance_flat_info_tree(flat_info_type *N) 
{ 
    if (N == NULL) 
        return 0; 
    return height(N->left) - height(N->right); 
} 


mapped_tree_node_type *insert_mapped_tree(mapped_tree_node_type * node,mapped_tree_node_type *newNode) 
{ int key = newNode->vehicle_number[5]*1000+newNode->vehicle_number[6]*100+newNode->vehicle_number[7]*10+newNode->vehicle_number[8]*1;

    /* 1.  Perform the normal BST insertion */
    if (node == NULL) 
        return newNode; 
  
    if (key < node->key) 
        node->left  = insert(node->left , newNode); 
    else if (key > node->key) 
        node->right = insert(node->right , newNode); 
    else // Equal keys are not allowed in BST 
        return node; 
  
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left), 
                           height(node->right)); 
  
    /* 3. Get the balance factor of this ancestor 
          node to check whether this node became 
          unbalanced */
    int balance = getBalance(node); 
  
    // If this node becomes unbalanced, then 
    // there are 4 cases 
  
    // Left Left Case 
    if (balance > 1 && key < node->left->key) 
        return rightRotate(node); 
  
    // Right Right Case 
    if (balance < -1 && key > node->right->key) 
        return leftRotate(node); 
  
    // Left Right Case 
    if (balance > 1 && key > node->left->key) 
    { 
        node->left =  leftRotate(node->left); 
        return rightRotate(node); 
    } 
  
    // Right Left Case 
    if (balance < -1 && key < node->right->key) 
    { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 
  
    /* return the (unchanged) node pointer */
    return node; 
} 


flat_info_type *insert_flat_info_tree(flat_info_type * node,flat_info_type * newNode) 
{  int key = (newNode->wing_id)*100 + newNode->flat_id;
    /* 1.  Perform the normal BST insertion */
    if (node == NULL) 
        return newNode; 
  
    if (key < node->key) 
        node->left  = insert(node->left,newNode); 
    else if (key > node->key) 
        node->right = insert(node->right,newNode);
    else // Equal keys are not allowed in BST 
        return node; 
  
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left), 
                           height(node->right)); 
  
    /* 3. Get the balance factor of this ancestor 
          node to check whether this node became 
          unbalanced */
    int balance = getBalance(node); 
  
    // If this node becomes unbalanced, then 
    // there are 4 cases 
  
    // Left Left Case 
    if (balance > 1 && key < node->left->key) 
        return rightRotate(node); 
  
    // Right Right Case 
    if (balance < -1 && key > node->right->key) 
        return leftRotate(node); 
  
    // Left Right Case 
    if (balance > 1 && key > node->left->key) 
    { 
        node->left =  leftRotate(node->left); 
        return rightRotate(node); 
    } 
  
    // Right Left Case 
    if (balance < -1 && key < node->right->key) 
    { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 
  
    /* return the (unchanged) node pointer */
    return node; 
} 


mapped_tree_node_type  *new_mapped_tree_node();
vehicle_map_info_type  *new_vehicle_map_info_node();
flat_info_type *new_flat_info_node();


flat_info_type *add_flat_info(mapped_tree_node_type **mapped_tree_pptr, flat_info_type **flat_info_tree_pptr);
void map_vehicle_Node();

void park_vehicle();
void Remove_vehicle_node ();

 void Display_Visitors();
void  Parking_status ();

flat_info_type *create_flat_info_tree(mapped_tree_node_type **,flat_info_type **);




void main()
{
   mapped_tree_node_type **mapped_tree_pptr;
   mapped_tree_node_type *mapped_tree_ptr =NULL;

   flat_info_type **flat_info_tree_pptr;
   flat_info_type *flat_info_tree_ptr=NULL;
   
  create_flat_info_tree(mapped_tree_pptr,flat_info_tree_pptr);

  flat_info_tree_ptr = *flat_info_tree_pptr;
  mapped_tree_ptr = *mapped_tree_pptr;

  return ;
}


flat_info_type *create_flat_info_tree(mapped_tree_node_type **mapped_tree_pptr, flat_info_type **flat_info_tree_pptr)
{  
   mapped_tree_node_type **mapped_tree_pptr_dummy;
   flat_info_type **flat_info_tree_pptr_dummy;

   mapped_tree_pptr_dummy =mapped_tree_pptr;
   flat_info_tree_pptr_dummy =flat_info_tree_pptr;

    for(int i=0;i<2;i++)
    {
       add_flat_info(mapped_tree_pptr_dummy,flat_info_tree_pptr_dummy);
       *mapped_tree_pptr = *mapped_tree_pptr_dummy;
       *flat_info_tree_pptr = *flat_info_tree_pptr_dummy;

    }


}

flat_info_type *add_flat_info(mapped_tree_node_type **mapped_tree_pptr, flat_info_type **flat_info_tree_pptr)
{
    mapped_tree_node_type *mapped_tree_ptr = *mapped_tree_pptr;
     flat_info_type *flat_info_tree_ptr = *flat_info_tree_pptr;

    flat_info_type *newNode = new_flat_info_node();

}