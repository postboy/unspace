#define w p = putchar

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

int g() {
    int c = getchar();
    return c < 0 ? exit(0), c: c;
}

int c, s, n, p = '\n';

int main() {
b:
    c = g();

    if (c == '\n' && n)
	w(c), n = 0;

    if (isspace(c)) {
	if (isalnum(p) || p == '_')
	    s = 1;
	goto b;
    }

    if ((isalnum(c) || c == '_') && s)
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
    else
	w(c);
    goto b;
}
