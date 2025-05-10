#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
 
int main()
{
    map<char, string> mp;
    string temp;
    int m, n;
 
    cin >> n;
    while (n--)
    {
        cin >> temp;
        mp[temp[0]] = temp;
    }
 
    cin >> m;
    vector<string> str(m);
    for (int i = 0; i < m; i++)
    {
        cin >> str[i];
        str[i] = mp[str[i][0]];
    }
 
    for (int i = 0; i < m; i++)
    {
        cout << str[i] << " ";
    }
    cout << endl;
 
    return 0;
}
 