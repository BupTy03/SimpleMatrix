#include<iostream>
#include"simple_nmatrix.hpp"

int main()
{
	using namespace std;

	system("chcp 1251");
	system("cls");

	my::simple_nmatrix<3, int> mtx(std::array<int, 3>{3,3,3});

	for (int i = 0; i < (mtx.dimentions()).at(0); ++i)
	{
		for (int j = 0; j < (mtx.dimentions()).at(1); ++j)
		{
			for (int k = 0; k < (mtx.dimentions()).at(2); ++k)
			{
				cout << mtx.at(std::array<int, 3>{i, j, k}) << " ";
			}
			cout << endl;
		}
		cout << "----------------------------------------------" << endl;
	}

	system("pause");
	return 0;
}