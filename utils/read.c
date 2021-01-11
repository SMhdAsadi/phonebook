#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "delay.h"
#include "print.h"

int isWhiteSpace(char *string)
{
    int allAreWhiteSpace = 1, isLetterWhiteSpace;
    char whiteSpaces[] = {' ', '\n', '\t', '\r'};
    
    for (int i = 0; i < strlen(string); i++)
    {
        isLetterWhiteSpace = 0;
        for (int j = 0; j < sizeof(whiteSpaces); j++)
        {
            if (string[i] == whiteSpaces[j])
            {
                isLetterWhiteSpace = 1;
                break;
            }
        }
        if (!isLetterWhiteSpace)
        {
            return 0;
        }
    }
    return 1;
}

int readInt()
{
    printPrompt();

    char input[20];
    fgets(input, 20, stdin);

    char *giberish;
    long inputNumber = strtol(input, &giberish, 10);
    if (inputNumber == 0)
    {
        printf("Didn't catch that!\n");
        delayOneSecond();
        printf("Please try again...\n");
        delayOneSecond();
        return readInt();
    }
    
    return inputNumber;
}

int readIntInRange(int from, int to)
{
    int input = readInt();
    while (input < from || input > to)
    {
        printf("Please enter valid number.\n");
        delayOneSecond();
        return readIntInRange(from, to);
    }

    return input;
}

char *readString(int size, int havePrompt, int isRequired)
{
    if (havePrompt)
    {
        printPrompt();
    }
    char *input = malloc(size + 1);

    fgets(input, size + 1, stdin);
    if (isRequired && isWhiteSpace(input))
    {
        return NULL;
    }
    
    // to ignore newline at the end
    input[strlen(input) - 1] = '\0';
    return input;
}