#include <iostream>

void init_arr(int arr[1000][10][10][10])
{
	for (int i = 0; i < 1000; ++i)
		for (int j = 0; j < 10; ++j)
			for (int g = 0; g < 10; ++g)
				for (int h = 0; h < 10; ++h)
					arr[i][j][g][h] = 0;
}

int count_of_megahold(int n, int a)
{
	int arr[1000][10][10][10];
	init_arr(arr);
	int pow, diff, last;
	int i, d;
	for (d = 1; d <= 9; ++d)
		arr[1][1][9][d] = 1;
	for (i = 1; i < n; ++i)
	{
		for (pow = 1; pow <= 9; ++pow)
		{
			for (last = 1; last <= 9; ++last)
			{
				for (d = last; d <= 9; ++d)
				{
					arr[i + 1][pow][d - last][d] += arr[i][pow][9][last];
					arr[i + 1][pow][d - last][d] %= 1000000007;
				}
				for (diff = 0; diff < 9; ++diff)
				{
					for (d = last; d <= 9; ++d)
					{
						if (d - last == diff)
						{
							arr[i + 1][pow][diff][d] += arr[i][pow][diff][last];
							arr[i + 1][pow][diff][d] %= 1000000007;
						}
						else
						{
							arr[i+1][pow+1][9][d] += arr[i][pow][diff][last];
							arr[i+1][pow+1][9][d] %= 1000000007;
						}
					}
				}
			}
		}
	}
	int count = 0;
	for (last = 1; last <= 9; ++last)
		for (diff = 0; diff <= 9; ++diff)
			count += arr[n][a][diff][last] % 1000000007;
	return count;
}

int main()
{
	std::cout << count_of_megahold(1, 1) << '\n';
	std::cout << count_of_megahold(2, 1) << '\n';
	std::cout << count_of_megahold(10, 3) << '\n';

	std::cin.get();
	return 0;
}