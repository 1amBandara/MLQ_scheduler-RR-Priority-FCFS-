#include<stdio.h>
int arrival_time1[30],arrival_time2[30],priority2[30],process2[30],arrival_time3[30];
int burst_time1[30],burst_time2[30],burst_time3[30];

int Total=0,t1=0,t2=0,t3=0;

int n,i,at[30],bt[30],pr[30],j=0,k=0,l=0;

int total,x,temp[30],counter=0;
float avg_waiting_time1=0.0,avg_turnaround_time1=0.0;

int p,waiting_time3[30],turnaround_time3[30],completion_time3[30];
float avg_waiting_time3=0.0,avg_turnaround_time3=0.0;

int position,q,temp1,waiting_time2[30],turnaround_time2[30],completion_time2[30];
float sum=0,avg_waiting_time2,avg_turnaround_time2;

int main()
{
	printf("\n============================================== I N P U T S ==========================================================\n\n");
	printf("Enter the no. of process you want to enter : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n");
		printf("Enter details of process[%d]\n",i+1);
		printf("Arrival Time:");
		scanf("%d",&at[i]);
		printf("Burst Time:");
		scanf("%d",&bt[i]);
		printf("Priority(1 to 15):");
		scanf("%d",&pr[i]);
		Total=Total+bt[i];
	}

	printf("\n\n===================================================== R E S U L T S =====================================================\n\n");
	for(i=0;i<n;i++)
	{
		if(pr[i]>=1&&pr[i]<=5)
		{
			printf("Process[%d] belongs to Queue 1\n",i+1);
			arrival_time1[j]=at[i];
			burst_time1[j]=bt[i];
			j++;
			t1=t1+bt[i];
		}

		else if(pr[i]>=6&&pr[i]<=10)
		{
			printf("Process[%d] belongs to Queue 2\n",i+1);
			arrival_time2[k]=at[i];
			burst_time2[k]=bt[i];
			priority2[k]=pr[i];
			process2[k]=k+1;
			k++;
			t2=t2+bt[i];
		}

		else if(pr[i]>=11&&pr[i]<=15)
		{
			printf("Process[%d] belongs to Queue 3\n",i+1);
			arrival_time3[l]=at[i];
			burst_time3[l]=bt[i];
			l++;
			t3=t3+bt[i];
		}
	}
	printf("\n\n");

	printf("********************** Queue Execution Pattern **************************\n\n");
	round_robin1();

	printf("\n\n");
	printf("********************** Details of Queue 1 **************************\n\n");
	round_robin();

	printf("\n\n");
	printf("********************** Details of Queue 2 **************************\n\n");
	priority();

	printf("\n\n");
	printf("********************** Details of Queue 3 **************************\n\n");
	fcfs();

	printf("\n\n===================================================== F I N I S H E D =====================================================\n\n");
	return 0;
}

void round_robin1()
{
	printf("Note-: Time Quantum between the 3 queues is 10\n\n");
	for(i=1;i<Total;i=i+10)
	{
		if(t1>10)
		{
			printf("Queue1 is running for 10 units\n");
			t1=t1-10;
		}
		else if(t1<=10&&t1!=0)
		{
			printf("Queue1 is running for %d units\n",t1);
			t1=0;
		}
		if(t2>10)
		{
			printf("Queue2 is running for 10 units\n");
			t2=t2-10;
		}
		else if(t2<=10&&t2!=0)
		{
			printf("Queue2 is running for %d units\n",t2);
			t2=0;
		}
		if(t3>10)
		{
			printf("Queue3 is running for 10 units\n");
			t3=t3-10;
		}
		else if(t3<=10&&t3!=0)
		{
			printf("Queue3 is running for %d units\n",t3);
			t3=0;
		}
	}
}

void round_robin()
{
	printf("Note-: Time Quantum for Queue1 is 4\n\n");
	//sort_arrival(arrival_time1, burst_time1, j);

	for(i=0;i<j;i++)
	{
		temp[i]=burst_time1[i];
	}

	x=j;

    printf("Process ID\t Arrival Time\tBurst Time\t Turnaround Time\t Waiting Time");

    for(i=0,total=0;x>0;)
    {
    	if(temp[i]<=4&&temp[i]>0)
        {
            total=total+temp[i];
            temp[i]=0;
            counter=1;
        }
        else if(temp[i]>0)
        {
            temp[i]=temp[i]-4;
            total=total+4;
        }

        if(temp[i]==0&&counter==1)
        {
            x--;
            printf("\nProcess[%d]\t\t%d\t\t%d\t\t%d\t\t%d",i+1,arrival_time1[i],burst_time1[i],total-arrival_time1[i]+1,total-arrival_time1[i]-burst_time1[i]+1);

            avg_waiting_time1=avg_waiting_time1+total-arrival_time1[i]-burst_time1[i]+1;
            avg_turnaround_time1=avg_turnaround_time1+total-arrival_time1[i]+1;

            counter = 0;

        }
        if(i==j-1) //Check if this is the last process(only process to complete)
        {
            i=0;
        }
        else if(arrival_time1[i+1]<=total) //Else check if there is a process already arrived.
        {
            i++;
        }
        else //else run the same process again
        {
            i=0;
        }
    }

    avg_waiting_time1=avg_waiting_time1/j;
    avg_turnaround_time1=avg_turnaround_time1/j;

    printf("\n\nAverage Waiting Time:%f",avg_waiting_time1);
    printf("\nAverage Turnaround Time:%f\n",avg_turnaround_time1);

}

void priority()
{
    sort_arrival(arrival_time2, burst_time2, k);
    sort_priority_queue2();
    completion_time2[0] = arrival_time2[0] + burst_time2[0];
    waiting_time2[0] = 0;

    for (i = 1; i < k; i++) {
        waiting_time2[i] = completion_time2[i - 1] - arrival_time2[i];
        completion_time2[i] = waiting_time2[i] + burst_time2[i] + arrival_time2[i];
        sum += waiting_time2[i];
    }
    avg_waiting_time2=sum/k;
    sum=0;

     printf("Process ID\t Priority\t Arrival Time\tBurst Time\t Completion Time\t Turnaround Time\t Waiting Time");

    for(i=0;i<k;i++)
    {
    	turnaround_time2[i] = completion_time2[i] - arrival_time2[i];
        sum=sum+turnaround_time2[i];
        printf("\nProcess[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t%d",process2[i],priority2[i],arrival_time2[i],burst_time2[i],completion_time2[i],turnaround_time2[i],waiting_time2[i]);
    }
    avg_turnaround_time2=sum/k;
    printf("\n\nAverage Waiting Time: %f",avg_waiting_time2);
    printf("\nAverage Turnaround Time: %f\n",avg_turnaround_time2);


}

void fcfs()
{
    sort_arrival(arrival_time3, burst_time3, l);
    completion_time3[0] = arrival_time3[0] + burst_time3[0];

    for (i = 1; i < l; i++)
    {
        completion_time3[i] = completion_time3[i - 1] + burst_time3[i];
    }
     printf("Process ID\t Arrival Time\tBurst Time\t Completion Time\t Turnaround Time\t Waiting Time");


    for(i=0;i<l;i++)
    {
        turnaround_time3[i] = completion_time3[i] - arrival_time3[i];
        waiting_time3[i] = turnaround_time3[i] - burst_time3[i];

        avg_waiting_time3=avg_waiting_time3+waiting_time3[i];
        avg_turnaround_time3=avg_turnaround_time3+turnaround_time3[i];

        printf("\nProcess[%d]\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t%d",i+1,arrival_time3[i],burst_time3[i],completion_time3[i],turnaround_time3[i],waiting_time3[i]);
    }
    avg_waiting_time3=avg_waiting_time3/l;
    avg_turnaround_time3=avg_turnaround_time3/l;

    printf("\n\nAverage Waiting Time= %f",avg_waiting_time3);
    printf("\nAverage Turnaround Time= %f\n",avg_turnaround_time3);


}

void sort_arrival(int arrival[], int burst[], int n)
{
    for (int i = 0; i > n - 1; i++)
    {
        for (int m = 0; m < n - i - 1; m++)
        {
            if (arrival[m] < arrival[m + 1])
            {
                // Swap the processes based on arrival time
                int temp = arrival[m];
                arrival[m] = arrival[m + 1];
                arrival[m + 1] = temp;

                temp = burst[m];
                burst[m] = burst[m + 1];
                burst[m + 1] = temp;
            }
        }
    }

}

void sort_priority_queue2() {
    // Use Bubble Sort to sort processes in Queue 2 based on priority
    for (int i = 0; i < k - 1; i++) {
        for (int j = 0; j < k - i - 1; j++) {
            if (arrival_time2[j] == arrival_time2[j + 1] && priority2[j] > priority2[j + 1]) {
                // Sort based on priority only when arrival times are the same

                // Swap priority
                int temp = priority2[j];
                priority2[j] = priority2[j + 1];
                priority2[j + 1] = temp;

                // Swap process ID
                temp = process2[j];
                process2[j] = process2[j + 1];
                process2[j + 1] = temp;

                // Swap arrival time
                temp = arrival_time2[j];
                arrival_time2[j] = arrival_time2[j + 1];
                arrival_time2[j + 1] = temp;

                // Swap burst time
                temp = burst_time2[j];
                burst_time2[j] = burst_time2[j + 1];
                burst_time2[j + 1] = temp;
            }
        }
    }
}
