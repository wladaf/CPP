#include <iostream>
#include <String>
#include <cmath>

void Change(int &a);
void Create(int N, std::string s[]);


int val = 0;

int main(int argc, char** argv)
{
	int N;
	std::string *mass;
	int i, j;
	if(argc == 2)
	{
		N = std::pow(2,atoi(argv[1]));
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

	Create(N, mass);

	return 0;
}

void Change(int &a)
{
	a = (a + 1)%2;

}


void Create(int N, std::string s[])
{
	int value;
	int k = 2;
	int i;
	std::string str = "";
	for(i = 0; i < N; i++)
	{
		if(i%2 == 1)
			Change(val);
		s[i] = std::to_string(val);
		
	}
	while(k <= N/2)
	{
		int value = 1;
		for(i = 0; i < N; i++)
		{
			if(i%k == 0)
				Change(value);
			s[i] = std::to_string(value) + s[i];

		}
		k = k*2;
	}
	for(i = 0; i < N; i++)
	{
		std::cout <<  s[i] << std::endl;
	}
}

