#include "stdafx.h"
#include "memory.h"

using namespace std;

int main()
{
	char pos[8] = { 1,2,4,8,16,32,64,128 };
	char buck[2500];

	FILE *fp;
	fp = fopen("C:\\Users\\manas\\OneDrive\\Desktop\\alpha.txt", "r");
	if (!fp)
	{
		printf("FILE NAHI HAI");
		return 1;
	}

	memset(buck, 0, 2500);

	for (int i = 0; i<100; i++)
	{
		int x, in = 0, of = 0;
		fscanf(fp, "%d", &x);
		in = (x - 1) / 8;
		of = (x - 1) % 8;
		buck[in] = buck[in] | pos[of];
	}
	for (int i = 1; i<100; i++)
	{
		int in = 0, of = 0;
		in = (i - 1) / 8;
		of = (i - 1) % 8;
		if (buck[in] & pos[of])
			printf("%d\n", i);
    }
	return 0;
}