#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int total_process;
    int burst_time[10], index[10];
    int t = 0;
    int total_wait_time = 0;
    int wait_time = 0;
    for (int i = 0; i < 33; i++)
    {
        if (i == 15)
        {
            printf("Shortest Job First Scheduling");
        }
        else
        {
            printf("-");
        }
    }
    printf("\nEnter the number of processes you want: ");
    scanf("%d", &total_process);
    for (int i = 0; i < total_process; i++)
    {
        printf("Enter the Burst Time for p%d: ", (i + 1));
        scanf("%d", &burst_time[i]);
        index[i] = i + 1;
    }
    for (int i = 0; i < total_process; i++)
    {
        int temp = burst_time[i];
        int new = i;

        for (int j = i; j < total_process; j++)
        {
            if (burst_time[j] < temp)
            {
                temp = burst_time[j];
                new = j;
            }
        }
        swap(&burst_time[i], &burst_time[new]);
        swap(&index[i], &index[new]);
    }
    printf("\nProcess Id\tBurst Time\tWait Time\n");
    for (int i = 0; i < total_process; i++)
    {
        printf("P%d\t\t%d\t\t%d\n", index[i], burst_time[i], wait_time);
        total_wait_time = total_wait_time + wait_time;
        wait_time = wait_time + burst_time[i];
    }

    float avg_wait_time = (float)total_wait_time / total_process;
    printf("\nAverage waiting time is %f\n", avg_wait_time);
    int total_Turn_Around = 0;
    for (int i = 0; i < total_process; i++)
    {
        total_Turn_Around += burst_time[i];
    }
    float avg_Turn_Around = (float)total_Turn_Around / total_process;
    printf("\nAverage TurnAround Time is %f\n", avg_Turn_Around);

    for (int i = 0; i < 33; i++)
    {
        if (i == 15)
        {
            printf("Gantt Chart");
        }
        else
        {
            printf("-");
        }
    }   
    printf("\n\n");
    int totalb = 0;
    for (int i = 0; i < total_process; i++)
    {
        totalb = totalb + burst_time[i];
    }
    totalb = totalb + (2 * total_process) +(total_process + 1);
    for (int i = 0; i < totalb; i++)
    {
        printf("-");
    }
    printf("\n|");
    for (int i = 0; i < total_process; i++)
    {
        //index[i+1]
        printf("P%d", index[i]);
        for (int j = 0; j < burst_time[i]; j++)
        {
            printf("-");
        }
        printf("|");
    }
    printf("\n");
    for (int i = 0; i < totalb; i++)
    {
        printf("-");
    }
    int zero=0;
    printf("\n%d",zero);
    for (int i = 0; i < total_process; i++)
    {
        for (int j = 0; j < burst_time[i] + 1; j++)
        {
            printf(" ");
        }
        zero = zero + burst_time[i];
        printf("%d",zero);
        printf(" ");
    }
    return 0;
}