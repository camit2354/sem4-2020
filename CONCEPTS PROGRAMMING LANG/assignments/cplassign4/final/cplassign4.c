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

// ********************************************************** 
 status is_element_of(set *, char *);
 boolean is_empty(set *);
 int size(set *);
 set *enumerate(set *);   //sorting version of given list 
 
//**********************************************************


//**********************************************************
set *create();
status add(set *,char *);
status removeString(set *myset ,char *str);
//**********************************************************


//**********************************************************
set *union_of_two_sets(set *,set *);
set *intersection(set *,set *);
set *differance(set *,set *);
boolean is_subset(set *,set *);
//**********************************************************

//**********************************************************
//  set *build(char *);
//  set *build(char *,char *);
//  set *build(char *,char *,char *);
//  set *build(char *,char *,char *,char *);
//  set *build(char *,char *,char *,char *,char *,char *);
//  set *build(char *,char *,char *,char *,char *,char *,char *);
//  set *build(char *,char *,char *,char *,char *,char *,char *,char *);
//  set *build(char *,char *,char *,char *,char *,char *,char *,char *,char *);
//  set *build(char *,char *,char *,char *,char *,char *,char *,char *,char *,char *);
//  set *build(char *,char *,char *,char *,char *,char *,char *,char *,char *,char *,char *);


int hashFun(set *myset ,char *str);
int indexString(set *myset ,char *str);  
void showSetElements(set *); 
 status isStringAtIndexExists(set *, int ); 
 int search(set *,char *);
 int key(char *);
 int lengthString(char *str);
 int compareString(char *str1 , char *str2);
 set *initializeSet(set *,char *);
/**********************************************************/


   // to determine no of elements present in set
// void enumerate();
// set *build(char *,char *,char *,char *,char *,char *,char *,char *); //to build a new set by using provided strings




void main()
{
     printf("\n 1 . isElementOf fun demo\n");
      printf("\n 2 .  is_empty fun demo \n");
       printf("\n 3 .  size fun demo \n");
        printf("\n 4 . enumerate fun demo \n");
         printf("\n 5 . build fun demo \n");
          printf("\n 6 .  create fun demo\n");
           printf("\n 7 .  add fun demo \n");
            printf("\n 8 .  remove fun demo \n");
             printf("\n 9 . union fun demo \n");
              printf("\n 10 . intersection fun demo\n");
               printf("\n 11 .  differnce fun demo \n");
                printf("\n 12 .  is subset fun demo \n");
                
    int choice =-1;
    printf("\n enter choice : \n");
    scanf("%d",&choice);

   

    set *S = create();   
    S = initializeSet(S,"strings1.txt");
     showSetElements(S);
    printf("\n**********************************************\n");
    
    set *T = create();    
    T = initializeSet(T,"strings2.txt");
    showSetElements(T);
    printf("\n**********************************************\n");

     set *U = create();    
     U = initializeSet(U,"strings3.txt");
     showSetElements(U);
     printf("\n**********************************************\n");

    switch(choice)
    {
        case 1: printf("\n isElementOf fun demo :\n");
                printf("enter element to compare : ");
                char ele[15];
                scanf("%s",ele);
                if(is_element_of(S,ele))
                {
                    printf("\n string is present in set \n");
                }
                break;

        case 2: printf("\n is_empty fun demo :\n");
                if(is_empty(S))
                {
                    printf("\n set is empty \n");
                }
                else
                {
                     printf("\n set is not empty \n");
                }
                
                break;

        case 3: printf("\n size fun demo :\n");
                printf("\n size : %d \n",size(S));
                break;

        case 4: printf("\n enumerate fun demo :\n");
                S = enumerate(S);
                showSetElements(S);
                break;

        case 5: printf("\n build fun demo :\n");
                // build("xmax","jio","reliance","sam");
                break;

        case 6: printf("\n  create fun demo :\n");
                 set *S1 = create(); 
                 showSetElements(S1);  
                // S1 = initializeSet(S1,"strings1.txt");
                 
                break;

        case 7: printf("\n  add fun demo :\n");
                 showSetElements(S);
                 add(S,"max");
                 showSetElements(S);
                break;

        case 8: printf("\n  remove fun demo :\n");
                showSetElements(S);
                removeString(S,"amit");
                showSetElements(S);
                break;

        case 9: printf("\n union fun demo \n");
                set *Z = union_of_two_sets(S,T);
                showSetElements(S);
                showSetElements(T);
                showSetElements(Z);
                printf("\n**********************************************\n");
        break; 

         case 10: printf("\n intersection fun demo \n");
                  set *X = intersection(S,T);
                  showSetElements(S);
                  showSetElements(T);
                  showSetElements(X);
                  printf("\n**********************************************\n");
                  break;

         case 11: printf("\n differnce fun demo \n");
                  set *Y = differance(S,T);
                  showSetElements(Y);
                  printf("\n**********************************************\n");
                  
                  break; 

         case 12: printf("\n  is subset fun demo \n");
                  printf("\n S IS SUBSET OF T: %d \n",is_subset(S,T));
                  break; 

         default : printf("\n  entered choice is invalid \n");
         break;              
                

    }

    

   

    

    
    
}

set *enumerate(set *myset)
{
    set *newSet = (set *)malloc(sizeof(set));
    char min[15];
    int minindex = -1;
    newSet = myset;
    showSetElements(newSet);
    
    for(int i=0;i<N-1;i++)
    {
        strcpy(min,newSet->Arr[i]);
        minindex = i;
        for(int j=i+1;j<N;j++)
        {
            if(compareString(min,newSet->Arr[j])  == 1)
            {
                strcpy(min,newSet->Arr[j]);
                minindex = j;
            }

        }

        if(i != minindex)
        {
            strcpy(newSet->Arr[minindex],newSet->Arr[i]);
            strcpy(newSet->Arr[i],min);
        }
    }

    showSetElements(newSet);

}

 boolean is_subset(set *S,set *T)
 { boolean isSubset = true;
      for(int i=0;i<N && isSubset == true;i++)
     {
         if(S->Arr[i][0] != '\0')
         {
             if(is_element_of(T,S->Arr[i]) == 0)
             {
                 isSubset = false;
                 printf("\n this string is absent in T : %s\n",S->Arr[i]);
             }
         }
       
     }
     return isSubset;

 }

set *differance(set *S,set *T)
{
    set *Z = (set *)malloc(sizeof(set));
      int keyval = -1;

    for(int i=0;i<N;i++)
    {
        if(S->Arr[i][0] != '\0')
        {
                if(is_element_of(T,S->Arr[i]) == 0)
                {
                    add(Z,S->Arr[i]);
                }
          
               
        }
    }

    for(int i=0;i<N;i++)
    {
        if(T->Arr[i][0] != '\0')
        {
             if(is_element_of(S,T->Arr[i]) == 0)
                {
                    add(Z,T->Arr[i]);
                }
            

        }

    }

    return Z;

}

set *union_of_two_sets(set *S,set *T)
{
      set *Z = (set *)malloc(sizeof(set));
      int keyval = -1;

    for(int i=0;i<N;i++)
    {
        if(S->Arr[i][0] != '\0')
        {
                if(is_element_of(T,S->Arr[i]) == 0)
                {
                    add(Z,S->Arr[i]);
                }
          
               
        }
    }

    for(int i=0;i<N;i++)
    {
        if(T->Arr[i][0] != '\0')
        {
            add(Z,T->Arr[i]);

        }

    }

    return Z;
   
}

set *create()
{
    set *myset = (set *)malloc(sizeof(set));
   
    return myset;
}

set *initializeSet(set *myset, char *filename)
{
     char str[15];
    FILE *fp =fopen(filename,"r");
     
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
    printf("\n set elements are : \n");
    int count =0;
    for(int i=0;i<N;i++)
    {
        if(myset->Arr[i][0] != '\0')
        {
            printf(" Arr[ %d ] = %s: ",i,myset->Arr[i]);
           // puts(myset->Arr[i]);
         // printf(" \n Arr[%d] : %s \n",i,myset->Arr[i]);
          count++;
        }
    }
    printf("\n");

   // printf("\n count : %d\n",count);

}




status add(set *myset,char *str)
{
    if(is_element_of(myset,str))
    {
        printf(" problem in adding str : %s",str);
        return failure;

    }
    else
    {       int keyval = hashFun(myset,str);
            
            if(keyval == -1)
            {
                 printf(" problem in adding str since hashfun exhausted its limit : %s",str);

            }
            else
            {
                 strcpy(myset->Arr[keyval],str);
                 // printf("\n str : %s  added at index : %d \n-----------------------------------\n",str,keyval);
                 return success;
                /* code */
            }
            
           
           
    }
    
   
    

}

status removeString(set *myset ,char *str)
{
    if(is_element_of(myset,str))
    {
        int keyval = indexString(myset,str);
        printf("\n keyval for removal string : %d\n",keyval);
        myset->Arr[keyval][0] = '\0';
        return success;

    }
    else
    {
        printf("\n string : %s  is not present in set for removal \n",str);
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
   int index = indexString(myset,str);

   if(index == -1)
   return failure;
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

int compareString(char *str1 , char *str2)
{
    int retval =0;
    int len1 = lengthString(str1);
    int len2 = lengthString(str2);
    

    if(len1 == len2)
    {
        int i=0;
         while(str1[i] == str2[i]  && i<len1)
        {
            i++;
        }

        if(i == len1)
        {
            retval =0;
        }
        else
        {
           if(str1[i] < str2[i])
           {
               retval =-1;
           }            
           else
            {
                retval =1;
            }
            
        }
        

    }
    else
    {
        int i=0;
        while(str1[i] == str2[i] )
        {
            i++;
        }

        if(str1[i] < str2[i])
        {
            retval = -1;
        }
        else if (str1[i] > str2[i])
        {
            retval = 1;
        }
        
    }
    
   
    return retval;

}

int indexString(set *myset ,char *str)
{

    int keyval = key(str);
    int i=0;
   
    
    
    while(compareString(str,myset->Arr[keyval]) != 0  && i<N)
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

int size(set *myset)
{
    int count =0;
    for(int i=0;i<N;i++)
    {
        if(myset->Arr[i][0] != '\0')
        {
           
        count++;
        }
    }

    return count;

}




set *intersection(set *S,set *T)
{
     set *Z = (set *)malloc(sizeof(set));
    int keyval = -1;
    for(int i=0;i<N;i++)
    {
        if(S->Arr[i][0] != '\0')
        {
           if(is_element_of(T,S->Arr[i]))
           {
              add(Z,S->Arr[i]);
           }
          
               
        }
    }

    return Z;


}


//  set *build(char *str1)
//  {
//      set *newSet = create();
//      add(newSet,str1);

//      return newSet;
//  }

//  set *build(char *str1,char *str2)
//  {

//      set *newSet = create();
//      add(newSet,str1);
//      add(newSet,str2);

//      return newSet;

//  }

//  set *build(char *str1,char *str2,char *str3)
//  {

//      set *newSet = create();
//       add(newSet,str1);
//      add(newSet,str2);
//      add(newSet,str3);

//      return newSet;
//  }

//  set *build(char *str1,char *str2,char *str3,char *str4)
//  {

//      set *newSet = create();
//        add(newSet,str1);
//      add(newSet,str2);
//      add(newSet,str3);
//      add(newSet,str4);

//      return newSet;
//  }

//  set *build(char *str1,char *str2,char *str3,char *str4,char *str5)
//  {

//      set *newSet = create();
//       add(newSet,str1);
//      add(newSet,str2);
//      add(newSet,str3);
//      add(newSet,str4);
//      add(newSet,str5);

//      return newSet;
//  }

//  set *build(char *str1,char *str2,char *str3,char *str4,char *str5,char *str6)
//  {

//      set *newSet = create();
//       add(newSet,str1);
//      add(newSet,str2);
//      add(newSet,str3);
//      add(newSet,str4);
//      add(newSet,str5);
//      add(newSet,str6);

//      return newSet;
//  }

//  set *build(char *str1,char *str2,char *str3,char *str4,char *str5,char *str6,char *str7)
//  {

//      set *newSet = create();
//      add(newSet,str1);
//      add(newSet,str2);
//      add(newSet,str3);
//      add(newSet,str4);
//      add(newSet,str5);
//      add(newSet,str6);
//      add(newSet,str7);

//      return newSet;
//  }

//  set *build(char *str1,char *str2,char *str3,char *str4,char *str5,char *str6,char *str7,char *str8)
//  {

//      set *newSet = create();
//       add(newSet,str1);
//      add(newSet,str2);
//      add(newSet,str3);
//      add(newSet,str4);
//      add(newSet,str5);
//      add(newSet,str6);
//      add(newSet,str7);
//      add(newSet,str8);

//      return newSet;
//  }
 