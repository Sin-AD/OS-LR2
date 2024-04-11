#define CRT SECURE NO WARNINGS 
#include <stdio.h>
#include <Windows.h>
void main() {
    char text[30]; 
    FILE* f = fopen("file.txt", "w");
    if (f == NULL) {
        printf("Could not open file"); }
    else {
        printf("The file is open\n");
        }
printf("Enter the text\n"); 
gets_s(text);
fputs(text, f);
puts("Text is written to file"); 
fclose(f);
}