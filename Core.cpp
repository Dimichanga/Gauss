#include <iostream>
#include <fstream>
#include <vector>
#include "X.hpp"
using namespace std;

vector <vector<double>> A;
vector <double> B;
vector <double> x;

int main()
{
	ifstream fin("input.txt"); //Открываю входной файл

	if (!fin.is_open()) //если файл не был открыт
		cout << "File can/t be open.\n";
	else
	{
		int N;
		float buff;

		fin >> N; //Считываю размерность массивов
		//Считываем А и В
		A.resize(N);
		B.resize(N);
		x.resize(N);
		for (int i = 0; i < N; i++)
		{
			A[i].resize(N);
			for (int j = 0; j < N; j++)
				fin >> A[i][j];
			fin >> B[i];
		}
		

		fin.close();//Закрыл входной файл

		ofstream fout("output.txt");//Открыл выходной файл
		//Выводим А и В
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				fout << A[i][j] << '	';
			fout << B[i] << endl;
		}
		fout << endl << endl;
		
		x=X(A, B);

		fout << "Iskomiy vektor x: "<<endl;
		for (int i = 0; i < B.size(); i++)
			fout << x[i] <<endl;

		fout.close();//Закрыл выходной файл

		return 0;
	}	
}