#include <stdio.h>

int main(){
	char filenamein[] = "lab1.txt" ;
	char filenameout[] = "lab1w.txt" ;
	FILE *input, *output;
	char s[100];
	if ((input = fopen(filenamein,"r")) == NULL) {
		printf("Cannot open file");
		return 0;
	}
	else {
		input = fopen(filenamein, "r");
		output = fopen(filenameout, "w");
		
		while (fgets( s, 100, input)!= NULL)
		{
	    	fputs( s, output);		
		}
		
		fclose(output);
	    fclose(input);
	}
	return 0;
}
