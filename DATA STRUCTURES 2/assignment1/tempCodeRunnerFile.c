TreeNode *CreateMazeTree(int x, int y,PQNode PQptr[],TreeNode *root)
// {  int static count =-1;

//    TreeNode *newptr = makeTreeNode(x,y,root);
//    Arr[x][y].boxvar = '1';

//   if(x==endi && y==endj)
//   {     
//        count++;            
//        InsertPathPQ(newptr,count);
            
//   }
//   else
//   {
//      if(ValidateMove(x+1,y))      //down
//      {
//            newptr->down = CreateMazeTree(x+1,y,PQptr,newptr);
//      }
//    if(ValidateMove(x,y+1))       //right
//        {
//           newptr->right = CreateMazeTree(x,y+1,PQptr,newptr);
//        }
//     if(ValidateMove(x,y-1))        //left
//       {
//          newptr->left = CreateMazeTree(x,y-1,PQptr,newptr);

//       }
//      if(ValidateMove(x-1,y))    //up
//        {
//          newptr->up =  CreateMazeTree(x-1,y,PQptr,newptr);

//        }

//   }   
  

//     return newptr;

// }

// TreeNode *makeTreeNode(int x,int y,TreeNode *prev)
// {
//     TreeNode *ptr= (TreeNode*)malloc(sizeof(TreeNode));

//     ptr->x=x;
//     ptr->y=y;
//     ptr->prev=prev;

//     ptr->down=NULL;
//     ptr->left=NULL;
//     ptr->right=NULL;
//     ptr->up=NULL;
// }

// PathNode *makePathNode(int x,int y)
// {
//     PathNode *ptr = (PathNode*)malloc(sizeof(PathNode));
//     ptr->x=x;
//     ptr->y=y;
//     ptr->next=NULL;
// }

// int ValidateMove(int x,int y)
// {  int retval ;

//      if(x<m && y<n )
//      {
//           if(Arr[x][y].boxvar == '@'  || Arr[x][y].boxvar == '0' )
//           {
//               retval =1;
//           }
//           else
//           {
//               retval=0;
//           }
          
//      }
//      else
//      {
//          retval =0;
//      }

//      return retval;
     
// }




// void PrintPath(PathNode * root)
// {
//     while(root!=NULL)
//     {
//         printf(" i= %d j=%d --> ",root->x,root->y);

//         root = root->next;
//     }
//     printf(".........................\n");
// }

// void PrintPQ(PQNode PQptr[])
// {
//     int i;
//     for(i=0;i<m*n;i++)
//     {      printf("%d",i);
//              PrintPath(PQptr[i].root);
//     }
// }





// PQNode *InitializePQ(PQNode PQptr[])
// {
//     int i=0,size=m*n;
//     for(i=0;i<size;i++)
//     {
//        PQptr[i].root=NULL;
//     }
// }


