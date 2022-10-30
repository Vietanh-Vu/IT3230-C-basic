#include <stdio.h>

int main(){
	char filenamein[] = "lab1.txt" ;
	char filenameout[] = "lab1w.txt" ;
	FILE *input, *output;
	char c;
	if ((input = fopen(filenamein,"r")) == NULL) {
		printf("Cannot open file");
		return 0;
	}
	else {
		input = fopen(filenamein, "r");
		output = fopen(filenameout, "w");
		
		c = fgetc(input);
		
		while (c !=EOF) {
			if( 65 <= c && 90 >= c ) {
				fputc(c + 32, output);
				c = fgetc(input);
			}
			else if( 97 <= c && 122 >= c ) {
				fputc(c - 32, output);
				c = fgetc(input);
			}
			else{
				fputc(c, output);
				c = fgetc(input);
			}
		}
		fclose(output);
	    fclose(input);
	}
	return 0;
}
