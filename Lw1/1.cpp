/** 1.1.[# 5] Сгенерировать с помощью алгоритма Нарайаны порождения всех перестановок
с выводом времени работы до сотых секунд для 𝑁=10. Записать время порождения всех
перестановок для 𝑁=10, 𝑁=15, 𝑁=20 без вывода полученных последовательностей.
Оценить время работы программы для входа 𝑁=50 и 𝑁=100.
Ошаев Олег ИПС-2023
Visual Studio Professional 2022 (64x) 17.3.4
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <random>
#include <string>  
#include <vector>
#include <boost/timer.hpp>

using namespace std;

vector<size_t> getRandomVector(int size);
int getRandomNumber(int min, int max);
double getPermutationDuration(vector<size_t> vector);
long double fact(int N);

int main()
{
	int n;
	char answer;
	cout << "Please input vector size: ";
	cin >> n;
	vector<size_t> v = getRandomVector(n);
	boost::timer t;
	t.restart();
	sort(v.begin(), v.end());
	cout << "Permutations for vector size " << n << ":" << endl;
	do
	{
		copy(v.begin(), v.end(), ostream_iterator<size_t>(cout, " "));
		cout << endl;
	} while (next_permutation(v.begin(), v.end()));
	double duration = t.elapsed();

	cout << "\n" << "Algorithm Narayana duratuon with output: " << "\n"
		<< "t(" << n << ") = " << duration << " seconds" << "\n" << "\n"
		<< "Algorithm Narayana duratuon without output:" << "\n" << "Be patient..."
		<< "t(10) = " << getPermutationDuration(getRandomVector(10)) << " seconds" << "\n"
		<< "t(15) = " << getPermutationDuration(getRandomVector(15)) << " seconds" << "\n"
		<< "t(20) = " << getPermutationDuration(getRandomVector(20)) << " seconds" << "\n" << endl;
	cout << "T(50) = " << fact(50) << " seconds" << endl;
	cout << "T(100) = " << fact(100) << " seconds" << endl;

	system("pause");
}

int getRandomNumber(int min, int max) {
	return rand() % (max - min + 1) + min;
}

double getPermutationDuration(vector<size_t> vector)
{
	ofstream file("output.txt");
	file.open("output.txt");
	boost::timer t;
	t.restart();
	std::sort(vector.begin(), vector.end());
	do
	{
		copy(vector.begin(), vector.end(), ostream_iterator<size_t>(file, ""));
	} while (next_permutation(vector.begin(), vector.end()));
	file.close();
	return t.elapsed();
}

long double fact(int N)
{
	if (N == 0)
		return 1;
	else
		return N * fact(N - 1);
}

vector<size_t> getRandomVector(int size)
{
	vector<size_t> vec;
	for (size_t i = 0; i < size; ++i)
		vec.push_back(getRandomNumber(1, size));
	return vec;
}