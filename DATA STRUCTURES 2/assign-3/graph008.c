#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef enum {FALSE =0 ,TRUE =1 }boolean;
typedef enum{success =1 ,failure =0}status;

#define QueueSize 100
typedef struct EdgeNodeTag
{    char graphNodeName; 
    struct EdgeNodeTag *right;
    int weight;

}EdgeNode;

typedef struct VertexNodeTag
{
    char graphNodeName;
    int mark;  //  0 = unmarked , 1 = marked      
    struct VertexNodeTag *down;
    EdgeNode *right;

}VertexNode;

typedef struct graphTag
{
    VertexNode *VertexListRoot;
    int isWeightedGraph;
    int isDirectedGraph;

}graph;


typedef struct QueueTag
{
    char Arr[QueueSize];
    int front;
    int rear;
    boolean isfull;
}Queue;

//**********************************************************
Queue *initializeQueue();
status push(Queue *,char );
char pop(Queue *);
boolean isEmpty(Queue *);
boolean isFull(Queue *);
void printQueue(Queue *);
//**********************************************************


//**********************************************************
graph *initializeGraph();

graph *addVertex(graph *, char nodeName);
graph *deleteVertex(graph * , char nodeName);

graph *addEdge(graph *, char startNodeName ,char endNodeName ,int weight);
graph *deleteEdge(graph *, char startNodeName ,char endNodeName);

//***********************************************************



//***********************************************************
void simplyDisplay(graph *);
void displayDepthFirst(graph *graphPtr , char startPoint);
void displayBreadthFirst(graph *graphPtr , Queue *qptr);
void displayTopoSort();
//***********************************************************

//****************************************************************
#define INF 1000
void dijkstra(int no_of_vertex,int grapharr[][no_of_vertex]);
boolean isAllFound(int no_of_vertex,int arr[no_of_vertex]);
int selMin(int no_of_vertex,int found[],int dist[]);
//****************************************************************

//****************************************************************
void apsp(int no_of_vertex,int grapharr[][no_of_vertex]);
//****************************************************************

status BreadthFirstSearch(graph *,char ,char );
status BreadthFirstAlgo(graph *gp,Queue *qptr,char endPoint);
status DepthFirstSearch(graph *,char ,char );
status DepthFirstAlgo(graph *,char ,char );

boolean isPathExists(graph * ,char , char );
boolean isDisConnected(graph *);

VertexNode *insertVertexNode(VertexNode * ,VertexNode *);
EdgeNode *insertEdgeNode(EdgeNode * ,EdgeNode *);
void markVertex(graph *,char );
boolean isMarked(graph *,char ele);
void markedNodes(graph *);



void main()
{
      graph *graphPtr = initializeGraph();
      simplyDisplay(graphPtr);
      DepthFirstSearch(graphPtr,'A','D');

       
    
    

    //  graph *graphPtr = initializeGraph();
    // simplyDisplay(graphPtr);
    // BreadthFirstSearch(graphPtr,'C','A');

    //  int Arr2[3][3] = {{0,4,11},{6,0,2},{3,INF,0}};
    //  apsp(3,Arr2);

    

    //  int Arr[5][5] ={{0,2,5,INF,3},
    //                 {INF,0,6,4,10},
    //                 {INF,INF,0,INF,2},
    //                 {INF,INF,INF,0,INF},
    //                 {INF,INF,1,2,0}};

    //  dijkstra(5,Arr);
    //  printf("\n\n\n");
    //  int Arr1[6][6] = {{0,50,45,20,INF,INF},
    //                     {INF,0,10,15,INF,INF},
    //                     {INF,INF,0,INF,30,INF},
    //                     {10,INF,INF,0,15,INF},
    //                     {INF,20,35,INF,0,INF},
    //                     {INF,INF,INF,INF,23,0}};

    //   dijkstra(6,Arr1);              

    // graph *graphPtr = initializeGraph();
    // simplyDisplay(graphPtr);
    // printf("\n printing graph using depth first search :\n");
    // displayDepthFirst(graphPtr,'A');

    // Queue *qptr = initializeQueue();
    // push(qptr,'A');
    // markVertex(graphPtr,'A');
    // printf("\n graph using breadth first \n");
    // displayBreadthFirst(graphPtr,qptr);

   
    // printf("\n adding edge A ->D with weight = 23\n");
    // addEdge(graphPtr,'A','D',23);
    // simplyDisplay(graphPtr);


    // printf("\n adding node F\n");
    // addVertex(graphPtr,'F');
    // simplyDisplay(graphPtr);

    // printf("\n deleting node  ' B '\n");
    //  deleteVertex(graphPtr,'B');
    // simplyDisplay(graphPtr);

    // printf("\n deleting edge A->B\n");
    // deleteEdge(graphPtr,'A','D');
    // simplyDisplay(graphPtr);
}

//*********************************************************************
//******** search : breadth first  ********************************
status BreadthFirstSearch(graph *gp,char startPoint,char endPoint )
{   status isfound = failure;
    Queue *qptr = initializeQueue();
    push(qptr,startPoint);
    markVertex(gp,startPoint);

    isfound = BreadthFirstAlgo(gp,qptr,endPoint);

    if(isfound)
    {
        printf("\n path %c -> %c exists\n",startPoint,endPoint);
    }
    else
    {
         printf("\n path %c -> %c does not exists\n",startPoint,endPoint);
       
    }
    

}

status BreadthFirstAlgo(graph *gp,Queue *qptr,char endPoint)
{
    status retval = failure;
     char printChar = pop(qptr);

     if(printChar == endPoint)
     {
         retval = success;
     }
     else
     {
         if(printChar == '\0')
         {
             retval = failure;
         }
         else
         {   // printf("[ %c ] ",printChar);
             VertexNode *vptr = gp->VertexListRoot;

               while(vptr->graphNodeName != printChar)
               {
                   vptr = vptr->down;
               }

                EdgeNode *egptr = vptr->right;
                while(egptr != NULL)
                {
                    
                        if(isMarked(gp,egptr->graphNodeName) == 0)
                        {
                            push(qptr,egptr->graphNodeName);
                            markVertex(gp,egptr->graphNodeName);
                        //  printf(" [ %c ] ",egptr->graphNodeName);

                        }

                        egptr =egptr->right;
                    
                }
                
                   // markVertex(graphPtr,printChar);
                   // markedNodes(graphPtr);
                   // printf("\n");
                  // printQueue(qptr);
                 retval = BreadthFirstAlgo(gp,qptr,endPoint);
         }
         
     }
 return retval;

}

//***********search : depth first *********************************
status DepthFirstSearch(graph *gp,char startPoint,char endPoint )
{
        if(DepthFirstAlgo(gp,startPoint,endPoint))
        {
            printf("\n path exists :\n");
        }
        else
        {
            printf("\n path does not exists :\n");
        }
     
}

status DepthFirstAlgo(graph *gp,char startPoint,char endPoint )
{
    status retval = failure;
     VertexNode *vptr = gp->VertexListRoot;

        while(vptr->graphNodeName != startPoint  )
        {
            vptr = vptr->down;
        }

        if(vptr->mark == 0)
        {
            vptr->mark = 1;
            if(vptr->graphNodeName == endPoint)
            {
                retval = success;
            }
            else
            {
                EdgeNode *cnPtr =vptr->right;
                while(cnPtr != NULL && retval==failure)
                {
                    retval = DepthFirstAlgo(gp,cnPtr->graphNodeName,endPoint);
                    cnPtr = cnPtr->right;
                }
                /* code */
            }
           
        }
        
        
        
       return retval; 

}
//**********************************************************************



//*************************************************************************
//********** shortest path : [ APSP ] all pair shortest path alogoritm **************
void apsp(int no_of_vertex,int grapharr[][no_of_vertex])
{
        int prev[no_of_vertex][no_of_vertex];

        for(int i=0;i<no_of_vertex;i++)
        {
            for(int j=0;j<no_of_vertex;j++)
            {
                prev[i][j] = i;
            }
        }


    for(int k=0;k<no_of_vertex;k++)
    {
        for(int i=0;i<no_of_vertex;i++)
        {
            for(int j=0;j<no_of_vertex;j++)
            {
                if(grapharr[i][k] + grapharr[k][j] < grapharr[i][j])
                {
                    grapharr[i][j] = grapharr[i][k] + grapharr[k][j] ;
                    prev[i][j] = k;
                }
            }
        }


         for(int i=0;i<no_of_vertex;i++)
        {
            for(int j=0;j<no_of_vertex;j++)
            {
                printf("[ %d ]",grapharr[i][j]);
            }
            printf("\n");
        }
        printf("\n\n");

    }

       for(int i=0;i<no_of_vertex;i++)
        {
            for(int j=0;j<no_of_vertex;j++)
            {
                printf("\n reverse path [%d]->[%d]",i,j);
                int m= i;
                printf("[%d]",j);
                while(prev[m][j] != j)
                {
                     printf("<-[%d]",prev[m][j]);
                     m = prev[m][j];
                    
                }
                printf("<-[%d]",i);
                
            }
            printf("\n");
        }
        printf("\n\n");


}

//************************************************************************



//**********************************************************************
//****************** shortest path : dijkstras alogithm ****************

void dijkstra(int no_of_vertex,int grapharr[][no_of_vertex])
{      //initialization of prev array 
        int prev[no_of_vertex];
        for(int i=0;i<no_of_vertex;i++)
        {
            prev[i] = -1;
        }
   
      // initialization of found array 
        int found[no_of_vertex];
        for(int i=0;i<no_of_vertex;i++)
        {
            found[i] = 0;
        }

     //initialization of dist array 
        int dist[no_of_vertex];
        for(int i=0;i<no_of_vertex;i++)
        {
            dist[i] = grapharr[0][i];
            prev[i] = 0;
        }
        found[0] = 1;

    while(isAllFound(no_of_vertex,found) == FALSE)
    {
        int minindex = selMin(no_of_vertex,found,dist);
        found[minindex] = 1;

        for(int i=0;i<no_of_vertex;i++)
        {
            if(found[i] == 0)
            {
                if(dist[minindex] + grapharr[minindex][i]<dist[i])
                {
                    dist[i] = dist[minindex] + grapharr[minindex][i];
                    prev[i] = minindex;
                }
            }
        }

        //  printf("\n found index : %d  \n dist array :",minindex);
        //  for(int i=0;i<no_of_vertex;i++)
        //  {
        //    printf("[ %d ]",dist[i]);
        //  }
        //  printf("\n");
   

    }

    printf("\n shortest paths : ");
    for(int i=1;i<no_of_vertex;i++)
    {    printf("\n path : [A]->[%C] length : %d ",'A'+i,dist[i]);
         printf("reverse path : "); 
         printf("[ %c ] ",'A'+i);
         int j = i;
           while(prev[j] != 0)
            {
                printf("<-[ %c ] ",'A'+prev[i]);
                j = prev[j];
                
            }
        printf("<-[ %c ] ",'A');
       
    }
    printf("\n");

    
    
}

boolean isAllFound(int no_of_vertex,int arr[no_of_vertex])
{ boolean retval = TRUE;
   for(int i=0;i<no_of_vertex;i++)
   {
       if(arr[i] == 0)
       retval = FALSE;
   }

   return retval;

}

int selMin(int no_of_vertex,int found[],int dist[])
{
    int minindex = -1;
    int min = INF;

    for(int i=0;i<no_of_vertex;i++)
    {
        if(dist[i] <= min && found[i] == 0)
        {
            min = dist[i];
            minindex = i;
        }
    }

    return minindex;


}
//***************************************************************



//**************************************************************************
//*********************** mark functions ***********************************

void markedNodes(graph *gp)
{
    VertexNode *vptr = gp->VertexListRoot;
       printf("printing marked nodes ");
            while(vptr != NULL)
            {
                 if(vptr->mark != 0)
                 {
                   printf("[ %c ]",vptr->graphNodeName);
                 }
        
                vptr = vptr->down;
            }
            printf("\n\n");

}

void markVertex(graph *graphPtr,char ele )
{
  VertexNode *vptr = graphPtr->VertexListRoot;
  while(vptr->graphNodeName != ele)
  {
      vptr = vptr->down;
  }

  if(vptr != NULL)
  {
      vptr->mark = 1;
  }
  else
  {
      printf("\n tht entered node to mark : [ %c ]is absent in graph \n",ele);
  }
  

}

boolean isMarked(graph *graphPtr,char ele)
{
     VertexNode *vptr = graphPtr->VertexListRoot;

            while(vptr->graphNodeName != ele)
            {
                vptr = vptr->down;
            }

       if(vptr != NULL)
       {
            if(vptr->mark == 0)
            {
                return FALSE;
            }
            else
            {
                return TRUE;
            }

       }
       else
       {
         printf("\n tht entered node to mark : [ %c ]is absent in graph \n",ele);
         return TRUE;
       }
       

        

}

boolean isAllMarked(graph *graphPtr,char ele)
{
    VertexNode *vptr = graphPtr->VertexListRoot;
    boolean retval = TRUE;

    while(vptr != NULL  && retval == TRUE)
    {
        if(vptr->mark == 0)
        {
            retval = FALSE;
        }
        vptr = vptr->down;
        
    }

    return retval;

}
//********************************************************************************



//*******************************************************************************
//************ graph standard functions ****************************************

graph *initializeGraph()
{
    int N=5;
    graph *graphPtr = (graph *)malloc(sizeof(graph));
    printf("\n enter graph details :\n");
    printf("\n is your graph weighted \n 0.no \n 1.yes \n");
    scanf("%d",&graphPtr->isWeightedGraph);
    printf("\n is your graph directed \n 0.no \n 1.yes \n");
    scanf("%d",&graphPtr->isDirectedGraph);
    graphPtr->VertexListRoot = NULL;
    // printf("\n enter no of nodes u wanted to enter in your graph initially \n");
    // scanf("%d",&N);

       simplyDisplay(graphPtr);
    int Arr[5][5] ={{0,2,5,1000,3},{0,0,6,4,10},{0,0,0,0,2},{0,0,0,0,0},{0,0,1,2,0}};
    for(int i=0;i<5;i++)
    {
        VertexNode *newVertexNode =(VertexNode *)malloc(sizeof(VertexNode));
        newVertexNode->graphNodeName ='A' + i;
        newVertexNode->mark = 0;
        newVertexNode->down = NULL;
        newVertexNode->right =NULL;
        

        for(int j=0;j<5;j++)
        {
            if(Arr[i][j] < 1000 && Arr[i][j] != 0)
            {
                EdgeNode *newEdgeNode = (EdgeNode *)malloc(sizeof(EdgeNode));
                newEdgeNode->graphNodeName = 'A' +j;
                newEdgeNode->weight = Arr[i][j];
                newEdgeNode->right =NULL;
                newVertexNode->right = insertEdgeNode(newVertexNode->right,newEdgeNode);
            }

        }
        
        graphPtr->VertexListRoot = insertVertexNode(graphPtr->VertexListRoot,newVertexNode);

       
    }
}

VertexNode *insertVertexNode(VertexNode *root,VertexNode *newNode)
{
    
    if(root ==NULL)
    {
        root = newNode;
    }
    else
    {
        VertexNode *ptr =root;
        while(ptr->down != NULL)
        {
            ptr =ptr->down;
        }
        ptr->down = newNode;
    }
    
  return root;
}

EdgeNode *insertEdgeNode(EdgeNode *root ,EdgeNode *newNode)
{
    if(root ==NULL)
    {
        root = newNode;
    }
    else
    {
        EdgeNode *ptr =root;
        while(ptr->right != NULL)
        {
            ptr =ptr->right;
        }
        ptr->right = newNode;
    }
    
  return root;

}

void simplyDisplay(graph *graphPtr)
{
    
    VertexNode *ptr1 =graphPtr->VertexListRoot;
   EdgeNode *ptr2 =NULL;

    if(graphPtr == NULL)
    {
         printf("\n graph is not initialized proprly \n");
    }
    else
    {
        while(ptr1 != NULL)
        {
            ptr2 = ptr1->right;
            printf("\n [ %c ]",ptr1->graphNodeName);
            while(ptr2 != NULL)
            {
                printf(" ( %c )",ptr2->graphNodeName);
                ptr2 = ptr2->right;
            }
            printf("\n");
            ptr1 = ptr1->down;
        }
        
    }
   

}

graph *addVertex(graph *graphPtr, char nodeName)
{
    VertexNode * newVertexNode = (VertexNode *)malloc(sizeof(VertexNode));
        newVertexNode->graphNodeName =nodeName;
        newVertexNode->mark = 0;
        newVertexNode->down = NULL;
        newVertexNode->right =NULL;
    graphPtr->VertexListRoot = insertVertexNode(graphPtr->VertexListRoot,newVertexNode);
    return graphPtr;

}

graph *deleteVertex(graph *graphPtr , char nodeName)
{
  VertexNode *prev = graphPtr->VertexListRoot,*ptr = graphPtr->VertexListRoot;

  while(ptr!= NULL && ptr->graphNodeName != nodeName)
  {
      prev = ptr;
      ptr = ptr->down;
  }

  if(ptr == NULL)
  {
      printf("\n this node is not present in graph \n");
  }
  else
  {
            if(prev == ptr)
            {
                graphPtr->VertexListRoot = ptr->down;
                ptr->down = NULL;
                free(ptr);

                VertexNode *ptr1 =graphPtr->VertexListRoot;
                while(ptr1 != NULL)
                {
                    deleteEdge(graphPtr,ptr1->graphNodeName,nodeName);
                    ptr1 = ptr1->down;
                }
                

            }
            else
            {
                prev->down = ptr->down;    // removing VertexNode 
                ptr->down = NULL;
                free(ptr);

                VertexNode *ptr1 =graphPtr->VertexListRoot;
                while(ptr1 != NULL)
                {
                    deleteEdge(graphPtr,ptr1->graphNodeName,nodeName);
                    ptr1 = ptr1->down;
                }

      }
      
     
  }

}

graph *addEdge(graph *graphPtr, char startNodeName ,char endNodeName ,int weight)
{
    VertexNode *ptr1 =graphPtr->VertexListRoot ,*ptr2 = graphPtr->VertexListRoot;

    while(ptr1 != NULL && ptr1->graphNodeName != startNodeName)
    {
        ptr1 = ptr1->down;
    }

    while(ptr2 != NULL && ptr2->graphNodeName != startNodeName)
    {
        ptr2 = ptr2->down;
    }

    if(ptr1 == NULL  || ptr2 == NULL)
    {
        printf("\n ONE OF YOUR ENTERED NODE IS NOT PRESENT IN GRAPH is not present in graph , u should first add node \n");
    }
    else
    {
        EdgeNode *newEdgeNode = ( EdgeNode *)malloc(sizeof(EdgeNode));
        newEdgeNode->graphNodeName = endNodeName;
        newEdgeNode->right = NULL;
        newEdgeNode->weight = weight;

        EdgeNode *cnPtr = ptr1->right;
        while(cnPtr->right != NULL)
        {
            cnPtr = cnPtr->right;
        }
        cnPtr->right = newEdgeNode;

       
    }
    
   
   return graphPtr; 

}

graph *deleteEdge(graph *graphPtr, char startNodeName ,char endNodeName)
{
    VertexNode *ptr = graphPtr->VertexListRoot;

    while(ptr!= NULL && ptr->graphNodeName != startNodeName)
    {
        ptr = ptr->down;
    }

    if(ptr == NULL)
    {
        printf("\n given edge is not present in graph\n");
    }
    else
     {     EdgeNode *ptr1 =ptr->right ,*prev =ptr->right;
                while(ptr1 != NULL && ptr1->graphNodeName != endNodeName)
                {
                    prev = ptr1;
                    ptr1 = ptr1->right;
                }

                  if(ptr1 == NULL)
                  {
                      printf("\n given edge is not present in graph\n");

                  }
                  else
                 {
                    if(prev != ptr1)
                    {
                        prev->right = ptr1->right;
                        ptr1->right = NULL;
                        free(ptr1);
                    }
                    else
                    {
                        ptr->right = ptr1->right;
                        free(ptr1);
                        
                    }
                    
                 }
     }
    

    

    return graphPtr;

}

boolean isPathExists(graph *graphPtr ,char startNodeName, char endNodeName)
{
    boolean retval =FALSE;
    VertexNode *vptr = graphPtr->VertexListRoot;

    while(vptr->graphNodeName != startNodeName )
    {
        vptr = vptr->down;
    }

    if(vptr->graphNodeName == endNodeName)
    { 
        retval = TRUE;
     
    }
    else
    {
       
        vptr->mark = 1;
        EdgeNode *cnPtr =vptr->right;
        while(cnPtr != NULL)
        {
            retval = isPathExists(graphPtr,cnPtr->graphNodeName,endNodeName);
            cnPtr = cnPtr->right;
        }

    }

    return retval;


}

boolean isDisConnected(graph *graphPtr)
{
    VertexNode *vptr1 = graphPtr->VertexListRoot,*vptr2 = graphPtr->VertexListRoot;
      boolean retval = TRUE;
    while(vptr1 != NULL)
    {
        vptr2 = graphPtr->VertexListRoot;
        while(vptr2 != NULL && retval == TRUE)
        {
            if(vptr1 != vptr2)
            {
                if(isPathExists(graphPtr,vptr1->graphNodeName,vptr2->graphNodeName) == 0)
                retval = FALSE;
            }
        }

    }

    return retval;

}

//************************************************************************************




//************************************************************************
// **************** display graph via : breadth first ********************************

void displayBreadthFirst(graph *graphPtr , Queue *qptr)
{
    char printChar = pop(qptr);
    if(printChar != '\0')
    {
        printf("[ %c ] ",printChar);
             VertexNode *vptr = graphPtr->VertexListRoot;
               while(vptr->graphNodeName != printChar)
               {
                   vptr = vptr->down;
               }
                    EdgeNode *egptr = vptr->right;
                    while(egptr != NULL)
                    {
                       
                          if(isMarked(graphPtr,egptr->graphNodeName) == 0)
                          {
                              push(qptr,egptr->graphNodeName);
                              markVertex(graphPtr,egptr->graphNodeName);
                            //  printf(" [ %c ] ",egptr->graphNodeName);

                          }

                          egptr =egptr->right;
                        
                    }
                    
                   // markVertex(graphPtr,printChar);
                   // markedNodes(graphPtr);
                   // printf("\n");
                  // printQueue(qptr);
                  displayBreadthFirst(graphPtr,qptr);
     }
     else
     {
         return ;
     }
     
   
   

}

Queue *initializeQueue()
{
    Queue *qptr =(Queue *)malloc(sizeof(Queue));

    for(int i=0;i<QueueSize;i++)
    {
        qptr->Arr[i] ='\0';
    }

    qptr->front = 0;
    qptr->rear = -1;
    qptr->isfull = FALSE;
}

status push(Queue *qptr,char ele)
{
    if(isFull(qptr))
    {
        printf("\n queue is  full \n");
        return failure;
    }
    else
    {
       
            qptr->rear = (qptr->rear +1)%QueueSize;
            qptr->Arr[qptr->rear] = ele;
            
            if((qptr->rear + 1)%QueueSize == qptr->front)
            {
                qptr->isfull = TRUE; 
            }

       
        

    }
    

}

char pop(Queue *qptr)
{
    char delchar = '\0';

    if(isEmpty(qptr))
    {
        printf("\n queue is empty \n");
        // exit(1);
    }
    else
    {
        delchar = qptr->Arr[qptr->front] ;
        qptr->Arr[qptr->front] = '\0';
        qptr->front = (qptr->front +1)%QueueSize;
       
    }
   
   
    return delchar;
    

}

boolean isEmpty(Queue *qptr)
{
    if(qptr->front ==(qptr->rear +1)%QueueSize  && qptr->isfull == FALSE)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
    

}

boolean isFull(Queue *qptr)
{
   if(qptr->front ==(qptr->rear +1)%QueueSize  && qptr->isfull == TRUE)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
    
}

void printQueue(Queue *qptr)
{ 
    printf("queue status :");
  for(int i=0;i<QueueSize;i++)
  {
      if(qptr->Arr[i] != '\0')
      {
         printf("[ %c ]",qptr->Arr[i]);
      }
        

  }

   

}

//**************************** display graph via : depth first  *********************************
void displayDepthFirst(graph *graphPtr , char startPoint)
{
    VertexNode *vptr = graphPtr->VertexListRoot;

    while(vptr->graphNodeName != startPoint  )
    {
        vptr = vptr->down;
    }

    if(vptr->mark == 1)
    { 
        return ;
     
    }
    else
    {
        printf("\t [ %c ]\t",vptr->graphNodeName);
        vptr->mark = 1;
        EdgeNode *cnPtr =vptr->right;
        while(cnPtr != NULL)
        {
            displayDepthFirst(graphPtr,cnPtr->graphNodeName);
            cnPtr = cnPtr->right;
        }

    }
     
    

}
//**********************************************************************************