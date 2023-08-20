#include <stdio.h>

const int MAXSIZE = 128;

template<class ANY_TYPE>
class stack
{
    ANY_TYPE array[MAXSIZE];
    int stack_pointer;
public:
    stack(void) { stack_pointer = 0; };
    void push(ANY_TYPE in_dat) { array[stack_pointer++] = in_dat; };
    ANY_TYPE pop(void) { return array[--stack_pointer]; };
    int empty(void) { return (stack_pointer == 0); };
};

char name[] = "John Smith";
int main(void)
{
stack<const char *> string_stack;
stack<int> int_stack;

int_stack.push(1);
int_stack.push(-2);
int_stack.push(5);
int_stack.push(3);
int_stack.push(100);
int_stack.push(-10);

   string_stack.push("This is line 1");
   string_stack.push("This is the second line");
   string_stack.push("This is the third line");
   string_stack.push(name);

   printf("\n     Integers\n");
   do
   {
       printf("%d\n", int_stack.pop());
   } while (!int_stack.empty());

   printf("\n     Strings\n");
   do 
   {
      printf("%s\n", string_stack.pop());
   } while (!string_stack.empty());

   return 0;
}


// Result of execution


//      Strings
// John Smith
// This is the third line
// This is the second line
// This is line 1
