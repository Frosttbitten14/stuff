#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1000

char* cezar_cipher(char* text, int key)
{
    int length = strlen(text);
    char* cipher = (char*) malloc(sizeof(char) * (length + 1));
    for(int i = 0; i < length; i++)
    {
        if(islower(text[i]))
        {
        cipher[i] = (text[i] - 'a' + key) % 26 + 'a';
        }
        else
        {
        cipher[i] = (text[i] - 'A' + key) % 26 + 'A';
        }
    }
    cipher[length] = '\0';
    return cipher;
}

void write_cipher(char* filename, char* cipher)
{
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "s", cipher);
    fclose(fp);
}

int main()
{
    char text[MAXN];
    fgets(text, MAXN, stdin);
    int key;
    scanf("%d", &key);
    char* cipher = cezar_cipher(text, key);
    printf("%s", cipher);
    free(cipher);
    return EXIT_SUCCESS;
}
