

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 1000
#define D 4
typedef struct allocateNodeTag
{
	char name[10];
	int location;
	int size;
	int words;
	struct allocateNodeTag * next;
}allocateNode;
	
typedef struct freeNodeTag
{
	int location;
	int size;
	struct freeNodeTag *next;
}freeNode;

void memoryAllocate(allocateNode **headAlloc,freeNode **headFree,int size,char pname[])
{
	freeNode *fptr,*mptr,*fprev;
	allocateNode *aptr,*ptr_new,*prev;
	aptr=*headAlloc;
	fptr=*headFree;
	int msize=(*headFree)->size;
	int flag=0;
	int wsize;
	while((aptr!=NULL)&&(strcmp(pname,aptr->name)!=0))
	{
		aptr=aptr->next;
	}
	if(aptr==NULL)
	{
		aptr=*headAlloc;
		if(size%D==0)
		{
			wsize=size/D;
		}
		else
		{	
			wsize=size/D+1;
		}
		mptr=fptr;
		while((fptr!=NULL)&&(flag==0))
		{
			if(fptr->size==wsize)
			{
				mptr=fptr;
				flag=1;
			}		
			else if(((fptr->size)<msize)&&(fptr->size>=wsize))
			{
				mptr=fptr;
				msize=fptr->size;
			}
			fprev=fptr;
			fptr=fptr->next;
		}
		if(msize>=wsize)
		{
			ptr_new=(allocateNode*)malloc(sizeof(allocateNode));
			strcpy(ptr_new->name,pname);
			ptr_new->size=size;
			ptr_new->words=wsize;
			ptr_new->location=mptr->location;
			ptr_new->next=NULL;
			if(aptr==NULL)
			{			
				*headAlloc=ptr_new;
			}
			else
			{
				while((aptr!=NULL)&&(aptr->location<mptr->location))
				{
					prev=aptr;
					aptr=aptr->next;
				}
				if(prev==NULL)
				{
					*headAlloc=ptr_new;
					ptr_new->next=aptr;
				}
				else
				{	
					prev->next=ptr_new;
					ptr_new->next=aptr;
				}
			}
			if(mptr->size==wsize)
			{
				if(mptr==(*headFree))
				{
					*headFree=mptr->next;
					free(mptr);
				}
				else
				{
					fprev->next=mptr->next;
					free(mptr);
				}
			}
			else
			{
				mptr->size-=wsize;
				mptr->location+=wsize;
			}
			printf("Memory of size %d is allocated at location %d\n",ptr_new->size,ptr_new->location);
		}
		else
			printf("Heap is full\n");
	}
	else
	{
		printf("\nError:Pointer name already in use\n");
	}
}

void freeMemory(allocateNode **headAlloc,freeNode **headFree,char pname[])
{
	allocateNode *aptr,*aprev;
	aptr=*headAlloc;
	freeNode *fptr,*ptr_new,*fprev;
	fptr=*headFree;
	fprev=NULL;
	ptr_new=(freeNode*)malloc(sizeof(freeNode));
	while((aptr!=NULL)&&(strcmp(aptr->name,pname)!=0))
	{
		aprev=aptr;		
		aptr=aptr->next;
	}
	if(aptr!=NULL)
	{
		ptr_new->location=aptr->location;
		ptr_new->size=aptr->words;
		ptr_new->next=NULL;
		while((fptr!=NULL)&&(fptr->location<ptr_new->location))
		{
			fprev=fptr;			
			fptr=fptr->next;
		}
		if(fptr==*headFree)
		{
			ptr_new->next=*headFree;
			*headFree=ptr_new;
		}
		else
		{
			fprev->next=ptr_new;
			ptr_new->next=fptr;
		}
		//Compaction
		if((fprev!=NULL)&&((fprev->location+fprev->size)==ptr_new->location))
		{
			
			fprev->size+=ptr_new->size;
			fprev->next=fptr;
			free(ptr_new);
			ptr_new=fprev;
		}
		if((fptr!=NULL)&&((ptr_new->location+ptr_new->size)==fptr->location))
		{
			ptr_new->size+=fptr->size;
			ptr_new->next=fptr->next;
			if(fptr->next==NULL)
				ptr_new->next=NULL;
			free(fptr);
		}
		if(aptr==*headAlloc)
		{
			*headAlloc=aptr->next;
			free(aptr);
		}
		else
		{
			aprev->next=aptr->next;
			free(aptr);
		}
		printf("Location is freed\n");
	}	
	else
	{
		printf("Not found\n");
	}		
}
void printAlloc(allocateNode *head)
{
	while(head!=NULL)
	{
		printf("Pointer name:%s\n",head->name);
		printf("Location:%d\n",head->location);
		printf("Size:%d\n",head->size);
		printf("Words used%d\n\n",head->words);
		head=head->next;
	}
}

void printFree(freeNode *head)
{
	while(head!=NULL)
	{
		printf("Location:%d\n",head->location);
		printf("Size:%d\n",head->size*D);
		printf("Number of words:%d\n\n",head->size);
		head=head->next;
	}
}
		
void main()
{
	allocateNode *headAlloc;
	headAlloc=NULL;
	freeNode * headFree;
	headFree=(freeNode*)malloc(sizeof(freeNode));
	headFree->location=0;
	headFree->size=N-1;
	headFree->next=NULL;
	char pname[10];
	int choice,al,size,f=1;
	do
	{
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
				memoryAllocate(&headAlloc,&headFree,size,pname);
				break;
			case 2:
				printf("Enter name of pointer\n");
				scanf("%s",pname);
				freeMemory(&headAlloc,&headFree,pname);
				break;
			case 3:
				printAlloc(headAlloc);
				break;
			case 4:
				printFree(headFree);
				break;
			case 5:
				f=0;
				break;
		}
	}while(f==1);
