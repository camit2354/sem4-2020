#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    char s[310];
    int size;
}bigint;

bigint *add(bigint ,bigint );
bigint *sub(bigint ,bigint );
bigint *multiply(bigint ,bigint );


int whoismax(bigint ,bigint );

bigint *addminusminus(bigint ,bigint );
bigint *addplusplus(bigint ,bigint );
bigint *addminusplus(bigint ,bigint );
bigint *addplusminus(bigint ,bigint );


bigint *subminusminus(bigint ,bigint,int );
bigint *subplusplus(bigint ,bigint ,int );
bigint *subminusplus(bigint ,bigint ,int );
bigint *subplusminus(bigint ,bigint ,int );


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
    printf("bigint subtraction:  %s  \n ",b->s);
  
   
   
 
   return;
}

/*******************************************************************************************************/

int whoismax(bigint b1,bigint b2)
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

    if(whoismax(b1,b2))
    { temp=b1;
      b1=b2;
      b2=temp;    
    }
  if(b1.s[0]=='-'&&b2.s[0]=='-')
  {
      sum=addminusminus(b1,b2);

  }
  else if(b1.s[0]=='-'&&b2.s[0]!='-')
  {
        sum= addminusplus(b1,b2);
  }
  else if(b1.s[0]!='-'&&b2.s[0]=='-')
  {
         sum= addplusminus(b1,b2);
  }
  else 
  {
       sum= addplusplus(b1,b2);
  }
return sum;

}


bigint *sub(bigint b1,bigint b2)
{    
     bigint temp,*sum;
        int flag=whoismax(b1,b2);
    if(flag==1)
    { temp=b1;
      b1=b2;
      b2=temp;    
    }

  
   
           if(b1.s[0]=='-'&&b2.s[0]=='-')
           {
             sum=subminusminus(b1,b2,flag);

           }
        else if(b1.s[0]=='-'&&b2.s[0]!='-')
           {     
             sum= subminusplus(b1,b2,flag);
               
            }
         else if(b1.s[0]!='-'&&b2.s[0]=='-')
            {       
             sum= subplusminus(b1,b2,flag);
                           
            }
           else 
            {
                 sum= subplusplus(b1,b2,flag);
            }
                
            
   
    return sum;
}


bigint *multiply(bigint b1, bigint b2)
{  
    bigint *b[b2.size],*bf=NULL,*sum=NULL;
    int i,j,a=1;

    i=b2.size-1;
    
    bf=(bigint *)malloc(sizeof(bigint));
    strcpy(bf->s,"0");
    bf->size=1;
    
    while(i>=0)
    { 
        b[i]=(bigint *)malloc(sizeof(bigint));
        strcpy(b[i]->s,"0");  
        b[i]->size=1;
       i--;
    }
   
    i=b2.size-1;
    while(i>=0)
    {
        j=(b2.s[i]-'0')*a;

          while(j>=1)
          {
              sum=add(*b[i],b1);
              b[i] = sum;
              j--;
          }

     i--;
     a=a*10;
    }


   i=b2.size-1;
    while(i>=0)
    {
        bf=add(*bf,*b[i]);
        i--;
    }
 
 if(b2.s[0]=='-'&&b1.s[0]=='-')
   bf->s[0]='0';
   
   if(b2.s[0]=='-'&&b1.s[0]!='-')
   bf->s[0]='-';

    return bf; 


}




bigint *addplusplus(bigint b1,bigint b2)
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

bigint *addminusminus(bigint b1,bigint b2)
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

bigint *addminusplus(bigint b1,bigint b2)
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

bigint *addplusminus(bigint b1,bigint b2)
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

bigint *subplusplus(bigint b1,bigint b2,int flag)
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


bigint *subminusminus(bigint b1,bigint b2,int flag)
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



bigint *subminusplus(bigint b1,bigint b2,int flag)
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


bigint *subplusminus(bigint b1,bigint b2,int flag)
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





