#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count(string word1);
int main(void)
{
    //Get the text
    string word1 = get_string("Text: ");

    //Conditions in the text
    int nl = 0;
    int np = 1;
    int ns = 0;
    for (int l = 0; l < strlen(word1); l++)
    {
        if ((word1[l] >= 'a' && word1[l] <= 'z') || (word1[l] >= 'A' && word1[l] <= 'Z'))
        {
            nl++;
        }
        if (word1[l] == ' ')
        {
            np++;
        }
        if (word1[l] == '.' || word1[l] == '!' || word1[l] == '?')
        {
            ns++;
        }
    }
    //Recall that the Coleman-Liau
    float res = 0.0588 * (100 * ((float)nl / (float)np)) - 0.296 * (100 * ((float)ns / (float)np)) - 15.8;

    //Print the grades
    if (res < 1)
    {
        string grade = "1";
        printf("%s\n", grade);
    }
    else if (res >= 10)
    {
        string grade = "Congratulations, 10!";
        printf("%s\n", grade);
    }
    else
    {
        string grade = "Score: ";
        printf("%s%.f\n", grade, res);
    }

}
