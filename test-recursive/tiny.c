#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define p putchar
#define l(x)else if(c==x){p(c);do{c=g();p(c);if(c=='\\')p(g());}while(c!=x);}
int g(){int c=getchar();if(c<0)exit(0);return c;}int prev_alnum,had_space,need_newline;int main(){for(;;){int c=g();if(c=='\n'&&need_newline){p(c);need_newline=0;}if(isspace(c)){if(prev_alnum)had_space=1;prev_alnum=0;continue;}if(isalnum(c)||c=='_'){prev_alnum=1;if(had_space)p(' ');had_space=0;do{p(c);c=g();}while(isalnum(c)||c=='_');ungetc(c,stdin);continue;}if(c=='\\'){c=g();if(c!='\n'){p('\\');p(c);}continue;}prev_alnum=0;had_space=0;if(c=='#'){need_newline=1;p(c);}l('\'')l('"')else if(c=='/'){c=g();if(c=='/')while(g()!='\n');else if(c=='*')while(g()!='*'||g()!='/');else ungetc(c,stdin);}else{p(c);}}}