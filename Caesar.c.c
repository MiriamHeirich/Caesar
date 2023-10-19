#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
char Alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

char encrypt(char c, int key)
{
    if (isupper(c))
    {
        return Alphabet[(c - 'A' + key) % 26];
    }
    else if (islower(c))
    {
        return tolower(Alphabet[(toupper(c) - 'A' + key) % 26]);
    }
    else
    {
        return c;
    }
}

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string key = argv[1];

    for (int i = 0; key[i] != '\0'; i++)
    {
        if (!isdigit(key[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int lengthKey = atoi(key);

    string word = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0; word[i] != '\0'; i++)
    {
        char encryptedChar = encrypt(word[i], lengthKey);
        printf("%c", encryptedChar);
    }

    printf("\n");

    return 0;
}
