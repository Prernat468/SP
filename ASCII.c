#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

typedef struct {
    char line[MAX_LINE_LENGTH];
} LineNode;

void printLastNLines(int n) {
    if (n <= 0) {
        fprintf(stderr, "Invalid value of n. It should be a positive integer.\n");
        return;
    }

    LineNode *buffer = (LineNode *)malloc(sizeof(LineNode) * n);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    int currentIndex = 0;
    int totalLines = 0;

    char currentLine[MAX_LINE_LENGTH];
    while (fgets(currentLine, MAX_LINE_LENGTH, stdin) != NULL) {
        strncpy(buffer[currentIndex].line, currentLine, MAX_LINE_LENGTH);
        currentIndex = (currentIndex + 1) % n;
        if (totalLines < n) {
            totalLines++;
        }
    }

    printf("\nLast %d lines of the input:\n", totalLines);
    for (int i = 0; i < totalLines; i++) {
        printf("%s", buffer[currentIndex].line);
        currentIndex = (currentIndex + 1) % n;
    }

    free(buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_lines>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    printLastNLines(n);

    return 0;
}
