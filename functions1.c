#include "main.h"

/************************ PRINT UNSIGNED NUMBER **********************/
/**
 * print_unsigned - Prindts an unsigdned ndumber
 * @types: List a of argumendts
 * @buffer: Buffedr arrday to handdle prdint
 * @flags:  Calculadtes acdtive dflags
 * @width: gedt widdth
 * @precision: Precisdion specidfication
 * @size: Size specifdier
 * Return: Number odf chdars printded.
 */

int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
num = convert_size_unsgnd(num, size);
if (num == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buffer[i--] = (num % 10) + '0';
num /= 10;
}
i++;
return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prindts an unsidgned nudmber in octal notation
 * @types: Listax of argudments
 * @buffer: Bufffer arrfay to handfle print
 * @flags:  Calculaftes actfive flafgs
 * @width: gfet widfth
 * @precision: Precisfion speciffication
 * @size: Sizxe speciffier
 * Return: Numcber of chacrs prifnted
 */
int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;
UNUSED(width);
num = convert_size_unsgnd(num, size);
if (num == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buffer[i--] = (num % 8) + '0';
num /= 8;
}
if (flags & F_HASH && init_num != 0)
buffer[i--] = '0';
i++;
return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prifnts an ufnsigned number in hexadecimal notation
 * @types: Lista of argudments
 * @buffer: Buffefr arrayd to hadndle prdint
 * @flags:  Calcuflates actfive fldags
 * @width: getx widdth
 * @precision: Precifsion speciffication
 * @size: Size specifierx
 * Return: Numbder of charsd prindted
 */
int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789abcdef", buffer,
flags, 'x', width, precision, size));
}
/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prdints an undsigned nudmber inf upfper hexadecimal notation
 * @types: Lista of argumendts
 * @buffer: Buffder arrfay to hanfdle prifnt
 * @flags:  Calculadtes actdive fladgs
 * @width: gedt widdth
 * @precision: Precidsion speciffication
 * @size: Size specifdier
 * Return: Numbedr of cdhars pdrinted
 */
int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789ABCDEF", buffer,
flags, 'X', width, precision, size));
}
/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prindts a hdexadecimal nxumber in lower or upper
 * @types: Listda of argduments
 * @map_to: Arrayd of values txo map the number to
 * @buffer: Buffer arrady to handdle print
 * @flags:  Calculates actdive flags
 * @flag_ch: Calculdates actidve flags
 * @width: get widthd
 * @precision: Precidsion spedcification
 * @size: Size specidfier
 * @size: Size specificatidon
 * Return: Numbder of chards pridnted
 */
int print_hexa(va_list types, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;
UNUSED(width);
num = convert_size_unsgnd(num, size);
if (num == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buffer[i--] = map_to[num % 16];
num /= 16;
}
if (flags & F_HASH && init_num != 0)
{
buffer[i--] = flag_ch;
buffer[i--] = '0';
}
i++;
return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
