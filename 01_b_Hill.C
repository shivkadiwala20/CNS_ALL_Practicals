#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>



void encrypt(char *plaintext, int key[][100], int size);
void decrypt(char *ciphertext, int key[][100], int size);

int main() {
    char input[100];
    int size,i,j;
int key[100][100];
clrscr();
    printf("Enter a string to encrypt: ");
    fgets(input, 100, stdin);
    printf("Enter the size of the key matrix: ");
    scanf("%d", &size);

    printf("Enter the key matrix:\n");
    for ( i = 0; i < size; i++) {
	for ( j = 0; j < size; j++) {
	    scanf("%d", &key[i][j]);
	}
    }
    encrypt(input, key, size);
    printf("Encrypted string: %s\n", input);
    decrypt(input, key, size);
    printf("Decrypted string: %s\n", input);
getch();
    return 0;
}

void encrypt(char *plaintext, int key[][100], int size) {
    int i,j,k,len = strlen(plaintext);
    char ciphertext[100];
    int padding = size - (len % size);
    for ( i = 0; i < padding; i++) {
	plaintext[len+i] = ' ';
    }
    plaintext[len+padding] = '\0';
    for ( i = 0; i < len+padding; i += size) {
	for ( j = 0; j < size; j++) {
	    int sum = 0;
	    for ( k = 0; k < size; k++) {
		sum += key[j][k] * (plaintext[i+k] - 'A');
	    }
	    ciphertext[i+j] = (sum % 26) + 'A';
	}
    }
    strcpy(plaintext, ciphertext);
}

void decrypt(char *ciphertext, int key[][100], int size) {
    int len = strlen(ciphertext),i,j,k,sum=0,padding=0;
    char plaintext[100];
    for (i = 0; i < len; i += size) {
	for ( j = 0; j < size; j++) {
	     sum = 0;
	    for ( k = 0; k < size; k++) {
		sum += key[k][j] * (ciphertext[i+k] - 'A');
	    }
	    plaintext[i+j] = (sum % 26) + 'A';
	}
    }

    for ( i = len-1; i >= 0; i--) {
	if (plaintext[i] == ' ') {
	    padding++;
	} else {
	    break;
	}
    }
    plaintext[len-padding] = '\0';
    strcpy(ciphertext, plaintext);
}
