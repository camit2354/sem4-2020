#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    char s[310];
    int size;
}bigint;

bigint *add(bigint ,bigint );
bigint *subtract(bigint ,bigint );
bigint *multiply(bigint,bigint);

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
   printf("\n bigint add size: %d \n",b->size);
   
   b=subtract(b1,b2);
    printf("bigint substraction :  %s  \n ",b->s);
   printf("\n bigint add size: %d \n",b->size);
   
 
   return ;
}

bigint *add(bigint b1,bigint b2)
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
        b->s[i+1]=sum+'0';
        i--;
        
    }
    b->s[i+1]=carry+'0';
   
    b->s[b1.size+1]='\0';

    
    return b;
}

bigint *subtract(bigint b1,bigint b2)
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
       printf("%d:%d:%c\n",j,i,b->s[i]);
    }


    while(i>=0)
     {
       b->s[i]=b1.s[i];
       i--;
      }

  b->s[b->size+1]='\0';

      return b;

}

bigint *multiply(bigint b1,bigint b2)
{
    bigint *b[b2.size],*bf;
    b=(bigint)malloc(sizeof(bigint)*(b2.size));
    int j=b2.size-1,k=1,a=1,i;
     
   while(j>=0)
   {
      /* initialize(b[j]);*/
   }

 j=b2.size-1;
    while(j>=0)
    {  a=a*10;
         while(k>1)
        { i=b2.s[j];

               while(i>0)
               {
                b[j]=add(*b[j],b1);
                  i--;
               }
            k--;
        }
        k=a;
       j--;
    }

    j=b2.size-1;
    while(j>=0)
    {
      bf=add(*bf,*b[j]);
    }

}



