#include <stdio.h>
#include <string.h>

void print_caca(void)
{
	char buffer[10];
	// char original[] = "0123456789\x90\x90\x30\xb5\x40\x00\x8b\xea"; // Retorna 46 45 44 43 (F E D C) || A e B "sobram" || EIP (registrador EIP (Instruction Pointer) 
	char original[] = "456789ABCDEF"; // Retorna 46 45 44 43 (F E D C) || A e B "sobram"
	

	strcpy(buffer, original);

	printf("%s",buffer);
}

int main(int argc, char **argv)
{
	char buffer[4];


	strcpy(buffer, "\x41\x42\x43\x44"
					"\x90\x90\x90\x90\x90"
					"\x90\x90\x90\x90\x90"
					"\x90\x90\x90\x90\x90"
					"\x90\x90\x90\x90\x90"
					"\x90\x90\x90\x90\x90"
					"\x90\x90\x90\x90\x90"
					"\x90\x90\x90\x90\x90"
					"\x90\x90\x90\x90\x90"
					"\x90\x90\x90\x90\x90"
					"\x90\x90\x90\x90\x90"
					"\x90\x90\x90\x90\x90"
					"\x90\x90\x90\x90\x90"
					"\x90\x90\x90\x90\x90"
					"\x90\x90\x90\x90\x90"
					"\x90\x90\x90\x90\x90"
					"\x90\x90\x90\x90\x90"
					"\x90\x90\x90\x90\x90"
					"\x90\x90\x90\x90\x90"
					"\x90\x90\x90\x90\x90"
					"\x90\x90\x90\x90\x90"

		);
	print_caca();

	return (0);
}

/*
push	ebp (1245120 -> 0x0012ffc0)
mov		ebp, esp (1245056 -> 0x0012ff80)
sub		esp, 40h (0x0012ff80 - 0x00000040 = 0x0012ff40) 
push	ebx // 7ffd5000 (diminui os enderecos ver o valor de 0x0012ff38)
push	esi // 00000000
push	edi // 00000000
lea		edi, [ebp - 40h] (edi = 0x00000000 / ebp = 0x0012ff80 -> ebp - 40h = 0x0012ff40)
mov		ecx, 10h (ecx = 1 -> 0x00000010)

*/