// Disassembler for Specified ISA by Amit Joshi and Pooja Mane.


#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(int argc, char** argv)
{
if(argc != 2)
{
printf("\nPlease include 1 argument that is the file path to the FISA memory image.\n\n");
exit(1);
}

uint32_t memory_space[256];

for(int i=0; i<256; i++)
{
memory_space[i] = 0;
}

FILE* in = fopen(argv[1], "rb");
if(in == NULL)
{
printf("\n*** Problem opening file! ***\n\n");
exit(1);
}

for(int i=0; i<256; i++)
{
int result = fread(&(memory_space[i]), sizeof(uint32_t), 1, in);

if(result == 0)
{
printf("\n*** Problem reading file after successfully opening it! ***\n\n");
exit(1);
}
}

for(int i=0; i<256; i++)
{
int op_code = (memory_space[i])&255;
int op1 = ((memory_space[i])>>8)&255;
int op2 = ((memory_space[i])>>16)&255;
int op3 = ((memory_space[i])>>24)&255;

printf("%d:\t", i);

switch(op_code)
{
case 0:
printf("q\n");
break;

case 2:
printf("p r%d\n", op1);
break;

case 3:
printf("p %d\n", op1);
break;

case 4:
printf("pc r%d\n", op1);
break;

case 5:
printf("pci %d\n", op1);
break;

case 32:
printf("ld r%d r%d\n", op1, op2);
break;

case 33:
printf("ldi r%d %d\n", op1, op2);
break;

case 34:
printf("st r%d r%d\n", op1, op2);
break;

case 35:
printf("sti r%d %d\n", op1, op2);
break;

case 36:
printf("stia %d r%d\n", op1, op2);
break;

case 37:
printf("stiai %d %d\n", op1, op2);
break;

case 64:
printf("add r%d r%d r%d\n", op1, op2, op3);
break;

case 65:
printf("addi r%d r%d %d\n", op1, op2, op3);
break;

case 66:
printf("sub r%d r%d r%d\n", op1, op2, op3);
break;

case 67:
printf("subi r%d r%d %d\n", op1, op2, op3);
break;

case 68:
printf("mul r%d r%d r%d\n", op1, op2, op3);
break;

case 69:
printf("muli r%d r%d %d\n", op1, op2, op3);
break;

case 72:
printf("div r%d r%d r%d\n", op1, op2, op3);
break;

case 73:
printf("divi r%d r%d %d\n", op1, op2, op3);
break;

case 80:
printf("mod r%d r%d r%d\n", op1, op2, op3);
break;

case 81:
printf("modi r%d r%d %d\n", op1, op2, op3);
break;

case 128:
printf("j %d\n", op1);
break;

case 130:
printf("beq %d r%d r%d\n", op1, op2, op3);
break;

case 131:
printf("beqi %d r%d %d\n", op1, op2, op3);
break;

case 132:
printf("blt %d r%d r%d\n", op1, op2, op3);
break;

case 133:
printf("blti %d r%d %d\n", op1, op2, op3);
break;

case 134:
printf("ble %d r%d r%d\n", op1, op2, op3);
break;

case 135:
printf("blei %d r%d %d\n", op1, op2, op3);
break;

case 136:
printf("bgt %d r%d r%d\n", op1, op2, op3);
break;

case 137:
printf("bgti %d r%d %d\n", op1, op2, op3);
break;

case 138:
printf("bge %d r%d r%d\n", op1, op2, op3);
break;

case 139:
printf("bgei %d r%d %d\n", op1, op2, op3);
break;

default:
printf("\n\n*** Unrecognized Op Code: %d ***\n\n", op_code);
exit(1);
break;
}
}

return 0;
}