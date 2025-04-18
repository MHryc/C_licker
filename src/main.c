// This is main of C_licker, a C_clicker

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int safe_multiply(int in_num);
int prefixate(int pvix);

int safe_multiply(int in_num) {
	int out_num;
	
	out_num = in_num * 2;
	if (out_num > 32000) {
		out_num /= 1000;
	}
	return out_num;
}

int prefixate(int pvix) {
	int prefix;

	// if previous prefix is outside of [a-z] range set prefix to 'a'
	if (pvix < 97 || pvix >= 122) {
		prefix = 97;
	} else {
		prefix = pvix + 1;
	}
	return prefix;
}

int main(void) {

	struct points_struct {
		unsigned int value;
		int pfx;
	} points;
	points.value = 1;
	points.pfx = 97;
	// from previous version with multi character prefixes, eg. aB
	//memset(points.pfx, 0, sizeof(points.pfx));
	//points.pfx_idx = 0;

	//printf("%d\t%d\t%d\t%d\n", 'a', 'z', 'A', 'Z');

	// REPL
	int command;
	printf("`1` for help\n");

	while (1) {
		printf("C_licker> ");

		scanf("%d", &command);

		// Prevents an endless loop when ^D or a string is input
		if (command < 0 || command > 16) {
			exit(EXIT_FAILURE);
		}

		switch (command) {
			case 0:
				exit(EXIT_SUCCESS);

			case 1:
				printf(
					"1\tto get this help\n"
					"2\tto multiply points\n"
					"0\tto stop C_licker\n"
				  );
				break;

			case 2:
				int tmp;
				tmp = safe_multiply(points.value);

				if (tmp < points.value) {
					points.pfx = prefixate(points.pfx);
				}
				points.value = tmp;

				printf("%d %c\n", points.value, points.pfx);
				break;

			default:
				printf(
					"1\tto get this help\n"
					"2\tto multiply points\n"
					"0\tto stop C_licker\n"
				  );
		}
	}
	return 0;
}
