#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
 
bool compare(const string &a, const string &b)
{
    return a + b > b + a;
}
 
string func(vector<string> &nums)
{
    sort(nums.begin(), nums.end(), compare);
    string ans;
    for (string s : nums)
        ans += s;
    return ans;
}
 
int main()
{
    int n;
    cin >> n;
    vector<string> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    string ans = func(nums);
    cout << ans << endl;
    return 0;
}
 