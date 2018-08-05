#include<stdio.h>
int main()
{
int a[10],n=0,l=0,i=0;
printf("Enter Length: ");
scanf("%d",&l);
printf("Enter Starting Block: ");
scanf("%d",&n);
for(i=0;i<l;i++)
{
a[i]=1;
printf("Blovk %d: %d\n",i+n,a[i]);
}
return 0;
}

