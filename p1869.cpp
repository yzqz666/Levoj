#include<iostream>
using namespace std;
int nums[1000000];
int main(){
    int n,i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>nums[i];
    }
    int preDiff=0;
    int curDiff=0;
    int result=1; // 长度为2，即使是两个数字相等，子序列长度也有一个
    for (i=1;i<n;i++){
        curDiff = nums[i]-nums[i-1];
        // 计算当前位置的变化方向
        if ((curDiff<0 && preDiff>=0) || (curDiff>0 && preDiff<=0)){  
            // 如果当前位置和前方位置的变化方向相反
            //序列长度加1，并记录变化方向
            result++;
            preDiff = curDiff;
        }
    }
    cout<<n-result<<endl;
    return 0;
}
