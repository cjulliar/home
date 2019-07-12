#include <stdio.h>
#include <stdlib.h>

int main()
{
	int entier = 5;
	if(entier < 0)
		return (0);
	char*name="Sully_%d.c";
	char *exec="clang -Wall -Wextra -Werror %s -o Sully_%d ; ./Sully_%d";
	char *file;
	asprintf(&file, name, entier);
	FILE *f = NULL;
	f=fopen(file,"w");
	if(f != NULL)
	{
		char *a="#include <stdio.h>%1$c#include <stdlib.h>%1$c%1$cint main()%1$c{%1$c%7$cint entier = %2$d;%1$c%7$cif(entier < 0)%1$c%7$c%7$creturn (0);%1$c%7$cchar*name=%6$c%3$s%6$c;%1$c%7$cchar *exec=%6$c%4$s%6$c;%1$c%7$cchar *file;%1$c%7$casprintf(&file, name, entier);%1$c%7$cFILE *f = NULL;%1$c%7$cf=fopen(file,%6$cw%6$c);%1$c%7$cif(f != NULL)%1$c%7$c{%1$c%7$c%7$cchar *a=%6$c%5$s%6$c;%1$c%7$c%7$cfprintf(f,a,10, entier-1, name, exec, a, 34, 9);%1$c%7$c%7$cfclose(f);%1$c%7$c}%1$c%7$cchar *make;%1$c%7$casprintf(&make, exec, file, entier, entier);%1$c%7$csystem(make);%1$c%7$c}%1$c";
		fprintf(f,a,10, entier-1, name, exec, a, 34, 9);
		fclose(f);
	}
	char *make;
	asprintf(&make, exec, file, entier, entier);
	system(make);
}
