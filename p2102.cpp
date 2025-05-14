#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
char str1[405],str2[405];
int pre1[405],pre2[405],suf1[405],suf2[405],point1,point2;
int main()
{
    cin >> str1 >> str2;
    {
        memset(pre1,0,sizeof pre1);
        memset(pre2,0,sizeof pre2);
        memset(suf1,0,sizeof suf1);
        memset(suf2,0,sizeof suf2);
        point1=strlen(str1);
        point2=strlen(str2);
        for(int i=0;str1[i];i++)
        {
            if(str1[i]=='.')
            {
                point1=i;
                break;
            }
            pre1[i]=str1[i]-48;
        }
        if(point1!=strlen(str1))
        {
            for(int i=point1+1;str1[i];i++)
                suf1[i-point1-1]=str1[i]-48;
        }
        for(int i=0;str2[i];i++)
        {
            if(str2[i]=='.')
            {
                point2=i;
                break;
            }
            pre2[i]=str2[i]-48;
        }
        if(point2!=strlen(str2))
        {
            for(int i=point2+1;str2[i];i++)
                suf2[i-point2-1]=str2[i]-48;
        }
        //suf相加
        int up_to_pre=0;
        for(int i=400;i>=0;i--)
        {
            suf1[i]+=suf2[i];
            if(i==0)
            {
                up_to_pre=suf1[0]/10;
                suf1[0]%=10;
            }
            else if(suf1[i]>9)
            {
                suf1[i-1]+=suf1[i]/10;
                suf1[i]%=10;
            }
        }
 
        //pre反转
        for(int i=0;i<point1/2;i++)
            swap(pre1[i],pre1[point1-i-1]);
        for(int i=0;i<point2/2;i++)
            swap(pre2[i],pre2[point2-i-1]);
        //pre相加
        pre1[0]+=up_to_pre;
        for(int i=0;i<point1 || i<point2;i++)
        {
            pre1[i]+=pre2[i];
            if(pre1[i]>9)
            {
                pre1[i+1]+=pre1[i]/10;
                pre1[i]%=10;
            }
        }
 
        //输出pre
        int top=0;
        for(int i=400;i>=0;i--)
        {
            if(pre1[i])
            {
                top=i;
                break;
            }
        }
        for(int i=top;i>=0;i--)
            printf("%d",pre1[i]);
 
        //输出suf
        int tail=-1;
        for(int i=400;i>=0;i--)
        {
            if(suf1[i])
            {
                tail=i;
                break;
            }
        }
        if(tail!=-1)
        {
            printf(".");
            for(int i=0;i<=tail;i++)
                printf("%d",suf1[i]);
        }
        else
        {
            cout << ".0" ;
        }
        printf("\n");
    }
    return 0;
}
