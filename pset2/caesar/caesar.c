#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

string plaintext;
int key;

int main(int argc, string argv[])
{
    //check if 2 arguments given
    if (argc == 2)
    {
        //check every character in key is a digit
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isdigit(argv[1][i]) != 0)
            {
                continue;
                return 0;
            }
            //return if digit not given
            else
            {
                printf("usage: ./caesar key\n");
                return 1;
            }
        }
        
    }
    //return if more than 2 arguments given
    else
    {
        printf("usage: ./caesar key\n");
        return 1;
    }
    
    //convert argument of key from string to integer
    key = atoi(argv[1]);
    //ask for plaintext if positive integer given
    if (key > 0)
    {
        plaintext = get_string("PLAINTEXT: ");
        printf("ciphertext: ");
    }
    else if (key == 0)
    {
        printf("usage: ./caesar key\n");
        return 1;
    }

    //ciphering text by key, going through character by charater
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if isalpha(plaintext[i])
        {
            //convert uppercase characters to uppercase cipher
            if isupper(plaintext[i])
            {
                printf("%c", (((plaintext[i] + key) - 65) % 26) + 65);    
            }
            //convert lowercase character to lowercase cipher
            if islower(plaintext[i])
            {
                printf("%c", (((plaintext[i] + key) - 97) % 26) + 97);
            }
        }
        //return anything that is not an alphabet
        else
        {
            printf("%c", plaintext[i]);
        }
        
    }
    printf("\n");
    
}