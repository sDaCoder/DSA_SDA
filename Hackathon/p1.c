#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char** wordArr(char words[])
{
    char** wordArr;
    char* token = strtok(words, " ");
    for (int i = 0; token != NULL; i++)
    {
        strcpy(wordArr[i], token);
        // puts(token);
        token = strtok(NULL, " ");
    }
    return wordArr;
}

void main()
{
    char str[] = "Hi how are you";
    char** words = wordArr(str);
    

    for (int i = 0; i < 4; i++)
    {
        puts(words[i]);
    }
    
    
        
}