#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

int i, j;
int* SN;
int length;

void SimpleNumbers(int n);

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

	

	int **array = new int*[k];

	for(i = 0; i < k; i++)
	{
		array[i] = new int[k];
	}
	n = 0;
	SimpleNumbers(k*k);

	while(maxCol >= minCol && maxRow >= minRow)
	{
		for(i = maxCol; i >= minCol; i--)
		{
			array[i][maxRow] = SN[n];
			n++;
		}
		maxRow--;

		for(i = maxRow; i >= minRow; i--)
		{
			array[minCol][i] = SN[n];
			n++;
		}
		minCol++;

		for(i = minCol; i <= maxCol; i++)
		{
			array[i][minRow] = SN[n];
			n++;
		}
		minRow++;

		for(i = minRow; i <= maxRow; i++)
		{
			array[maxCol][i] = SN[n];
			n++;
		}
		maxCol--;
	}

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

void SimpleNumbers(int n)
{
	int lastSN = 0;
	int k = 0;
	SN = new int[n];
	bool found = false;
	for(i = 0; i < n; i++)
	{
		while(!found)
		{
			lastSN++;
			found = true;
			for(j = 2; j < lastSN; j++)
			{
				if(lastSN % j == 0)
				{
					found = false;
					break;
				}
			}
				
		}
		found = false;
		SN[i] = lastSN;
		length = std::to_string(lastSN).length();
	}

}