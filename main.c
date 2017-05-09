#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void counthex(char* filename){
	FILE *f, *g;
	unsigned long counter[256];
	unsigned char *hex;
	unsigned int i;
	size_t s;

	for(i=0;i<=256;i++) counter[i]=0;

	f = fopen(filename,"rb");

	fseek(f,0,SEEK_END);

	s = ftell(f);

	rewind(f);

	hex = malloc(s);

	fread(hex,1,s,f);

	for(i=0;i<s;i++){
		counter[hex[i]]++;
	}

	g = fopen("result.txt","w");
	for(i=0;i<=256;i++)fprintf(g,"0x%.2x; %lu\n",i,counter[i]);

	free(hex);
	fclose(f);
	fclose(g);
}

int main(int argc, char* argv[]){

	if(argc != 2){
		printf("error! please state file!\n");
		printf("Usage: %s <file>\n", argv[0]);
		return -1;
	}
	counthex(argv[1]);

	return 0;
}