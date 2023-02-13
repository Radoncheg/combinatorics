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

long double getPermutationDuration(vector<size_t> vector)
{

	boost::timer t;
	t.restart();
	std::sort(vector.begin(), vector.end());
	do
	{
	} while (next_permutation(vector.begin(), vector.end()));
	return t.elapsed();
}

long double fact(int N)
{
	if (N == 0)
		return 1;
	else
		return N * fact(N - 1);
}

int main()
{
	vector<size_t> v = { 1, 2, 3, 4, 5, 6 };
	vector<size_t> v1 = { 1, 4, 5, 8, 2, 7, 9, 3, 6, 10 };
	vector<size_t> v2 = { 1, 4, 5, 8, 2, 7, 9, 3, 6, 10, 11, 12 };
	vector<size_t> v3 = { 1, 4, 5, 8, 2, 7, 9, 3, 6, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	boost::timer t;
	t.restart();
	sort(v.begin(), v.end());
	cout << "Permutations for vector size " << 6 << ":" << endl;
	do
	{
		copy(v.begin(), v.end(), ostream_iterator<size_t>(cout, " "));
		cout << endl;
	} while (next_permutation(v.begin(), v.end()));
	long double duration = t.elapsed();

	cout << "\n" << "Algorithm Narayana duratuon with output: " << "\n"
		<< "t(10) = " << duration << " seconds" << "\n" << "\n"
		<< "Algorithm Narayana duratuon without output:" << "\n" << "Be patient..."
		<< "t(10) = " << getPermutationDuration(v1) << " seconds" << "\n"
     	<< "t(15) = " << getPermutationDuration(v2) << " seconds" << "\n"
	    << "t(20) = " << getPermutationDuration(v3) << " seconds" << "\n" << endl;
	cout << "T(50) = " << fact(50) << " seconds" << endl;
	cout << "T(100) = " << fact(100) << " seconds" << endl;

	system("pause");
}



