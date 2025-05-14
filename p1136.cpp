#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#define N 201

using namespace std;
int result[N] = { 0 };

int main()
{
	string num1,num2;
	int pin;
	while (cin >> num1)
	{
		cin >> num2;
 
		int cnum1 = num1.size();
		int cnum2 = num2.size();
 
		reverse(num1.begin(),num1.end());
		reverse(num2.begin(),num2.end());
		int len;
		for (int i = 0; i < cnum1; i++)
		{
			pin = 0;
			for (int j = 0; j < cnum2; j++)
			{
				int temp = result[i + j] + (int)(num1[i] - '0') * (int)(num2[j] - '0') + pin; 
				result[i + j] = temp % 10;
				pin = temp / 10;
				len = i + j;     
			}
			if (pin)
			{
				result[cnum2 + i] = pin;
				len = cnum2 + i;
				
			}
		}
		for (int k = len; k >= 0; k--)
		{
			printf("%d", result[k]);
		}
		printf("\n");
	}
		
}

 
