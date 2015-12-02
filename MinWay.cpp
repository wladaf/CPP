#include <iostream>
#include <algorithm>


int*** mArray;
int** result;
int i, j, k, l;
int n;

void CreateAndGenerateM(int n);
void Find();
void MatrixMult(int ind);
void Min();

int main(int argc, char const *argv[]) {
  if(argc == 2)
	{
		n = atoi(argv[1]);
	}
  else
  {
    std::cout << "Arg error." << std::endl;
    return -1;
  }
  CreateAndGenerateM(n);
  Find();
  Min();
  std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      std::cout << result[i][j] << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}

void CreateAndGenerateM(int n)
{
  mArray = new int**[n-1];
  for(i = 0; i < n - 1; i++)
  {
    mArray[i] = new int*[n];
    for(j = 0; j < n; j++)
    {
      mArray[i][j] = new int[n];
    }
  }
  std::srand( std::time(0) );
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      mArray[0][i][j] = rand() % 5 + 1;
      std::cout << mArray[0][i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void Find()
{
  for(l = 1; l < n - 1; l++)
  {
    MatrixMult(l);
  }
}

void MatrixMult(int ind)
{
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      mArray[ind][i][j]=999999;
    }
  }
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      for(k = 0; k < n; k++)
      {
        mArray[ind][i][j] = std::min(mArray[ind-1][i][k] + mArray[0][k][j], mArray[ind][i][j]);
      }
    }
  }
}

void Min()
{
  result = new int*[n];
  for(i = 0; i < n; i++)
  {
    result[i] = new int[n];
  }
  int tmp = 999999;
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      for(k = 0; k < n - 1; k++)
      {
        if(mArray[k][i][j] < tmp)
        {
          tmp = mArray[k][i][j];
        }
      }
      result[i][j] = tmp;
      tmp = 999999;
    }
  }
}
