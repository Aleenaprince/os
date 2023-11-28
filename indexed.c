#include<stdio.h>
int main(){
int f[50], index[50],i, n, st, j, c, k, ind,count=0;
for(i=0;i<50;i++)
f[i]=0;
do
{
printf("Enter the index block: ");
scanf("%d",&ind);
if(f[ind]!=1)
{
printf("Enter no of blocks needed: ");
scanf("%d",&n);
f[ind]=1;
}
else
{
printf("%d index is already allocated \n",ind);
continue;
}
do
{
count=0;
printf("Enter the block numbers...\n");
for(i=0;i<n;i++)
{
scanf("%d", &index[i]);
if(f[index[i]]==0)
count++;
}
if(count==n)
{
for(j=0;j<n;j++)
f[index[j]]=1;
printf("Allocated\n");
printf("File Indexed\n");
for(k=0;k<n;k++)
printf("%d-------->%d:%d \n",ind,index[k],f[index[k]]);
}
else
{
printf("Block %d is already used \n",index[i]);
printf("Enter another set of blocks for index block %d\n",ind);
}
} while(count!=n);
printf("Do you want to enter more file(Yes - 1/No - 0)");
scanf("%d", &c);
} while(c==1);
return 0;
}
