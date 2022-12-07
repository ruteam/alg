#include <Windows.h>
#include <iostream>

using namespace std;


struct digit {
	int d;
	long long int st;
};

// пока сумма цифр != нужному числу, перебирать их

int main()
{
	long long int n;
	cout << ">>> ";
	cin >> n;
	
	int p = 9;
	digit ghr[9];
	for (int i = 0; i < p; i++)
		ghr[i].d = i + 1;

	for (long long int i = 1; i <= n; i++) {
		if (i < 10)
			cout << i << " = " << i << endl;

		else {			
			long long int sum = 0;
			long long int k = 0;
			long long int a = i;

			while (a != 0) {
				k += 1;
				a /= 10;
			}

			for (int j = 0; j < p; j++) {
				ghr[j].st = ghr[j].d;
				for (long long int t = 1; t < k; t++)
					ghr[j].st *= ghr[j].d;
				
			}

			a = i;

			//long long int h;
			while (a != 0) {
				if (a % 10 > 0) {
					for (int r = 0; r < p; r++) {
						if (ghr[r].d == a % 10) {
							sum += ghr[r].st;
						}
					}
			//		h = a % 10;
			//		for (long long int j = 1; j < k; j++)
			//			h *= a % 10;
			//		sum += h;
				}
				a /= 10;
			}

			if (i == sum)
				cout << i << " = " << sum << endl;
		}
	} 


	return 0;
}
