#include "ansi_escapes.h"
#include "delay.h"
#include <string.h>

#define DELAY 30

void setupScreen()
{
    setupConsole();
    clearScreen();
    moveTo(1, 1);
}

void restoreScreen()
{
    restoreConsole();
}

void printWithDelay(char *string, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%c", string[i]);
        fflush(stdout);
        delay(DELAY);
    }
}

void printColorful(char *string, int length, char *color)
{
    Color newColor;
    if (strcasecmp(color, "red") == 0)
        newColor = RED_TXT;
    else if (strcasecmp(color, "blue") == 0)
        newColor = BLUE_TXT;
    else if (strcasecmp(color, "green") == 0)
        newColor = GREEN_TXT;
    else if (strcasecmp(color, "yellow") == 0)
        newColor = YELLOW_TXT;
    else if (strcasecmp(color, "cyan") == 0)
        newColor = CYAN_TXT;
    else if (strcasecmp(color, "white") == 0)
        newColor = WHITE_TXT;
    else if (strcasecmp(color, "magenta") == 0)
        newColor = MAGENTA_TXT;
    else if (strcasecmp(color, "black") == 0)
        newColor = BLACK_TXT;
    else
        newColor = RESET_COLOR;

    setTextColorBright(newColor);
    printWithDelay(string, length);
    setTextColorBright(RESET_COLOR);
    restoreConsole();
}

void f(char *s, int length)
{
    printf("---%*s%*s---\n",length + (int)strlen(s) / 2, s, length - (int)strlen(s) / 2, "");
}

void printLoading(int round)
{
    setupConsole();
    setTextColorBright(CYAN_TXT);
    
    f("Loading", 20);

    for (int i = 0; i < round; i++)
    {
        for (int j = 0; j < 46; j++)
        {
            printf("%c", 178);
            fflush(stdout);
            delay(20);
        }

        for (int j = 0; j < 46; j++)
        {
            moveLeft(1);
            clearLineToRight();
            fflush(stdout);
            delay(20);
        }
    }

    moveUp(1);
    clearScreenToBottom();
    f("Load completed!", 20);
    delay(1000);
    restoreConsole();
}
