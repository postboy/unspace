#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// print
#define p(c) last_printed = putchar(c)

// token
#define t(c) (isalnum(c) || c == '_')

// literal
#define l(x) \
	else if (c == x) { \
	    p(c); \
	    do { \
		c = g(); \
		p(c); \
		if (c == '\\') \
		    p(g()); \
	    } while (c != x); \
	}

// get
int g() {
    int c = getchar();
    if (c < 0)
	exit(0);
    return c;
}

// character
int c, had_space, need_newline, last_printed = '\n';

int main() {
b: // begin
	c = g();

a: // analysis
        if (c == '\n' && need_newline)
	    p(c), need_newline = 0;
	    // fallthrough

	if (isspace(c)) {
	    if t(last_printed)
		had_space = 1;
	    goto b;
	}

	if t(c)
	     if (had_space)
		 p(' '), had_space = 0;

	if (c == '\\') {
	    c = g();
	    if (c != '\n')
		p('\\'), p(c);
	    goto b;
	}

	had_space = 0;
	if (c == '#') {
	    need_newline = 1;
	    if (last_printed != '\n')
		p('\n');
	    p(c);
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
	    p(c);
	goto b;
}
