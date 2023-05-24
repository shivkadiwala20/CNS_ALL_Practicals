
#include <stdio.h>
#include <conio.h>
#include <string.h>

void decryption(char a[], char key[])
{
	char b[50];
	int i;
	for (i = 0; i < strlen(a); i++)
	{
		b[i] = (a[i] - key[i] + 26) % 26;
		b[i] += 65;
	}
	b[i] = NULL;
	printf("\n Plaintext \n");
	printf(b);
}

void encryption(char a[], char key[])
{
	char decrypt[20];
	int i;
	for (i = 0; i < strlen(a); i++)
	{
		decrypt[i] = (a[i] + key[i]) % 26 + 65;
	}
	decrypt[i] = NULL;

	printf(" Encrypted Text \n");
	printf(decrypt);
	decryption(decrypt, key);
}

void main()
{
	char a[20];
	char key[20];
	clrscr();
	printf(" Enter the String : ");
	gets(a);
	printf(" Enter the Key : ");
	gets(key);
	strupr(a);
	strupr(key);
	if (strlen(a) > strlen(key))
	{
		int j = 0, i;
		for (i = strlen(key); i < strlen(a); i++)
		{
			key[i] = key[j];
			j++;
		}
		key[i] = NULL;
	}
	printf(" Modified Key \n");
	printf(key);
	printf("\n");
	encryption(a, key);

	getch();
}