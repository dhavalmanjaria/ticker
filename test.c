#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ASCII_ESC 27

int main(int argc, char *argv[])
{
	int x = 0;

	char output[][10] = {
		"hello1",
		"hello2",
		"hello3",
		"hello4",
		"hello5",
		"hello6",
		"hello7",
		"hello8",
		"hello9",
		"hello10",
	};

	char buf[4096];
	for (x = 0; x < 10; x++) {
		
		read(0,buf,1024);
		printf("%s",buf);
	}
	printf("%s",output[x]);

	return 0;
}
