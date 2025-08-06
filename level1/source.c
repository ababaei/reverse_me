#include <stdio.h>
#include <string.h>

int main(void)
{
    char pass[14] = "__stack_check";
    char input[100];
    int test;
    
    printf("Please enter key: ");
    scanf("%s", &input);

    test = strcmp(input, pass);
    if (test == 0)
        printf("Good job.\n");
    else
        printf("Nope.\n");
    return (0);
}