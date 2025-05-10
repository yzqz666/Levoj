#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn=206;

int n[maxn],m[maxn],ans[maxn];
int main(int argc, char const *argv[]) {
    string a,b;
    cin>>a>>b;{
        for(int i=0;i<maxn;i++) ans[i]=0;
        int len=a.length(),length=b.length();
        for(int i=0;i<len;i++){
            n[i]=a[len-i-1]-'0';
        }
        for(int j=0;j<length;j++){
            m[j]=b[length-j-1]-'0';
            // std::cout << m[j] << '\n';
        }
        int flag=0;
        // flag=1 那就是 a,n大 ,0就是 b,m大
        if(len>length) flag=1;
        else if(len==length) flag=2;
        if(flag==2){
            if(a>b) flag=1;
            else flag=0;
        }
        int c=len;
        if(!flag) c=length;
        if(flag){
            for(int i=0;i<c;i++){
                if(n[i]<m[i]){
                    n[i]+=10;
                    n[i+1]--;
                }
                ans[i]=n[i]-m[i];
            }
        }
        else {
            for(int i=0;i<c;i++){
                if(m[i]<n[i]){
                    m[i]+=10;
                    m[i+1]--;
                }
                ans[i]=m[i]-n[i];
            }
        }
        while (!ans[c]&&c>=0) c--;
        for(int i=c;i>=0;i--)
            std::cout << ans[i];
        std::cout  << '\n';
    }
}
