// Caesar Cipher by Christopher Burnette

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int cipher(char *s) {
	signed long long sp = 0;
	while(s[sp]){printf("%c",s[sp]+3); sp++;}
	return 0;
}

int decipher(char *s) {
	signed long long sp = 0;
	while(s[sp]){printf("%c",s[sp]-3); sp++;}
	return 0;
}

int main (int argc, char* args[]) {
	FILE *sf;
	if(argc!=3){printf("Usage: %s [-c/-d] file\n\t-c\tCipher the Data\n\t-d\tDecipher the Data\n",args[0]); return 1;}
	if ((strcmp(args[1],"-c")!=0)&&(strcmp(args[1],"-d")!=0)){printf("Error: Invalid parameter given!\n"); return 1;}
	if((sf=fopen(args[2],"rb"))==0){printf("Error: File not found or could not be accessed!\n"); return 1; }
	fseek(sf,0,SEEK_END);
	long fs=ftell(sf);
	rewind(sf);
	char *s=malloc(fs*(sizeof(char)));
	fread(s,sizeof(char),fs,sf);
	fclose(sf);
	if (strcmp(args[1],"-c")!=0){cipher(s);}
	else if (strcmp(args[1],"-d")!=0){decipher(s);}
	return 0;
}

