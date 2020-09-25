#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// write
#define w p = putchar

// token
#define t(c) (isalnum(c) || c == '_')

// literal
#define l(x)					\
    else if (c == x) {				\
	w(c);					\
	do {					\
	    c = g();				\
	    w(c);				\
	    if (c == '\\')			\
		w(g());				\
	} while (c != x);			\
    }

// get
int g() {
    int c = getchar();
    return c < 0 ? exit(0), c: c;
}

// character, had_space, need_newline, last_printed
int c, s, n, p = '\n';

int main() {
b: // begin
    c = g();

a: // analysis
    if (c == '\n' && n)
	w(c), n = 0;
    // fallthrough

    if (isspace(c)) {
	if t(p)
	    s = 1;
	goto b;
    }

    if t(c)
	if (s)
	    w(' '), s = 0;

    if (c == '\\') {
	c = g();
	if (c != '\n')
	    w('\\'), w(c);
	goto b;
    }

    s = 0;
    if (c == '#') {
	n = 1;
	if (p != '\n')
	    w('\n');
	w(c);
    }
    l('\'')
    l('"')
    else if (c == '/') {
	c = g();
	if (c == '/')
	    while (g() != '\n');
	else if (c == '*')
	    while (g() != '*' || g() != '/');
	else
	    goto a;
    }
    else
	w(c);
    goto b;
}
