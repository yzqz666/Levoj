#include <iostream>
#include <string>
using namespace std;
void judge(string t, int rule)
{
    int a = 0, b = 0;
    for (int i = 0; i < (int)t.size() - 1; i++)
    {
        if (t[i] == 'E')
            break;
        if (t[i] == 'W')
            a++;
        else if (t[i] == 'L')
            b++;
        if ((a >= rule && a - b > 1) || (b >= rule && b - a > 1))
        {
            cout << a << ":" << b << endl;
            a = 0, b = 0;
        }
    }
    cout << a << ":" << b << endl
         << endl;
}
 
int main()
{
    string t;
    getline(cin, t);
    judge(t, 11);
    judge(t, 21);
    return 0;
}
 