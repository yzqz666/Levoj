#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int a[3005]={0};
		a[0]=1;
		int i,j,c;
		for(i=2;i<=n;i++)
		{
			c=0;
			for(j=0;j<=3000;j++)
			{
				c=a[j]*i+c;
				a[j]=c%10;
				c/=10;
			}
		}
		j=3000;
		while(a[j]==0)j--;
		for( ;j>=0;j--)
			printf("%d",a[j]);
		printf("\n");
	}
		return 0;
	}
