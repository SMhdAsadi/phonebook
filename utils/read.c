#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "delay.h"
#include "print.h"

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