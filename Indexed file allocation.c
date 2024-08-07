#include <stdio.h>
struct files{
    int start,end,blockno,blocks[100];
};
struct files f[100];

int main() {
    int nf, i,j;
    char str[10][100]; 
    
    printf("Enter the number of files to be allocated: ");
    scanf("%d", &nf); 

    for (i = 0; i < nf; i++) {
        
        printf("Enter the start block of file %d: ",i);
        scanf("%d",&f[i].start);
        printf("Enter the length of file %d: ",i);
        scanf("%d",&f[i].end);
        printf("Enter the no of blocks of file:");
        scanf("%d",&f[i].blockno);
        printf("Enter the blocks allocated:");
        for(j=0;j<f[i].blockno;j++)
        {
            scanf("%d",&f[i].blocks[j]);
        }
        
    }
    printf("\n----INDEXED FILE ALLOCATION-----\n");
    printf("FileName\tNo of blocks\t StartBlock\tLength\n");
    for(i=0;i<nf;i++)
    {
        printf("file%d\t          %d\t            %d              %d\n",i,f[i].blockno,f[i].start,f[i].end);
    }
    int ch,fn;
    while(nf>0)
    {
        printf("\n1.Get the blocks\n2.exit\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("\nEnetr the file number:");
            scanf("%d",&fn);
            printf("\nBlocks allocated:");
            for(j=0;j<f[fn].blockno;j++)
            {
                printf("%d ",f[fn].blocks[j]);
            }
        }
        if(ch==2)
        {
            break;
        }
        
    }
   
    

    return 0;
}
