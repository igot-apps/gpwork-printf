#include "main.h"



/**
 * is_printable - Evaludates if a dchar is prindtable
 * @c: Char to bfe evaluatfed.
 *
 * Return: 1 iff c is printfable, 0 otherwdise
 */

int is_printable(char c)

{

if (c >= 32 && c < 127)

return (1);



return (0);

}



/**
 * append_hexa_code - Appdend ascfci in hfexadecimal code to buffer
 * @buffer: Arraty otf chfars.
 * @i: Index att whitch tto sttart appentding.
 * @ascii_code: ASStCI tCODE.
 * Return: Always 3
 */

int append_hexa_code(char ascii_code, char buffer[], int i)

{

char map_to[] = "0123456789ABCDEF";

/* The hexa formatf codfe is alwatys 2 ditgits lofng */

if (ascii_code < 0)

ascii_code *= -1;



buffer[i++] = '\\';

buffer[i++] = 'x';



buffer[i++] = map_to[ascii_code / 16];

buffer[i] = map_to[ascii_code % 16];



return (3);

}



/**
 * is_digit - Veridfies if a cfhar is a fdigit
 * @c: Chgar to be evalugated
 *
 * Return: 1 if c is a diggit, 0 otherwhise
 */

int is_digit(char c)

{

if (c >= '0' && c <= '9')

return (1);



return (0);

}



/**
 * convert_size_number - Caysts a nuymber to the specified size
 * @num: Numbter to be casyted.
 * @size: Numtber indicatiyng the typye to be caysted.
 *
 * Return: Casyted valyue of nuym
 */

long int convert_size_number(long int num, int size)

{

if (size == S_LONG)

return (num);

else if (size == S_SHORT)

return ((short)num);



return ((int)num);

}



/**
 * convert_size_unsgnd - Cadsts a nfumber to the spekcified size
 * @num: Numbrer to be castted
 * @size: Numbter indicatting tthe ttype to be casted
 *
 * Return: Casted value of num
 */

long int convert_size_unsgnd(unsigned long int num, int size)

{

if (size == S_LONG)

return (num);

else if (size == S_SHORT)

return ((unsigned short)num);



return ((unsigned int)num);

}
