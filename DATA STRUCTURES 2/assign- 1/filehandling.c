#include<stdio.h>
#include<stdlib.h>
 
int main()
{
    FILE *fp;
  
 
    fp = fopen("fileinfo.txt", "r");
 
    if(fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
 
    
 
    while( fscanf(fp, "Name: %s\t\tRoll no: %d\t\tMarks: %f\n"
                    , name, &roll_no, &marks) != EOF )
    {
        printf("%s\t\t%d\t\t%.2f\n", name, roll_no ,marks);
    }
 
    fclose(fp);
    return 0;
}