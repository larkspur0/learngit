#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char* argv[])
{
	FILE *source, *dest;
	int ch;						//此处用int而不是char

	if (argc != 3){
		fprintf(stderr, "usage: fcopy source dest\n");		//用fprintf
		exit(EXIT_FAILURE);
	}
	source = fopen(argv[1], "rb");
	dest = fopen(argv[2], "wb");

	if (source == NULL){
		fprintf(stderr, "Can't open %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (dest == NULL){
		fprintf(stderr, "Can't open %s.\n", argv[2]);
		fclose(source);			//source已经打开了，所以要关闭
		exit(EXIT_FAILURE);
	}

	while ((ch = fgetc(source)) != EOF)
		fputc(ch, dest);

	fclose(source);
	fclose(dest);				//记得关闭这两个文件
	return 0;	
}



