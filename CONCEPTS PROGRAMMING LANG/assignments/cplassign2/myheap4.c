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



freeNode *makefreeNode(int ,int );
allocateNode *makeallocateNode(char [],int ,int );
freeNode *initializefreell(freeNode *);
allocateNode *initializeallocll(allocateNode *);
void traversefreell(freeNode **);
void traverseallocatell(allocateNode **);
freeNode *modify(freeNode **,freeNode *);
freeNode *modify1(freeNode **,freeNode *);
int mymalloc(int ,char [],freeNode **,allocateNode **);
int myfree(char [],freeNode **,allocateNode **);




void main()
{
	
    int choice,al,size,f=1,quit=0;
    char pname[10];

    allocateNode *allocateptr=initializeallocll(allocateptr);
    freeNode *freeptr=initializefreell(freeptr);
    
    allocateNode **allocatepptr=&allocateptr;
    freeNode **freepptr=&freeptr;

	while(quit==0)
   {
		printf(".................................\n\n\n");
		printf("1.Malloc\n");
		printf("2.Free\n");
		printf("3.Print allocated list\n");
		printf("4.Print free list\n");
		printf("5.Quit\n");
		printf("...............................\n\n\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
                printf("\n..............................\n");
				printf("1.Integer\n");
				printf("2.Character\n");
				printf("3.Float\n");
				printf("4.Data type of specific size\n");
                printf("\n..............................\n");

				scanf("%d",&al);
				switch(al)
				{
					case 1:
                         printf("\n..............................\n");
						printf("Name of pointer\n\n");
						scanf("%s",pname);
						size=sizeof(int)+1;
						break;
					case 2:
                         printf("\n..............................\n");
						printf("Name of pointer\n\n");
						scanf("%s",pname);
						size=sizeof(char)+1;
						break;
					case 3:
                         printf("\n..............................\n");
						printf("Name of pointer\n\n");
						scanf("%s",pname);
						size=sizeof(float)+1;
						break;
					case 4:
                     printf("\n..............................\n");
						printf("Name of pointer \n\n");
						scanf("%s",pname);
                         printf("\n..............................\n");
						printf("Size \n");
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
             quit=1;
         default :
             printf("you entered invalid choice \n");
		
        }

        

   }

}



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
freeNode *initializefreell(freeNode *freeptr)
{    
    freeptr=makefreeNode(1024*sizeof(char),0);
    return freeptr;
}


/*......................... function 4: InitializeAllocLL ()...................*/
allocateNode *initializeallocll(allocateNode *allocateptr)
{  
 allocateptr=NULL;
 return allocateptr;
}


/*......................... function 5: Modify ().   modify free ll when allocating memory ..................*/
freeNode *modify(freeNode **freepptr,freeNode *ptr)
{
     
     freeNode *ptr1=NULL,*ptr2=NULL;
     ptr1=makefreeNode(ptr->size/2,ptr->location);
     ptr2=makefreeNode(ptr->size/2,ptr->location+ptr->size/2);

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
    
    traversefreell(freepptr);

     free(ptr);
     
     return ptr1;
         

}


/*......................... function 6: Modify1 ()  modify free ll when deallocating memory ...................*/
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
     traversefreell(freepptr);

}

/*........................function : updatefreell() ................*/

/*......................... function 7: MyMalloc ()...................*/
int mymalloc(int size,char vname[10],freeNode **freepptr,allocateNode **allocatepptr)
{  
   
   printf("size od dta u entered =%d \n",size);
   
   freeNode *ptr= *freepptr;
   printf("size of first node %d \n",ptr->size);
   if((size<ptr->size)&&(size<ptr->size/2)) 
   {
     while((size<=ptr->size)&&(size<ptr->size/2))
     {
       ptr=modify(freepptr,ptr);
     }
   
        if((size<=ptr->size)&&(size>ptr->size/2))
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
   else if((size<=ptr->size)&&(size>ptr->size/2))
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
   else if((size>ptr->size))
   {
      while((size>=ptr->size))
      {
        ptr=ptr->next;
      }

      while((size<ptr->size)&&(size<ptr->size/2))
     {
       ptr=modify(freepptr,ptr);
     }
   
        if((size<=ptr->size)&&(size>ptr->size/2))
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
   

   if(*allocatepptr!=NULL)
   {
    if(strcmp((*allocatepptr)->name,vname)==0)
    {
        allocateNode *temp=*allocatepptr;
        *allocatepptr = (*allocatepptr)->next;

        freeNode *ptr=makefreeNode(temp->size,temp->location);
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
        
        
       freeNode *kptr=makefreeNode(ptr1->size,ptr1->location);
        modify1(freepptr,kptr);

        
        kptr=NULL;
        ptr1=NULL;
      }
      else
      {
         printf("memory is not present to free \n");
      }
     

   }
   }
   else
   {
       printf(" no allocated memory \n");
   }
   
    
}

/*......................... function 9: TraverseFreeLL ()...................*/
void traversefreell(freeNode **freepptr)
{
   freeNode *ptr=*freepptr;
   int i=1;
    printf("\n *********************************** \n");
    printf(" your free list :\n\n ");

   while(ptr!=NULL)
   {  
       printf("node no %d \n",i);
       printf("\n %d ..%d ..\n",ptr->location,ptr->size);
        printf("\n.....................................\n");
       i++;
       ptr=ptr->next;
   }

   printf("\n *********************************** \n");


}


/*......................... function 10: TraverseAllocteLL ()...................*/
void traverseallocatell(allocateNode **allocatepptr)
{
    
  allocateNode *ptr=*allocatepptr;
  int i=1;
  printf("\n  ******************************************* \n");
  printf(" your allocateed list :\n\n ");
  while(ptr!=NULL)
   {     
       printf(" %s...%d ..%d ..\n",ptr->name,ptr->location,ptr->size);
        printf("\n.....................................\n");
        i++;
       ptr=ptr->next;
   }
   printf("\n*****************************************************\n");

}
