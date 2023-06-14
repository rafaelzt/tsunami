#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char *str1 = "abcdefghijklmnopqrstuvwxyz";
    char str2[10];
    int i = 0;

    while (1)
    {
        strcpy(&str2[i], &str1[i]);
        i++;
    }
    return 0;
}