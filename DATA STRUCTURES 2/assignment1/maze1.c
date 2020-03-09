#include<stdio.h>
#include<string.h>
#include<stdlib.h>

# define m 10
# define n 10
# define starti 1
# define startj 1
# define endi 7
# define endj 8

typedef struct 
{
    char boxvar;

}BoxNode;


typedef struct TreeNodeTag
{
    int x,y;
    struct TreeNodeTag *up,*down,*right,*left;
    struct TreeNodeTag *prev;
}TreeNode;

typedef struct PathNodeTag
{
    int x,y;
    struct PathNodeTag *next;

}PathNode;

typedef struct PQNodeTag
{
   PathNode *root;
}PQNode;




// BoxNode Arr[m][n] ={{'#','#','#','#','#','#','#','#','#','#'},{'0','0','0','0','0','0','0','0','0','0'},{},{},{},{},{},{},{},{}};
 BoxNode Arr[m][n] ;


void InitializeMaze();
PQNode *InitializePQ(PQNode PQptr[]);

int ValidateMove(int x,int y);
void InsertPathPQ(TreeNode * endnode,int index);
TreeNode *CreateMazeTree(int x, int y,PQNode[],TreeNode *root);
PQNode *SortPaths(PQNode *PQptr);
void printOptimumPath(PQNode *PQptr);

void PrintMaze();
void PrintPQ(PQNode *PQptr);
void PrintPath(PathNode * root);
void PrintMazeTree();

TreeNode *makeTreeNode(int x,int y,TreeNode *prev);
BoxNode *makeBoxNode(char symbol);
PathNode *makePathNode(int x,int y);
PQNode *makePQNode( PathNode *rootptr);

void main()
{
   InitializeMaze(); PrintMaze();

//     PQNode PQptr[m*n]; InitializePQ(PQptr);PrintPQ(PQptr);
    
//    TreeNode *root=NULL;
//    root = CreateMazeTree(starti,startj,PQptr,root);
//    SortPaths(PQptr);
//    printOptimumPath(PQptr);
   
    
  return ;
}


void InitializeMaze()
{
     int i=0,j=0;
    FILE *filePointer;
    char ch;

    filePointer = fopen("mazefile.txt", "r");
    
    if (filePointer == NULL)
    {
        printf("File is not available \n");
    }
    else
    {
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                ch =fgetc(filePointer);
                Arr[i][j].boxvar = ch;
            }
        }
       
    }
    
    fclose(filePointer);
    return ;

}

void PrintMaze()
{
    int i,j;
   char symbol;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            symbol = Arr[i][j].boxvar;
            printf("%c",symbol);           
        }
        printf("\n");
    }
}

// TreeNode *CreateMazeTree(int x, int y,PQNode PQptr[],TreeNode *root)
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


