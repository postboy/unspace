#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int safe_getchar(void) {
    int c = getchar();
    if (c == EOF)
	exit(0);
    return c;
}

int main(void) {
    bool prev_alnum = false;
    bool had_space = false;
    bool need_newline = false;

    for (;;) {
	int c = safe_getchar();

        if (c == '\n' && need_newline) {
	    putchar(c);
	    need_newline = false;
	    prev_alnum = false;
	    continue;
	}

	if (isspace(c)) {
	    if (prev_alnum)
		had_space = true;
	    prev_alnum = false;
	    continue;
	}

	if (isalnum(c) || c == '_') {
	    prev_alnum = true;
	    if (had_space)
		putchar(' ');
	    had_space = false;
	    do {
		putchar(c);
		c = safe_getchar();
	    } while (isalnum(c) || c == '_');
	    ungetc(c, stdin);
	    continue;
	}

	prev_alnum = false;
	had_space = false;
	if (c == '\\') {
	    c = safe_getchar();
	    if (c != '\n') {
		putchar('\\');
		putchar(c);
	    }
	}
	else if (c == '\'') {
	    putchar(c);
	    do {
		c = safe_getchar();
		putchar(c);
		if (c == '\\')
		    putchar(safe_getchar());
	    } while (c != '\'');
	}
	else if (c == '"') {
	    putchar(c);
	    do {
		c = safe_getchar();
		putchar(c);
		if (c == '\\')
		    putchar(safe_getchar());
	    } while (c != '"');
	}
	else if (c == '/') {
	    c = safe_getchar();
	    if (c == '/')
		while (safe_getchar() != '\n');
	    else if (c == '*')
		while (safe_getchar() != '*' || safe_getchar() != '/');
	    else
		ungetc(c, stdin);
	}
	else if (c == '#') {
	    need_newline = true;
	    putchar(c);
	}
	else {
	    putchar(c);
	}
    }
}
