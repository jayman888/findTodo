#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFF 1024
#define MAX_FNAME 100

// PROTOTYPES
void printTodos(FILE *fp);

int main(int argc, char *argv[]) {

    /*
        Revision 1
            - Search through file give as command line arg
            - Find single lines with TODOs in them
            - print out on single lines, info
                line No. > TODO the rest of the line comment

        Ideas for future
            - Multi line TODOs
            - this file can be used to search through folders or projects
                    FILE.c
                1 > TODO fix this
                8 > TODO fix that
                9 > TODO etc
            - Possibly also get branch name?
    */

    char filename[MAX_FNAME];                               // FILENAME

    if (argc == 2) {
                strcpy(filename, argv[1]);
    } else {
        printf("ERROR: No file supplied\nUsage: %s <file>\n", argv[0]);
        return 1;                                           // EXIT FAIL
    }

    char const* const fileName = argv[1]; /* should check that argc > 1 */
    FILE* file = fopen(fileName, "r"); /* should check the result */
    printTodos(file);                                         // PRINT TODOs
    fclose(file);                                             // CLOSE FILE
    return 0;
}

void printTodos(FILE *fp) {

    char iter_buff[MAX_BUFF];                                   // Line buffer
    int  lineCount = 1;                                         // Line count
    char *ret;                                                  // Pointer to TODO in str

    while (fgets(iter_buff, sizeof(iter_buff), fp)) {
        if ( (ret = strstr(iter_buff, "TODO")) ) {
            printf("[%d] %s", lineCount, ret);
        }
        lineCount++;
    }
}
