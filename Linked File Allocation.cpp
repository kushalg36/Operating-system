#include<stdio.h>
int main()
{
int a[10],n=0,m=0,l=0,i=0,j=0;
printf("Enter Length: ");
scanf("%d",&l);
for(i=0;i<l;i++)
{
a[i]=1;
}
printf("Enter Starting Block: ");
scanf("%d",&n);
printf("Enter number of blocks already allotted: ");
scanf("%d",&m);
printf("Enter Blocks:\n");
for(i=0;i<m;i++)
{
scanf("%d",&j);
a[j-n]=0;
}
for(i=0;i<l;i++)
{
printf("Block %d: %d\n",i+n,a[i]);
}
return 0;
}
