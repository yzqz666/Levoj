#include<iostream>
using namespace std;
 
int ysf(int sum, int k, int n){
	if(n == 1)
		return (sum + k - 1) % sum + 1;
	return (ysf(sum-1,k,n-1) + k - 1) % sum + 1;
}
 
int main()
{
	int m;
	cin >> m;
	
		int sum = 2 * m, n = 0;
		int k = m + 1;
		while(++n <= m)
		{
			int t = ysf(sum,k,n);
			if(t <= m)
			{
				n = 0;
				k++;
			}
		}
		cout << k << endl;
	return 0;
}	   
