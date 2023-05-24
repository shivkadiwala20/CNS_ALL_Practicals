#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

int i;
char ctext[50];
char ch;
int key;
char ptext[50];

void encrypt()
{

	for (i = 0; i < strlen(ptext); i++)
	{
		ch = ptext[i];
		if (isalnum(ch))
		{
			if (islower(ch))
			{
				ch = (ch - 'a' + key) % 26 + 'a';
			}
			if (isupper(ch))
			{
				ch = (ch - 'A' + key) % 26 + 'A';
			}
		}
		ctext[i] = ch;
	}
	printf("\n Encrypted text:");
	puts(ctext);
}

void decrypt()
{
	for (i = 0; i < strlen(ctext); i++)
	{
		ch = ctext[i];
		if (isalnum(ch))
		{
			if (islower(ch))
			{
				ch = (ch - 'a' - key + 26) % 26 + 'a';
			}
			if (isupper(ch))
			{
				ch = (ch - 'A' - key + 26) % 26 + 'A';
			}
		}
		ptext[i] = ch;
	}
	printf("\n Decrypted text:");
	puts(ptext);
}

void main()
{
	clrscr();
	printf("Enter the text you want to encrypt:");
	gets(ptext);
	printf("\n Enter the key:");
	scanf("%d", &key);

	if (key >= 26)
	{
		key = key % 26;
	}

	printf("\n Your plaintext:");
	puts(ptext);
	encrypt();
	decrypt();

	getch();
}
