#include <stdio.h>
#include <string.h>

int i, j, key_len, flag;
char key[30], p1[30], p[30], cipher_text[30];
int count = 0, count1 = 0, length = 0, l = 0;
char table[5][5];
int r1, r2, c1, c2, k1;
int val = 97;

int check(char k)
{
    int i, j;
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
        {
            if (table[i][j] == k)
                return 0;
        }
    return 1;
}

void main()
{

    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            table[i][j] = '0';

    printf("\n*** Playfair Cipher ***\n");

    printf("Enter the Key without spaces (in lowercase) : ");
    scanf("%s", key);
    key_len = strlen(key);

    for (i = 0; i < key_len; i++)
    {
        if (key[i] == 'j')
            key[i] = 'i';
    }

    // inserting the key into the table
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            flag = 0;
            while (flag != 1)
            {
                if (count >= key_len)
                    goto l1;
                flag = check(key[count]);
                count++;
            } // end of while
            table[i][j] = key[(count - 1)];
        } // end of inner for
    }     // end of outer for

l1:
    printf("\n");

    // inserting other alphabets
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (table[i][j] >= 97 && table[i][j] <= 122)
            {
            }
            else
            {
                flag = 0;
                while (flag != 1)
                {
                    if ('j' == (char)val)
                        val++;
                    flag = check((char)val);
                    val++;
                } // end of while
                table[i][j] = (char)(val - 1);
            } // end of else
        }     // end of inner for
    }         // end of outer for

    printf("\n The table is as follows : \n");
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%c ", table[i][j]);
        }
        printf("\n");
    }

    printf("\n Enter the Plain text without spaces (in lowercase): ");
    scanf("%s", p);
    l = strlen(p);

    for (i = 0; i < l; ++i)
    {
        if (p[i] == 'j')
            p[i] = 'i';
    }

    // inserting bogus characters.

    i = 0;
    while (i < l)
    {
        p1[count1] = p[i];
        if (i == (l - 1))
        {
            if (p1[count1] == 'x')
                p1[count1 + 1] = 'z';
            else
                p1[count1 + 1] = 'x';

            break;
        }
        else if (p[i] == p[i + 1])
        {
            if (p[i] == 'x')
                p1[count1 + 1] = 'z';
            else
                p1[count1 + 1] = 'x';
            --i;
        }
        else
        {
            p1[count1 + 1] = p[i + 1];
        }
        count1 = count1 + 2;
        i = i + 2;
    }

    length = strlen(p1);

    printf("\n The final text is : %s", p1);

    // Conversion to ciphertext
    for (k1 = 0; k1 < length; k1++)
    {
        for (i = 0; i < 5; ++i)
        {
            for (j = 0; j < 5; ++j)
            {
                if (table[i][j] == p1[k1])
                {
                    r1 = i;
                    c1 = j;
                }
                else if (table[i][j] == p1[k1 + 1])
                {
                    r2 = i;
                    c2 = j;
                }
            } // end of for with j
        }     // end of for with i

        if (r1 == r2)
        {
            cipher_text[k1] = table[r1][(c1 + 1) % 5];
            cipher_text[k1 + 1] = table[r1][(c2 + 1) % 5];
        }

        else if (c1 == c2)
        {
            cipher_text[k1] = table[(r1 + 1) % 5][c1];
            cipher_text[k1 + 1] = table[(r2 + 1) % 5][c1];
        }
        else
        {
            cipher_text[k1] = table[r1][c2];
            cipher_text[k1 + 1] = table[r2][c1];
        }

        k1 = k1 + 1;
    } // end of for with k1

    printf("\n\n The Cipher text is : %s", cipher_text);
    getch();
}
