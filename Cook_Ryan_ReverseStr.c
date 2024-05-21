#include <stdio.h>
#include <string.h>
#define MAX_LEN 256

void reverseStr(char *str);
void swap(char *left, char *right);

int main()
{
    char input[MAX_LEN];
    printf("Enter a string; ");
    fgets(input, MAX_LEN, stdin);
    input[strcspn(input, "\n")] = 0;
    printf("Original string: %s\n", input);
        reverseStr(input);
    printf("Reversed String: %s\n", input);
    return 0;
}
void reverseStr(char *str)
{
int start = 0;
int end = strlen(str) - 1;
while (start < end) {
swap(str + start, str + end);
start++;
end--;
}
}
void swap(char *left, char *right)
{
char temp = *left;
*left = *right;
*right = temp;
}
