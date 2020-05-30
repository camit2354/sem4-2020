#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 133

typedef enum { success =1,failure =0}status;
typedef enum { true =1,false =0}boolean;

typedef struct setTag
{
    char Arr[N][15];
}set ;

int hashFun(set *myset ,char *str);
set *create();  // to create or initialize an empty set
void showSetElements(set *);
 status add(set *,char *);
 status isStringAtIndexExists(set *, int );
 status is_element_of(set *, char *);
 boolean is_empty(set *);
 int search(set *,char *);
 int key(char *);
 int lengthString(char *str);
// int size(set *);  // to determine no of elements present in set
// void enumerate();
// set *build(char *,char *,char *,char *,char *,char *,char *,char *); //to build a new set by using provided strings


// status remove(set *,char *);
// set *union_of_two_sets(set *,set *);
// set *intersection(set *,set *);
// set *differance(set *,set *);
// status is_subset(set *,set *);

void main()
{

    set *myset = create();
    showSetElements(myset);
    int keyval =-1;

    char str[15];
    printf("\n enter string :\n");
    scanf("%s",str);
    
    

     if(is_element_of(myset,str))
     {
         printf("\n amit is in myset \n");
     }
     else
     {
          printf("\n amit is not in myset \n");
     }
     
   
    // printf("\n your entered string is : %s \n",str);
    // int key = hashFun(str);
    // printf("\nkey of string : %d\n",key);
    
}

int key(char *str)
{
        int len = lengthString(str);
        int p =3;
        int mul =3;
        int sum =0;
        int retkey =-1;

        for(int i=0;i<len;i++)
        {
           sum = sum + str[i]*p;
           p = p*mul;
        }

        retkey = sum%N;
        
        return retkey;

}  



int hashFun(set *myset ,char *str)
{
    int keyval = key(str);
    printf("\n i am in fun hashfun key fun val : %d\n",keyval);
    
    int i=1;

    while(isStringAtIndexExists(myset,keyval) && i<N)
    {
        keyval =(keyval + i*i)%N;
        i++;
    }

    if(i == N)
    {
        return -1;
    }
    else
    {
        return keyval;
    }
    
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
    status status_of_add =failure;

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

status add(set *myset,char *str)
{
    int keyval = hashFun(myset,str);
    if(keyval != -1)
    {
      strcpy(myset->Arr[keyval],str);
      printf("\n str : %s  added at index : %d \n-----------------------------------\n",str,keyval);
     return success;
    }
    else
    {
        return failure;
    }
    

}

status isStringAtIndexExists(set *myset, int index)
{
    if(myset->Arr[index][0] != '\0')
    {
        return success;
    }
    else
    {
        return failure;
    }
    
}

status is_element_of(set *myset, char *str)
{
    int keyval = key(str);
    int i=0;
    printf("\n i am in fun is_element_of :  keyval = %d , i = %d \n",keyval,i);
    
    
    while(strcmp(str,myset->Arr[keyval]) != 0  && i<N)
    {
        keyval =(keyval + i*i)%N;
        i++;
    }

   
   if(i == N)
   {
       return failure;
   }
   else
   {
       return success;
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
          return failure;

      }
      else
      {
          return success;
      }
      
 }

 int lengthString(char *str)
{
    int len =0;
     while(str[len] != '\n' && str[len] != '\0') //
    {
        len++;
    }

return len;
}

boolean compareString(char *str1 , char *str2)
{
    boolean retval =TRUE;
    int i=0;
    while(str1[i] != '\0' && str1[i]!= '\n' && str2[i] != '\0' && str2[i]!= '\n')
    {
        if(str1[i] != str2[i])
        {
             retval =FALSE;
        }
        i++;
    }
    return retval;

}
