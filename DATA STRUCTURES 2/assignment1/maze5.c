#include<stdio.h>
#include<string.h>
#include<stdlib.h>

# define m 5
# define n 5
# define starti 1
# define startj 0
# define endi 3
# define endj 4



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
void ReInitializeMaze();

int ValidateMove(int x,int y);
void InsertPathPQ(PQNode PQptr[],TreeNode * endnode,int index);
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

int factorial(int num);


void main()
{
   InitializeMaze(); PrintMaze();//    SortPaths(PQptr);//    printOptimumPath(PQptr);
    int NoOfPossiblePaths = factorial(m+n-2)/(factorial(m-1)*factorial(n-1));
    PQNode PQptr[NoOfPossiblePaths]; InitializePQ(PQptr);// PrintPQ(PQptr);    
      TreeNode *root=NULL;
       root = CreateMazeTree(starti,startj,PQptr,root); 
      // PrintMazeTree(root); 
      // PrintPQ(PQptr); 
    
  return ;
}




TreeNode *CreateMazeTree(int x, int y,PQNode PQptr[],TreeNode *root)
{  int static count =-1;

   TreeNode *newptr = makeTreeNode(x,y,root);
  Arr[x][y].boxvar = '1';

  if(x==endi && y==endj)
  {     
       count++;            
       InsertPathPQ(PQptr,newptr,count);
      
     printf("\n for count %d \n",count);
      PrintMaze();
      PrintPath(PQptr[count].root);
            
  }
  else
  {
     if(ValidateMove(x+1,y))      //down
     {
           newptr->down = CreateMazeTree(x+1,y,PQptr,newptr);
     }
   if(ValidateMove(x,y+1))       //right
       {
          newptr->right = CreateMazeTree(x,y+1,PQptr,newptr);
       }
    if(ValidateMove(x,y-1))        //left
      {
         newptr->left = CreateMazeTree(x,y-1,PQptr,newptr);

      }
     if(ValidateMove(x-1,y))    //up
       {
         newptr->up =  CreateMazeTree(x-1,y,PQptr,newptr);

       }

  }   
  
   Arr[x][y].boxvar = '0';
    return newptr;

}

void InsertPathPQ(PQNode PQptr[],TreeNode * endnode,int index)
{
    TreeNode *ptr=endnode;

     while(ptr!=NULL)
     {
       PathNode *nptr = makePathNode(ptr->x,ptr->y);
       nptr->next = PQptr[index].root;
       PQptr[index].root = nptr;
       ptr = ptr->prev;
     }

     return ;
}



void PrintPath(PathNode * root)
{
    while(root!=NULL)
    {
        printf(" (%d, %d )   -->   ",root->x,root->y);

        root = root->next;
    }
   
}

void PrintPQ(PQNode PQptr[])
{
    int i;
    for(i=0;i<NoOfPossiblePaths;i++)
    {      printf("%d -- \n",i);
    printf("\n");
             PrintPath(PQptr[i].root);
             printf("\n");
    }
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

void PrintMazeTree(TreeNode *root)
{ if(root!=NULL)
    {
        printf("(%d,%d)",root->x,root->y);
        printf("\n-------------------\n");
        PrintMazeTree(root->down);
        PrintMazeTree(root->right);
        PrintMazeTree(root->left);               
        PrintMazeTree(root->up);
        
        
        
      
    }

}





PQNode *InitializePQ(PQNode PQptr[])
{
    int i=0,size=NoOfPossiblePaths;
    for(i=0;i<size;i++)
    {
       PQptr[i].root=NULL;
    }
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


void ReInitializeMaze()
{
    printf("\n hi,ia m in function reinitalzemaze() \n");
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(Arr[i][j].boxvar == '1')
            {
                Arr[i][j].boxvar = '0';
            }
        }
    }
}



TreeNode *makeTreeNode(int x,int y,TreeNode *prev)
{
    TreeNode *ptr= (TreeNode*)malloc(sizeof(TreeNode));

    ptr->x=x;
    ptr->y=y;
    ptr->prev=prev;

    ptr->down=NULL;
    ptr->left=NULL;
    ptr->right=NULL;
    ptr->up=NULL;
}

PathNode *makePathNode(int x,int y)
{
    PathNode *ptr = (PathNode*)malloc(sizeof(PathNode));
    ptr->x=x;
    ptr->y=y;
    ptr->next=NULL;
}

int ValidateMove(int x,int y)
{  int retval ;

     if(x<m && y<n && x>=0 && y>=0)
     {
          if(Arr[x][y].boxvar == '@'  || Arr[x][y].boxvar == '0' )
          {
              retval =1;
          }
          else
          {
              retval=0;
          }
          
     }
     else
     {
         retval =0;
     }

     return retval;
     
}


int factorial(int num)
{
    int retval=1,i;
    for(i=1;i<=n;i++)
    {
        retval = retval*i;
    }

    return retval;
}