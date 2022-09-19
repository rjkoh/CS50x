#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    
    //calculate number of letters in text
    int letter_count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //count lowercase letters
        if ('a' <= text[i] && text[i] <= 'z')
        {
            letter_count++;
        }
        //count uppercase letters
        else if ('A' <= text[i] && text[i] <= 'Z')
        {
            letter_count++;
        }
    }

    //calculate number of words in text
    int word_count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //counting spaces
        if (text[i] == ' ')
        {
            word_count++;
        }
    }
    //counting number of words by adding 1 to number of spaces
    word_count++;
    
    //count nunber of sentences
    int sentence_count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //counting .?!
        if (text[i] == '.' || text [i] == '?' || text[i] == '!')
        {
            sentence_count++;
        }
    }

    //getting average number of letters per 100 words
    float L = ((float)letter_count / word_count * 100);
    
    //getting average number of sentences per 100 words
    float S = ((float)sentence_count / word_count * 100);
    
    int index = round((0.0588 * L) - (0.296 * S) - 15.8);
    
    //printing grade level
    //below grade 1
    if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    //grade 2-15
    if (index >= 2 && index <= 15)
    {
        printf("Grade %i\n", index);
    }
    //grade 16 and above
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    
}