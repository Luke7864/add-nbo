#include <stdint.h> // for uint32_t
#include <stdio.h> // for printf
#include <netinet/in.h> //for htonl

int main(int argc, char *argv[]) {
	char *file1 = argv[1];
	char *file2 = argv[2];
	FILE *fd1;
	FILE *fd2;

	uint32_t num1;
	uint32_t num2;
	uint32_t sum;

	if (argc < 3){
		printf("At least 2 argvs needed\n");
		return 0;
	}

	fd1 = fopen(file1, "r");
	fread(&num1, sizeof(uint32_t), 1, fd1);
	fclose(fd1);

	fd2 = fopen(file2, "r");
	fread(&num2, sizeof(uint32_t), 1, fd2);
	fclose(fd2);

	num1 = htonl(num1);
	num2 = htonl(num2);

	sum = num1 + num2;

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, sum, sum);
}
