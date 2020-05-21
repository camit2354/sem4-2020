#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct doubttag
{
    char *a[3];
}doubttype;

void main()
{
  doubttype *ptr = (doubttype *)malloc(sizeof(doubttype));

    char *arr0 ="mh23j6666";
    char *arr1 ="mh23j6886";
    char *arr2 ="mh23j9966";

 
    ptr->a[0] = arr0;
     printf("\n string : %s \n",arr0);
    printf("\n string : %s \n",ptr->a[0]);
     printf("\n string : %s \n",ptr->a[1]);
     printf("\n string : %s \n",ptr->a[2]);



 
     ptr->a[1] = arr1;

    printf("\n string : %s \n",ptr->a[0]);
    printf("\n string : %s \n",ptr->a[1]);
    printf("\n string : %s \n",ptr->a[2]);


 
       ptr->a[2] = arr2;

    printf("\n string : %s \n",ptr->a[0]);
    printf("\n string : %s \n",ptr->a[1]);
    printf("\n string : %s \n",ptr->a[2]);

    return ;


}