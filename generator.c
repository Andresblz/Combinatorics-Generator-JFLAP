#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int main(int argc, const char *argv[]) {
    int wordCount;
    char alphabet[MAX];

    if (argc <= 1) {
        fprintf(stderr, "Use: generator (alphabet) [word count]");
        exit(1);
    }

    strcpy(alphabet, argv[1]);

    if (argc == 3) {
        wordCount = atoi(argv[2]);
    }

    puts("");
    return 0;
}
