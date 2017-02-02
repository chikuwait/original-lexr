#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NMAX 100
char *token[NMAX];
int ix;

void
lexer(char *text)
{
    ix = 0;
    while(*text != '\0')
    {
        if(*text <= ' ')
        {
            text++;
            continue;
        }
        char *pBgn = text;

        if(isdigit(*text))
        {
            while(isdigit(*text) || *text == '.') text++;
        }
        else if(isalpha(*text))
        {
            while(isalnum(*text)) text++;
        }
        else
        {
            text++;
        }
        token[ix]=malloc((int)(text-pBgn)+1);
        strncpy(token[ix],pBgn,(int)(text-pBgn));
        token[ix][text-pBgn]= '\0';
        ix++;
    }
}
int
main(void)
{
    char buf[1024];

    fgets(buf,100,stdin);
    lexer(buf);
    for(int n = 0 ; n < ix ; n++)
    {
        printf("%s%s", token[n], (n<ix-1 ? " " : "\n"));
        free(token[n]);
    }
}

