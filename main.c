#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removechars(){
	FILE *f, *g;
	char c;

	f = fopen("newcap.txt","r");
	g = fopen("newcapout.txt","w");

	while ((c = fgetc(f)) != EOF)
    {
    	if(c != 0x7c)
        fputc(c,g);
    }

    printf("-----%ld\n",ftell(f));
    //fputc("\0",g);
	fclose(f);
	fclose(g);	
}