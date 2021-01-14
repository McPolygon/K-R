/*
 *  K&R entab.c
 *
 *  Created on: Jan 13, 2021
 *  Author: Jesse Kukuk
 *
 *  "Write a program entab that replaces strings of blanks by the minimum number
 *   of tabs and blanks to achieve the same spacing. Use the same tab stops, say
 *   every n columns. Should n be a variable or a symbolic parameter?"
 */

#include <stdio.h>

#define TAB_STOP 4
#define ARR_SYMB_CONST_LEN 1024

int getLine(char [], int);
void entab(char [], int);

int main(void)
{
	char line[ARR_SYMB_CONST_LEN];

	while (getLine(line, ARR_SYMB_CONST_LEN) > 0) {
		entab(line, TAB_STOP);
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

/* entab() K&R solution */
void entab(char s[], int col)
{
	int space = 0;
	int pos = 0;
	int arr_pos = 0;

	while (s[arr_pos] != '\n') {
		++pos;

		if (s[arr_pos] == ' ') {
			++space;
			if ((pos % col == 0) && (space > 0)) {
				if (space == 1) {
					printf("_");
					space = 0;
				} else {
					printf("\\t");
					space = 0;
				}
			}
		} else if (s[arr_pos] == '\n') {
			putchar('\n');
			space = 0;
			pos = 0;
			arr_pos = 0;
		} else {
			while (space > 0) {
				printf("_");
				--space;
			}
			printf("%c", s[arr_pos]);
		}
		++arr_pos;
	}
}
