#include <stdio.h>
#include <stdlib.h>
#define entier 7
int main()
{
	char *file;
	asprintf(&file, "Sully_%d.c", entier);
	FILE *f = NULL;
	f=fopen(file,"w");
	if(f != NULL)
	{
		char *a="#include <stdio.h>%c#include <stdlib.h>%c#define entier %d%cint main()%c{%cchar *file;%casprintf(&file, %cSully_%d.c%c);%cFILE *f = NULL;%cf=fopen(file,%cw%c);%cif(f != NULL)%c{%cchar *a=%c%s%c%c;fprintf(f,a,10,10,entier - 1,10,10,10,10, 34,entier - 1,34,10, 10, 34,34,10, 10,10, 34,a,34,10, 10,10,10,10,10,10, 34,entier - 1,34,10, 10,10);%cfclose(f);%c}%cif (entier > 1)%c{%cchar *make;%casprintf(&make, %cclang -Wall -Wextra -Werror Sully_%d.c -o Sully ; ./Sully%c);%csystem(make);%c}%c}";
		fprintf(f,a,10,10,entier - 1,10,10,10,10, 34,entier - 1,34,10, 10, 34,34,10, 10,10, 34,a,34,10, 10,10,10,10,10,10, 34,entier - 1,34,10, 10,10);
		fclose(f);
	}
	if (entier > 1)
	{
		char *make;
		asprintf(&make, "clang -Wall -Wextra -Werror %s -o Sully ; ./Sully", file);
		system(make);
	}
}