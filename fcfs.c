#include <stdio.h>
#include <string.h>

int main()
{
    int n,i,j;

    printf("Enter number of processes:\n");
    scanf("%d",&n);

    char pid[20][10],temp[10];
    int at[20],bt[20],ct[20],wt[20],tat[20];
    int t;

    printf("Enter PID ArrivalTime BurstTime:\n");

    for(i=0;i<n;i++)
        scanf("%s %d %d",pid[i],&at[i],&bt[i]);

    // Sort by arrival time
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(at[i]>at[j])
            {
                t=at[i]; 
                at[i]=at[j]; 
                at[j]=t;

                t=bt[i]; 
                bt[i]=bt[j]; 
                bt[j]=t;

                strcpy(temp,pid[i]);
                strcpy(pid[i],pid[j]);
                strcpy(pid[j],temp);
            }
        }
    }

    int time=0;

    for(i=0;i<n;i++)
    {
        if(time<at[i])
            time=at[i];

        ct[i]=time+bt[i];
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];

        time=ct[i];
    }

    float avg_wt=0,avg_tat=0;

    printf("\nWaiting Time:\n");
    for(i=0;i<n;i++)
    {
        printf("%s %d\n",pid[i],wt[i]);
        avg_wt+=wt[i];
    }

    printf("\nTurnaround Time:\n");
    for(i=0;i<n;i++)
    {
        printf("%s %d\n",pid[i],tat[i]);
        avg_tat+=tat[i];
    }

    printf("\nAverage Waiting Time: %.2f\n",avg_wt/n);
    printf("Average Turnaround Time: %.2f\n",avg_tat/n);

    return 0;
}
