#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

char safe_getchar(void) {
    int c = getchar();
    if (c == EOF)
	exit(0);
    return c;
}

#define smart_putchar(c) last_printed = putchar(c)

int main(void) {
    bool prev_alnum = false;
    bool had_space = false;
    bool need_newline = false;
    int last_printed = '\n';

    for (;;) {
	char c = safe_getchar();

        if (c == '\n' && need_newline) {
	    smart_putchar(c);
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
		smart_putchar(' ');
	    had_space = false;
	    do {
		smart_putchar(c);
		c = safe_getchar();
	    } while (isalnum(c) || c == '_');
	    ungetc(c, stdin);
	    continue;
	}

	if (c == '\\') {
	    c = safe_getchar();
	    if (c != '\n') {
		smart_putchar('\\');
		smart_putchar(c);
	    }
	    continue;
	}

	prev_alnum = false;
	had_space = false;
	if (c == '#') {
	    need_newline = true;
	    if (last_printed != '\n')
		smart_putchar('\n');
	    smart_putchar(c);
	}
	else if (c == '\'') {
	    smart_putchar(c);
	    do {
		c = safe_getchar();
		smart_putchar(c);
		if (c == '\\')
		    smart_putchar(safe_getchar());
	    } while (c != '\'');
	}
	else if (c == '"') {
	    smart_putchar(c);
	    do {
		c = safe_getchar();
		smart_putchar(c);
		if (c == '\\')
		    smart_putchar(safe_getchar());
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
	else {
	    smart_putchar(c);
	}
    }
}
