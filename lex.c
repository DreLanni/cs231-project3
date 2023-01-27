//
// Created by drela on 1/25/2023.
//
//Coded by: Andreas Lanni
//Palindrone
#include <stdio.h>
#define MAX_LINES 100
#define MAX_LINE_LENGTH 100

//Checks if the input parameter is a alphabetical letter
int isLetter(char letter)
{
    if ((letter >= 65 && letter <= 90) || (letter >= 95 && letter <= 123))
    {
        return 1;
    }
    return 0;
}


int main(int argc, char *argv[])
{

    FILE *input;
    FILE *output;

    //Opens the input file specified when running code
    input = fopen("C:\\Users\\drela\\Downloads\\test.txt", "r");

    //Specifies the output file to write new text to.
    output = fopen("C:\\Users\\drela\\Downloads\\output.txt", "w");

    //2d array to store charters
    //First dimension: Column

    //Second dimension: Line
    char data[MAX_LINES][MAX_LINE_LENGTH];
    int line = 0;

    //Pulls data from input file and inputs it into the data array
    while (!feof(input))
    {
        if (fgets(data[line], MAX_LINE_LENGTH, input) != NULL)
            line++;
    }
    //Nested for loop to check every character of data array
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < MAX_LINE_LENGTH; j++)
        {
            //Checks if reached end of a line
            if (data[i][j] == 0)
            {
                j=MAX_LINE_LENGTH;
            }
            else if(data[i][j] == 32 || data[i][j] == 10)
            {
                putchar(10);
            }
                //If it hasn't reached end of line checks character for upper or lower case
            else
            {
                if (isLetter(data[i][j]) == 1)
                {
                    int letter = data[i][j];
                    putchar(letter);
                }
            }
        }

    }

    if (output == NULL)
    {
        fclose(input);
        return 0;
    }


    printf("\nFile copied successfully.\n");

    fclose(input);
    fclose(output);

    return 0;
}


