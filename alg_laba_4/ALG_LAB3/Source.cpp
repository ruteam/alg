#include <iostream>

int arr[1000][10][10][10];

void init_arr(int arr[1000][10][10][10])
{
	for (int i = 0; i < 1000; ++i)
		for (int j = 0; j < 10; ++j)
			for (int g = 0; g < 10; ++g)
				for (int h = 0; h < 10; ++h)
					arr[i][j][g][h] = 0;
}

int print_count_of_megacool(int n, int a)
{
	int count = 0;
	if (a <= 9)
	{
		init_arr(arr);
		int pow, //���������� ������� ���������� �����

			diff, //������� �����\���� ���������� � �����
			//����������� �������� diff = 9 ����������, ��� ���������
			//���������� ������� �� ������ ����� � �� ������� �� ����������.


			last; //��������� ����� �����

		//���������� ���������� ����� ������� ������ ��������������� ��� i = 1, 2, 3, �, n.
		//��� i = 1 ������� ����� ���� ����� ��� ������� ������ ���� (1, 9, d), 1 <= d <= 9 � 0 ����� ��� ��������� �������.

		for (int d = 1; d <= 9; ++d)
			arr[1][1][9][d] = 1;

		//����������, ��� ���� ���������� � ������� ��� ����� ����� i,
		//�������� ������ � ������� ��� ����� ����� i + 1.
		//���������� ��������� ������ ����� ����� i � ��� ������� �� ���
		//�������, ����� ����� ����� �������� ����������� ����� �����.
		//������������� ���������� ��������� :
		for (int i = 1; i < n; ++i)
		{
			std::cout << "i = " << i << '\n';
			for (pow = 1; pow <= a; ++pow)
			{
				std::cout << "  pow = " << pow << '\n';
				for (last = 1; last <= 9; ++last)
				{
					std::cout << "    last = " << last << '\n';
					//� ������� ����� �� ������(pow, 9, last) ����� �������� ����� ����� d, last <= d <= 9,
					//������� ��������� ���������� ���� ������.� ���������� ������� ����� �� ������ (pow, d � last, d)
					for (int d = last; d <= 9; ++d)
					{
						std::cout << "      d = " << d << '\n';
						if (arr[i][pow][9][last])
						{
							arr[i + 1][pow][d - last][d] += arr[i][pow][9][last] % 1000000007;
							std::cout << "      arr[" << i + 1 << "][" << pow << "][" << d - last << "][" << d << "] = " << arr[i + 1][pow][d - last][d] << '\n';
						}
					}
					//� ������� ����� �� ������ (pow, diff, last), 0 <= diff < 9, ����� �������� ����� ����� d,
					//last <= d <= 9. ���� d � last = diff, �� �� ����� �������� ��������� ���������� �
					//�������� ����� �� ������ (pow, diff, d). 
					for (diff = 0; diff < 9; ++diff)
					{
						std::cout << "      diff = " << diff << '\n';
						for (int d = last; d <= 9; ++d)
						{
							std::cout << "        d = " << d << '\n';
							if (arr[i][pow][diff][last])
								if (d - last == diff)
								{
									arr[i + 1][pow][diff][d] += arr[i][pow][diff][last] % 1000000007;
									std::cout << "        arr[" << i + 1 << "][" << pow << "][" << diff << "][" << d << "] = " << arr[i + 1][pow][diff][d] << '\n';
								}
							//����� ���������� �������� ����� ���������� � ����� ����� ����� ������������ ������ (pow + 1, 9, d).
								else
								{
									arr[i + 1][pow + 1][9][d] += arr[i][pow][diff][last] % 1000000007;
									std::cout << "        arr[" << i + 1 << "][" << pow + 1 << "][" << 9 << "][" << d << "] = " << arr[i + 1][pow + 1][9][d] << '\n';
								}
						}
					}
				}
			}
			std::cout << '\n';
		}

		//������� ������ ����� ���������� ���� ����� � ������� (a, diff, last),
		//������������� n - �������� ������������ ������.
		for (last = 1; last <= 9; ++last)
			for (diff = 0; diff <= 9; ++diff)
				count += arr[n][a][diff][last] % 1000000007;
	}
	return count;
}

int count_of_megacool(int n, int a)
{
	/*
		pow - ���������� ������� ���������� �����
		diff - ������� ��������� ���������� � �����
		last - ��������� ����� �����
	*/
	int count = 0;
	if (a <= 9)
	{
		init_arr(arr);
		int pow, diff, last;

		for (int d = 1; d <= 9; ++d)
			arr[1][1][9][d] = 1;

		for (int i = 1; i < n; ++i)
			for (pow = 1; pow <= a; ++pow)
				for (last = 1; last <= 9; ++last)
				{
					//� ������� ����� �� ������(pow, 9, last) ����� �������� ����� ����� d, last <= d <= 9,
					//������� ��������� ���������� ���� ������.� ���������� ������� ����� �� ������ (pow, d � last, d)
					for (int d = last; d <= 9; ++d)
						if (arr[i][pow][9][last])
							arr[i + 1][pow][d - last][d] += arr[i][pow][9][last] % 1000000007;

					//� ������� ����� �� ������ (pow, diff, last), 0 <= diff < 9, ����� �������� ����� ����� d,
					//last <= d <= 9. ���� d � last = diff, �� �� ����� �������� ��������� ���������� �
					//�������� ����� �� ������ (pow, diff, d). 
					for (diff = 0; diff < 9; ++diff)
						for (int d = last; d <= 9; ++d)
							if (arr[i][pow][diff][last])
								if (d - last == diff)
									arr[i + 1][pow][diff][d] += arr[i][pow][diff][last] % 1000000007;

								//����� ���������� �������� ����� ���������� � ����� ����� ����� ������������ ������ (pow + 1, 9, d).
								else
									arr[i + 1][pow + 1][9][d] += arr[i][pow][diff][last] % 1000000007;
				}

		//������� ������ ����� ���������� ���� ����� � ������� (a, diff, last),
		//������������� n - �������� ������������ ������.
		for (last = 1; last <= 9; ++last)
			for (diff = 0; diff <= 9; ++diff)
				count += arr[n][a][diff][last] % 1000000007;
	}
	return count;
}

int main()
{
	std::cout << count_of_megacool(1, 1)  << '\n';
	std::cout << count_of_megacool(2, 1)  << '\n';
	std::cout << count_of_megacool(10, 3) << '\n';
	std::cin.get();
}