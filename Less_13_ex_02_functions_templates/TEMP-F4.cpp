#include <stdio.h>

template<class ANY_TYPE>
ANY_TYPE maximum(ANY_TYPE a, ANY_TYPE b)
{
    return (a > b) ? a : b;
}
int main(void)
{
int x = 12, y = -7;
float real = 3.1415;
char ch = 'A';

   printf("%8d\n", maximum(x, y));
   printf("%8d\n", maximum(-34, y));
   printf("%8.3f\n", maximum(real, float(y)));
   printf("%8.3f\n", maximum(real, float(x)));
   printf("%c\n", maximum(ch, 'X'));

   return 0;
}