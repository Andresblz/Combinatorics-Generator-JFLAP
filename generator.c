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
        char new_prefix[strlen(prefix) + 1];
        strcpy(new_prefix, prefix);
        new_prefix[strlen(prefix)] = alphabet[i];
        new_prefix[strlen(prefix) + 1] = '\0';
        generateWords(alphabet, length, remaining - 1, maxWords, new_prefix, wordCount);
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
        fprintf(stderr, "Use: generator (alphabet) [word count]");
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
