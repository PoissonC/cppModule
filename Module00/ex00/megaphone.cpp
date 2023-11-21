#include <stdio.h>
#include <ctype.h>

int main(int argc, char **argv) {

	if (argc > 1){
		for (int i = 1; i < argc; i++) {
			for (int j = 0; argv[i][j]; j++) {
				argv[i][j] = toupper(argv[i][j]);
			}
			printf("%s", argv[i]);
			if (i + 1 != argc)
				printf(" ");
		}
	}
	else {
		printf("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
	}
	printf("\n");
}
