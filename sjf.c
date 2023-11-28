#include <stdio.h>
void main()
{
  int i,j,n,at[10],bt[10],ct[10],tat[10],wt[10],current_time=0,temp,flag=0;
  float total_tat=0,total_wt=0;
  printf("Enter the number of processes\n");
  scanf("%d",&n);
  int id[n];
  int id1[n];
  for(i=0;i<n;i++)
     id[i]=i+1;
  //char id[4]={'A','B','C','D'};
  //char id1[4];
  printf("Enter the process details\n");
  for(i=0;i<n;i++)
     {
      printf("Arrival time of %d:",i+1);
      scanf("%d",&at[i]);
      printf("Burst time of %d:",i+1);
      scanf("%d",&bt[i]);
     }
  //sorting
  for(i=0;i<n;i++)
     {
     for(j=0;j<n-i-1;j++)
        {
            if(bt[j]>bt[j+1])
              {
                temp=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;
                temp=at[j];
                at[j]=at[j+1];
                at[j+1]=temp;
                temp=id[j];
                id[j]=id[j+1];
                id[j+1]=temp;
              }
        }
     }
    printf("Process AT BT CT TAT WT\n");
    for(j=0;j<n;j++)
       {
       for(i=0;i<n;i++)
         {   
         if(current_time>=at[i]&&ct[i]==0)
              {
                flag=1;
                break;
              }
         }
        if(flag==0)
          {
            current_time++;
            j--;
          }
        if(flag==1)
          {
            current_time=current_time+bt[i];
            ct[i]=current_time;
            tat[i]=ct[i]-at[i];
            wt[i]=tat[i]-bt[i];
            printf("%d   %d  %d  %d  %d  %d \n ",id[i],at[i],bt[i],ct[i],tat[i],wt[i]);
            id1[j]=id[i];
          }
       }
    for(i=0;i<n;i++)
      {
     total_tat=total_tat+tat[i];
     total_wt=total_wt+wt[i];
      }
  printf("Average TAT is %.2f\n",total_tat/n);
  printf("Average WT is %.2f",total_wt/n);

  printf("Gantt Chart\n");
  for(i=0;i<n;i++)
  {
   printf("|");
   printf("\t%d\t",id1[i]);
  }
}
