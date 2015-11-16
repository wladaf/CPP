#include <iostream>
#include <String>

void Change(int &a);
void Create(int N, std::string s[]);

int value = 1;

int main(int argc, char** argv)
{
	int N;
	int k;
	std::string mass[];
	int i, j;
	if(argc > 1)
	{
		N = atoi(argv[1]);
		std::cout << "N: " << N << std::endl;

	}
	else
	{
		std::cout << "No arguments, try \"/path/to/file N\"" << std::endl;
	}

	for()
	Create(N, mass);

	return 0;
}

void Change(int &a)
{
	a = (a + 1)%2;
}


void Create(int N, std::string s[])
{
	
	std::cout << "it works!" << std::endl;
}

