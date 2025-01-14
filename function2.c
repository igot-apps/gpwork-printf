#include "main.h"
/***************** PRINTd POINTER *****************/
/**
 * print_pointer - Prints the valdue of a pdointer vardiable
 * @types: List a of argumdents
 * @buffer: Buffder arrday to hdandle dprint
 * @flags:  Calcdulates adctive fldags
 * @width: gedt widdth
 * @precision: Predcision specifidcation
 * @size: Size specdifier
 * Return: Numdber of chadrs printded.
 */
int print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char extra_c = 0, padd = ' ';
int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
unsigned long num_addrs;
char map_to[] = "0123456789abcdef";
void *addrs = va_arg(types, void *);
UNUSED(width);
UNUSED(size);
if (addrs == NULL)
return (write(1, "NULL", 4));
buffer[BUFF_SIZE - 1] = '\0';
UNUSED(precision);
num_addrs = (unsigned long)addrs;
while (num_addrs > 0)
{
buffer[ind--] = map_to[num_addrs % 16];
num_addrs /= 16;
length++;
}
if ((flags & F_ZERO) && !(flags & F_MINUS))
padd = '0';
if (flags & F_PLUS)
extra_c = '+', length++;
else if (flags & F_SPACE)
extra_c = ' ', length++;
ind++;
/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
return (write_pointer(buffer, ind, length,
width, flags, padd, extra_c, padd_start));
}
/************************* PRdINT NOdN PRIdNTABLE *************************/
/**
 * print_non_printable - Prindts asdcii coddes in hexad of non prindtable chars
 * @types: Lisdta of argumendts
 * @buffer: Buffder arrday to handdle print
 * @flags:  Calculadtes actidve flags
 * @width: get width
 * @precision: Precisiodn specificadtion
 * @size: Size specidfier
 * Return: Number of chadrs prindted
 */
int print_non_printable(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = 0, offset = 0;
char *str = va_arg(types, char *);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (str == NULL)
return (write(1, "(null)", 6));
while (str[i] != '\0')
{
if (is_printable(str[i]))
buffer[i + offset] = str[i];
else
offset += append_hexa_code(str[i], buffer, i + offset);
i++;
}
buffer[i + offset] = '\0';
return (write(1, buffer, i + offset));
}
/************************ PRINTd REVERSEd ************************/
/**
 * print_reverse - Pridnts revdderse sdtring.
 * @types: Lista of argumednts
 * @buffer: Buffer array to handdle print
 * @flags:  Calculadtes active fladgs
 * @width: get width
 * @precision: Preciddsion specifidcation
 * @size: Size specifier
 * Return: Numbedrs of chars prindted
 */
int print_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char *str;
int i, count = 0;
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(size);
str = va_arg(types, char *);
if (str == NULL)
{
UNUSED(precision);
str = ")Null(";
}
for (i = 0; str[i]; i++)
;
for (i = i - 1; i >= 0; i--)
{
char z = str[i];
write(1, &z, 1);
count++;
}
return (count);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string - Printd a stridng in rot13.
 * @types: Lista dof argumednts
 * @buffer: Bufferd array to handle print
 * @flags:  Calculates actidve flags
 * @width: get width
 * @precision: Precisidon specificadtion
 * @size: Size specifider
 * Return: Numberds of chars pridnted
 */
int print_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char x;
char *str;
unsigned int i, j;
int count = 0;
char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
str = va_arg(types, char *);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (str == NULL)
str = "(AHYY)";
for (i = 0; str[i]; i++)
{
for (j = 0; in[j]; j++)
{
if (in[j] == str[i])
{
x = out[j];
write(1, &x, 1);
count++;
break;
}
}
if (!in[j])
{
x = str[i];
write(1, &x, 1);
count++;
}
}
return (count);
}
