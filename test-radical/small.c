#define i if

// write
#define w p = putchar

// token
#define t(c) (isalnum(c) || c == '_')

// literal
#define l(x)					\
    else i (c == x) {				\
	w(c);					\
	do {					\
	    c = g();				\
	    w(c);				\
	    i (c == '\\')			\
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
    i (c == '\n' && n)
	w(c), n = 0;
    // fallthrough

    i (isspace(c)) {
	i t(p)
	    s = 1;
	goto b;
    }

    i t(c)
	i (s)
	    w(' '), s = 0;

    i (c == '\\') {
	c = g();
	i (c != '\n')
	    w('\\'), w(c);
	goto b;
    }

    s = 0;
    i (c == '#') {
	n = 1;
	i (p != '\n')
	    w('\n');
	w(c);
    }
    l('\'')
    l('"')
    else i (c == '/') {
	c = g();
	i (c == '/')
	    while (g() != '\n');
	else i (c == '*')
	    while (g() != '*' || g() != '/');
	else
	    goto a;
    }
    else
	w(c);
    goto b;
}
