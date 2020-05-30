#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 133

typedef enum { TRUE =1,FALSE =0}boolean;

typedef struct setTag
{
    char *Arr[N];
}set ;

int hashFun(char *);
set *create();  // to create or initialize an empty set
void showSetElements(set *);
 boolean add(set *,char *);
// boolean is_element_of(set *, char *);
// boolean is_empty(set *);
// int size(set *);  // to determine no of elements present in set
// void enumerate();
// set *build(char *,char *,char *,char *,char *,char *,char *,char *); //to build a new set by using provided strings


// boolean remove(set *,char *);
// set *union_of_two_sets(set *,set *);
// set *intersection(set *,set *);
// set *differance(set *,set *);
// boolean is_subset(set *,set *);

void main()
{

    set *myset = create();
    showSetElements(myset);
    // char str[15];
    // printf("\n enter string :\n");
    // scanf("%s",str);
    // printf("\n your entered string is : %s \n",str);
    // int key = hashFun(str);
    // printf("\nkey of string : %d\n",key);
    
}

int hashFun(char *str)
{
    int len = strlen(str);
    int p =3;
    int mul =3;
    int sum =0;

    for(int i=0;i<len;i++)
    {
      sum = sum + str[i]*p;
      p = p*mul;

    }

    sum = sum%N;
    return sum;
}


void showSetElements(set *myset)
{
    int count =0;
    for(int i=0;i<N;i++)
    {
        if(myset->Arr[i] != NULL)
        {
            printf("\n Arr[ %d ] : ",i);
            puts(myset->Arr[i]);
        // printf(" \n Arr[%d] : %s \n",i,myset->Arr[i]);
        count++;
        }
    }

    printf("\n count : %d\n",count);

}


set *create()
{
    set *myset = (set *)malloc(sizeof(set));
    char str[15];

    FILE *fp =fopen("strings.txt","r");
     
     if(fp == NULL)
     {
         printf("\nproblem in opening file  !!!\n"); 
     }
     else
     {
          while(fgets(str ,15 ,fp)!= NULL)
          {
              add(myset ,str);
          }
         /* code */
     }
     
   
    return myset;
}

boolean add(set *myset,char *str)
{
    int key = hashFun(str);
     myset->Arr[key] = str;
    printf("\n add fun str : %s  & myset->str : %s \n",str,myset->Arr[key]);
    //  strcpy(myset->Arr[key],str);

}