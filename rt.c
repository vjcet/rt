# include<stdio.h>
# include<stdlib.h>
 
struct node{
    unsigned dist[20],nexthop[20];
}rt[20];

int main()
{
    
    int i,j,k,n,cc[20][20],count;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    printf("Enter the cost martix:\n");
    for(i=0;i<n;i++)
    	for(j=0;j<n;j++)
        {
            scanf("%d",&cc[i][j]);
            rt[i].dist[j]=cc[i][j];
            rt[i].nexthop[j]=j;
        }

    do
    {
        count = 0;
        for(i=0;i<n;i++)
           for(j=0;j<n;j++)
              for(k=0;k<n;k++)
                 if(rt[i].dist[j]>rt[i].dist[k] + rt[k].dist[j])
                    {
                        rt[i].dist[j]= rt[i].dist[k] + rt[k].dist[j];
                        rt[i].nexthop[j] = k;
                        count++;
                    }

    }while(count>0);
    
    for(i=0;i<n;i++)
    {
    	printf("\nRouter %d:\n",i+1);
        for(j=0;j<n;j++)
       		printf("The distance from Router %d to Router %d is %d via Router %d\n",i+1,j+1,rt[i].dist[j],rt[i].nexthop[j]+1);
        
    }
return 0;    
}
 
