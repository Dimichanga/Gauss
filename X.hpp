using namespace std;
vector <double> X(vector <vector<double>>& A, vector <double>& B)
{
	double d, buff, s;
	vector <double> x;

	x.resize(B.size());
	for (int k = 0; k < B.size() - 1; k++)
		for (int i = k + 1; i < B.size(); i++)
		{
			if (A[k][k] == 0) //Начинаем проверку на нулевой элемент матрицы
			{
				for (int i = k + 1; i < B.size(); i++)
				{
					if (A[k][i] != 0) //Встретили первый ненулевой
					{
						for (int j = 0; j < B.size(); j++) //Цикл для того, чтобы поменять столбцы местами
						{
							buff = A[j][i];
							A[j][i] = A[j][k];
							A[j][k] = buff;
						}
						break;
					}
				}

			}
			d = A[i][k] / (A[k][k]); //ВЫчисления прямого хода
			for (int j = k; j < B.size(); j++)
				A[i][j] = A[i][j] - d * (A[k][j]);
			B[i] -= d * (B[k]);
		}
	for (int k = B.size() - 1; k >= 0; k--)
	{
		d = 0;
		for (int j = 0; j < B.size(); j++)
		{
			s = A[k][j] * x[j];
			d += s;
		}
		x[k] = (B[k] - d) / A[k][k];
	}
	return x;
}


