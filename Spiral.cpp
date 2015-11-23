#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

int i, j;
int main(int argc, char** argv)
{
	int k = 4;
	if(argc == 2)
	{
		k = atoi(argv[1]);
	}
	
	int n;
	int minRow = 0;
	int maxRow = k - 1;
	int minCol = 0;
	int maxCol = k - 1;

	int length = std::to_string(k*k).length();

	int **array = new int*[k];

	for(i = 0; i < k; i++)
	{
		array[i] = new int[k];
	}
	n = k*k;
	while(maxCol >= minCol && maxRow >= minRow)
	{
		for(i = maxCol; i >= minCol; i--)
		{
			array[i][maxRow] = n;
			n--;
		}
		maxRow--;

		for(i = maxRow; i >= minRow; i--)
		{
			array[minCol][i] = n;
			n--;
		}
		minCol++;

		for(i = minCol; i <= maxCol; i++)
		{
			array[i][minRow] = n;
			n--;
		}
		minRow++;

		for(i = minRow; i <= maxRow; i++)
		{
			array[maxCol][i] = n;
			n--;
		}
		maxCol--;
	}
	/*for(i = 0; i < k; i++)
	{
		for(j = 0; j < k; j++)
		{
			array[i][j] = i*j;
		}
	}*/

	for(i = 0; i < k; i++)
	{
		for(j = 0; j < k; j++)
		{
			std::cout << std::setw(length) << array[j][i] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}