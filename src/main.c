// This is main of C_licker, a C_clicker

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>

float safe_multiply(float in_num, float multiplier);
int prefixate(int pvix);

float safe_multiply(float in_num, float multiplier) {
	float out_num;
	
	out_num = in_num * multiplier;
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

	// Define player stats and score count
	struct points_struct {
		float value;
		int pfx;
		float mul;
	} player = {1.0, 97, 1.1};
	// from previous version with multi character prefixes, eg. aB
	//memset(points.pfx, 0, sizeof(points.pfx));
	//points.pfx_idx = 0;

	//printf("%d\t%d\t%d\t%d\n", 'a', 'z', 'A', 'Z');

	initscr();
    //noecho();

	refresh();

	// REPL
	int command;
	char ch;
	printf("`1` for help\n");

	while ((ch = getch()) != 'q') {
		printw("C_licker> ");

		switch (ch) {
			case '0':
				exit(EXIT_SUCCESS);

			case '1':
				printw(
					"1\tto get this help\n"
					"2\tto multiply points\n"
					"0\tto stop C_licker\n"
				  );
				break;

			case ' ':
				float tmp;
				tmp = safe_multiply(player.value, player.mul);
				player.mul += 0.1;

				if (tmp < player.value) {
					player.pfx = prefixate(player.pfx);
				}
				player.value = tmp;

				clear();

				printw("%c%f\t%f\n", player.pfx, player.value, player.mul);

				refresh();

				break;

			case 'c':
				clear();
				break;

//			default:
//				printf(
//					"1\tto get this help\n"
//					"2\tto multiply points\n"
//					"0\tto stop C_licker\n"
//				  );
		}
	}
	refresh();
	endwin();
	return 0;
}
