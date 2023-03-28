#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int z_char_situation();

int main(int argc, string argv[])
{
    int password, ascii;
    const int ascii_Z = 90;
    const int ascii_z = 122;

    if(argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    password = atoi(argv[1]);
    printf("%i\n", password);
    string plaintext = get_string("Plaintext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        ascii = (int) plaintext[i];
        if(ascii >= 65 && ascii <= 90)
        {
            for(int k = 0; k < password; k++)
            {
                ascii += 1;
                ascii = z_char_situation(ascii, ascii_Z);
            }
        }
        else if(ascii >= 97 && ascii <= 122)
        {
            for(int k = 0; k < password; k++)
            {
                ascii += 1;
                ascii = z_char_situation(ascii, ascii_z);
            }
        }
        plaintext[i] = (char) ascii; 
    }
    printf("ciphertext: %s\n", plaintext);
    return 0;
}

int z_char_situation(int x, int y)
{
    if(x >= y)
    {
        x = x - 26;
        return x;
    }
    else
    {
        return x;
    }
}