/*Suppose that the following processes arrive for execution at the times indicated. Each process will run for the amount of time listed. In answering the questions, use nonpreemptive scheduling, and base all decisions on the information you have at the time the decision must be made.
Process Arrival Time Burst Time
P1 0.0 8
P2 0.4 4
P3 1.0 1
a. What is the average turnaround time for these processes with the FCFS scheduling algorithm?
b. What is the average turnaround time for these processes with the SJF scheduling algorithm?
c. Compute what average turnaround time will be if the CPU is left idle for the first 1 unit and then SJF scheduling is used. Remember that processes P1 and P2 are waiting during this idle time, so their waiting time may increase.*/

#include<stdio.h>
int main()
{
	int process[3],BT[3];
	float AT[3],WT[3],TT[3];
	int i;
	float avg_WT,avg_TT,temp;
	for(i=0;i<3;i++)
	{
		process[i]=0;
		AT[i]=0;
		BT[i]=0;
		WT[i]=0;
		TT[i]=0;
	}
	printf("Total number of processes taken = 3\n");
	again:
	printf("Allocate each process a number starting from 0 : \n");
	for(i=0;i<3;i++)
	{
		scanf("%d",&process[i]);
	}
	for(i=0;i<3;i++)
	if(process[i]<0)
	{
		printf("The process ID should be positive\n");
		goto again;
	}
	again1:
	printf("Enter the Arrival time of each process : \n");
	for(i=0;i<3;i++)
	{
		scanf("%f",&AT[i]);
	}
	for(i=0;i<3;i++)
	if(AT[i]<0)
	{
		printf("The arrival time should be positive\n");
		goto again1;
	}
	again2:
	printf("Enter the Burst time of each process : \n");
	for(i=0;i<3;i++)
	{
		scanf("%d",&BT[i]);
	}
	for(i=0;i<3;i++)
	if(BT[i]<0)
	{
		printf("The burst time should be positive\n");
		goto again2;
	}
	printf("\nInitial values given are\n\n");
	printf("\tProcess\t\tArrival Time\t\tBurst time\n");
	for(i=0;i<3;i++)
	{
		printf("\tp%d\t\t%0.2f\t\t\t%d\n",process[i],AT[i],BT[i]);
	}
	WT[0]=0;
	WT[1]=BT[0]-AT[1];
	WT[2]=((BT[0]+BT[1])-AT[2]);
	
	temp=0;
	for(i=0;i<3;i++)
	{
		temp=temp+WT[i];
	}
	
	avg_WT=(temp/3);
	
	for(i=0;i<3;i++)
	{
		TT[i]=WT[i]+BT[i];
	}
	
	temp=0;
	for(i=0;i<3;i++)
	{
		temp=temp+TT[i];
	}
	
	avg_TT=(temp/3);
	
	printf("\nFOR FIRST COME FIRST SERVE Average Turnaround time = %0.3f\n\n",avg_TT);
	
	WT[0]=0;
	WT[2]=BT[0]-AT[2];
	WT[1]=((BT[0]+BT[2])-AT[1]);
	
	for(i=0;i<3;i++)
	{
		TT[i]=WT[i]+BT[i];
	}
	
	temp=0;
	for(i=0;i<3;i++)
	{
		temp=temp+TT[i];
	}
	
	avg_TT=(temp/3);
	
		printf("FOR Shortest Job First Non-Premptive Scheduling Average Turnaround time = %0.3f\n\n",avg_TT);
	WT[0]=(BT[1]+BT[2]+1)-AT[0];
	WT[1]=(BT[2]+1)-AT[1];
	WT[2]=0;
	
	for(i=0;i<3;i++)
	{
		TT[i]=WT[i]+BT[i];
	}
	
	temp=0;
	for(i=0;i<3;i++)
	{
		temp=temp+TT[i];
	}
	
	avg_TT=(temp/3);
	
	
	
	
	printf("\nIf CPU is left idle for 1 unit initially then according to Non-Premptive Shortest Job First Scheduling the average turnaround time = %0.3f\n",avg_TT);
	
	
}
