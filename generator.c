#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

void generateWords(char *alphabet, int length, int remaining, int maxWords, char *prefix, int *wordCount, FILE *fp) {
    if (*wordCount == maxWords) {
        return;
    }
    if (remaining == 0) {
        fprintf(fp, " %s", prefix);
        (*wordCount)++;
        return;
    }
    for (int i = 0; i < strlen(alphabet); i++) {
        char newPrefix[strlen(prefix) + 1];
        strcpy(newPrefix, prefix);
        newPrefix[strlen(prefix)] = alphabet[i];
        newPrefix[strlen(prefix) + 1] = '\0';
        generateWords(alphabet, length, remaining - 1, maxWords, newPrefix, wordCount, fp);
    }
}

void possibleCombinations(char *alphabet, int maxWords, FILE *fp) {
    int length = 1;
    int wordCount = 0;

    while (wordCount < maxWords) {
        generateWords(alphabet, length, length, maxWords, "", &wordCount, fp);
        length++;
    }
}

int main(int argc, const char *argv[]) {
    int maxWords;
    char alphabet[MAX];
    char filename[100];
    FILE *fp;

    if (argc <= 1) {
        fprintf(stderr, "Usage: ./generator alphabet [word count]");
        exit(1);
    }

    strcpy(alphabet, argv[1]);
    strcat(filename, alphabet);
    strcat(filename, ".txt");

    if (argc == 3) {
        maxWords = atoi(argv[2]);

        if (maxWords > MAX) {
            fprintf(stderr, "Info: word count could not be higher than %d", MAX);
            maxWords = MAX;
        }
    } else {
        maxWords = MAX;
    }

    fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file");
        exit(1);
    }

    possibleCombinations(alphabet, maxWords, fp);

    fclose(fp);
    printf("Output written to output.txt\n");
    return 0;
}
