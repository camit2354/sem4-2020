#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void main()
{
     int i=0,j=0,m=10,n=10;
     char Arr[10][10];
    FILE *filePointer;
    char ch;

    filePointer = fopen("readdemo.txt", "r");
    
    if (filePointer == NULL)
    {
        printf("File is not available \n");
    }
    else
    {
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                ch =fgetc(filePointer);
                if(ch =='\n')
                {
                    ch =fgetc(filePointer);
                }
                Arr[i][j] = ch;
            }
        }
       
    }
    
    fclose(filePointer);
    for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                printf("[ %c ]",Arr[i][j]);
            }
            printf("\n");
        }
    return ;

}