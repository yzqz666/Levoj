#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,j;
	char s[14]={0},t;
	scanf("%d",&n);
	while(n-->0)
	{
		int k;
		scanf("%s",s);
		k=(s[0]-'0'+(s[2]-'0')*2+(s[3]-'0')*3+(s[4]-'0')*4+(s[6]-'0')*5+(s[7]-'0')*6+(s[8]-'0')*7+(s[9]-'0')*8+(s[10]-'0')*9)%11;
		if(n==10)
			t='X';
		else
		t=k+'0';
		if(t==s[12])
			printf("Right\n");
		else 
		{
			s[12]=t;
			printf("%s\n",s);
		}
	}
	return 0;
}
