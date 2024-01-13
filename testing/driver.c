#include <stdio.h>
#include <stdlib.h>

extern int yyparse();
extern FILE* yyin;

int main(int argc, char *argv[]){
    if (argc == 1)return -1;
    FILE* fp = fopen(argv[1], "r");
    yyin = fp;
    yyparse();
    fclose(fp);
}