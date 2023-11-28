#include <stdio.h>
void main()
{
  int i,j,n,at[10],bt[10],ct[10],tat[10],wt[10],current_time=0;
  float total_tat=0,total_wt=0;
  printf("Enter the number of processes\n");
  scanf("%d",&n);
  printf("Enter the process details\n");
  for(i=0;i<n;i++)
     {
      printf("Arrival time of %d:",i+1);
      scanf("%d",&at[i]);
      printf("Burst time of %d:",i+1);
      scanf("%d",&bt[i]);
     }
  for(i=0;i<n;i++)
     {
      if(current_time>=at[i])
        {
          current_time=current_time+bt[i];
          ct[i]=current_time;
          tat[i]=ct[i]-at[i];
          wt[i]=tat[i]-bt[i];
        }
      else
        {
          current_time++;
          i--;
        }
     }
  printf("Process AT BT CT TAT WT\n");
  for(i=0;i<n;i++)
     printf("%d  %d  %d  %d  %d  %d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
  for(i=0;i<n;i++)
     {
     total_tat=total_tat+tat[i];
     total_wt=total_wt+wt[i];
     }
  printf("Average TAT is %.2f\n",total_tat/n);
   printf("Average WT is %.2f",total_wt/n);

}
