#include <stdio.h>
#include <string.h>

void print_caca(void)
{
	char buffer[10];
	char original[] = "0123456789\x90\x90\x30\xb5\x40\x00\x8b\xea"; // Retorna 46 45 44 43 (F E D C) || A e B "sobram"
	

	strcpy(buffer, original);
}

void print_coco(void)
{
	char buffer[10];
	char original[] = "0123456789__\x20\x10\x40\x00"; // Retorna 46 45 44 43 (F E D C) || A e B "sobram"
	

	strcpy(buffer, original);
}

int main(void)
{
	print_caca();
	return (0);
}