#include <stdio.h>
/*
	first comment
*/
void	other()
{
	return ;
}
int	main()
{
	/*
		main comment
	*/
	char *a="#include <stdio.h>%c/*%c%cfirst comment%c*/%cvoid%cother()%c{%c%creturn ;%c}%cint%cmain()%c{%c%c/*%c%c%cmain comment%c%c*/%c%cchar%c*a=%c%s%c;%c%cother();%c%cprintf(a,10,10,9,10,10,9,10,10,9,10,10,9,10,10,9,10,9,9,10,9,10,9,32,34,a,34,10,9,10,9,10);%c}";
	other();
	printf(a,10,10,9,10,10,9,10,10,9,10,10,9,10,10,9,10,9,9,10,9,10,9,32,34,a,34,10,9,10,9,10);
}