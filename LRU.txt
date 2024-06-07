
#include <stdio.h>

int main()
{
    int frames,pages,frame[100],page[100],pageexist,i,j,pagen,counter[100]={0},pagefault=0,min,k;
    printf("Enter the no of frames:");
    scanf("%d",&frames);
    //initialising the frames
    for(i=0;i<frames;i++)
    {
        frame[i]=-1;
    }
    printf("Enter the no of pages:");
    scanf("%d",&pages);
    printf("Enetr the page string:");
    for(i=0;i<pages;i++)
    {
        scanf("%d",&page[i]);
    }
    for(i=0;i<pages;i++)
    {
        pageexist=0;
        pagen=page[i];
        for(j=0;j<frames;j++)
        {
            if(pagen==frame[j])
            {
                pageexist=1;
                counter[j]=i+1;
                break;
            }
        }
        if(pageexist==0)
        {
            min=0;
            for(j=1;j<frames;j++)
            {
                if(counter[j]<counter[min])
                {
                    min=j;
                }
            }
            frame[min]=pagen;
            counter[min]=i+1;
            pagefault++;
        }
        printf("\nPage:%d\t",pagen);
        for(k=0;k<frames;k++)
        {
            printf("%d\t",frame[k]);
           
        }
        
    }
    printf("\nPagefault=%d",pagefault);

    return 0;
}
