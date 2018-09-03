#include "stdafx.h"
#include "memory.h"
#include "math.h"
using namespace std;

int main()
{
	int whichbit[32];
	int buck[625];

	for (int i = 0; i < 32; i++)
	{
		whichbit[i] = pow(2, i);
	}

	FILE *fp;
	fp = fopen("C:\\Users\\manas\\OneDrive\\Desktop\\alpha.txt", "r");
	if (!fp)
	{
		printf("FILE NAHI HAI");
		return 1;
	}

	memset(buck, 0, 625*4);

	for (int i = 0; i<100; i++)
	{
		int x, in = 0, of = 0;
		fscanf(fp, "%d", &x);
		in = (x - 1) / 32;
		of = (x - 1) % 32;
		buck[in] = buck[in] | whichbit[of];
	}
	for (int i = 1; i<100; i++)
	{
		int in = 0, of = 0;
		in = (i - 1) / 32;
		of = (i - 1) % 32;
		if (buck[in] & whichbit[of])
			printf("%d\n", i);
    }
	return 0;
}