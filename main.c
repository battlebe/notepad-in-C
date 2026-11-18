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
	char *file = NULL;
	size_t fileSize = 0;
	size_t relPosisionFromStart = 0;
	size_t lineCount = 0;

	while(1) {
		printf(">");
		//scanf("%9s", userInput);
		fgets(userInput,sizeof(userInput),stdin);
		enum Command command;

		//parser command
		if( strcmp(userInput, "append\n") == 0 ) {
			command = APPEND;
			printf(">");  //prompt

			//get line
			char inputLine[100];
			fgets(inputLine, sizeof(inputLine), stdin);

			// strlen统计 '\0' 之前的所有字符
			printf("[dbg] strlen of input is %zu \n", strlen(inputLine));    	// h e l l o   w o r l  d \n 's strlen = 12
																				// 1 2 3 4 5 6 7 8 9 10 11 12

			fileSize += strlen(inputLine) * sizeof(char);
			char *tmp = realloc(file, fileSize);
			if( tmp == NULL ) {
				// 分配失败
				free(file);
				file = NULL;
				return -1;
			} else {
				file = tmp;
				tmp = NULL; // tmp不再使用
				printf("[dbg] block file's size is %zu * sizeof(char) \n",fileSize );
			}

			char *currentCh = file + relPosisionFromStart;
			char *line = inputLine;
			while( *line != '\0' ) {
				*currentCh = *line;
				currentCh++;
				line++;
				relPosisionFromStart++;
			}
			printf("[dbg] appended a line, currentCh position = %zu \n",relPosisionFromStart);
			lineCount++;

			
			
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

		//print file
		char *tmp = file;
		int tmpLinecount = 1;
		for(int i = 0; i < lineCount; i++) {
			printf("l%d. ", tmpLinecount);
			while (*tmp != '\n')
			{
				printf("%c", *tmp);
				tmp++;
			}
			tmp++;
			tmpLinecount++;
			printf("\n");
		}

	}

	
}

