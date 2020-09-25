#define i if
#define w p=putchar
#define t(c)(isalnum(c)||c=='_')
#define l(x)else i(c==x){w(c);do{c=g();w(c);i(c=='\\')w(g());}while(c!=x);}
int g(){int c=getchar();return c<0?exit(0),c:c;}int c,s,n,p='\n';int main(){b:c=g();a:i(c=='\n'&&n)w(c),n=0;i(isspace(c)){i t(p)s=1;goto b;}i t(c)i(s)w(' '),s=0;i(c=='\\'){c=g();i(c!='\n')w('\\'),w(c);goto b;}s=0;i(c=='#'){n=1;i(p!='\n')w('\n');w(c);}l('\'')l('"')else w(c);goto b;}