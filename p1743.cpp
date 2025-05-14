#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=105;
struct D{int nxt,to,w;}e[N*20];
int fir[N],tot,d[N][N];
int n,m,Q,t;
priority_queue< pair<int,int> > q;
bool v[N];
void add(int x,int y,int z)
{
	e[++tot].nxt=fir[x];
	e[tot].to=y;
	e[tot].w=z;
	fir[x]=tot;
}
void dij(int x)
{
	memset(v,0,sizeof(v));
	d[x][x]=0;
	q.push(make_pair(0,x));
	while(!q.empty())
	{
		int now=q.top().second;
		q.pop();
		if(v[now]) continue;
		v[now]=1;
		for(int i=fir[now];i;i=e[i].nxt)
		{
			int p=e[i].to;
			if(d[x][p]>max(d[x][now],e[i].w))
			{
				d[x][p]=max(d[x][now],e[i].w);
				q.push(make_pair(-d[x][p],p));
			}
		}
	}
}
void solve()
{
	//if(t>1) puts("");
	printf("Case #%d\n",t);
	tot=0;
	memset(fir,0,sizeof(fir));
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);add(y,x,z);
	}
	for(int i=1;i<=n;i++) dij(i);
	for(int i=1;i<=Q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(d[x][y]!=0x3f3f3f3f) printf("%d\n",d[x][y]);
		else printf("no path\n");
	}
}
int main()
{
		while(cin >> n >> m >> Q)
		{
			t++;
			if(n==0&&m==0&&Q==0) break;
			solve();
		}
	return 0;
}