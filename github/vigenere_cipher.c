#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXN 1024

char* vigenere_encrypt(char* plaintext, char* key)
{
    int text_length = strlen(plaintext);
    int key_length = strlen(key);
    char* cipher = (char*) malloc(sizeof(char) * (text_length + 1));
    memset(cipher, '\0', sizeof(char) * (text_length + 1));


    for(int i = 0; i < text_length; i++)
    {
        if(isalpha(plaintext[i]))
        {
            int shift = tolower(key[i % key_length]) - 'a';
        if(islower(plaintext[i]))
        {
            cipher[i] = (plaintext[i] + shift - 'a') % 26 + 'a';
        }
        else
        {
            cipher[i] = (plaintext[i] + shift - 'A') % 26 + 'A';
        }
    }
    else
    {
        cipher[i] = plaintext[i];
    }


    cipher[text_length] = '\0';
    return cipher;
}}

int read_file(char* filename, char* plaintext)
{
    FILE *fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Error opening file.");
        return EXIT_FAILURE;
    }

    if(fgets(plaintext, MAXN, fp) == NULL)
    {
        printf("Error reading from file.");
        return EXIT_SUCCESS;
    }
    fclose(fp);
    return EXIT_SUCCESS;
}

void write_cipher(char* filename, char* cipher)
{
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "s", cipher);
    fclose(fp);
}

int main()
{
    char plaintext[MAXN];
    read_file("plaintext.txt", plaintext);
    printf("%s\n", plaintext);
    char key[MAXN];
    read_file("vigenereKey.txt", key);
    printf("The key is: %s\n", key);
    char* cipher = vigenere_encrypt(plaintext, key);
    printf("%s", cipher);
    write_cipher("vigenereCipher.txt", cipher);
    free(cipher);
    return EXIT_SUCCESS;
}