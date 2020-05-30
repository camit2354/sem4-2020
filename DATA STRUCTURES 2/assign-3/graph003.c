#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef enum {FALSE =0 ,TRUE =1 }boolean;

typedef struct EdgeNodeTag
{    char vertexName;   // end vertex name of edge
    struct EdgeNodeTag *right;
    VertexNode *vertex;
    int weight;

}EdgeNode;

typedef struct VertexNodeTag
{
    char vertexName;
    int mark;  //  0 = unmarked , 1 = marked      
    struct VertexNodeTag *down;
    EdgeNode *right;

}VertexNode;

typedef struct graphTag
{
    VertexNode *VertexPtr;
    int isWeightedGraph;
    int isDirectedGraph;

}graph;

//*******************************************************************************
VertexNode *insertVertexNode(VertexNode * ,VertexNode *);
VertexNode *addVertex(graph *, char nodeName);
VertexNode *deleteVertex(graph * , char nodeName);

//*******************************************************************************



//*******************************************************************************

//*******************************************************************************
graph *initializeGraph();


EdgeNode *addEdgeaddEdge(graph *, char startNodeName ,char endNodeName ,int weight);
graph *deleteEdge(graph *, char startNodeName ,char endNodeName);
void simplyDisplay(graph *);
void displayDepthFirst(graph *graphPtr , char startPoint);
void displayBreadthFirst();
void displayTopoSort();
boolean isPathExists(graph * ,char , char );
void isDisConnected();

EdgeNode *insertEdgeNode(EdgeNode * ,EdgeNode *);

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
    // addVertex(graphPtr,'F');
    // simplyDisplay(graphPtr);

    // printf("\n deleting node  ' B '\n");
    //  deleteVertex(graphPtr,'B');
    // simplyDisplay(graphPtr);

    // printf("\n deleting edge A->B\n");
    // deleteEdge(graphPtr,'A','D');
    // simplyDisplay(graphPtr);
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

VertexNode *addVertex(graph *graphPtr, char nodeName)
{
    VertexNode * newVertexNode = (VertexNode *)malloc(sizeof(VertexNode));
        newVertexNode->vertexName =nodeName;
        newVertexNode->mark = 0;
        newVertexNode->down = NULL;
        newVertexNode->right =NULL;
    graphPtr->VertexPtr = insertVertexNode(graphPtr->VertexPtr,newVertexNode);
    return graphPtr;

}

graph *deleteVertex(graph *graphPtr , char nodeName)
{
  VertexNode *prev = graphPtr->VertexPtr,*ptr = graphPtr->VertexPtr;

  while(ptr!= NULL && ptr->vertexName != nodeName)
  {
      prev = ptr;
      ptr = ptr->down;
  }

  if(ptr == NULL)
  {
      printf("\n this vertex is not present in graph \n");
  }
  else
  {
            if(prev == ptr)
            {
                 VertexNode *iptr =graphPtr->VertexPtr;
                while(iptr != NULL)
                {
                    deleteEdge(graphPtr,iptr->vertexName,nodeName);
                    iptr = iptr->down;
                }


                graphPtr->VertexPtr = ptr->down;
                ptr->down = NULL;
                free(ptr);


            }
            else
            {
                 VertexNode *iptr =graphPtr->VertexPtr;
                    while(iptr != NULL)
                    {
                        deleteEdge(graphPtr,iptr->vertexName,nodeName);
                        iptr = iptr->down;
                    }

                prev->down = ptr->down;    // removing Vertexnode 
                ptr->down = NULL;
                free(ptr);

            }
  }

}


EdgeNode *addEdge(graph *graphPtr, char startNodeName ,char endNodeName ,int weight)
{
    VertexNode *ptr1 =graphPtr->VertexPtr ,*ptr2 = graphPtr->VertexPtr;

    while(ptr1 != NULL && ptr1->vertexName != startNodeName)
    {
        ptr1 = ptr1->down;
    }

    while(ptr2 != NULL && ptr2->vertexName != endNodeName)
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
        newEdgeNode->vertexName = endNodeName;
        newEdgeNode->vertex = ptr2;
        newEdgeNode->right = NULL;
        newEdgeNode->weight = weight;

        EdgeNode *ptr= ptr1->right,*egptr = ptr1->right;
        while(egptr->right != NULL)
        {
            egptr = egptr->right;
        }
        egptr->right = newEdgeNode;

       
    }
    
   
   return ptr1->right; 

}


EdgeNode *insertEdgeNode(EdgeNode *root ,EdgeNode *newNode)
{
    if(root ==NULL)
    {
        root = newNode;
    }
    else
    {
        EdgeNode *egptr =root;
        while(egptr->right != NULL)
        {
            egptr =egptr->right;
        }
        egptr->right = newNode;
    }
    
  return root;

}

graph *deleteEdge(graph *graphPtr, char startNodeName ,char endNodeName)
{
    VertexNode *ptr = graphPtr->VertexPtr;

    while(ptr!= NULL && ptr->vertexName != startNodeName)
    {
        ptr = ptr->down;
    }

    if(ptr == NULL)
    {
        printf("\n given edge is not present in graph\n");
    }
    else
     {     EdgeNode *ptr1 =ptr->right ,*prev =ptr->right;
                while(ptr1 != NULL && ptr1->vertexName != endNodeName)
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
                         ptr1->vertex = NULL;
                        prev->right = ptr1->right;
                        ptr1->right = NULL;
                        free(ptr1);
                    }
                    else
                    {
                        ptr1->vertex = NULL;
                        ptr->right = ptr1->right;
                        free(ptr1);
                        
                    }
                    
                 }
     }
    

    

    return graphPtr;

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
    graphPtr->VertexPtr = NULL;
    // printf("\n enter no of nodes u wanted to enter in your graph initially \n");
    // scanf("%d",&N);

       simplyDisplay(graphPtr);
    int Arr[5][5] ={{0,2,5,1000,3},{0,0,6,4,10},{0,0,0,0,2},{0,0,0,0,0},{0,0,1,2,0}};
    for(int i=0;i<5;i++)
    {
        VertexNode *newVertexNode =(VertexNode *)malloc(sizeof(VertexNode));
        newVertexNode->vertexName ='A' + i;
        newVertexNode->mark = 0;
        newVertexNode->down = NULL;
        newVertexNode->right =NULL;
        

        for(int j=0;j<5;j++)
        {
            if(Arr[i][j] < 10000 && Arr[i][j] != 0)
            {
                
               newVertexNode->right = addEdge(graph *graphPtr,'A' +i,'A' +j,Arr[i][j]);
            
            }

        }
        
        graphPtr->VertexPtr = insertVertexNode(graphPtr->VertexPtr,newVertexNode);

       
    }
}



void simplyDisplay(graph *graphPtr)
{
    
    VertexNode *ptr1 =graphPtr->VertexPtr;
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
            printf("\n [ %c ]",ptr1->vertexName);
            while(ptr2 != NULL)
            {
                printf(" ( %c )",ptr2->vertexName);
                ptr2 = ptr2->right;
            }
            printf("\n");
            ptr1 = ptr1->down;
        }
        
    }
   

}











void displayDepthFirst(graph *graphPtr , char startPoint)
{
    VertexNode *alPtr = graphPtr->VertexPtr;

    while(alPtr->vertexName != startPoint  )
    {
        alPtr = alPtr->down;
    }

    if(alPtr->mark == 1)
    { 
        return ;
     
    }
    else
    {
        printf("\t [ %c ]\t",alPtr->vertexName);
        alPtr->mark = 1;
        EdgeNode *egptr =alPtr->right;
        while(egptr != NULL)
        {
            displayDepthFirst(graphPtr,egptr->vertexName);
            egptr = egptr->right;
        }

    }
     
    

}


boolean isPathExists(graph *graphPtr ,char startNodeName, char endNodeName)
{
    boolean retval =FALSE;
    VertexNode *alPtr = graphPtr->VertexPtr;

    while(alPtr->vertexName != startNodeName  )
    {
        alPtr = alPtr->down;
    }

    if(alPtr->vertexName == endNodeName)
    { 
        retval = TRUE;
     
    }
    else
    {

        alPtr->mark = 1;
        EdgeNode *egptr =alPtr->right;
        while(egptr != NULL)
        {
            retval = isPathExists(graphPtr,egptr->vertexName,endNodeName);
            egptr = egptr->right;
        }

    }

    return retval;


}