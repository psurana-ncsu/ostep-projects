#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	FILE *fd;
	int noFiles=argc-1;
	for(int i=0;i<noFiles;i++){
	char *filename= argv[i+1];
	fd = fopen(filename,"r");
	//printf("%s\n", argv[1]);
	if (fd==NULL){
		printf("wcat: cannot open file\n");
		return 1;
	}
	char *line=NULL;
	size_t bufsize=0;

	size_t chars_read;
	while((chars_read = getline(&line, &bufsize, fd)) != -1){
		printf("%s", line);
	}
	free(line);

	fclose(fd);
}
	return 0;
}

