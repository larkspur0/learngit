#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char* argv[])
{
	FILE *fp1, *fp2;
	char ch;
	if (argc != 3){
		printf("Usage: fcopy file1 file2 \n");
		exit(EXIT_FAILURE);
	}
	fp1 = fopen(argv[1], "r");
	fp2 = fopen(argv[2], "w");
	if (fp1 == NULL || fp2 == NULL){
		printf("Can't open file.\n");
		exit(EXIT_FAILURE);
	}

	while ((ch = fgetc(fp1)) != EOF){
		fputc(ch, fp2);
	}

	return 0;	
}



