#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Nice code ^_^ */
//here Ahmed ^^
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

int main(){
	printf("Welcome to file system ^_^...\n");
	removechars();
	return 0;
}
