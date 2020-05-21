#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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



typedef struct flat_info_tag
{
    int wing_id;
    int flat_id; 

     int  no_of_two_wheelers;
     int no_of_four_wheelers;
     int total_no_of_vehicles;      
    
    char vehicle_number[max_vehicle][9];
    struct flat_info_tag *left ,*right;

     int key;
     int height;


}flat_info_type;


typedef struct available_map_space_tag
{
    int compact_space[3];
    int large_space[3];

    
}available_map_space_type;



flat_info_type *create_flat_info_tree(available_map_space_type **map_space_pptr,mapped_tree_node_type **,flat_info_type **);
flat_info_type *add_flat_info(available_map_space_type **map_space_pptr,mapped_tree_node_type **mapped_tree_pptr, flat_info_type **flat_info_tree_pptr);

available_map_space_type *new_available_map_space();


int max(int a, int b);

int height_mapped_tree(mapped_tree_node_type *nodeptr) ;
mapped_tree_node_type *rightRotate_mapped_tree(mapped_tree_node_type *y) ;
mapped_tree_node_type *leftRotate_mapped_tree(mapped_tree_node_type *x) ;
int getBalance_mapped_tree(mapped_tree_node_type *N) ;
mapped_tree_node_type *insert_mapped_tree(mapped_tree_node_type * node,mapped_tree_node_type *newNode);



int height_file_info_tree(flat_info_type *nodeptr) ;
flat_info_type *rightRotate_flat_info_tree(flat_info_type *y);
flat_info_type *leftRotate_flat_info_tree(flat_info_type *x) ;
int getBalance_flat_info_tree(flat_info_type *N);
flat_info_type *insert_flat_info_tree(flat_info_type * node,flat_info_type * newNode) ;

mapped_tree_node_type  *new_mapped_tree_node(int wing_id,int dedicated_parking_wing ,int flat_id,int vehicle_type ,int index,char vehicleArr[]);
flat_info_type *new_flat_info_node();


void preOrderMappedTree(mapped_tree_node_type *root) ;
void preOrderFlatInfoTree(flat_info_type *root);
void map_vehicle_Node();
void park_vehicle();
void Remove_vehicle_node ();
 void Display_Visitors();
void  Parking_status ();


void main()
{
  //  available_map_space_type **map_space_pptr = NULL;
    available_map_space_type *map_space_ptr = new_available_map_space();
    
  mapped_tree_node_type *mapped_tree_ptr =NULL;
   mapped_tree_node_type **mapped_tree_pptr =&mapped_tree_ptr;
   
  flat_info_type *flat_info_tree_ptr=NULL;
   flat_info_type **flat_info_tree_pptr = &flat_info_tree_ptr;
   
   
  create_flat_info_tree(&map_space_ptr,mapped_tree_pptr,flat_info_tree_pptr);

  flat_info_tree_ptr = *flat_info_tree_pptr;
  mapped_tree_ptr = *mapped_tree_pptr;

 // preOrderMappedTree(mapped_tree_ptr);
  preOrderFlatInfoTree(flat_info_tree_ptr);
  return ;
}

/*   ................... preorder function..................*/
void preOrderMappedTree(mapped_tree_node_type *root) 
{ 
    if(root != NULL) 
    { 
        printf("\n vehicle number =%s , key =%d ", root->vehicle_number,root->key); 
        preOrderMappedTree(root->left); 
        preOrderMappedTree(root->right); 
    } 
} 

void preOrderFlatInfoTree(flat_info_type *root)
{  printf("\n i am in function preOrderFlatInfoTree\n");
    if(root != NULL) 
    { 
        printf(" \n wing id=%d, flat id =%d key =%d", root->wing_id,root->flat_id,root->key); 
        preOrderFlatInfoTree(root->left); 
        preOrderFlatInfoTree(root->right); 
    } 

}

/*   ................... create_flat_info_tree..................*/

flat_info_type *create_flat_info_tree(available_map_space_type **map_space_pptr,mapped_tree_node_type **mapped_tree_pptr, flat_info_type **flat_info_tree_pptr)
{  printf("\n i am in function create_flat_info_tree \n");
   mapped_tree_node_type **mapped_tree_pptr_dummy;
   flat_info_type **flat_info_tree_pptr_dummy;
   available_map_space_type **map_space_pptr_dummy;

   mapped_tree_pptr_dummy =mapped_tree_pptr;
   flat_info_tree_pptr_dummy =flat_info_tree_pptr;
   map_space_pptr_dummy = map_space_pptr;

    for(int i=0;i<2;i++)
    {
       add_flat_info(map_space_pptr_dummy,mapped_tree_pptr_dummy,flat_info_tree_pptr_dummy);
       *mapped_tree_pptr = *mapped_tree_pptr_dummy;
       *flat_info_tree_pptr = *flat_info_tree_pptr_dummy;
        *map_space_pptr_dummy = *map_space_pptr;

    }


}

/*   ................... */
flat_info_type *add_flat_info(available_map_space_type **map_space_pptr,mapped_tree_node_type **mapped_tree_pptr, flat_info_type **flat_info_tree_pptr)
{  printf("\n i am in function add_flat_info \n");
    int i,j;
   int dedicated_parking_wing;
   // mapped_tree_node_type *mapped_tree_ptr = *mapped_tree_pptr;
     flat_info_type *flat_info_tree_ptr = *flat_info_tree_pptr;

    flat_info_type *newNode = new_flat_info_node();
    *flat_info_tree_pptr = insert_flat_info_tree(*flat_info_tree_pptr , newNode);

   for( i=0;i<newNode->no_of_two_wheelers;i++)
   {   

       if((*map_space_pptr)->compact_space[newNode->wing_id -1] <36)
       {
                dedicated_parking_wing = newNode->wing_id;
                mapped_tree_node_type *newMappedTreeNode = new_mapped_tree_node(newNode->wing_id,dedicated_parking_wing,newNode->flat_id,2,(*map_space_pptr)->compact_space[dedicated_parking_wing-1],newNode->vehicle_number[i]);
                (*map_space_pptr)->compact_space[dedicated_parking_wing-1] = (*map_space_pptr)->compact_space[dedicated_parking_wing-1] +1;
               *mapped_tree_pptr = insert_mapped_tree(*mapped_tree_pptr , newMappedTreeNode);

      
       }
       else if ((*map_space_pptr)->compact_space[(newNode->wing_id)%3] <36)
       {

                dedicated_parking_wing = (newNode->wing_id)%3 +1;
                mapped_tree_node_type *newMappedTreeNode = new_mapped_tree_node(newNode->wing_id,dedicated_parking_wing,newNode->flat_id,2,(*map_space_pptr)->compact_space[dedicated_parking_wing-1],newNode->vehicle_number[i]);
                (*map_space_pptr)->compact_space[dedicated_parking_wing-1] = (*map_space_pptr)->compact_space[dedicated_parking_wing-1] +1;
                  *mapped_tree_pptr = insert_mapped_tree(*mapped_tree_pptr , newMappedTreeNode);

       }
       else if ((*map_space_pptr)->compact_space[(newNode->wing_id +1)%3] <36)
       {

           dedicated_parking_wing = (newNode->wing_id +1 )%3 +1;
           mapped_tree_node_type *newMappedTreeNode = new_mapped_tree_node(newNode->wing_id,dedicated_parking_wing,newNode->flat_id,2,(*map_space_pptr)->compact_space[dedicated_parking_wing-1],newNode->vehicle_number[i]);
            (*map_space_pptr)->compact_space[dedicated_parking_wing-1] = (*map_space_pptr)->compact_space[dedicated_parking_wing-1] +1;
               *mapped_tree_pptr = insert_mapped_tree(*mapped_tree_pptr , newMappedTreeNode);

       }
       else
       {

           printf("\n space is not available for parking \n");
          // return NULL;

       }
       
       
      // return newMappedTreeNode ;
       
   }

  for( j=0;j<newNode->no_of_four_wheelers;j++)
  {   if(j==0)
      {
          dedicated_parking_wing = newNode->wing_id ;
           mapped_tree_node_type *newMappedTreeNode = new_mapped_tree_node(newNode->wing_id,dedicated_parking_wing,newNode->flat_id,2,(*map_space_pptr)->compact_space[dedicated_parking_wing-1],newNode->vehicle_number[i]);
           (*map_space_pptr)->compact_space[dedicated_parking_wing-1] = (*map_space_pptr)->compact_space[dedicated_parking_wing-1] +1;
           *mapped_tree_pptr = insert_mapped_tree(*mapped_tree_pptr , newMappedTreeNode);

      }

      if(j==1)
      {
           dedicated_parking_wing = (newNode->wing_id )%3 +1 ;
            mapped_tree_node_type *newMappedTreeNode = new_mapped_tree_node(newNode->wing_id,dedicated_parking_wing,newNode->flat_id,2,(*map_space_pptr)->compact_space[dedicated_parking_wing-1],newNode->vehicle_number[i]);
             (*map_space_pptr)->compact_space[dedicated_parking_wing-1] = (*map_space_pptr)->compact_space[dedicated_parking_wing-1] +1;
              *mapped_tree_pptr = insert_mapped_tree(*mapped_tree_pptr , newMappedTreeNode);  
      
      }

     if(j>=2)
     {
         printf("\n this vehicle not added in mapped tree since max 2 four wheelers can be added, this vehicle will work as guest vehicle\n");
     }
  
  }


}

/*   ................... */
flat_info_type *new_flat_info_node()
{     printf("\n i am in function new_flat_info_node \n");

    flat_info_type *newNode =(flat_info_type *)malloc(sizeof(flat_info_type));

    printf("\n enter wing id \n");
    scanf("%d",&newNode->wing_id);

    printf("\n enter flat id \n");
    scanf("%d",&newNode->flat_id);

    printf("\n enter no of two wheelers \n");
    scanf("%d",&newNode->no_of_two_wheelers);

    printf("\n enter no of four wheelers \n");
    scanf("%d",&newNode->no_of_four_wheelers);

    newNode->total_no_of_vehicles =newNode->no_of_four_wheelers + newNode->no_of_two_wheelers;

    for(int i=0;i<newNode->total_no_of_vehicles;i++)
    { printf("\nenter vehicle number\n");
        scanf("%s",newNode->vehicle_number[i]);
    }

    newNode->key = newNode->wing_id*100 + newNode->flat_id;

    newNode->left = NULL;
    newNode->right = NULL;

printf(" i am out of function new_flat_info_node");
    return newNode;

}

/*   ................... */
available_map_space_type *new_available_map_space()
{   printf("\n i am in function new_available_map_space \n");  

    available_map_space_type *newNode = (available_map_space_type *)malloc(sizeof(available_map_space_type));
    newNode->compact_space[0] = 0;
    newNode->large_space[0] =0;

    newNode->compact_space[1]= 0;
    newNode->large_space[1]=0;

    newNode->compact_space[2] = 0;
    newNode->large_space[2] =0;

    return newNode;
}

/*   ................... */
mapped_tree_node_type  *new_mapped_tree_node(int wing_id,int dedicated_parking_wing ,int flat_id,int vehicle_type ,int index,char vehicleArr[])
{
     printf("\n i am in function new_flat_info_node \n");

    mapped_tree_node_type  *newNode = (mapped_tree_node_type  *)malloc(sizeof(mapped_tree_node_type));
    newNode->wing_id = wing_id;
    newNode->flat_id = flat_id;
    newNode->dedicated_parking_wing = dedicated_parking_wing;

    if(vehicle_type ==2)
  {  newNode->compact_spot_index =index;
    newNode->large_spot_index = -1;
  }
  else
  {  newNode->compact_spot_index =-1;
    newNode->large_spot_index = index;
      
  }
  

    strcpy(newNode->vehicle_number,vehicleArr);
    newNode->key =vehicleArr[5]*1000+vehicleArr[6]*100+vehicleArr[7]*10+vehicleArr[8];

    newNode->left=NULL;
    newNode->right = NULL;

    return newNode;
}



/*   ...................max.................. */
int max(int a, int b) 
{ 
    printf("\n i am in function max\n");

    return (a > b)? a : b; 
} 

/*   ...................height_mapped_tree..................... */
int height_mapped_tree(mapped_tree_node_type *nodeptr) 
{ 
    printf("\n i am in function height_mapped_tree \n");

    if (nodeptr == NULL) 
        return 0; 
    return nodeptr->height; 
} 

/*   ................... height_file_info_tree.............. */
int height_file_info_tree(flat_info_type *nodeptr) 
{ printf("\n i am in function height_file_info_tree \n");

    if (nodeptr == NULL) 
        return 0; 
    return nodeptr->height; 
} 

/*   ...................rightRotate_mapped_tree.................... */
mapped_tree_node_type *rightRotate_mapped_tree(mapped_tree_node_type *y) 
{ printf("\n i am in function rightRotate_mapped_tree \n");

    mapped_tree_node_type *x = y->left; 
    mapped_tree_node_type *T2 = x->right; 
  
    // Perform rotation 
    x->right = y; 
    y->left = T2; 
  
    // Update heights 
    y->height = max(height_mapped_tree(y->left),height_mapped_tree(y->right))+1; 
    x->height = max(height_mapped_tree(x->left), height_mapped_tree(x->right))+1; 
  
    // Return new root 
    return x; 
} 
  

/*   ...................leftRotate_mapped_tree...................... */
mapped_tree_node_type *leftRotate_mapped_tree(mapped_tree_node_type *x) 
{ 
    printf("\n i am in function leftRotate_mapped_tree \n");

    mapped_tree_node_type *y = x->right; 
    mapped_tree_node_type *T2 = y->left; 
  
    // Perform rotation 
    y->left = x; 
    x->right = T2; 
  
    //  Update heights 
    x->height = max(height_mapped_tree(x->left), height_mapped_tree(x->right))+1; 
    y->height = max(height_mapped_tree(y->left), height_mapped_tree(y->right))+1; 
  
    // Return new root 
    return y; 
} 
  
  /*   ...................getBalance_mapped_tree..................... */
int getBalance_mapped_tree(mapped_tree_node_type *N) 
{ printf("\n i am in function getBalance_mapped_tree \n");
    if (N == NULL) 
        return 0; 
    return height_mapped_tree(N->left) - height_mapped_tree(N->right); 
} 

/*   ...................rightRotate_flat_info_tree.............. */
flat_info_type *rightRotate_flat_info_tree(flat_info_type *y) 
{ printf("\n i am in function rightRotate_flat_info_tree \n");

    flat_info_type *x = y->left; 
    flat_info_type *T2 = x->right; 
  
    // Perform rotation 
    x->right = y; 
    y->left = T2; 
  
    // Update heights 
    y->height = max(height_file_info_tree(y->left), height_file_info_tree(y->right))+1; 
    x->height = max(height_file_info_tree(x->left), height_file_info_tree(x->right))+1; 
  
    // Return new root 
    return x; 
} 
  
/*   ................... leftRotate_flat_info_tree..................................*/ 
flat_info_type *leftRotate_flat_info_tree(flat_info_type *x) 
{ 
    printf("\n i am in function leftRotate_flat_info_tree \n");

    flat_info_type *y = x->right; 
    flat_info_type *T2 = y->left; 
  
    // Perform rotation 
    y->left = x; 
    x->right = T2; 
  
    //  Update heights 
    x->height = max(height_file_info_tree(x->left), height_file_info_tree(x->right))+1; 
    y->height = max(height_file_info_tree(y->left), height_file_info_tree(y->right))+1; 
  
    // Return new root 
    return y; 
} 
  
/*   ...................  getBalance_flat_info_tree.................................*/
int getBalance_flat_info_tree(flat_info_type *N) 
{ printf("\n i am in function getBalance_flat_info_tree \n");

    if (N == NULL) 
        return 0; 
    return height_file_info_tree(N->left) - height_file_info_tree(N->right); 
} 

/*   ...................insert_mapped_tree ..................................*/
mapped_tree_node_type *insert_mapped_tree(mapped_tree_node_type * node,mapped_tree_node_type *newNode) 
{ printf("\n i am in function insert_mapped_tree \n");

    int key = newNode->key;

    /* 1.  Perform the normal BST insertion */
    if (node == NULL) 
        return newNode; 
  
    if (key < node->key) 
        node->left  = insert_mapped_tree(node->left , newNode); 
    else if (key > node->key) 
        node->right = insert_mapped_tree(node->right , newNode); 
    else // Equal keys are not allowed in BST 
        return node; 
  
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height_mapped_tree(node->left), 
                           height_mapped_tree(node->right)); 
  
    /* 3. Get the balance factor of this ancestor 
          node to check whether this node became 
          unbalanced */
    int balance = getBalance_mapped_tree(node); 
  
    // If this node becomes unbalanced, then 
    // there are 4 cases 
  
    // Left Left Case 
    if (balance > 1 && key < node->left->key) 
        return rightRotate_mapped_tree(node); 
  
    // Right Right Case 
    if (balance < -1 && key > node->right->key) 
        return leftRotate_mapped_tree(node); 
  
    // Left Right Case 
    if (balance > 1 && key > node->left->key) 
    { 
        node->left =  leftRotate_mapped_tree(node->left); 
        return rightRotate_mapped_tree(node); 
    } 
  
    // Right Left Case 
    if (balance < -1 && key < node->right->key) 
    { 
        node->right = rightRotate_mapped_tree(node->right); 
        return leftRotate_mapped_tree(node); 
    } 
  
    /* return the (unchanged) node pointer */
    return node; 
} 

/*   ................... insert_flat_info_tree ......................................*/
flat_info_type *insert_flat_info_tree(flat_info_type * node,flat_info_type * newNode) 
{   printf("\n i am in function insert_flat_info_tree\n");

    int key = newNode->key;
    /* 1.  Perform the normal BST insertion */
    if (node == NULL) 
        return newNode; 
  
    if (key < node->key) 
        node->left  = insert_flat_info_tree(node->left,newNode); 
    else if (key > node->key) 
        node->right = insert_flat_info_tree(node->right,newNode);
    else // Equal keys are not allowed in BST 
        return node; 
  
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height_file_info_tree(node->left), 
                           height_file_info_tree(node->right)); 
  
    /* 3. Get the balance factor of this ancestor 
          node to check whether this node became 
          unbalanced */
    int balance = getBalance_flat_info_tree(node); 
  
    // If this node becomes unbalanced, then 
    // there are 4 cases 
  
    // Left Left Case 
    if (balance > 1 && key < node->left->key) 
        return rightRotate_flat_info_tree(node); 
  
    // Right Right Case 
    if (balance < -1 && key > node->right->key) 
        return leftRotate_flat_info_tree(node); 
  
    // Left Right Case 
    if (balance > 1 && key > node->left->key) 
    { 
        node->left =  leftRotate_flat_info_tree(node->left); 
        return rightRotate_flat_info_tree(node); 
    } 
  
    // Right Left Case 
    if (balance < -1 && key < node->right->key) 
    { 
        node->right = rightRotate_flat_info_tree(node->right); 
        return leftRotate_flat_info_tree(node); 
    } 
  
    /* return the (unchanged) node pointer */
    return node; 
} 
