#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

struct Process
{
	char name;
	int runtime;
};

void BuildProcess(Process& process)
{
	static char n = 'A';

	process.name = n;
	process.runtime = rand() % 100 + 1;

	if(n == 'Z')
	{
		n = 'A';
	}
	else 
	{
		n += 1;
	}
}

//n is the size of the array
bool BuildProcessArray(Process processes[],int n)
{
	if(n > 0 && n < 26)
	{
		for(int i = 0;i < n;i += 1)
		{
			BuildProcess(processes[i]);
		}
	}
}

/****************************
Define Function Below Here
****************************/
void RoundRobin(Process processes[], int n, int quota) {
	char terminated_processes[n];
	int j = 0;
	while (j < n) {
		for (int i = 0; i < n; i++) {
			if (processes[i].name != '$') {
				processes[i].runtime -= quota;
				if (processes[i].runtime <= 0) {
					terminated_processes[j] = processes[i].name;
					processes[i].name = '$';
					j++;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		std::cout << terminated_processes[i] << ' ';
	}
	std::cout << std::endl;
}

/***************************
Define Function Above Here
***************************/ 

int main()
{
	srand(time(NULL));
	return 0;
}
