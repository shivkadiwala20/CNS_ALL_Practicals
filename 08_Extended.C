#include<stdio.h>
#include<conio.h>
void main()
{
  int m,b,q=0,t1,t2,t3,a1=1,a2=0,a3,b1=0,b2=1,b3;

  printf("Enter the value of Galois field(m):");
  scanf("%d",&m);

  printf("Enter the number whose value is to be found(b):");
  scanf("%d",&b);

  a3=m;
  b3=b;

  while(b3!=1 && b3!=0)
  {
    q=a3/b3;

    t1=(a1-(q*b1));
    t2=(a2-(q*b2));
    t3=(a3-(q*b3));

    //copying values of previous b1,b2,b3 into current a1,a2,a3
    a1=b1;
    a2=b2;
    a3=b3;

    b1=t1;
    b2=t2;
    b3=t3;
  }

    if(b3==0)
    {
      printf("Inverse does not exist");
    }

    else
    {
      if(b2<0)                             //if inverse value found is negative
      {
	     b2=m+b2;                           //m=galois field
      }
      printf("The inverse of %d in galois field(%d) is : %d",b,m,b2);
    }
getch();    
    
 }
