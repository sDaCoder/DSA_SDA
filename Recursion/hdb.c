#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void cols(int c)
{
    if (c==1)
    {
        printf("*\n");
        return;
    }
    else
    {
        printf("* ");
        cols(c-1);
    }
}

void pattern(int r, int c)
{
    if (r == 1)
    {
        cols(c);
        return;
    }
    else
    {
        cols(c);
        pattern(r-1, c);
    }
    
}

void main(){
    system("cls");
    // printf("Hello world\n");
    int rows, cols;
    printf("Enter rows: ");
    scanf("%d", &rows);
    printf("\nEnter columns: ");
    scanf("%d", &cols);
    pattern(rows, cols);

}