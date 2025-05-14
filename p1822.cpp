#include<iostream>
using namespace std;
double MAX=-1;
int main(){
    int m,u,v,i;
    cin>>m;
    for(i=0;i<m;i++){
        cin>>u>>v;
        if(v>MAX) MAX=v;
    }
	//此为不用数学函数版代码
    int depth=0, p=1;
    while(p<=MAX){
	    p*=2;
	    depth++;
    }
    cout<<depth-1<<endl;
    return 0;
}
