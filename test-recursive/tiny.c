#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define p(c)last_printed=putchar(c)
#define t(c)(isalnum(c)||c=='_')
#define l(x)else if(c==x){p(c);do{c=g();p(c);if(c=='\\')p(g());}while(c!=x);}
int g(){int c=getchar();if(c<0)exit(0);return c;}int c,s,n,last_printed='\n';int main(){b:c=g();a:if(c=='\n'&&n)p(c),n=0;if(isspace(c)){if t(last_printed)s=1;goto b;}if t(c)if(s)p(' '),s=0;if(c=='\\'){c=g();if(c!='\n')p('\\'),p(c);goto b;}s=0;if(c=='#'){n=1;if(last_printed!='\n')p('\n');p(c);}l('\'')l('"')else if(c=='/'){c=g();if(c=='/')while(g()!='\n');else if(c=='*')while(g()!='*'||g()!='/');else goto a;}else p(c);goto b;}