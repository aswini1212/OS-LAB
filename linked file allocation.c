#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node*next;
    int data;
};
struct node*newnode,*current;
int main()
{
    int  n1,i,j,n2,n=1,ch,start;
    struct node*head=NULL,*tail=NULL;
    printf("Enetr the no of blocks which are already allocated: ");
    scanf("%d",&n1);
    printf("Enetr the blocks which are already allocated:");
    for(i=0;i<n1;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL&&tail==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
        }
    }
    while(n>0)
    {
        printf("\n1.Add file\n2.Exit");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("Enter the no of blocks to be allocated:");
        scanf("%d",&n2);
        
        printf("Enter the file blocks:");
        for(i=0;i<n2;i++)
        {
            newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL&&tail==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
        }
        }
        
        current=head;
        while(current!=NULL)
        {
            printf("%d",current->data);
            if(current->next!=NULL)
            {
                printf("--->");
            }
            current=current->next;
        }
        }
        else if(ch==2)
        {
         break;   
        }
        
    }
    
    return 0;
}
