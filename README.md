# Combinatorics Generator

This is a command-line tool that generates all possible combinations of characters from a given alphabet.

## Usage

Compile the program by running:

```
gcc generator.c -o generator
```

Then, run the executable with the following arguments:

```
./generator alphabet [word count]
```

The `alphabet` argument is a string of characters that represent the alphabet to be used for the combinations. The `word count` argument is an optional integer that specifies the maximum number of words to generate. If the `word count` argument is not provided, the tool will generate all possible combinations.

## Example

```
./generator abc 5

Output:
a
b
c
aa
ab
```

## Implementation

The tool is implemented in C and uses a recursive algorithm to generate all possible combinations. The algorithm generates all combinations of a given length, and then generates all combinations of the next length until the maximum number of words is reached. The tool uses a stack to keep track of the generated words and to print them in the correct order.

The code is divided into two main functions:

* `generateWords`: generates all possible combinations of a given length and prints them to the console.
* `possibleCombinations`: generates all possible combinations up to a given length and prints them to the console.

The tool also includes error handling for invalid input arguments and a maximum limit of 1000 words to prevent the tool from generating an excessive amount of output.