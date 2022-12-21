#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <fstream>

void print(std::vector<int> sequence)
{
	for (size_t i = 0; i < sequence.size(); ++i)
		std::cout << sequence.at(i);
}

int elegant_sum(std::vector<int> sequence)
{
	int sum = 0;
	for (size_t i = 0; i < sequence.size()-1; ++i)
		sum += abs(sequence.at(i) - sequence.at(i + 1));
	return sum;
}

int task(std::vector<int> sequence)
{
	std::map<std::vector<int>, int> m;
	std::queue<std::vector<int>> q;
	q.push(sequence);
	m[sequence] = elegant_sum(sequence);
	int max_elegant_sum = m[sequence];

	while (!q.empty())
	{
		std::vector<int> new_sequence = q.front();
		q.pop();

		if (m[new_sequence] > max_elegant_sum)
			max_elegant_sum = m[new_sequence];

		for (size_t i = 0; i + 2 < sequence.size() + 1; ++i)
		{
			std::vector<int> tmp_sequence = new_sequence;
			std::reverse(tmp_sequence.begin() + i, tmp_sequence.begin() + i + 2);

			if (!m.count(tmp_sequence))
			{
				m[tmp_sequence] = elegant_sum(tmp_sequence);
				q.push(tmp_sequence);
			}
		}
	}
	return max_elegant_sum;
}

int main()
{
	std::ifstream file("test.txt");
	size_t count_of_tests;
	file >> count_of_tests;
	for (size_t i = 0; i < count_of_tests; ++i)
	{
		std::vector<int> sequence;
		size_t size_of_sequence;
		file >> size_of_sequence;
		for (size_t i = 0; i < size_of_sequence; i++)
		{
			int value;
			file >> value;
			sequence.push_back(value);
		}
		std::cout << "Case " << i + 1 << ": " << task(sequence) << '\n';
	}
	std::cin.get();
}