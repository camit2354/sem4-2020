#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    char s[310];
    int size;
}bigint;

bigint *add(bigint ,bigint );
int whoisgreater(bigint ,bigint );

bigint *addtwoneg(bigint ,bigint );
bigint *addtwopos(bigint ,bigint );
bigint *addfirstneg(bigint ,bigint );
bigint *addlastneg(bigint ,bigint );


void main()
{
  bigint b1,b2,*b;
  
  printf("\nenter bigint1 -:");
  scanf("%s",b1.s);

  printf("\nenter bigint2 -:");
  scanf("%s",b2.s);

   b1.size=strlen(b1.s);
   b2.size=strlen(b2.s);

   printf("bigint 1 :  %s  \n ",b1.s);
   printf("bigint 2 :  %s  \n ",b2.s);

   printf("\n bigint 1 : %d",b1.size);
   printf("\n bigint 2 : %d \n",b2.size);

    
   b=add(b1,b2);
    printf("bigint addition :  %s  \n ",b->s);
  
   
   
 
   return;
}

/*******************************************************************************************************/

bigint *addtwopos(bigint b1,bigint b2)
{   
    bigint *b=(bigint *)malloc(sizeof(bigint));
    b->size=b1.size+1;
    int i=b1.size-1;
    int j=b2.size-1;
    int x,y;
    int carry=0,sum=0;

    while(j>=0)
    {
          x=(int)(b1.s[i]-'0');
          y=(int)(b2.s[j]-'0');

        sum =x+y+carry;
        b->s[i+1]=sum%10+'0';
        carry=sum/10;

        printf(" %d :%c \n",j,b->s[i+1]);
            j--;
            i--;   

    }

   
   
    while(i>=0)
    {
         x=(int)(b1.s[i]-'0');
        sum=x + carry ;
        carry=sum/10;
        b->s[i+1]=sum%10+'0';
        i--;
        
    }
    b->s[i+1]=carry+'0';
   
    b->s[b1.size+1]='\0';

    
    return b;
}

bigint *addtwoneg(bigint b1,bigint b2)
{ 
    bigint *b=(bigint *)malloc(sizeof(bigint));
    b->size=b1.size+1;
    int i=b1.size-1;
    int j=b2.size-1;
    int x,y;
    int carry=0,sum=0;

    while(j>=1)
    {
          x=(int)(b1.s[i]-'0');
          y=(int)(b2.s[j]-'0');

        sum =x+y+carry;
        b->s[i+1]=sum%10+'0';
        carry=sum/10;
        
            j--;
            i--;   

    }

   
    while(i>=1)
    {
         x=(int)(b1.s[i]-'0');
        sum=x + carry ;
        carry=sum/10;
        b->s[i+1]=sum%10+'0';
        i--;
                
    }
   
    b->s[1]=carry+'0';
   
    b->s[0]='-';
     
    b->s[b->size]='\0';
     
    return b;
}

bigint *addfirstneg(bigint b1,bigint b2)
{ 
    bigint *b=(bigint *)malloc(sizeof(bigint));
    b->size=b1.size;

    int i=b1.size-1;
    int j=b2.size-1;

    int z,k;

    while(j>=0)
    {

        if(b1.s[i]>=b2.s[j])
        {
            
            b->s[i]=b1.s[i]-b2.s[j]+'0';
        }
        else
        {
            k=i-1;
            z=b1.s[k]-'0';
            while(z==0)
            {
                k=k-1;
                z=b1.s[k]-'0';
            }
            z=z-1;
            b1.s[k]=z+'0';
            k++;
           
           if(k!=i)
           {   while(k!=i-1)
               {
               b1.s[k]='9';
               k++;
               }
               k++;
           }

           b1.s[k]=b1.s[k]+10;
           b->s[i]=b1.s[i]-b2.s[j]+'0';



        }
       j--;
       i--; 
     
    }


    while(i>=1)
     {
       b->s[i]=b1.s[i];
       i--;
      }

     b->s[i]='-';
  b->s[b->size+1]='\0';

      return b;

}

bigint *addlastneg(bigint b1,bigint b2)
{   
    bigint *b=(bigint *)malloc(sizeof(bigint));
    b->size=b1.size;

    int i=b1.size-1;
    int j=b2.size-1;

    int z,k;

    while(j>=1)
    {

        if(b1.s[i]>=b2.s[j])
        {
            
            b->s[i]=b1.s[i]-b2.s[j]+'0';
        }
        else
        {
            k=i-1;
            z=b1.s[k]-'0';
            while(z==0)
            {
                k=k-1;
                z=b1.s[k]-'0';
            }
            z=z-1;
            b1.s[k]=z+'0';
            k++;
           
           if(k!=i)
           {   while(k!=i-1)
               {
               b1.s[k]='9';
               k++;
               }
               k++;
           }

           b1.s[k]=b1.s[k]+10;
           b->s[i]=b1.s[i]-b2.s[j]+'0';



        }
       j--;
       i--; 
      
    }


    while(i>=0)
     {
       b->s[i]=b1.s[i];
       i--;
      }
      
    
  b->s[b->size+1]='\0';

      return b;

}

int whoisgreater(bigint b1,bigint b2)
{   
    int count1,count2,retval;

    if(b1.s[0]=='-')
    {
        count1=strlen(b1.s)-1;

    }
    else
    {
        count1=strlen(b1.s);
    }
    

    if(b2.s[0]=='-')
    {
        count2=strlen(b2.s)-1;

    }
    else
    {
        count2=strlen(b2.s);
    }

    if(count1==count2)
    {
        if(strcmp(b1.s,b2.s)>=0)
         retval=0;
         else
         {
             retval=1;
         }
         
    }
    else 
    {
        if(count1>count2)
         retval=0;
        else
        {
            retval=1;
        }
        
        
    }

   
    return retval;
    
}

bigint *add(bigint b1,bigint b2)
{    
     bigint temp,*sum;

    if(whoisgreater(b1,b2))
    { temp=b1;
      b1=b2;
      b2=temp;    
    }
  if(b1.s[0]=='-'&&b2.s[0]=='-')
  {
      sum=addtwoneg(b1,b2);

  }
  else if(b1.s[0]=='-'&&b2.s[0]!='-')
  {
        sum= addfirstneg(b1,b2);
  }
  else if(b1.s[0]!='-'&&b2.s[0]=='-')
  {
         sum= addlastneg(b1,b2);
  }
  else 
  {
       sum= addtwopos(b1,b2);
  }
return sum;

}




