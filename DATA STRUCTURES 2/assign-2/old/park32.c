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
   char indate[6];
   char outdate[6];
   char vehicle_number[9];
   int dedicated_parking_wing_id;
   int dedicated_compact_spot_index;
   int dedicated_large_spot_index;
   int is_visitor;

} parked_vehicle_type;

typedef struct parking_db_day_tag
{ char indate[6];

  int top;
  int key;
  int height;
  parked_vehicle_type *parked_vehicles_arr[100];     

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
void show_current_map_space_index(available_map_space_type *map_space_ptr);
parking_lot_status_type *initialize_parking_lot(parking_lot_status_type **parking_lot_status_pptr);


int max(int a, int b);

int height_parking_db_day_tree(parking_db_day_type *nodeptr) ;
parking_db_day_type *rightRotate_parking_db_day_tree(parking_db_day_type *y) ;
parking_db_day_type *leftRotate_parking_db_day_tree(parking_db_day_type *x) ;
int getBalance_parking_db_day_tree(parking_db_day_type *N) ;
parking_db_day_type *insert_parking_db_day_tree(parking_db_day_type *node,parking_db_day_type *newnode);
void preOrderParkingDbDayTree(parking_db_day_type *root);

parking_db_day_type *search_parking_db_day_tree(parking_db_day_type *root,int key);
int get_dedicated_wing_for_new_parked_vehicle(int vehicle_type,char vehicle_number[9],mapped_tree_node_type *mapped_tree_ptr,parking_lot_status_type **parking_lot_status_pptr);
int get_dedicated_index_for_new_parked_vehicle(int vehicle_type,char vehicle_number[9],mapped_tree_node_type *mapped_tree_ptr,parking_lot_status_type **parking_lot_status_pptr);
void initialize_parking_db_day_tree(mapped_tree_node_type *mapped_tree_ptr,parking_lot_status_type **parking_lot_status_pptr,parking_db_day_type **parking_db_day_tree_pptr);
int is_visitor(char vehicle_number[9],mapped_tree_node_type *mapped_tree_ptr);



int height_mapped_tree(mapped_tree_node_type *nodeptr) ;
mapped_tree_node_type *rightRotate_mapped_tree(mapped_tree_node_type *y) ;
mapped_tree_node_type *leftRotate_mapped_tree(mapped_tree_node_type *x) ;
int getBalance_mapped_tree(mapped_tree_node_type *N) ;
mapped_tree_node_type *insert_mapped_tree(mapped_tree_node_type * node,mapped_tree_node_type *newNode);
void preOrderMappedTree(mapped_tree_node_type *root) ;
void initialize_parking_db_day_tree(mapped_tree_node_type *mapped_tree_ptr,parking_lot_status_type **parking_lot_status_pptr,parking_db_day_type **parking_db_day_tree_pptr);




int height_flat_info_tree(flat_info_type *nodeptr) ;
flat_info_type *rightRotate_flat_info_tree(flat_info_type *y);
flat_info_type *leftRotate_flat_info_tree(flat_info_type *x) ;
int getBalance_flat_info_tree(flat_info_type *N);
flat_info_type *insert_flat_info_tree(flat_info_type * node,flat_info_type * newNode) ;
void preOrderFlatInfoTree(flat_info_type *root);
flat_info_type *search_flat_node(flat_info_type **flat_info_tree_pptr ,int wing_id ,int flat_id);


mapped_tree_node_type  *new_mapped_tree_node(int wing_id,int dedicated_parking_wing ,int flat_id,int vehicle_type ,int index,char vehicleArr[]);
flat_info_type *new_flat_info_node();




mapped_tree_node_type *map_vehicle_node(available_map_space_type **map_space_pptr,mapped_tree_node_type **mapped_tree_pptr, flat_info_type **flat_info_tree_pptr, int wing_id,int flat_id,int vehicle_type ,char *vehicle_number);
void park_vehicle(mapped_tree_node_type *mapped_tree_ptr,parking_lot_status_type **parking_lot_status_pptr,parking_db_day_type **parking_db_day_tree_pptr,int vehicle_type,char intime[4],char indate[6],char vehicle_number[9]);
void Remove_vehicle_node ();
void Display_Visitors(char indate[6],parking_db_day_type *parking_db_day_ptr);
void  Parking_status (parking_lot_status_type *parking_lot_ptr);


void main()
{
  //  available_map_space_type **map_space_pptr = NULL;
    available_map_space_type *map_space_ptr = new_available_map_space();
     available_map_space_type **map_space_pptr = &map_space_ptr;

    parking_lot_status_type *parking_lot_status_ptr=NULL;
    parking_lot_status_type **parking_lot_status_pptr = &parking_lot_status_ptr;
    

    parking_db_day_type *parking_db_day_tree_ptr = NULL;
     parking_db_day_type **parking_db_day_tree_pptr = &parking_db_day_tree_ptr;
    
    
   mapped_tree_node_type *mapped_tree_ptr =NULL;
   mapped_tree_node_type **mapped_tree_pptr =&mapped_tree_ptr;
   
    flat_info_type *flat_info_tree_ptr=NULL;
    flat_info_type **flat_info_tree_pptr = &flat_info_tree_ptr;  
   
  
  
   
    initialize_parking_lot(parking_lot_status_pptr);  
    initialize_flat_info_tree(&map_space_ptr,mapped_tree_pptr,flat_info_tree_pptr);    


     printf("\n initialization of flat information using flat_info.txt\n");
     printf("\n\n .............. mapped tree  ......\n\n");
    preOrderMappedTree(*mapped_tree_pptr);
    printf("\n\n ...........  flat info tree ...\n\n");
    preOrderFlatInfoTree(*flat_info_tree_pptr);



   initialize_parking_db_day_tree(mapped_tree_ptr,parking_lot_status_pptr,parking_db_day_tree_pptr);
    // show_current_map_space_index(map_space_ptr);

   printf("\n initialization of flat information using parking_db.txt\n");
  printf("\n\n .............. parking tree  ......\n\n");
   preOrderParkingDbDayTree(*parking_db_day_tree_pptr);


 


    printf("\n enter choice :\n");printf("\n 1 . map vehicle \n");
   printf("\n 2 . park vehicle\n");printf("\n 3 . unmap vehicle\n");
   printf("\n 4 . visitors of particular day\n");printf("\n 5 .parking lot status\n");

   int choice =0;
   printf("\n enter choice :");
    scanf("%d",&choice);

 int wing_id;
 int flat_id;
 int vehicle_type ;
 char vehicle_number[9];
 char intime[4];
 char indate[6];

  switch (choice)
  {
      case 1:printf("\n mapping new purchased vehicle\n");
        
        printf("\n enter wing id : \n ");
        scanf("%d",&wing_id);

        
         printf("\n enter flat id : \n ");
         scanf("%d",&flat_id);

        
         printf("\n enter vehicle type : \n ");
         scanf("%d",&vehicle_type);

        
         printf("\n enter vehicle number : \n ");
         scanf("%s",vehicle_number);

               map_vehicle_node(map_space_pptr,mapped_tree_pptr, flat_info_tree_pptr,wing_id,flat_id,vehicle_type ,vehicle_number);
        // flat_info_type *flat_node = search_flat_node(flat_info_tree_pptr,wing_id,flat_id);
        // printf("\n wing_id :%d ,flat_id :%d , toatal_no_of_vehicles : %d,\n",flat_node->wing_id,flat_node->flat_id,flat_node->total_no_of_vehicles);
        
            printf("\n\n ...........  flat info tree ...\n\n");
            preOrderFlatInfoTree(*flat_info_tree_pptr);        
              break;

      case 2: printf("\n parking vehicle\n");

             
             printf("\n enter vehicle type : \n ");
            scanf("%d",&vehicle_type);

              printf("\n enter intime :\n");           
            scanf("%s",intime);  

            
              printf("\n enter indate :\n") ;
            scanf("%s",indate);    


          

             printf("\n enter vehicle number : \n ");
            scanf("%s",vehicle_number);
         
         
            //   1 31 1 1 mh24j1127 mh24j1128;
            //   2 0120 010120 mh24j1111;
           park_vehicle(*mapped_tree_pptr,parking_lot_status_pptr,parking_db_day_tree_pptr,vehicle_type,intime,indate,vehicle_number);
           preOrderParkingDbDayTree(*parking_db_day_tree_pptr);

           break;

      case 3: printf("\n unmaping selled vehicle \n");
           break;

      case 4: printf("\n printing visitors of day ****\n");
           
           
           printf("\nenter date :");
           scanf("%s",indate);
           Display_Visitors(indate,*parking_db_day_tree_pptr);
           break;

      case 5: printf("\n\n parking lot status \n\n");            
            Parking_status(*parking_lot_status_pptr);
    
           break;

     default: 
         printf("\nyou entered invalid choice \n");
         break;
        }
  
  return ;
}


void  Parking_status (parking_lot_status_type *parking_lot_ptr)
{
     parking_wing_status_type *wing_a_ptr =parking_lot_ptr->wing_a_ptr;
     parking_wing_status_type *wing_b_ptr =parking_lot_ptr->wing_b_ptr;
     parking_wing_status_type *wing_c_ptr =parking_lot_ptr->wing_c_ptr;

     if(wing_a_ptr == NULL)
     {
         printf("\n wing_a_ptr :NULL\n");
     }
     else
     {
         printf("\n parking wing : %d \n",wing_a_ptr->parking_wing);
     }

      if(wing_b_ptr == NULL)
     {
         printf("\n wing_b_ptr :NULL\n");
     }
     else
     {
         printf("\n parking wing : %d \n",wing_b_ptr->parking_wing);
     }

      if(wing_c_ptr == NULL)
     {
         printf("\n wing_c_ptr :NULL\n");
     }
     else
     {
         printf("\n parking wing : %d \n",wing_c_ptr->parking_wing);
     }
     

    //  printf("\n wing %d occupied compact spots are below\n",wing_a_ptr->parking_wing);
    //  for(int i=0;i<36;i++)
    //  {
         
    //          printf("\tspot id :%d\t",i);
         
    //  }

    //   printf("\n wing %d occupied compact large are below\n",wing_a_ptr->parking_wing);
    //  for(int i=0;i<36;i++)
    //  {
         
    //          printf("\tspot id :%d\t",i);
         
    //  }



    //   printf("\n wing %d occupied compact spots are below\n",wing_b_ptr->parking_wing);
    //   for(int i=0;i<36;i++)
    //  {
         
    //          printf("\tspot id :%d\t",i);
         
    //  }
    //   printf("\n wing %d occupied large spots are below\n",wing_b_ptr->parking_wing);
    //  for(int i=0;i<36;i++)
    //  {
        
    //          printf("\tspot id :%d\t",i);
         
    //  }



    //    printf("\n wing %d occupied compact spots are below\n",wing_c_ptr->parking_wing);
    //   for(int i=0;i<36;i++)
    //  {
         
    //          printf("\tspot id :%d\t",i);
         
    //  }
    //   printf("\n wing %d occupied large spots are below\n",wing_c_ptr->parking_wing);
    //  for(int i=0;i<36;i++)
    //  {
         
    //          printf("\tspot id :%d\t",i);
         
    //  }

     return ;
}


parking_lot_status_type *initialize_parking_lot(parking_lot_status_type **parking_lot_status_pptr)
{
    *parking_lot_status_pptr = (parking_lot_status_type *)malloc(sizeof(parking_lot_status_type));
    parking_wing_status_type *wing_a_ptr = (parking_wing_status_type *)malloc(sizeof(parking_wing_status_type));
    parking_wing_status_type *wing_b_ptr = (parking_wing_status_type *)malloc(sizeof(parking_wing_status_type));
    parking_wing_status_type *wing_c_ptr = (parking_wing_status_type *)malloc(sizeof(parking_wing_status_type));

     (wing_a_ptr)->parking_wing =1;
     (wing_b_ptr)->parking_wing =2;
     (wing_c_ptr)->parking_wing =3;

    (*parking_lot_status_pptr)->wing_a_ptr = wing_a_ptr;
    (*parking_lot_status_pptr)->wing_a_ptr = wing_a_ptr;
     (*parking_lot_status_pptr)->wing_a_ptr = wing_a_ptr;

     printf("\n %d \n",(wing_a_ptr)->parking_wing);
     printf("\n %d \n",(wing_b_ptr)->parking_wing);
     printf("\n %d \n",(wing_c_ptr)->parking_wing);

return *parking_lot_status_pptr;

}

/*   ................... initialize_flat_info_tree..................*/

flat_info_type *initialize_flat_info_tree(available_map_space_type **map_space_pptr,mapped_tree_node_type **mapped_tree_pptr, flat_info_type **flat_info_tree_pptr)
{ // printf("\n i am in function initialize_flat_info_tree \n");
    
     int wing_id;
    int flat_id; 
     int  no_of_two_wheelers;
     int no_of_four_wheelers;      
    char vehicle_number[max_vehicle][9];

    char *vehicle_number0;
    char *vehicle_number1;
    

    FILE *fp;
    fp = fopen("flatinfo2.txt","r");
     
  
    if(fp == NULL)
    {
        printf("Error opening flat\n");
        exit(1);
    }
  while(fscanf(fp, "%d\t%d\t%d\t%d\t%s\t%s",&wing_id,&flat_id,&no_of_two_wheelers,&no_of_four_wheelers,vehicle_number[0],vehicle_number[1])!=EOF  )
  {   
    
    flat_info_type *newNode =(flat_info_type *)malloc(sizeof(flat_info_type));
   // printf("\n%d %d %d %d %s %s\n",wing_id,flat_id,no_of_two_wheelers,no_of_four_wheelers,vehicle_number[0],vehicle_number[1]);
   
   
    newNode->wing_id = wing_id;
    newNode->flat_id = flat_id;

    newNode->no_of_two_wheelers = 0;    
    newNode->no_of_four_wheelers = 0;
    newNode->total_no_of_vehicles =0;

    // strcpy(newNode->vehicle_number[0],vehicle_number[0]); 
    for(int i =0;i<9;i++)
    {
        newNode->vehicle_number[0][i] = vehicle_number[0][i] ;
    }
    newNode->vehicle_number[0][9] = '\0';
  
  
   //  strcpy(newNode->vehicle_number[1],vehicle_number[1]);
   for(int i =0;i<9;i++)
    {
        newNode->vehicle_number[1][i] = vehicle_number[1][i];
    }
     newNode->vehicle_number[1][9] = '\0';

   
    newNode->key = newNode->wing_id*100 + newNode->flat_id;      
    
    
         int i,j;
         int dedicated_parking_wing;
           
               flat_info_type *flat_info_tree_ptr = *flat_info_tree_pptr;
              *flat_info_tree_pptr = insert_flat_info_tree(*flat_info_tree_pptr , newNode);
         

   for( i=0;i<no_of_two_wheelers;i++)
   {   
  
       *mapped_tree_pptr = map_vehicle_node(map_space_pptr,mapped_tree_pptr, flat_info_tree_pptr, newNode->wing_id,newNode->flat_id,2,newNode->vehicle_number[0]);   
     
       
   }

  for( j=0;j<no_of_four_wheelers;j++)
  {  
     *mapped_tree_pptr = map_vehicle_node(map_space_pptr,mapped_tree_pptr, flat_info_tree_pptr, newNode->wing_id,newNode->flat_id,4,newNode->vehicle_number[1]);
  }

  

  } 

  fclose(fp);

   return *flat_info_tree_pptr; 


}



mapped_tree_node_type *map_vehicle_node(available_map_space_type **map_space_pptr,mapped_tree_node_type **mapped_tree_pptr, flat_info_type **flat_info_tree_pptr, int wing_id,int flat_id,int vehicle_type ,char *vehicle_number)
{
    /*   code  of  function add flat info */ 
         int i,j;
         int dedicated_parking_wing;

         flat_info_type *flat_node = search_flat_node(flat_info_tree_pptr,wing_id,flat_id);
       
         
           
   if(vehicle_type ==2 )
   {
           flat_node->no_of_two_wheelers = flat_node->no_of_two_wheelers +1;
            flat_node->total_no_of_vehicles = flat_node->total_no_of_vehicles  +1;           

            strcpy(flat_node->vehicle_number[flat_node->total_no_of_vehicles -1],vehicle_number) ;
           
          
          if((*map_space_pptr)->compact_space[wing_id -1] <36)
       {
                dedicated_parking_wing = wing_id;
                mapped_tree_node_type *newMappedTreeNode = new_mapped_tree_node(wing_id,dedicated_parking_wing,flat_id,vehicle_type,(*map_space_pptr)->compact_space[dedicated_parking_wing-1],vehicle_number);
                (*map_space_pptr)->compact_space[dedicated_parking_wing-1] = (*map_space_pptr)->compact_space[dedicated_parking_wing-1] +1;
               *mapped_tree_pptr = insert_mapped_tree(*mapped_tree_pptr , newMappedTreeNode);

      
       }
       else if ((*map_space_pptr)->compact_space[(wing_id)%3] <36)
       {

                dedicated_parking_wing = (wing_id)%3 +1;
                mapped_tree_node_type *newMappedTreeNode = new_mapped_tree_node(wing_id,dedicated_parking_wing,flat_id,vehicle_type,(*map_space_pptr)->compact_space[dedicated_parking_wing-1],vehicle_number);
                (*map_space_pptr)->compact_space[dedicated_parking_wing-1] = (*map_space_pptr)->compact_space[dedicated_parking_wing-1] +1;
                  *mapped_tree_pptr = insert_mapped_tree(*mapped_tree_pptr , newMappedTreeNode);

       }
       else if ((*map_space_pptr)->compact_space[(wing_id +1)%3] <36)
       {

           dedicated_parking_wing = (wing_id +1 )%3 +1;
           mapped_tree_node_type *newMappedTreeNode = new_mapped_tree_node(wing_id,dedicated_parking_wing,flat_id,vehicle_type,(*map_space_pptr)->compact_space[dedicated_parking_wing-1],vehicle_number);
            (*map_space_pptr)->compact_space[dedicated_parking_wing-1] = (*map_space_pptr)->compact_space[dedicated_parking_wing-1] +1;
               *mapped_tree_pptr = insert_mapped_tree(*mapped_tree_pptr , newMappedTreeNode);

       }
       else
       {

           printf("\n space is not available for parking \n");
          // return NULL;

       }


   }
   else 
   {
          flat_node->no_of_four_wheelers = flat_node->no_of_four_wheelers +1;
          flat_node->total_no_of_vehicles = flat_node->total_no_of_vehicles  +1;

               strcpy(flat_node->vehicle_number[flat_node->total_no_of_vehicles -1],vehicle_number) ;

        if((*map_space_pptr)->large_space[wing_id -1] <36)
      {
          dedicated_parking_wing = wing_id ;
           mapped_tree_node_type *newMappedTreeNode = new_mapped_tree_node(wing_id,dedicated_parking_wing,flat_id,vehicle_type,(*map_space_pptr)->large_space[dedicated_parking_wing-1],vehicle_number);
           (*map_space_pptr)->large_space[dedicated_parking_wing-1] = (*map_space_pptr)->large_space[dedicated_parking_wing-1] +1;
           *mapped_tree_pptr = insert_mapped_tree(*mapped_tree_pptr , newMappedTreeNode);

      }
     else if((*map_space_pptr)->large_space[(wing_id)%3] <36)
      {
           dedicated_parking_wing = (wing_id )%3 +1 ;
            mapped_tree_node_type *newMappedTreeNode = new_mapped_tree_node(wing_id,dedicated_parking_wing,flat_id,vehicle_type,(*map_space_pptr)->large_space[dedicated_parking_wing-1],vehicle_number);
             (*map_space_pptr)->large_space[dedicated_parking_wing-1] = (*map_space_pptr)->large_space[dedicated_parking_wing-1] +1;
              *mapped_tree_pptr = insert_mapped_tree(*mapped_tree_pptr , newMappedTreeNode);  
      
      }
      else if ((*map_space_pptr)->large_space[(wing_id +1)%3] <36)
      {
          
      }     
     else
     {
          printf("\n space is not available for parking \n");
          
     }

   }  
     

    return *mapped_tree_pptr;
  
  

}


flat_info_type *search_flat_node(flat_info_type **flat_info_tree_pptr ,int wing_id ,int flat_id)
{
    int key = wing_id*100 + flat_id;
    int found =0;
    flat_info_type *ptr = *flat_info_tree_pptr;

    while(ptr!=NULL && found==0)
    {
        if(key == ptr->key)
        {
            found =1;
        }
        else if (key < ptr->key)
        {
            ptr =ptr->left;
        }
        else
        {
            ptr = ptr->right;
        }        
        
    }

    return ptr;
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
{ printf("\n..................................\n");
    if(root != NULL) 
    { 
        printf("\n date  =  %s\t  ,key =%d ,top =%d \n ",root->indate,root->key,root->top);

        
        int top = root->top; 
        for(int i=0;i<top;i++)
        {
            if(root->parked_vehicles_arr[i]->dedicated_compact_spot_index == -1)
            {
                printf("\n parked vehicle number = %s ,dedicated_wing : %d ,large_index : %d ,isvisitor :%d , intime : %s ,outtime : %s \n",(root->parked_vehicles_arr[i])->vehicle_number,(root->parked_vehicles_arr[i])->dedicated_parking_wing_id,(root->parked_vehicles_arr[i])->dedicated_large_spot_index,(root->parked_vehicles_arr[i])->is_visitor,(root->parked_vehicles_arr[i])->intime,(root->parked_vehicles_arr[i])->outtime);
            }
            else
            {
                printf("\n parked vehicle number = %s ,dedicated_wing : %d ,compact_index : %d, ,isvisitor :%d , intime : %s ,outtime : %s \n",(root->parked_vehicles_arr[i])->vehicle_number,(root->parked_vehicles_arr[i])->dedicated_parking_wing_id,(root->parked_vehicles_arr[i])->dedicated_compact_spot_index,(root->parked_vehicles_arr[i])->is_visitor,(root->parked_vehicles_arr[i])->intime,(root->parked_vehicles_arr[i])->outtime);
            }
            
            
        }
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
    {       if(root->compact_spot_index == -1)
            {
                     printf("\n vehicle number =%s\t,wing_d = %d ,flat_id =%d ,dedicated wing = %d ,large index =%d  ,key =%d ,\n", root->vehicle_number,root->wing_id,root->flat_id,root->dedicated_parking_wing,root->large_spot_index,root->key);
           }
           else
           {
                            printf("\n vehicle number =%s\t,wing_d = %d ,flat_id =%d ,dedicated wing = %d ,vehicle compact index = %d key =%d ,\n", root->vehicle_number,root->wing_id,root->flat_id,root->dedicated_parking_wing,root->compact_spot_index,root->key);
            }
    
        
        preOrderMappedTree(root->left); 
        preOrderMappedTree(root->right); 
    } 
} 


/*   ..............flat info treetree..................*/
/*   ..............flat info tree..................*/
/*   ..............flat infotree..................*/
/*   ..............flat info tree..................*/




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
        printf(" \n wing id=%d, flat id =%d  , key =%d  , no of two wheelers = %d ,no of four wheelers = %d , total no of vehicles = %d ", root->wing_id,root->flat_id,root->key,root->no_of_two_wheelers,root->no_of_four_wheelers,root->total_no_of_vehicles);
        for(int i=0;i<root->total_no_of_vehicles;i++) 
        {
            printf("\n vehicle number %d :%s\n",i,root->vehicle_number[i]);
        }
        preOrderFlatInfoTree(root->left); 
        preOrderFlatInfoTree(root->right); 
    } 

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
    newNode->key =(vehicleArr[5]-'0')*1000+(vehicleArr[6]-'0')*100+(vehicleArr[7]-'0')*10+(vehicleArr[8]-'0');

    newNode->left=NULL;
    newNode->right = NULL;

    return newNode;
}






void show_current_map_space_index(available_map_space_type *map_space_ptr)
{
    printf("\nwing :A \n");
    printf("\ncompact index  : %d  large index : %d \n",map_space_ptr->compact_space[0],map_space_ptr->large_space[0]);
    printf("\nwing :B \n");
     printf("\ncompact index  : %d  large index : %d \n",map_space_ptr->compact_space[1],map_space_ptr->large_space[1]);
    printf("\nwing :C \n");
     printf("\ncompact index  : %d  large index : %d \n",map_space_ptr->compact_space[2],map_space_ptr->large_space[2]);
}





int is_visitor(char vehicle_number[9],mapped_tree_node_type *mapped_tree_ptr)
{
    int found =1;
   int key = (vehicle_number[5] -'0')*1000+ (vehicle_number[6] -'0')*100+(vehicle_number[7] -'0')*10+(vehicle_number[8] -'0');
   mapped_tree_node_type *ptr = mapped_tree_ptr;

     while(ptr!=NULL && found==1)
     {
        if(ptr->key == key)
         { 
            found =0;

         }
        else if(ptr->key < key)
        {
            ptr = ptr->right;
        }
        else
        {
            ptr =ptr->left;
        }       
        
    }

    return found;
}

int get_dedicated_wing_for_new_parked_vehicle(int vehicle_type,char vehicle_number[9],mapped_tree_node_type *mapped_tree_ptr,parking_lot_status_type **parking_lot_status_pptr)
{  int wing =0;
   int found =0;
   int key = (vehicle_number[5]-'0')*1000 + (vehicle_number[6]-'0')*100+(vehicle_number[7]-'0')*10+(vehicle_number[8]-'0');
   mapped_tree_node_type *retval,*ptr = mapped_tree_ptr;

     while(ptr!=NULL && found==0)
     {
        if(ptr->key == key)
         { retval = ptr;
            found =1;

         }
        else if(ptr->key < key)
        {
            ptr = ptr->right;
        }
        else
        {
            ptr =ptr->left;
        }       
        
    }

    if(retval == NULL)
    {
         
         parking_wing_status_type *wing_a_ptr = (*parking_lot_status_pptr)->wing_a_ptr ;
         if(vehicle_type == 2)
         {
               for(int i=0;i<no_of_compact_spots;i++)
               {
                   if(wing_a_ptr->status_compactspots_arr[i]==0)
                   {
                       wing = wing_a_ptr->parking_wing;
                       found =1;
                   }
               }
         }
         else
         {
             for(int i= 0;i<no_of_large_spots;i++)
             {
                 if(wing_a_ptr->status_large_spots_arr[i] == 0)
                 {
                     wing = wing_a_ptr->parking_wing;
                     found =1;
                 }
             }
             
         }

         if(found == 0)
         {

                  parking_wing_status_type *wing_b_ptr = (*parking_lot_status_pptr)->wing_b_ptr ;
            if(vehicle_type == 2)
           {
               for(int i=0;i<no_of_compact_spots;i++)
               {
                   if(wing_b_ptr->status_compactspots_arr[i]==0)
                   {
                       wing = wing_b_ptr->parking_wing;
                       found =1;
                   }
               }
           }
           else
           {
               for(int i= 0;i<no_of_large_spots;i++)
             {
                 if(wing_b_ptr->status_large_spots_arr[i] == 0)
                 {
                     wing = wing_b_ptr->parking_wing;
                     found =1;
                 }
             }
           }
         }

         if(found ==0)
         {
                  parking_wing_status_type *wing_c_ptr = (*parking_lot_status_pptr)->wing_c_ptr ;
             if(vehicle_type == 2)
             {
               for(int i=0;i<no_of_compact_spots;i++)
               {
                   if(wing_c_ptr->status_compactspots_arr[i]==0)
                   {
                       wing = wing_c_ptr->parking_wing;
                       found =1;
                   }
               }
            }
           else
           {
             for(int i= 0;i<no_of_large_spots;i++)
             {
                 if(wing_c_ptr->status_large_spots_arr[i] == 0)
                 {
                     wing = wing_c_ptr->parking_wing;
                     found =1;
                 }
             }
           }
         }
         
    }
    else
    {
        wing = retval->dedicated_parking_wing ;
    }
    

    return wing;

}

int get_dedicated_index_for_new_parked_vehicle(int vehicle_type,char vehicle_number[9],mapped_tree_node_type *mapped_tree_ptr,parking_lot_status_type **parking_lot_status_pptr)
{   int index =0;
   int found =0;
   int key = (vehicle_number[5]-'0')*1000 + (vehicle_number[6]-'0')*100+(vehicle_number[7]-'0')*10+(vehicle_number[8]-'0');
   mapped_tree_node_type *retval,*ptr = mapped_tree_ptr;

     while(ptr!=NULL && found==0)
     {
        if(ptr->key == key)
         { retval = ptr;
            found =1;

         }
        else if(ptr->key < key)
        {
            ptr = ptr->right;
        }
        else
        {
            ptr =ptr->left;
        }       
        
    }

    if(retval == NULL)
    {
         
         parking_wing_status_type *wing_a_ptr = (*parking_lot_status_pptr)->wing_a_ptr ;
         if(vehicle_type == 2)
         {
               for(int i=0;i<no_of_compact_spots;i++)
               {
                   if(wing_a_ptr->status_compactspots_arr[i]==0)
                   {
                       index = i;
                       found =1;
                   }
               }
         }
         else
         {
             for(int i= 0;i<no_of_large_spots;i++)
             {
                 if(wing_a_ptr->status_large_spots_arr[i] == 0)
                 {
                      index = i;
                     found =1;
                 }
             }
             
         }

         if(found == 0)
         {

                  parking_wing_status_type *wing_b_ptr = (*parking_lot_status_pptr)->wing_b_ptr ;
         if(vehicle_type == 2)
         {
               for(int i=0;i<no_of_compact_spots;i++)
               {
                   if(wing_b_ptr->status_compactspots_arr[i]==0)
                   {
                        index = i;
                       found =1;
                   }
               }
         }
         else
         {
             for(int i= 0;i<no_of_large_spots;i++)
             {
                 if(wing_b_ptr->status_large_spots_arr[i] == 0)
                 {
                     index = i;
                     found =1;
                 }
             }
         }
         }

         if(found ==0)
         {
                  parking_wing_status_type *wing_c_ptr = (*parking_lot_status_pptr)->wing_c_ptr ;
         if(vehicle_type == 2)
         {
               for(int i=0;i<no_of_compact_spots;i++)
               {
                   if(wing_c_ptr->status_compactspots_arr[i]==0)
                   {
                       index = i;
                       found =1;
                   }
               }
         }
         else
         {
             for(int i= 0;i<no_of_large_spots;i++)
             {
                 if(wing_c_ptr->status_large_spots_arr[i] == 0)
                 {
                      index = i;
                     found =1;
                 }
             }
         }
         }
         
    }
    else
    {
        if(vehicle_type == 2)
        index = retval->compact_spot_index;  
        else
        index = retval->large_spot_index;
    }
    

    return index;   

}





parking_db_day_type *search_parking_db_day_tree(parking_db_day_type *root,int key)
{
    parking_db_day_type *retval =NULL;
    parking_db_day_type *ptr = root;
    int found =0;

   
    
     while(ptr!=NULL && found==0)
     {
        if(ptr->key == key)
         { retval = ptr;
            found =1;

         }
        else if(ptr->key < key)
        {
            ptr = ptr->right;
        }
        else
        {
            ptr =ptr->left;
        }       
        
    }

    return retval;
    
}


void Display_Visitors(char indate[6],parking_db_day_type *root)
{
    
    int key =(indate[4]-'0')*100000+(indate[5]-'0')*10000+(indate[2]-'0')*1000+(indate[3]-'0')*100+(indate[0]-'0')*10+(indate[1]-'0')*1;
   if(root != NULL) 
    { 
       
        
        int top = root->top; 
        for(int i=0;i<top;i++)
        {  if((root->parked_vehicles_arr[i])->is_visitor)
            printf("\n parked vehicle number = %s ,dedicated_wing : %d ,compact_index : %d,large_index : %d ,isvisitor :%d , intime : %s ,outtime : %s \n",(root->parked_vehicles_arr[i])->vehicle_number,(root->parked_vehicles_arr[i])->dedicated_parking_wing_id,(root->parked_vehicles_arr[i])->dedicated_compact_spot_index,(root->parked_vehicles_arr[i])->dedicated_large_spot_index,(root->parked_vehicles_arr[i])->is_visitor,(root->parked_vehicles_arr[i])->intime,(root->parked_vehicles_arr[i])->outtime);
            
            
        }
        Display_Visitors(indate ,root->left); 
        Display_Visitors(indate ,root->right); 
    } 



}

void park_vehicle(mapped_tree_node_type *mapped_tree_ptr,parking_lot_status_type **parking_lot_status_pptr,parking_db_day_type **parking_db_day_tree_pptr,int vehicle_type,char *intime,char *indate,char *vehicle_number)
{
    
      int dedicated_index = -1;
      int dedicated_wing =-1 ;  

          parking_db_day_type *dayNode = NULL;
         // printf("%d %s %s %s \n",vehicle_type,intime,indate,vehicle_number);       
        
        int key =(indate[4]-'0')*100000+(indate[5]-'0')*10000+(indate[2]-'0')*1000+(indate[3]-'0')*100+(indate[0]-'0')*10+(indate[1]-'0')*1;
        
        dayNode = search_parking_db_day_tree(*parking_db_day_tree_pptr,key);
        if(dayNode == NULL)
        {
            

            parked_vehicle_type *newParkedVehicleNode = ( parked_vehicle_type *)malloc(sizeof(parked_vehicle_type));
           
           // strcpy(newParkedVehicleNode->intime,intime);
            for(int i=0;i<4;i++)
            {
               newParkedVehicleNode->intime[i] = intime[i] ;
            }
            newParkedVehicleNode->intime[4] ='\0';

           // strcpy(newParkedVehicleNode->indate,indate);
            for(int i=0;i<6;i++)
            {
               newParkedVehicleNode->indate[i] = indate[i] ;
            }
            newParkedVehicleNode->indate[6] ='\0';

          //  strcpy(newParkedVehicleNode->vehicle_number,vehicle_number);
            for(int i=0;i<9;i++)
            {
               newParkedVehicleNode->vehicle_number[i] = vehicle_number[i] ;
            }
            newParkedVehicleNode->vehicle_number[9] ='\0';

            printf(" \n %d %s %s %s \n",vehicle_type,newParkedVehicleNode->intime,newParkedVehicleNode->indate,newParkedVehicleNode->vehicle_number);
                  dedicated_wing = get_dedicated_wing_for_new_parked_vehicle(vehicle_type,vehicle_number,mapped_tree_ptr,parking_lot_status_pptr);
                  newParkedVehicleNode->dedicated_parking_wing_id = dedicated_wing;
                  dedicated_index = get_dedicated_index_for_new_parked_vehicle(vehicle_type,vehicle_number,mapped_tree_ptr,parking_lot_status_pptr);
               
                 newParkedVehicleNode->is_visitor = is_visitor(vehicle_number,mapped_tree_ptr);
               if(vehicle_type ==2 )
               {
                  newParkedVehicleNode->dedicated_compact_spot_index = dedicated_index;
                   newParkedVehicleNode->dedicated_large_spot_index = -1;
               }
               else
               {
                   newParkedVehicleNode->dedicated_compact_spot_index = -1;
                   newParkedVehicleNode->dedicated_large_spot_index = dedicated_index;
               }
               
            
            parking_db_day_type *newDayNode=(parking_db_day_type *)malloc(sizeof(parking_db_day_type));
            newDayNode->key = key;
           
           // printf(" \n before insertion assigneed key :%d \n", newDayNode->key);
           // strcpy(newDayNode->indate,indate);
           for(int i=0;i<6;i++)
           {
               newDayNode->indate[i] = indate[i];
           }
             
            newDayNode->left =NULL;
            newDayNode->right =NULL;
            newDayNode->top =0;
            
            newDayNode->parked_vehicles_arr[newDayNode->top]=newParkedVehicleNode;
            newDayNode->top +=1;
            
            *parking_db_day_tree_pptr = insert_parking_db_day_tree(*parking_db_day_tree_pptr,newDayNode);
           // printf(" \n after insertion assigneed key :%d \n", newDayNode->key);

         //  *parking_db_day_tree_pptr = insert_parking_db_day_tree(*parking_db_day_tree_pptr,newDayNode);
           
        }
        else
        {


             parked_vehicle_type *newParkedVehicleNode = ( parked_vehicle_type *)malloc(sizeof( parked_vehicle_type));
           // strcpy(newParkedVehicleNode->intime,intime);
            for(int i=0;i<4;i++)
            {
               newParkedVehicleNode->intime[i] = intime[i] ;
            }
            newParkedVehicleNode->intime[4] ='\0';

           // strcpy(newParkedVehicleNode->indate,indate);
            for(int i=0;i<6;i++)
            {
               newParkedVehicleNode->indate[i] = indate[i] ;
            }
            newParkedVehicleNode->indate[6] ='\0';

          //  strcpy(newParkedVehicleNode->vehicle_number,vehicle_number);
            for(int i=0;i<9;i++)
            {
               newParkedVehicleNode->vehicle_number[i] = vehicle_number[i] ;
            }
            newParkedVehicleNode->vehicle_number[9] ='\0';
            printf(" \n %d %s %s %s \n",vehicle_type,newParkedVehicleNode->intime,newParkedVehicleNode->indate,newParkedVehicleNode->vehicle_number);
                  dedicated_wing = get_dedicated_wing_for_new_parked_vehicle(vehicle_type,vehicle_number,mapped_tree_ptr,parking_lot_status_pptr);
                  newParkedVehicleNode->dedicated_parking_wing_id = dedicated_wing;                 
                  dedicated_index = get_dedicated_index_for_new_parked_vehicle(vehicle_type,vehicle_number,mapped_tree_ptr,parking_lot_status_pptr);
              
               newParkedVehicleNode->is_visitor = is_visitor(vehicle_number,mapped_tree_ptr);
               if(vehicle_type ==2 )
               {
                  newParkedVehicleNode->dedicated_compact_spot_index = dedicated_index;
                   newParkedVehicleNode->dedicated_large_spot_index = -1;
               }
               else
               {
                   newParkedVehicleNode->dedicated_compact_spot_index = -1;
                   newParkedVehicleNode->dedicated_large_spot_index = dedicated_index;
               }

              dayNode->parked_vehicles_arr[dayNode->top]=newParkedVehicleNode;
              dayNode->top +=1; 
               

            
        }
        


}


void initialize_parking_db_day_tree(mapped_tree_node_type *mapped_tree_ptr,parking_lot_status_type **parking_lot_status_pptr,parking_db_day_type **parking_db_day_tree_pptr)
{
    FILE *fp;
    fp = fopen("parking_db.txt","r");

    
    int vehicle_type;
    int dedicated_index;
    int dedicated_wing;
    char intime[4];
    char indate[6];
    char vehicle_number[9];
    

    while(fscanf(fp,"%d %s %s %s",&vehicle_type,intime,indate,vehicle_number)!=EOF)
    {
        
       park_vehicle(mapped_tree_ptr,parking_lot_status_pptr,parking_db_day_tree_pptr,vehicle_type,intime,indate,vehicle_number);;
            
        
        
    }

    return ;
}


