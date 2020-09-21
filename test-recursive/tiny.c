#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define p(c)last_printed=putchar(c)
#define t(c)(isalnum(c)||c=='_')
#define l(x)else if(c==x){p(c);do{c=g();p(c);if(c=='\\')p(g());}while(c!=x);}
int g(){int c=getchar();if(c<0)exit(0);return c;}int had_space,need_newline,last_printed='\n';int main(){for(;;){int c=g();a:if(c=='\n'&&need_newline)p(c),need_newline=0;if(isspace(c)){if t(last_printed)had_space=1;continue;}if t(c)if(had_space)p(' '),had_space=0;if(c=='\\'){c=g();if(c!='\n')p('\\'),p(c);continue;}had_space=0;if(c=='#'){need_newline=1;if(last_printed!='\n')p('\n');p(c);}l('\'')l('"')else if(c=='/'){c=g();if(c=='/')while(g()!='\n');else if(c=='*')while(g()!='*'||g()!='/');else goto a;}else p(c);}}