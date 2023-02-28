#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

void generateWords(char *alphabet, int length, int remaining, int maxWords, char *prefix, int *wordCount) {
    if (*wordCount == maxWords) {
        return;
    }
    if (remaining == 0) {
        printf("%s\n", prefix);
        (*wordCount)++;
        return;
    }
    for (int i = 0; i < strlen(alphabet); i++) {
        char newPrefix[strlen(prefix) + 1];
        strcpy(newPrefix, prefix);
        newPrefix[strlen(prefix)] = alphabet[i];
        newPrefix[strlen(prefix) + 1] = '\0';
        generateWords(alphabet, length, remaining - 1, maxWords, newPrefix, wordCount);
    }
}

void possibleCombinations(char *alphabet, int maxWords) {
    int length = 1;
    int wordCount = 0;

    while (wordCount < maxWords) {
        generateWords(alphabet, length, length, maxWords, "", &wordCount);
        length++;
    }
}

int main(int argc, const char *argv[]) {
    int maxWords;
    char alphabet[MAX];

    if (argc <= 1) {
        fprintf(stderr, "Usage: ./generator alphabet [word count]");
        exit(1);
    }

    strcpy(alphabet, argv[1]);

    if (argc == 3) {
        maxWords = atoi(argv[2]);
    } else {
        maxWords = MAX;
    }

    possibleCombinations(alphabet, maxWords);

    puts("");
    return 0;
}