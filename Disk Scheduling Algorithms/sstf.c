#include<stdio.h>
#include<stdlib.h>
int main()
{
    int RQ[100],i,n,TotalHeadMoment=0,head,count=0;
    printf("Enter the number of Requests\n");
    scanf("%d",&n);
    printf("Enter the Requests sequence\n");
    for(i=0;i<n;i++)
     scanf("%d",&RQ[i]);
    printf("Enter head head position\n");
    scanf("%d",&head);
    int seq[n+1];
    seq[0]=head;
    int k=1;
    // logic for sstf disk scheduling
    
        /* loop will execute until all process is completed*/
    while(count!=n)
    {
        int min=1000,d,index;
        for(i=0;i<n;i++)
        {
           d=abs(RQ[i]-head);
           if(min>d)
           {
               min=d;
               index=i;
           }
           
        }
        TotalHeadMoment=TotalHeadMoment+min;
        head=RQ[index];
		seq[k++]=RQ[index];
        // 1000 is for max
        // you can use any number
        RQ[index]=1000;
        count++;
    }
    
    printf("Total head movement is %d\n",TotalHeadMoment);
	for(int i=0;i<=n;i++)
	{
		printf("%d ",seq[i]);
	}
    return 0;
}
