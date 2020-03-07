#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char heap[1024];
/* .....................  structure declarations .......................*/

typedef struct allocateNodeTag
{
	char name[10];
	int location;
	int size;
	struct allocateNodeTag * next;
}allocateNode;

	
typedef struct freeNodeTag
{
	int location;
	int size;
	struct freeNodeTag *next;
}freeNode;


/*......................... function 1: MakeFreeNode ()...................*/

freeNode *makefreeNode(int size,int location)
{
    freeNode *nptr=(freeNode *)malloc(sizeof(freeNode));
    nptr->location=location;
    nptr->size= size ;
    nptr->next=NULL;

    return nptr;
}

/*......................... function 2: MakeAllocateNode ()...................*/

allocateNode *makeallocateNode(char name[],int location,int size)
{      
     allocateNode *nptr=(allocateNode *)malloc(sizeof(allocateNode));
       nptr->location=location;
        nptr->size= size ;
        strcpy(nptr->name,name);
        nptr->next=NULL;

        return nptr;
}

/*......................... function 3: InitializeFreeLl ()...................*/
void initializefreell(freeNode **freepptr)
{
      *freepptr=makefreeNode(sizeof(heap),0);
}


/*......................... function 4: InitializeAllocLL ()...................*/
void initializeallocll(allocateNode **allocatepptr)
{
 *allocatepptr=NULL;
}

/*......................... function 5: Modify ()...................*/
freeNode *modify(freeNode **freepptr,freeNode *ptr)
{
     freeNode *ptr1=NULL,*ptr2=NULL;
     ptr1=makefreeNode(ptr->location,ptr->size/2);
     ptr2=makefreeNode(ptr->location+ptr->size/2,ptr->size/2);

     ptr2->next=ptr->next;
     ptr1->next=ptr2;

  if(ptr!=*freepptr)
  {   freeNode *prev=*freepptr;
     while(prev->next!=ptr)
     {
       prev=prev->next;
     }

     prev->next=ptr1;
  }

  if(ptr==*freepptr)
    *freepptr=ptr1;

     free(ptr);
     
     return ptr1;
         

}


/*......................... function 6: Modify1 ()...................*/
freeNode *modify1(freeNode **freepptr,freeNode *ptr)
{
     freeNode *iptr=*freepptr;

     while(iptr->size<=ptr->size)
     {
         iptr=iptr->next;
     }
     
     if(iptr==*freepptr)
     {
          ptr->next=(*freepptr)->next;
          *freepptr=ptr;
     }
     else
     {
        freeNode *prev=*freepptr;
        while(prev->next!=iptr)
        {
            prev=prev->next;
        }
        ptr->next=iptr;
        prev->next=ptr;
     }
     

}

/*......................... function 7: MyMalloc ()...................*/
int mymalloc(int size,char vname[10],freeNode **freepptr,allocateNode **allocatepptr)
{
   freeNode *ptr= *freepptr;
   if((size<ptr->size)&&(size<ptr->size/2)) 
   {
     while((size<ptr->size)&&(size<ptr->size/2))
     {
       ptr=modify(freepptr,ptr);
     }
   
        if((size<ptr->size)&&(size>ptr->size/2))
     {
        allocateNode *temp=NULL;
        temp=makeallocateNode(vname,ptr->location,ptr->size);
        temp->next=*allocatepptr;
        *allocatepptr=temp;

        *freepptr=ptr->next;
        ptr->next=NULL;
        free(ptr);

       return temp->location;
     }  

   }
   else if((size<ptr->size)&&(size>ptr->size/2))
   {
          allocateNode *temp=NULL;
        temp=makeallocateNode(vname,ptr->location,ptr->size);
        temp->next=*allocatepptr;
        *allocatepptr=temp;

        *freepptr=ptr->next;
        ptr->next=NULL;
        free(ptr);

       return temp->location;  
   }  
   else if((size<ptr->size))
   {
      while((size<ptr->size))
      {
        ptr=ptr->next;
      }

      while((size<ptr->size)&&(size<ptr->size/2))
     {
       ptr=modify(freepptr,ptr);
     }
   
        if((size<ptr->size)&&(size>ptr->size/2))
     {
        allocateNode *temp=NULL;
        temp=makeallocateNode(vname,ptr->location,ptr->size);
        temp->next=*allocatepptr;
        *allocatepptr=temp;

         freeNode *prev= *freepptr;
         while(prev->next!=ptr)
         {
             prev=prev->next;
         }
        prev->next=ptr->next;
        ptr->next=NULL;
        free(ptr);

       return temp->location;
     }  

   }   
   else
   {
       printf("memory is unavailable \n");
   }
   
   

}

/*......................... function 8: MyFree ()...................*/
int myfree(char vname[10],freeNode **freepptr,allocateNode **allocatepptr)
{
   
    if(strcmp((*allocatepptr)->name,vname)==0)
    {
        allocateNode *temp=*allocatepptr,*ptr=NULL;
        *allocatepptr = (*allocatepptr)->next;

        ptr=makefreeNode(temp->size,temp->location);
        modify1(freepptr,ptr);

        temp->next=NULL;
        free(temp);        
    }
    else
    {
       allocateNode *ptr=NULL,*ptr1=*allocatepptr;
       while(strcmp(ptr1->name,vname)&&ptr1!=NULL)
       {
           ptr1=ptr1->next;
       }

      if(ptr1!=NULL) 
      {  
         while(ptr->next!=ptr1)
        { 
           ptr=ptr->next;
        }
       ptr->next=ptr1->next;
       ptr1->next=NULL;
        
        
       ptr=makefreeNode(ptr1->size,ptr1->location);
        modify1(freepptr,ptr);

        
        ptr=NULL;
        ptr1=NULL;
      }
      else
      {
         printf("memory is not present to free \n");
      }
     

   }
    
}

/*......................... function 9: TraverseFreeLL ()...................*/
void traversefreell(freeNode **freepptr)
{ freeNode *ptr=*freepptr;
   while(ptr!=NULL)
   {
       printf("\n %d ..%d ..\n",ptr->location,ptr->size);
       ptr=ptr->next;
   }

}


/*......................... function 10: TraverseAllocteLL ()...................*/
void traverseallocatell(allocateNode **allocatepptr)
{
  allocateNode *ptr=*allocatepptr;
  while(ptr!=NULL)
   {
       printf("\n %s...%d ..%d ..\n",ptr->name,ptr->location,ptr->size);
       ptr=ptr->next;
   }

}


void main()
{
	
	
	int choice,al,size,f=1;
    char pname[10];

    allocateNode **allocatepptr=NULL;
    freeNode **freepptr=NULL;

    initializefreell(freepptr);
    initializeallocll(allocatepptr);


	
		printf("*********\n");
		printf("1.Malloc\n");
		printf("2.Free\n");
		printf("3.Print allocated list\n");
		printf("4.Print free list\n");
		printf("5.Quit\n");
		printf("*********\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("1.Integer\n");
				printf("2.Character\n");
				printf("3.Float\n");
				printf("4.Data type of specific size\n");
				scanf("%d",&al);
				switch(al)
				{
					case 1:
						printf("Name of pointer\n");
						scanf("%s",pname);
						size=sizeof(int);
						break;
					case 2:
						printf("Name of pointer\n");
						scanf("%s",pname);
						size=sizeof(char);
						break;
					case 3:
						printf("Name of pointer\n");
						scanf("%s",pname);
						size=sizeof(float);
						break;
					case 4:
						printf("Name of pointer");
						scanf("%s",pname);
						printf("Size");
						scanf("%d",&size);
						break;
					default:
						printf("Enter valid option\n");
						break;
				}
				mymalloc(size,pname,freepptr,allocatepptr);
				break;
			case 2:
				printf("Enter name of pointer\n");
				scanf("%s",pname);
				myfree(pname,freepptr,allocatepptr);
				break;
			case 3:
				traverseallocatell(allocatepptr);
				break;
			case 4:
				traversefreell(freepptr);
				break;
            case 5:
                 printf(" you entered invalid choice \n");
		
        }

}


