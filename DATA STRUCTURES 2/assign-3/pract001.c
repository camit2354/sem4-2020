#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef enum {FALSE =0 ,TRUE =1 }boolean;
typedef enum{success =1 ,failure =0}status;
#define INF 1000

typedef struct EdgeNodeTag
{   
     struct VertexNode 
    {
        char graphNodeName;
        int mark;  //  0 = unmarked , 1 = marked      
        struct VertexNodeTag *down;
        struct EdgeNodeTag *right;
    }*startVertex,*endVertex;

     char graphNodeName; 
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




void simplyDisplay(graph *);
graph *initializeGraph();

graph *addVertex(graph *, char nodeName);
graph *deleteVertex(graph * , char nodeName);

graph *addEdge(graph *, char startNodeName ,char endNodeName ,int weight);
graph *deleteEdge(graph *, char startNodeName ,char endNodeName);

graph *CreateMST(graph *);


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
     // CreateMST(graphPtr);

    //   graph *graphPtr = initializeGraph();
    //   simplyDisplay(graphPtr);
    //   DepthFirstSearch(graphPtr,'A','D');


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

//**************minimum spanning tree :  Calculate and display  ********************
graph *CreateMST(graph *gp)
{
    graph *gp1 = gp;
    simplyDisplay(gp1);
  
}

EdgeNode *LowestWeightEdge(graph *gp)
{
    EdgeNode *retedge = NULL;
    VertexNode *vptr = gp->VertexListRoot;
    EdgeNode *egptr = vptr->right;
    retedge = egptr;
    while(vptr != NULL)
    {
        egptr = vptr->right;
        while(egptr != NULL)
        {  if(retedge->weight > egptr->weight )
           {
             retedge = egptr;
           }
            egptr = egptr->right;
        }
        vptr = vptr->down;
    }

    return retedge;
}
//*************************************************************************************

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
   // int Arr[5][5] ={{0,2,5,1000,3},{0,0,6,4,10},{0,0,0,0,2},{0,0,0,0,0},{0,0,1,2,0}};
    int Arr[7][7] = {{0,28,INF,INF,INF,10,INF},
                        {28,0,16,INF,INF,INF,14},
                        {INF,16,0,12,INF,INF,INF},
                        {INF,INF,12,0,22,INF,18},
                        {INF,INF,INF,22,0,25,24},
                        {INF,INF,INF,INF,25,0,INF},
                        {INF,14,INF,18,24,INF,0}};
    for(int i=0;i<7;i++)
    {
        VertexNode *newVertexNode =(VertexNode *)malloc(sizeof(VertexNode));
        newVertexNode->graphNodeName ='0' + i;
        newVertexNode->mark = 0;
        newVertexNode->down = NULL;
        newVertexNode->right =NULL;
        

        for(int j=0;j<7;j++)
        {
            if(Arr[i][j] < 1000 && Arr[i][j] != 0)
            {
                EdgeNode *newEdgeNode = (EdgeNode *)malloc(sizeof(EdgeNode));
                newEdgeNode->graphNodeName = '0' +j;
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
            printf("\n [ %c ] : ",ptr1->graphNodeName);
            while(ptr2 != NULL)
            {
                printf(" ( %c ) : start :%c end :%c \t",ptr2->graphNodeName,ptr2->startVertex->graphNodeName,ptr2->endVertex->graphNodeName);
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
        newEdgeNode->startVertex = ptr1;
        newEdgeNode->endVertex = ptr2;

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
        while(cnPtr != NULL && retval == FALSE)
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





