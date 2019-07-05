#include "..\..\..\cstudy\engine\tge.h"

void sample2()
{
	char animal[5][10] = {
		"tiger",
		"monkey",
		"dog",
		"cat",
		"wolf"
	};

	for (int i = 0; i < 5; i++)
	{
		printf_s("%d ", sizeof(animal[i]));
		puts(animal[i]);
	}

	const char *_animal[5] = {
		"tiger",
		"monkey",
		"dog",
		"cat",
		"wolf"
	};

	for (int i = 0; i < 5; i++)
	{
		printf_s("%d ", sizeof(_animal[i]));
		puts(_animal[i]);
	}
}



