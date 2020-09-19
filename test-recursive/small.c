#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int g() {
    int c = getchar();
    if (c < 0)
	exit(0);
    return c;
}

int prev_alnum, had_space, need_newline;

int main() {
    for (;;) {
	int c = g();

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
		c = g();
	    } while (isalnum(c) || c == '_');
	    ungetc(c, stdin);
	    continue;
	}

	prev_alnum = 0;
	had_space = 0;
	if (c == '\\') {
	    c = g();
	    if (c != '\n') {
		putchar('\\');
		putchar(c);
	    }
	}
	else if (c == '\'') {
	    putchar(c);
	    do {
		c = g();
		putchar(c);
		if (c == '\\')
		    putchar(g());
	    } while (c != '\'');
	}
	else if (c == '"') {
	    putchar(c);
	    do {
		c = g();
		putchar(c);
		if (c == '\\')
		    putchar(g());
	    } while (c != '"');
	}
	else if (c == '/') {
	    c = g();
	    if (c == '/')
		while (g() != '\n');
	    else if (c == '*')
		while (g() != '*' || g() != '/');
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
