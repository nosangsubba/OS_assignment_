#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
int main()
	{
		int AT[20],BT[20],RT[10],end_Time,i,smallest;
		int remain=0,n,time,sum_wait=0,sum_turnaround=0;

		printf("Enter no of Processes : ");
		scanf("%d",&n);
		for(i=0;i<n;i++)
			{	
				printf("Enter Arrival time for Process P%d : ",i+1);
				scanf("%d",&AT[i]);
				printf("Enter Burst time for Process P%d : ",i+1);
				scanf("%d",&BT[i]);
				RT[i]=BT[i];
			}
		printf("\nProcess\t|Turnaround Time| Waiting Time\n");
		RT[9]=9999;
for(time=0;remain!=n;time++)
	{
		smallest=9;
		for(i=0;i<n;i++)
			{
				if(AT[i]<=time && RT[i]<RT[smallest] && RT[i]>0)
					{
						smallest=i;

					}
			}
        
		RT[smallest]--;
		if(RT[smallest]==0)
			{
				remain++;
				end_Time=time+1;
				printf("\nP[%d]\t|\t%d\t|\t%d",smallest+1,end_Time-AT[smallest],end_Time-BT[smallest]-AT[smallest]);
				sum_wait+=end_Time-BT[smallest]-AT[smallest];
				sum_turnaround+=end_Time-AT[smallest];
			}
	}
		printf("\n");
		printf("\nAverage waiting time = %f\n",sum_wait*1.0/n);
		printf("Average Turnaround time = %f",sum_turnaround*1.0/5);
		return 0;
}
