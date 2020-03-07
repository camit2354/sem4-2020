#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    char s[310];
    int size;
}bigint;

bigint *add(bigint ,bigint );
bigint *sub(bigint ,bigint );

int whoisgreater(bigint ,bigint );

bigint *addtwoneg(bigint ,bigint );
bigint *addtwopos(bigint ,bigint );
bigint *addfirstneg(bigint ,bigint );
bigint *addlastneg(bigint ,bigint );

bigint *subtwoneg(bigint ,bigint,int );
bigint *subtwopos(bigint ,bigint ,int );
bigint *subfirstneg(bigint ,bigint ,int );
bigint *sublastneg(bigint ,bigint ,int );


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

       
   b=add(b1,b2);
    printf("bigint addition :  %s  \n ",b->s);  

     b=sub(b1,b2);
    printf("bigint addition :  %s  \n ",b->s);     
 
   return;
}

/*******************************************************************************************************/

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


bigint *sub(bigint b1,bigint b2)
{    
     bigint temp,*sum;
        int flag=whoisgreater(b1,b2);
    if(flag==1)
    { temp=b1;
      b1=b2;
      b2=temp;    
    }

  
   
           if(b1.s[0]=='-'&&b2.s[0]=='-')
           {
             sum=subtwoneg(b1,b2,flag);

           }
        else if(b1.s[0]=='-'&&b2.s[0]!='-')
           {     
             sum= subfirstneg(b1,b2,flag);
               
            }
         else if(b1.s[0]!='-'&&b2.s[0]=='-')
            {       
             sum= sublastneg(b1,b2,flag);
                           
            }
           else 
            {
                 sum= subtwopos(b1,b2,flag);
            }
                
            
   
    return sum;
}

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


bigint *subtwoneg(bigint b1,bigint b2,int flag)
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


    while(i>=1)
     {
       b->s[i]=b1.s[i];
       i--;
      }
      if(flag==1)
      {  
          b->s[i]='+';
      }
      else
      {
          b->s[i]='-';
      }
         
  b->s[b->size+1]='\0';

      return b;

}


bigint *subtwopos(bigint b1,bigint b2,int flag)
{   
    bigint *b=(bigint *)malloc(sizeof(bigint));
    b->size=b1.size+1;

    int i=b1.size-1;
    int j=b2.size-1;

    int z,k;

    while(j>=0)
    {

        if(b1.s[i]>=b2.s[j])
        {
            
            b->s[i+1]=b1.s[i]-b2.s[j]+'0';
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
           b->s[i+1]=b1.s[i]-b2.s[j]+'0';



        }
       
       j--;
       i--; 
       
    }


    while(i>=0)
     {
       b->s[i+1]=b1.s[i];
       i--;
      }

     if(flag==1)
     {
         b->s[0]='-';
     } 
     else
     {
         b->s[0]='0';
     }
       
    puts(b->s);
    
      return b;

}


bigint *sublastneg(bigint b1,bigint b2,int flag)
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

   
   
    while(i>=0)
    {
         x=(int)(b1.s[i]-'0');
        sum=x + carry ;
        carry=sum/10;
        b->s[i+1]=sum%10+'0';
        i--;
        
    }

    if(flag==0)
    b->s[0]=carry+'0';
    else
    {
        b->s[0]='-';
    }
    
   
    b->s[b1.size+1]='\0';
    
    return b;
}

bigint *subfirstneg(bigint b1,bigint b2,int flag)
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
    if(flag==0)
    b->s[0]='-';
    else
    {
         b->s[0]='0';
    }
    
     
    b->s[b->size]='\0';
      
  
    return b;
}


