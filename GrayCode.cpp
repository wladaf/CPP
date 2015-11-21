#include <iostream>
#include <string>
#include <cmath>

void Create();

int i, j;
int N;
int n;
std::string *s;

int main(int argc, char** argv)
{
	if(argc == 2)
	{
		n = atoi(argv[1]);
		N = std::pow(2,n);
		if(N > 0)
		{
			s = new std::string[N];
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

	Create();
	return 0;
}


void Create()
{
	std::string str = "";
	for(int k = 2, i = 0; i < n; i++, k*=2)
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
				s[j] = std::to_string(j >= k/2)+ s[j];
			}
		}
	}

	for(i = 0; i < N; i++)
	{
		std::cout <<  s[i] << std::endl;
	}
}

