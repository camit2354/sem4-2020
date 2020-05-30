#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef enum {FALSE =0 ,TRUE =1 }boolen;
typedef struct ConnectNodeTag
{    char graphNodeName; 
    struct ConnectNodeTag *right;
    int weight;

}ConnectNode;

typedef struct AdjListNodeTag
{
    char graphNodeName;
    int mark;  //  0 = unmarked , 1 = marked      
    struct AdjListNodeTag *down;
    ConnectNode *right;

}AdjListNode;

typedef struct graphTag
{
    AdjListNode *AdjListPtr;
    int isWeightedGraph;
    int isDirectedGraph;

}graph;

graph *initializeGraph();
graph *addNode(graph *, char nodeName);
graph *deleteNode(graph * , char nodeName);
graph *addEdge(graph *, char startNodeName ,char endNodeName ,int weight);
graph *deleteEdge(graph *, char startNodeName ,char endNodeName);
void simplyDisplay(graph *);
void displayDepthFirst(graph *graphPtr , char startPoint);
void displayBreadthFirst();
void displayTopoSort();
boolen isPathExists(graph * ,char , char );
void isDisConnected();
AdjListNode *insertAdjListNode(AdjListNode * ,AdjListNode *);
ConnectNode *insertConnectNode(ConnectNode * ,ConnectNode *);

void main()
{

    graph *graphPtr = initializeGraph();
    simplyDisplay(graphPtr);
    printf("\n printing graph using depth first search :\n");
    displayDepthFirst(graphPtr,'A');

  
   
    // printf("\n adding edge A ->D with weight = 23\n");
    // addEdge(graphPtr,'A','D',23);
    // simplyDisplay(graphPtr);


    // printf("\n adding node F\n");
    // addNode(graphPtr,'F');
    // simplyDisplay(graphPtr);

    // printf("\n deleting node  ' B '\n");
    //  deleteNode(graphPtr,'B');
    // simplyDisplay(graphPtr);

    // printf("\n deleting edge A->B\n");
    // deleteEdge(graphPtr,'A','D');
    // simplyDisplay(graphPtr);
}

graph *initializeGraph()
{
    int N=5;
    graph *graphPtr = (graph *)malloc(sizeof(graph));
    printf("\n enter graph details :\n");
    printf("\n is your graph weighted \n 0.no \n 1.yes \n");
    scanf("%d",&graphPtr->isWeightedGraph);
    printf("\n is your graph directed \n 0.no \n 1.yes \n");
    scanf("%d",&graphPtr->isDirectedGraph);
    graphPtr->AdjListPtr = NULL;
    // printf("\n enter no of nodes u wanted to enter in your graph initially \n");
    // scanf("%d",&N);

       simplyDisplay(graphPtr);
    int Arr[5][5] ={{0,2,5,1000,3},{0,0,6,4,10},{0,0,0,0,2},{0,0,0,0,0},{0,0,1,2,0}};
    for(int i=0;i<5;i++)
    {
        AdjListNode *newAdjListNode =(AdjListNode *)malloc(sizeof(AdjListNode));
        newAdjListNode->graphNodeName ='A' + i;
        newAdjListNode->mark = 0;
        newAdjListNode->down = NULL;
        newAdjListNode->right =NULL;
        

        for(int j=0;j<5;j++)
        {
            if(Arr[i][j] < 1000 && Arr[i][j] != 0)
            {
                ConnectNode *newConnectNode = (ConnectNode *)malloc(sizeof(ConnectNode));
                newConnectNode->graphNodeName = 'A' +j;
                newConnectNode->weight = Arr[i][j];
                newConnectNode->right =NULL;
                newAdjListNode->right = insertConnectNode(newAdjListNode->right,newConnectNode);
            }

        }
        
        graphPtr->AdjListPtr = insertAdjListNode(graphPtr->AdjListPtr,newAdjListNode);

       
    }
}


AdjListNode *insertAdjListNode(AdjListNode *root,AdjListNode *newNode)
{
    
    if(root ==NULL)
    {
        root = newNode;
    }
    else
    {
        AdjListNode *ptr =root;
        while(ptr->down != NULL)
        {
            ptr =ptr->down;
        }
        ptr->down = newNode;
    }
    
  return root;
}

ConnectNode *insertConnectNode(ConnectNode *root ,ConnectNode *newNode)
{
    if(root ==NULL)
    {
        root = newNode;
    }
    else
    {
        ConnectNode *ptr =root;
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
    
    AdjListNode *ptr1 =graphPtr->AdjListPtr;
   ConnectNode *ptr2 =NULL;

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

graph *addNode(graph *graphPtr, char nodeName)
{
    AdjListNode * newAdjListNode = (AdjListNode *)malloc(sizeof(AdjListNode));
        newAdjListNode->graphNodeName =nodeName;
        newAdjListNode->mark = 0;
        newAdjListNode->down = NULL;
        newAdjListNode->right =NULL;
    graphPtr->AdjListPtr = insertAdjListNode(graphPtr->AdjListPtr,newAdjListNode);
    return graphPtr;

}


graph *deleteNode(graph *graphPtr , char nodeName)
{
  AdjListNode *prev = graphPtr->AdjListPtr,*ptr = graphPtr->AdjListPtr;

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
                graphPtr->AdjListPtr = ptr->down;
                ptr->down = NULL;
                free(ptr);

                AdjListNode *ptr1 =graphPtr->AdjListPtr;
                while(ptr1 != NULL)
                {
                    deleteEdge(graphPtr,ptr1->graphNodeName,nodeName);
                    ptr1 = ptr1->down;
                }
                

            }
            else
            {
                prev->down = ptr->down;    // removing adjlistnode 
                ptr->down = NULL;
                free(ptr);

                AdjListNode *ptr1 =graphPtr->AdjListPtr;
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
    AdjListNode *ptr1 =graphPtr->AdjListPtr ,*ptr2 = graphPtr->AdjListPtr;

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
        ConnectNode *newConnectNode = ( ConnectNode *)malloc(sizeof(ConnectNode));
        newConnectNode->graphNodeName = endNodeName;
        newConnectNode->right = NULL;
        newConnectNode->weight = weight;

        ConnectNode *cnPtr = ptr1->right;
        while(cnPtr->right != NULL)
        {
            cnPtr = cnPtr->right;
        }
        cnPtr->right = newConnectNode;

       
    }
    
   
   return graphPtr; 

}

graph *deleteEdge(graph *graphPtr, char startNodeName ,char endNodeName)
{
    AdjListNode *ptr = graphPtr->AdjListPtr;

    while(ptr!= NULL && ptr->graphNodeName != startNodeName)
    {
        ptr = ptr->down;
    }

    if(ptr == NULL)
    {
        printf("\n given edge is not present in graph\n");
    }
    else
     {     ConnectNode *ptr1 =ptr->right ,*prev =ptr->right;
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



void displayDepthFirst(graph *graphPtr , char startPoint)
{
    AdjListNode *alPtr = graphPtr->AdjListPtr;

    while(alPtr->graphNodeName != startPoint  )
    {
        alPtr = alPtr->down;
    }

    if(alPtr->mark == 1)
    { 
        return ;
     
    }
    else
    {
        printf("\t [ %c ]\t",alPtr->graphNodeName);
        alPtr->mark = 1;
        ConnectNode *cnPtr =alPtr->right;
        while(cnPtr != NULL)
        {
            displayDepthFirst(graphPtr,cnPtr->graphNodeName);
            cnPtr = cnPtr->right;
        }

    }
     
    

}


boolen isPathExists(graph *graphPtr ,char startNodeName, char endNodeName)
{
    boolean retval =FALSE;
    AdjListNode *alPtr = graphPtr->AdjListPtr;

    while(alPtr->graphNodeName != startPoint  )
    {
        alPtr = alPtr->down;
    }

    if(alPtr->graphNodeName == endNodeName)
    { 
        retval = TRUE;
     
    }
    else
    {
        if
        
        alPtr->mark = 1;
        ConnectNode *cnPtr =alPtr->right;
        while(cnPtr != NULL)
        {
            retval = isPathExists(graphPtr,cnPtr->graphNodeName,endNodeName);
            cnPtr = cnPtr->right;
        }

    }

    return retval;


}