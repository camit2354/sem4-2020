#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max_vehicle 3
#define no_of_compact_spots 36
#define no_of_large_spots 36

typedef struct parked_vehicle_tag
{
   char intime[4];
   char outtime[4];
   char vehicle_number[9];
   int dedicated_parking_wing_id;
   int compact_spot_index;
   int large_spot_index;

} parked_vehicle_type;

typedef struct parking_db_day_tag
{ char indate[6];
  char outdate[6];

  int top;
  parked_vehicle_type *parked_vehicles_arr[100];

      int key;
     int height;

     struct parking_db_day_tag *left ,*right;

}parking_db_day_type;


typedef struct parking_wing_status_tag
{
  int parking_wing;
  int status_compactspots_arr[no_of_compact_spots] ;
  int status_large_spots_arr[no_of_large_spots] ;

} parking_wing_status_type;

typedef struct parking_lot_status_tag
{
   parking_wing_status_type *wing_a_ptr;
   parking_wing_status_type *wing_b_ptr;
   parking_wing_status_type *wing_c_ptr;

}parking_lot_status_type;
 

 


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



flat_info_type *initialize_flat_info_tree(available_map_space_type **map_space_pptr,mapped_tree_node_type **,flat_info_type **);
flat_info_type *add_flat_info(available_map_space_type **map_space_pptr,mapped_tree_node_type **mapped_tree_pptr, flat_info_type **flat_info_tree_pptr);

available_map_space_type *new_available_map_space();


int max(int a, int b);

int height_parking_db_tree(parking_db_day_type *nodeptr) ;
parking_db_day_type *rightRotate_parking_db_tree(parking_db_day_type *y) ;
parking_db_day_type *leftRotate_parking_db_tree(parking_db_day_type *x) ;
int getBalance_parking_db_tree(parking_db_day_type *N) ;
parking_db_day_type *insert_parking_db_tree(parking_db_day_type *node,parking_db_day_type *newnode);
void preOrderParkingDbDayTree(parking_db_day_type *root);


int height_mapped_tree(mapped_tree_node_type *nodeptr) ;
mapped_tree_node_type *rightRotate_mapped_tree(mapped_tree_node_type *y) ;
mapped_tree_node_type *leftRotate_mapped_tree(mapped_tree_node_type *x) ;
int getBalance_mapped_tree(mapped_tree_node_type *N) ;
mapped_tree_node_type *insert_mapped_tree(mapped_tree_node_type * node,mapped_tree_node_type *newNode);
void preOrderMappedTree(mapped_tree_node_type *root) ;
void initialize_parking_db_day_tree(parking_db_day_type **parking_db_day_tree_pptr);

int height_flat_info_tree(flat_info_type *nodeptr) ;
flat_info_type *rightRotate_flat_info_tree(flat_info_type *y);
flat_info_type *leftRotate_flat_info_tree(flat_info_type *x) ;
int getBalance_flat_info_tree(flat_info_type *N);
flat_info_type *insert_flat_info_tree(flat_info_type * node,flat_info_type * newNode) ;
void preOrderFlatInfoTree(flat_info_type *root);


mapped_tree_node_type  *new_mapped_tree_node(int wing_id,int dedicated_parking_wing ,int flat_id,int vehicle_type ,int index,char vehicleArr[]);
flat_info_type *new_flat_info_node();




void map_vehicle_Node();
void park_vehicle(int vehicle_type,char vehicle_number[9],char intime[4],char indate[6]);
void Remove_vehicle_node ();
void Display_Visitors();
void  Parking_status (parking_lot_status_type *parking_lot_ptr);


void main()
{
  //  available_map_space_type **map_space_pptr = NULL;
    available_map_space_type *map_space_ptr = new_available_map_space();

    parking_db_day_type *parking_db_day_tree_ptr = NULL;
     parking_db_day_type **parking_db_day_tree_pptr = &parking_db_day_tree_ptr;

     initialize_parking_db_day_tree(parking_db_day_tree_pptr);
    
  mapped_tree_node_type *mapped_tree_ptr =NULL;
   mapped_tree_node_type **mapped_tree_pptr =&mapped_tree_ptr;
   
  flat_info_type *flat_info_tree_ptr=NULL;
   flat_info_type **flat_info_tree_pptr = &flat_info_tree_ptr;
   
   
  initialize_flat_info_tree(&map_space_ptr,mapped_tree_pptr,flat_info_tree_pptr);

  flat_info_tree_ptr = *flat_info_tree_pptr;
  mapped_tree_ptr = *mapped_tree_pptr;

  preOrderMappedTree(mapped_tree_ptr);
  preOrderFlatInfoTree(flat_info_tree_ptr);
  return ;
}

void initialize_parking_db_day_tree(parking_db_day_type **parking_db_day_tree_pptr)
{
    return ;
}


/*   ...................max.................. */
int max(int a, int b) 
{ 
  //  printf("\n i am in function max\n");

    return (a > b)? a : b; 
} 

/*   ..............parking_db_day tree..................*/
/*   ..............parking_db_day tree..................*/
/*   ..............parking_db_day tree..................*/
/*   ..............parking_db_day tree..................*/


/*   ...................height_parking_db_tree..................... */
int height_parking_db_day_tree(parking_db_day_type *nodeptr) 
{ 
   // printf("\n i am in function height_parking_db_tree \n");

    if (nodeptr == NULL) 
        return 0; 
    return nodeptr->height; 
} 

/*   ...................rightRotate_parking_db_tree.................... */
parking_db_day_type *rightRotate_parking_db_day_tree(parking_db_day_type *y) 
{  // printf("\n i am in function rightRotate_parking_db_tree \n");

    parking_db_day_type *x = y->left; 
    parking_db_day_type *T2 = x->right; 
  
    // Perform rotation 
    x->right = y; 
    y->left = T2; 
  
    // Update heights 
    y->height = max(height_parking_db_day_tree(y->left),height_parking_db_day_tree(y->right))+1; 
    x->height = max(height_parking_db_day_tree(x->left), height_parking_db_day_tree(x->right))+1; 
  
    // Return new root 
    return x; 
} 

/*   ...................leftRotate_parking_db_tree...................... */
parking_db_day_type *leftRotate_parking_db_day_tree(parking_db_day_type *x) 
{ 
   // printf("\n i am in function leftRotate_parking_db_tree \n");

    parking_db_day_type *y = x->right; 
    parking_db_day_type *T2 = y->left; 
  
    // Perform rotation 
    y->left = x; 
    x->right = T2; 
  
    //  Update heights 
    x->height = max(height_parking_db_day_tree(x->left), height_parking_db_day_tree(x->right))+1; 
    y->height = max(height_parking_db_day_tree(y->left), height_parking_db_day_tree(y->right))+1; 
  
    // Return new root 
    return y; 
} 

 /*   ...................getBalance_parking_db_tree..................... */
int getBalance_parking_db_day_tree(parking_db_day_type *N) 
{ // printf("\n i am in function getBalance_parking_db_tree \n");
    if (N == NULL) 
        return 0; 
    return height_parking_db_day_tree(N->left) - height_parking_db_day_tree(N->right); 
} 

/*   ...................insert_parking_db_tree ..................................*/
parking_db_day_type *insert_parking_db_day_tree(parking_db_day_type *node,parking_db_day_type *newNode) 
{  // printf("\n i am in function insert_parking_db_tree \n");

    int key = newNode->key;

    /* 1.  Perform the normal BST insertion */
    if (node == NULL) 
        return newNode; 
  
    if (key < node->key) 
        node->left  = insert_parking_db_day_tree(node->left , newNode); 
    else if (key > node->key) 
        node->right = insert_parking_db_day_tree(node->right , newNode); 
    else // Equal keys are not allowed in BST 
        return node; 
  
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height_parking_db_day_tree(node->left), 
                           height_parking_db_day_tree(node->right)); 
  
    /* 3. Get the balance factor of this ancestor 
          node to check whether this node became 
          unbalanced */
    int balance = getBalance_parking_db_day_tree(node); 
  
    // If this node becomes unbalanced, then 
    // there are 4 cases 
  
    // Left Left Case 
    if (balance > 1 && key < node->left->key) 
        return rightRotate_parking_db_day_tree(node); 
  
    // Right Right Case 
    if (balance < -1 && key > node->right->key) 
        return leftRotate_parking_db_day_tree(node); 
  
    // Left Right Case 
    if (balance > 1 && key > node->left->key) 
    { 
        node->left =  leftRotate_parking_db_day_tree(node->left); 
        return rightRotate_parking_db_day_tree(node); 
    } 
  
    // Right Left Case 
    if (balance < -1 && key < node->right->key) 
    { 
        node->right = rightRotate_parking_db_day_tree(node->right); 
        return leftRotate_parking_db_day_tree(node); 
    } 
  
    /* return the (unchanged) node pointer */
    return node; 
} 


/*   ................... preorder function..................*/
void preOrderParkingDbDayTree(parking_db_day_type *root)
{ 
    if(root != NULL) 
    { 
        printf("\n key =%d ",root->key); 
        preOrderParkingDbDayTree(root->left); 
        preOrderParkingDbDayTree(root->right); 
    } 
} 




/*   ..............mapped tree..................*/
/*   ..............mapped tree..................*/
/*   ..............mapped tree..................*/
/*   ..............mapped tree..................*/

/*   ...................height_mapped_tree..................... */
int height_mapped_tree(mapped_tree_node_type *nodeptr) 
{ 
   // printf("\n i am in function height_mapped_tree \n");

    if (nodeptr == NULL) 
        return 0; 
    return nodeptr->height; 
} 

/*   ...................rightRotate_mapped_tree.................... */
mapped_tree_node_type *rightRotate_mapped_tree(mapped_tree_node_type *y) 
{  // printf("\n i am in function rightRotate_mapped_tree \n");

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
   // printf("\n i am in function leftRotate_mapped_tree \n");

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
{ // printf("\n i am in function getBalance_mapped_tree \n");
    if (N == NULL) 
        return 0; 
    return height_mapped_tree(N->left) - height_mapped_tree(N->right); 
} 

/*   ...................insert_mapped_tree ..................................*/
mapped_tree_node_type *insert_mapped_tree(mapped_tree_node_type * node,mapped_tree_node_type *newNode) 
{  // printf("\n i am in function insert_mapped_tree \n");

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


/*   ................... preorder function..................*/
void preOrderMappedTree(mapped_tree_node_type *root) 
{ 
    if(root != NULL) 
    { 
        printf("\n vehicle number =%s\t, key =%d ", root->vehicle_number,root->key); 
        preOrderMappedTree(root->left); 
        preOrderMappedTree(root->right); 
    } 
} 


/*   ..............flat info treetree..................*/
/*   ..............flat info tree..................*/
/*   ..............flat infotree..................*/
/*   ..............flat info tree..................*/

/*   ................... height_flat_info_tree.............. */
int height_flat_info_tree(flat_info_type *nodeptr) 
{ // printf("\n i am in function height_flat_info_tree \n");

    if (nodeptr == NULL) 
        return 0; 
    return nodeptr->height; 
} 

 
 
/*   ...................rightRotate_flat_info_tree.............. */
flat_info_type *rightRotate_flat_info_tree(flat_info_type *y) 
{  // printf("\n i am in function rightRotate_flat_info_tree \n");

    flat_info_type *x = y->left; 
    flat_info_type *T2 = x->right; 
  
    // Perform rotation 
    x->right = y; 
    y->left = T2; 
  
    // Update heights 
    y->height = max(height_flat_info_tree(y->left), height_flat_info_tree(y->right))+1; 
    x->height = max(height_flat_info_tree(x->left), height_flat_info_tree(x->right))+1; 
  
    // Return new root 
    return x; 
} 
  
/*   ................... leftRotate_flat_info_tree..................................*/ 
flat_info_type *leftRotate_flat_info_tree(flat_info_type *x) 
{ 
   // printf("\n i am in function leftRotate_flat_info_tree \n");

    flat_info_type *y = x->right; 
    flat_info_type *T2 = y->left; 
  
    // Perform rotation 
    y->left = x; 
    x->right = T2; 
  
    //  Update heights 
    x->height = max(height_flat_info_tree(x->left), height_flat_info_tree(x->right))+1; 
    y->height = max(height_flat_info_tree(y->left), height_flat_info_tree(y->right))+1; 
  
    // Return new root 
    return y; 
} 
  
/*   ...................  getBalance_flat_info_tree.................................*/
int getBalance_flat_info_tree(flat_info_type *N) 
{  // printf("\n i am in function getBalance_flat_info_tree \n");

    if (N == NULL) 
        return 0; 
    return height_flat_info_tree(N->left) - height_flat_info_tree(N->right); 
} 



/*   ................... insert_flat_info_tree ......................................*/
flat_info_type *insert_flat_info_tree(flat_info_type * node,flat_info_type * newNode) 
{  //  printf("\n i am in function insert_flat_info_tree\n");

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
    node->height = 1 + max(height_flat_info_tree(node->left), 
                           height_flat_info_tree(node->right)); 
  
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


void preOrderFlatInfoTree(flat_info_type *root)
{ // printf("\n i am in function preOrderFlatInfoTree\n");
    if(root != NULL) 
    { 
        printf(" \n wing id=%d, flat id =%d key =%d", root->wing_id,root->flat_id,root->key); 
        preOrderFlatInfoTree(root->left); 
        preOrderFlatInfoTree(root->right); 
    } 

}



/*   ................... initialize_flat_info_tree..................*/

flat_info_type *initialize_flat_info_tree(available_map_space_type **map_space_pptr,mapped_tree_node_type **mapped_tree_pptr, flat_info_type **flat_info_tree_pptr)
{ // printf("\n i am in function initialize_flat_info_tree \n");
    
     int wing_id;
    int flat_id; 
     int  no_of_two_wheelers;
     int no_of_four_wheelers;      
    char vehicle_number[max_vehicle][9];
    

    FILE *fp;
    fp = fopen("flatinfo.txt","r");
     
  
    if(fp == NULL)
    {
        printf("Error opening flat\n");
        exit(1);
    }
while(fscanf(fp, "%d\t%d\t%d\t%d\t%s\t%s",&wing_id,&flat_id,&no_of_two_wheelers,&no_of_four_wheelers,vehicle_number[0],vehicle_number[1])!=EOF  )
{   flat_info_type *newNode =(flat_info_type *)malloc(sizeof(flat_info_type));
    newNode->wing_id = wing_id;
    newNode->flat_id = flat_id;
    newNode->no_of_two_wheelers = no_of_two_wheelers;
    newNode->no_of_four_wheelers = no_of_four_wheelers;
    strcpy(newNode->vehicle_number[0],vehicle_number[0]); printf("\n vehicle number 1=%s \t vehicle number 2=%s",vehicle_number[0],vehicle_number[1]);
    strcpy(newNode->vehicle_number[1],vehicle_number[1]);
     newNode->total_no_of_vehicles = newNode->no_of_four_wheelers + newNode->no_of_two_wheelers;
    newNode->key = newNode->wing_id*100 + newNode->flat_id;
    
    
    
     /*   code  of  function add flat info */ 
         int i,j;
         int dedicated_parking_wing;
           
               flat_info_type *flat_info_tree_ptr = *flat_info_tree_pptr;
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

  fclose(fp);
    


}

/*   ................... */
flat_info_type *add_flat_info(available_map_space_type **map_space_pptr,mapped_tree_node_type **mapped_tree_pptr, flat_info_type **flat_info_tree_pptr)
{ // printf("\n i am in function add_flat_info \n");
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
{    // printf("\n i am in function new_flat_info_node \n");

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

    // printf(" i am out of function new_flat_info_node");
    return newNode;

}

/*   ................... */
available_map_space_type *new_available_map_space()
{  // printf("\n i am in function new_available_map_space \n");  

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
   //  printf("\n i am in function new_flat_info_node \n");

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



void park_vehicle(int vehicle_type,char vehicle_number[9],char intime[4],char indate[6])
{

}

void  Parking_status (parking_lot_status_type *parking_lot_ptr)
{
     parking_wing_status_type *wing_a_ptr =parking_lot_ptr->wing_a_ptr;
     parking_wing_status_type *wing_b_ptr =parking_lot_ptr->wing_b_ptr;
     parking_wing_status_type *wing_c_ptr =parking_lot_ptr->wing_c_ptr;

     printf("\n wing A free compact spots are below\n");
     for(int i=0;i<36;i++)
     {
         if(wing_a_ptr->status_compactspots_arr[i]!=1)
         {
             printf("\tspot id :%d\t",i);
         }
     }
     printf("\n wing A free large spots are below\n");
     for(int i=0;i<36;i++)
     {
         if(wing_a_ptr->status_large_spots_arr[i]!=1)
         {
             printf("\tspot id :%d\t",i);
         }
     }



      printf("\n wing B free compact spots are below\n");
      for(int i=0;i<36;i++)
     {
         if(wing_b_ptr->status_compactspots_arr[i]!=1)
         {
             printf("\tspot id :%d\t",i);
         }
     }
     printf("\n wing B free large spots are below\n");
     for(int i=0;i<36;i++)
     {
         if(wing_b_ptr->status_large_spots_arr[i]!=1)
         {
             printf("\tspot id :%d\t",i);
         }
     }



      printf("\n wing C  free compact spots are below\n");
      for(int i=0;i<36;i++)
     {
         if(wing_c_ptr->status_compactspots_arr[i]!=1)
         {
             printf("\tspot id :%d\t",i);
         }
     }
     printf("\n wing C free large spots are below\n");
     for(int i=0;i<36;i++)
     {
         if(wing_c_ptr->status_large_spots_arr[i]!=1)
         {
             printf("\tspot id :%d\t",i);
         }
     }

     return ;
}
