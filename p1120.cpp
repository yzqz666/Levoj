#include <iostream>
#include <string.h>
#include <algorithm>
#include<string>
using namespace std;
const int maxn=206;

int n[maxn],m[maxn],ans[maxn];
int main(int argc, char const *argv[]) {
    char a[maxn],b[maxn];
    cin>>a>>b;
     {
        for(int i=0;i<maxn;i++) ans[i]=0;
        int len=strlen(a),length=strlen(b);
        for(int i=0;i<len;i++){
            n[i]=a[len-i-1]-'0';
        }
        for(int j=0;j<length;j++){
            m[j]=b[length-j-1]-'0';
        }
        int c=max(len,length);
        for(int i=0;i<c;i++){
            ans[i]+=n[i]+m[i];
            ans[i+1]+=(ans[i]/10);
            ans[i]%=10;
        }
        if(!ans[c]) c--;
        for(int i=c;i>=0;i--){
            std::cout << ans[i];
        }
        std::cout  << '\n';
    }
}

