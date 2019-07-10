#include <stdio.h>
#define file "Grace_kid.c"
#define login "cjulliar"
#define macro() int main(){FILE *f = NULL;f=fopen(file,"w");if(f!= NULL){char *a="#include <stdio.h>%c#define file %cGrace_kid.c%c%c#define login %ccjulliar%c%c#define macro() int main(){FILE *f = NULL;f=fopen(file,%cw%c);if(f!= NULL){char *a=%c%s%c;fprintf(f,a,10,34,34,10,34,34,10,34,34,34,a,34,34,34,34,34,10,10,9,10,10);fclose(f);if(login == %ccjulliar%c)printf(%cpouet%c);}}%c/*%c%ccomment%c*/%cmacro();";fprintf(f,a,10,34,34,10,34,34,10,34,34,34,a,34,34,34,34,34,10,10,9,10,10);fclose(f);if(login == "cjulliar")printf("pouet");}}
/*
	comment
*/
macro();