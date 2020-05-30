#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 133

typedef enum { TRUE =1,FALSE =0}boolean;

typedef struct setTag
{
    char Arr[N][15];
}set ;

int hashFun(set *myset ,char *str);
set *create();  // to create or initialize an empty set
void showSetElements(set *);
 boolean add(set *,char *);
 boolean isStringAtIndexExists(set *, int );
 boolean is_element_of(set *, char *);
 boolean is_empty(set *);
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
     if(is_element_of(myset,"amit"))
     {
         printf("\n amit is in myset \n");
     }
     else
     {
          printf("\n amit is not in myset \n");
     }
     
    // char str[15];
    // printf("\n enter string :\n");
    // scanf("%s",str);
    // printf("\n your entered string is : %s \n",str);
    // int key = hashFun(str);
    // printf("\nkey of string : %d\n",key);
    
}

int hashFun(set *myset ,char *str)
{
    int len = strlen(str);
    int p =3;
    int mul =3;
    int sum =0;
    int key;

    for(int i=0;i<len;i++)
    {
      sum = sum + str[i]*p;
      p = p*mul;

    }

    key = sum%N;
    int i=1;

    while(isStringAtIndexExists(myset,key))
    {
        key = key + i*i;
        i++;
    }
    return key ;
}


void showSetElements(set *myset)
{
    int count =0;
    for(int i=0;i<N;i++)
    {
        if(myset->Arr[i][0] != '\0')
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
    boolean status_of_add =FALSE;

    FILE *fp =fopen("strings.txt","r");
     
     if(fp == NULL)
     {
         printf("\nproblem in opening file  !!!\n"); 
     }
     else
     {
          while(fgets(str ,15 ,fp)!= NULL)
          {
              printf("\n string from file  : %s ",str);
              status_of_add = add(myset ,str);

             
          }
         /* code */
     }
     
   
    return myset;
}

boolean add(set *myset,char *str)
{
    int key = hashFun(myset , str);
    
     strcpy(myset->Arr[key],str);
     printf("\n str : %s  added at index : %d \n-----------------------------------\n",str,key);
     

}

boolean isStringAtIndexExists(set *myset, int index)
{
    if(myset->Arr[index][0] != '\0')
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
    
}

boolean is_element_of(set *myset, char *str)
{
    int key = hashFun(myset , str);

    if(isStringAtIndexExists(myset,key))
    {
        return TRUE;

    }
    else
    {
        return FALSE;
    }
    

}


 boolean is_empty(set *myset)
 {
     int found =0;
     for(int i=0;i<N && found ==0 ;i++)
     {
         if(isStringAtIndexExists(myset ,i))
         found =1;
     }

      if(found)
      {
          return FALSE;

      }
      else
      {
          return TRUE;
      }
      
 }







