#include <stdio.h>
#include <stdlib.h>
int main(){
int f[50], p, i, st, len, j, c, k, a,alloc[50];
for (i = 0; i < 50; i++)
f[i] = 0;
printf("Enter how many blocks already allocated: ");
scanf("%d", &p);
printf("Enter blocks already allocated:\n ");
for (i = 0; i < p; i++) {
printf("Block :");
scanf("%d", &a);
f[a] = 1;
}
do{
printf("Enter index starting block and length: ");
scanf("%d%d", &st, &len);
k = len;
if (f[st] == 0)
 {
for (j = st; j < (st + k); j++){
if (f[j] == 0){
f[j] = 1;
printf("%d---->", j);
}
else
k++;
}
}
else
printf("%d starting block is already allocated \n", st);
printf("\nDo you want to enter more file(Yes - 1/No - 0)");
scanf("%d", &c);
} while(c==1);
}
