#include<stdio.h>

int main()
{
	int tc,i,a,b;
	scanf("%d", &tc);
	for(i=1;i<=tc;i++)
	{
		scanf("%d%d", &a,&b);
		printf("Case %d: %d\n", i,a+b);
	}
}
