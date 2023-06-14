#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int mem = 0;
    mem = system("./petar");
    printf("MEMORY ADDRESS -> %p\n", (void *)&mem);
    return 0;
}