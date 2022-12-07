//(Ì + Î + Ñ + Ê + Â + À)^4 = Ì Î Ñ Ê Â À

#include <Windows.h>
#include <iostream>

using namespace std;

void print(int sum, int temp, int* arr)
{
	if (pow(sum, 4) == temp)
	{
		cout << "(";
		for (int i = 0; i < 6; i++)
		{
			if (i != 5)
				cout << arr[i] << " + ";
			else
				cout << arr[i] << ")^4 = ";
		}
		cout << temp;
	}
}

void repeat(int k, int* arr, int* dop)
{
	if (k == 6)
	{
		int sum = 0, temp=0;
		int n = 100000;
		for (int i = 0; i < 6; i++)
		{
			temp += (arr[i] * n);
			sum += arr[i];
			n /= 10;
		}
		print(sum, temp, arr);
	}
	else
	{
		for (int y = 0; y < 10; y++)
		{
			if (dop[y] > 0)
			{
				arr[k] = y;
				dop[y] = dop[y] - 1;
				repeat(k + 1, arr, dop);
				dop[y] = dop[y] + 1;
			}
		}
	}
}

void main()
{
	setlocale(0, "");
	int arr[6];
	int dop[10];
	for (int i = 0; i < 10; i++)
	{
		dop[i] = 1;
		repeat(0, arr, dop);
	}
}