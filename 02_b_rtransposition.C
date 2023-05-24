#include <stdio.h>
#include <string.h>
#include <math.h>

char ptext[50], encrypt[80], decrypt[80];
char data[20][20];
char a = 'a', A = 'A', ch;
int key[50];
int plength, keylen;
int i, j, k, z, count = 0;
int row, len, len1, el;

void main()
{
	clrscr();

	printf("Enter the plain text: ");
	scanf("%s", ptext);
	plength = strlen(ptext);

	printf("\nEnter the length of key: ");
	scanf("%d", &keylen);
	printf("\nEnter your key(Enter space): ");
	for (i = 0; i < keylen; i++)
	{
		scanf("%d", &key[i]);
	}

	row = ceil((plength / (float)keylen) + 1);
	el = row * keylen;

	for (i = 0, k = 0; i < 1; i++)
	{
		for (j = 0; j < keylen; j++)
		{
			data[i][j] = key[k] + 65;
			if (k < keylen)
			{
				k++;
			}
			if (k >= keylen)
			{
				break;
			}
		}
	}

	k = 0;

	for (i = 1; i < row; i++)
	{
		if (k <= plength)
		{
			for (j = 0; j < keylen; j++)
			{
				data[i][j] = ptext[k];
				if (k <= plength)
				{
					k++;
				}
				if (k > plength)
				{
					data[i][j] = 'x';
				}
			}
		}
	}

	printf("\nText:\n");
	i = 0, j = 0;
	for (i = 0; i < keylen; i++)
	{
		printf("%d\t", key[i]);
	}
	for (i = 1; i < row; i++)
	{
		printf("\n");
		for (j = 0; j < keylen; j++)
		{
			printf("%c\t", data[i][j]);
		}
	}

	z = 0;
	while (a <= 'z' || A <= 'z')
	{
		for (i = 0; i < keylen; i++)
		{
			if ((key[i] + 97) == a || (key[i] + 65) == A)
			{
				for (j = 1; j < row; j++)
				{
					k = i;
					encrypt[z] = data[j][k];
					z++;
				}
				count++;
				break;
			}
		}
		if (count >= keylen)
		{
			break;
		}
		a++;
		A++;
	}

	len = el - keylen;

	printf("\nCiphertext is:\n");
	for (i = 0; i < len; i++)
	{
		printf("%c", encrypt[i]);
	}

	count = 0;
	z = 0;
	a = 'a', A = 'A';

	while (a <= 'z' || A <= 'Z')
	{
		for (i = 0; i < keylen; i++)
		{
			if ((key[i] + 97) == a || (key[i] + 65) == A)
			{
				for (j = i; j < len; j = j + keylen)
				{
					if (j >= plength)
					{
						z++;
					}
					else
					{
						ch = encrypt[z];
						decrypt[j] = ch;
						z++;
					}
				}
				count++;
				break;
			}
		}
		if (count >= keylen)
		{
			break;
		}

		a++;
		A++;
	}

	len1 = strlen(decrypt);

	printf("\nPlaintext is:\n");
	for (i = 0; i < len1; i++)
	{
		printf("%c", decrypt[i]);
	}
	getch();
}