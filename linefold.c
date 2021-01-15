/*
 * linefold.c K&R
 *
 *  Created on: Jan 13, 2021
 *  Author: Jesse Kukuk
 *  
 *  input: 
 *  Adama: What do you hear, Starbuck? Starbuck: Nothing but the rain, sir. Adama: Then get your gun, and bring the cat in.
 *
 *	Output : 
 *  Adama: What do y
 *	ou hear, Starbuc
 *	k? Starbuck: Not
 *	hing but the rai
 *	n, sir. Adama: T
 *	hen get your gun
 *	, and bring the
 *	cat in.
 */

#include <stdio.h>

#define ARR_LEN 1000
#define FOLD 16

int getLine(char [], int);
void foldLine(char [], int);

int main(void)
{
	char line[ARR_LEN];
	while (getLine(line, ARR_LEN) > 0) {
		foldLine(line, FOLD);
	}
}

/* getLine() K&R */
int getLine(char s[], int len)
{
	int i, c;
	for (i = 0; i < len - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = '\n';
		++i;
	}
	s[i] = '\0';
	return i;
}

/* foldLine() K&R Solution */
void foldLine(char s[], int fold)
{
	int arr_pos = 0;
	int new_ln = 0;

	putchar('\n');

	while (s[arr_pos] != '\n') {

		if (((arr_pos % fold) + 1) == fold) {
			if ((s[arr_pos] == ' ') || (s[arr_pos] == '\t')) {
				++arr_pos;
				putchar('\n');
				new_ln = 1;
			} else {
				putchar(s[arr_pos]);
				putchar('\n');
				++arr_pos;
				new_ln = 1;
			}
		} else {
			if((new_ln == 1) && (s[arr_pos] == ' ')) {
				++arr_pos;
				new_ln = 0;
			} else {
				putchar(s[arr_pos]);
				++arr_pos;
				new_ln = 0;
			}
		}
	}
}
