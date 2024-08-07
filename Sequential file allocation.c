#include <stdio.h>

int main() {
    int nf, i,start[100],end[100];
    char str[10][100]; 
    
    printf("Enter the number of files to be allocated: ");
    scanf("%d", &nf); 

    for (i = 0; i < nf; i++) {
        printf("Enter the name of file %d: ", i + 1);
        scanf("%s", str[i]);
        printf("Enter the start block of file %d: ",i+1);
        scanf("%d",&start[i]);
        printf("Enter the length of file %d: ",i+1);
        scanf("%d",&end[i]);
        
    }
    printf("\n----CONTIGUOUS FILE ALLOCATION-----\n");
    printf("FileName\tStartBlock\tLength\n");
    for(i=0;i<nf;i++)
    {
        printf("%s\t          %d\t         %d\n",str[i],start[i],end[i]);
    }
    for(i=0;i<nf;i++)
    {
        printf("\nThe file %d is allocated from block %d to block %d\n",i+1,start[i],(start[i]+end[i]-1));
    }
   
    

    return 0;
}
