#include <stdio.h>
#include <conio.h>

int gcd(int, int);

void main()
{
	int a, b;
	clrscr();
	printf("Enter The a : ");
	scanf("%d", &a);
	printf("Enter The b : ");
	scanf("%d", &b);
	printf("%d", gcd(a, b));
	getch();
}

int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else if (a < b)
	{
		return gcd(b, a);
	}
	else
	{
		return gcd(b, a % b);
	}
}