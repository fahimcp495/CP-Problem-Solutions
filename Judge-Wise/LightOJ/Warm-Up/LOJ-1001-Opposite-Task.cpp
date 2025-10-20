#include<stdio.h>

int main()
{
	int tc,i,n;
	scanf("%d", &tc);
	for(i=1;i<=tc;i++)
	{
		scanf("%d", &n);
		if(n>10)
			printf("%d %d\n", n-10,10);
		else
			printf("%d %d\n", 0,n);
	}
}
