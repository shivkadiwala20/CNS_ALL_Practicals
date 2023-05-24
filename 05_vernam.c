#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

void vernamEncrypt(char *plaintext, char *key, char *ciphertext)
{
    int i;
    int len = strlen(plaintext);

    for (i = 0; i < len; i++)
    {
        ciphertext[i] = plaintext[i] ^ key[i];
    }
    ciphertext[i] = '\0';
}

void vernamDecrypt(char *ciphertext, char *key, char *decrypted)
{
    int i;
    int len = strlen(ciphertext);

    for (i = 0; i < len; i++)
    {
        decrypted[i] = ciphertext[i] ^ key[i];
    }
    decrypted[i] = '\0';
}

int main()
{
    char plaintext[100];
    char key[100];
    char ciphertext[100];
    char decrypted[100];

    clrscr();

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove trailing newline

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; // Remove trailing newline

    vernamEncrypt(plaintext, key, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    vernamDecrypt(ciphertext, key, decrypted);
    printf("Decrypted Text: %s\n", decrypted);

    getch();
    return 0;
}
