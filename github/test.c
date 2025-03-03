#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1000

char* cezar_cipher(char* text, int key)
{
    int length = strlen(text);
    char* cipher = (char*) malloc(sizeof(char) * (length + 1));
    if (!cipher) return NULL;
    
    for(int i = 0; i < length; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z') {
            cipher[i] = ((text[i] - 'a' + key) % 26 + 26) % 26 + 'a';
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            cipher[i] = ((text[i] - 'A' + key) % 26 + 26) % 26 + 'A';
        } else if (text[i] >= '0' && text[i] <= '9') {
            cipher[i] = ((text[i] - '0' + key) % 10 + 10) % 10 + '0';
        } else {
            cipher[i] = text[i]; // Оставяме другите символи непроменени
        }
    }
    cipher[length] = '\0';
    return cipher;
}

int main()
{
    char text[MAXN];
    int key;
    
    fgets(text, MAXN, stdin);
    text[strcspn(text, "\n")] = '\0'; // Премахва новия ред, ако има такъв
    
    scanf("%d", &key);
    getchar(); // Изчиства новия ред от буфера
    
    char* cipher = cezar_cipher(text, key);
    if (cipher) {
        printf("%s", cipher);
        free(cipher);
    }
    return EXIT_SUCCESS;
}
