#include <iostream>
#include <string>
#include <cmath>

void Create(int N, int n, std::string s[]);


int main(int argc, char** argv)
{
	int N;
	int n;
	std::string *mass;
	int i, j;
	if(argc == 2)
	{
		n = atoi(argv[1]);
		N = std::pow(2,n);
		if(N > 0)
		{
			mass = new std::string[N];
			std::cout << "N: " << N << std::endl;
		}
		else
		{
			std::cout << "N must be > 0" << std::endl;
		}
	}
	else
	{
		std::cout << "Error. Try: graycode N [Filename]" << std::endl;
	}

	Create(N, n, mass);
	return 0;
}


void Create(int N, int n, std::string s[])
{
	int k = 2;
	int i, j;
	std::string str = "";
	for(i = 0; i < n; i++)
	{
		if(i == 0)
		{
			s[0] = "0";
			s[1] = "1";
		}
		else
		{
			for(j = 0; j < k/2; j++)
			{
				s[k-1-j]=s[j];
			}
			for(j = 0; j < k; j++)
			{
				if(j < k/2)
					s[j] = "0" + s[j];
				else
					s[j] = "1" + s[j];
			}
		}
		k = k * 2;
	}

	for(i = 0; i < N; i++)
	{
		std::cout <<  s[i] << std::endl;
	}
}

