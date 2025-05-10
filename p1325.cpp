#include<stdio.h>
#include<string.h>
#include<iostream>

using namespace std;
#define N 10000
#define M 50000
int main()
{
    int n,c=0;
    int m[N]={0};
    int a[N][2]={0};
    cin >> n;
    {

        int *n1=NULL;
        int *n2=NULL;
        n1=(int *)malloc(sizeof(int)*n);
        n2=(int *)malloc(sizeof(int)*n);
        int max=0,min=M;
        int i,j,k;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&n1[i],&n2[i]);
            if(n1[i]<min)
            {
                min=n1[i];
            }
            if(n2[i]>max)
            {
                max=n2[i];
            }
        }
        for(i=0;a[i][0]!=0;i++);
        int *count=NULL;
        count=(int *)malloc(sizeof(int)*(max+2));
        for(j=0;j<=max+1;j++)
        {
            count[j]=0;
        }
        for(k=0;k<n;k++)
        {
            for(j=n1[k]+1;j<=n2[k];j++)
            {
                count[j]=1;
            }
        }
        for(j=1;j<=max;j++)
        {
            if(count[j-1]==0&&count[j]==1)
            {
                a[i+m[c]][0]=j-1;
            }
            if(count[j]==1&&count[j+1]==0)
            {
                a[i+m[c]][1]=j;
                m[c]++;
            }
        }
        c++;
        free(n1);
        free(n2);
        free(count);
    }
    int i,j;
    for(i=0;a[i][0]!=0;i++);
    for(j=0,c=0;j<i;j++)
    {
        printf("%d %d\n",a[j][0],a[j][1]);
        if(j==m[c]-1)
        {
            printf("\n");
            c++;
            m[c]+=m[c-1];
        }
    }
    return 0;
}
