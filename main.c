#include <stdio.h>
#include <string.h>
#include <stdlib.h>


enum Command {
	APPEND,
	LIST,
	DELETE,
	SAVE,
	UNKNOWN,
	EXIT,
};


int main() {
	
	// cmd: append, list, delet
	char userInput[10];
	while(1) {
		printf(">");
		//scanf("%9s", userInput);
		fgets(userInput,sizeof(userInput),stdin);
		enum Command command;
		size_t sizeOfContent = 100;
		char *file = malloc(sizeof(char) * 100);

		//parser command
		if( strcmp(userInput, "append\n") == 0 ) {
			char line[100];
			command = APPEND;
			printf(">");
			//scanf("%99s",line);
			fgets(line, sizeof(line), stdin);
			printf("[dbg] input a line\n");
			printf("[dbg] the lengh of inputline: %zu \n", sizeof(line));
			printf("[dbg] the char count of inputline: %zu \n", strlen(line));
			printf("[dbg] str: %s \n", line);

			
		}
		else if( strcmp(userInput, "exit\n") == 0 ) {
			command = EXIT;
			puts("command: EXIT");
			break;
		}
		else if( strcmp(userInput, "list\n") == 0 ) {
			command = LIST;
			puts("command:LIST");
		}
		else if( strcmp(userInput, "\n") == 0 ) {
			puts(">");
		}
		else {
			command = UNKNOWN;
			puts("unknown command");
		}
	}

	
}

