#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char* argv[]) {
	FILE *f , *final ;
	f = fopen(argv[1], "r+");
	if(f == NULL) {
		printf("File doesn't exit");
		exit(1);
	}
	final = fopen(argv[2],"w");
	
    char c[300];

	while (feof(f) == 0) {
		fread(c,1, 300, f);
		printf("%s", c);
		fwrite(c,1, strlen(c), final);
		}
		
	fclose(f);
	fclose(final);
	return 0;
	
}
