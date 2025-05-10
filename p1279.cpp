#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


const int N = 100001;
int n, len, num;
int d[N] = {0};
 
void Scanf()
{
     cin >> len >> num;
        int i;
 
        for(i = 0; i < num; i ++)
            cin >> d[i];
}
 
int min()
{
    int dis[N] = {0}, i;
    for(i = 0; i < num; i ++)
    {
        if(d[i] >= len/2)
            dis[i] = len - d[i];
        else if(d[i] <= len/2)
            dis[i] = d[i];
    }
 
    int imin = 0;
    for(i = 0; i < num; i ++)
        if(dis[i] > imin)
            imin = dis[i];
 
    return imin;
}
 
int max()
{
    int dis[N] = {0}, i;
    for(i = 0; i < num; i ++)
    {
        if(d[i] >= len/2)
            dis[i] = d[i];
        else if(d[i] <= len/2)
            dis[i] = len - d[i];
    }
 
    int imax = 0;
    for(i = 0; i < num; i ++)
        if(dis[i] > imax)
            imax = dis[i];
 
    return imax;
}
 
void Printf()
{
    printf("%d %d\n", min(), max());
}
 
void Initialize ()
{
    int i;
    for(i = 0; i < N; i ++)
        d[i] = 0;
}
 
int main()
{
    
        Scanf();
 
        Printf();
 
        Initialize();
    
    return 0;
}
