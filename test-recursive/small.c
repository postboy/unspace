#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int safe_getchar() {
    int c = getchar();
    if (c == EOF)
	exit(0);
    return c;
}

int main() {
    int prev_alnum = 0;
    int had_space = 0;
    int need_newline = 0;

    for (;;) {
	int c = safe_getchar();

        if (c == '\n' && need_newline) {
	    putchar(c);
	    need_newline = 0;
	    prev_alnum = 0;
	    continue;
	}

	if (isspace(c)) {
	    if (prev_alnum)
		had_space = 1;
	    prev_alnum = 0;
	    continue;
	}

	if (isalnum(c) || c == '_') {
	    prev_alnum = 1;
	    if (had_space)
		putchar(' ');
	    had_space = 0;
	    do {
		putchar(c);
		c = safe_getchar();
	    } while (isalnum(c) || c == '_');
	    ungetc(c, stdin);
	    continue;
	}

	prev_alnum = 0;
	had_space = 0;
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
	    need_newline = 1;
	    putchar(c);
	}
	else {
	    putchar(c);
	}
    }
}
