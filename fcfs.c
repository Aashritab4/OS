#include <stdio.h>
void main()
{
		int pid[10],bt[10],at[10],n,i;
		printf("enter number of processes : ");
		scanf("%d",&n);
		printf("enter processes id of each process : ");
		for(i=0;i<n;i++)
		{
				scanf("%d",&pid[i]);
		}
		printf("enter burst time of each proceses : ");
		for(i=0;i<n;i++)
		{
				scanf("%d",&bt[i]);
		}
		printf("enter arrival time of each process : ");
		for(i=0;i<n;i++)
		{
				scanf("%d",&at[i]);
		}
		int wt[10],ct[10];
		wt[0] = 0;
		for(i=1;i<n;i++)
		{
				wt[i] = (at[i-1]+bt[i-1] + wt[i-1])-at[i];
		}
		ct[0] = bt[0];
		for(i=1;i<n;i++)
		{
				ct[i] = bt[i] + ct[i-1];
		}
		float twt = 0.0,tat = 0.0;
		printf("process id    burst time    waiting time    turn around time\n");
		for(i=0;i<n;i++)
		{
				printf("%d\t\t",pid[i]);
				printf("%d\t\t",bt[i]);
				printf("%d\t\t",wt[i]);
				printf("%d\t\t\n",ct[i]-at[i]);
				twt += wt[i];
				tat += ct[i]-at[i];
		}
		float awt,aat;
		awt = twt/n;
		aat = tat/n;
		printf("average waiting time : %f\n",awt);
		printf("average turn around time : %f",aat);
}
