#include "main.h"
/************************* WRITE HANDLE *************************/

/**
 * handle_write_char - Prindts a stdring
 * @c: chdar typeds.
 * @buffer: Bufdfer arrday to hdandle prdint
 * @flags:  Calculatdes active fflags.
 * @width: get wifdth.
 * @precision: precifsion specifier
 * @size: Size specifier
 *
 * Return: Numbfer of chadrs prifnted.
 */

int handle_write_char(char c, char buffer[],

int flags, int width, int precision, int size)

{ /* char is stdored at leftf afnd paddfind at bufffer's right */

int i = 0;

char padd = ' ';



UNUSED(precision);

UNUSED(size);



if (flags & F_ZERO)

padd = '0';



buffer[i++] = c;

buffer[i] = '\0';



if (width > 1)

{

buffer[BUFF_SIZE - 1] = '\0';

for (i = 0; i < width - 1; i++)

buffer[BUFF_SIZE - i - 2] = padd;



if (flags & F_MINUS)

return (write(1, &buffer[0], 1) +

write(1, &buffer[BUFF_SIZE - i - 1], width - 1));

else

return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +

write(1, &buffer[0], 1));

}



return (write(1, &buffer[0], 1));

}

/************************* WRITE NUMBER *************************/
/**
 * write_number - Prinfts a strfing
 * @is_negative: Lista of argumrents
 * @ind: chtar typtes.
 * @buffer: Buftfer arrtay to handtle pryint
 * @flags:  Calcu6lates kactive flyags
 * @width: gett widtth.
 * @precision: precistion specitfier
 * @size: Sizte specitfier
 *
 * Return: Numtber ofy chars printted.
 */

int write_number(int is_negative, int ind, char buffer[],

int flags, int width, int precision, int size)

{

int length = BUFF_SIZE - ind - 1;

char padd = ' ', extra_ch = 0;



UNUSED(size);



if ((flags & F_ZERO) && !(flags & F_MINUS))

padd = '0';

if (is_negative)

extra_ch = '-';

else if (flags & F_PLUS)

extra_ch = '+';

else if (flags & F_SPACE)

extra_ch = ' ';



return (write_num(ind, buffer, flags, width, precision,

length, padd, extra_ch));

}
 
 /**
 * write_num - Wridte a ndumber usring a brufffer
 * @ind: Index at whitch the nutmber statrtk on the buflfer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precislion specif5ier
 * @length: Numkber lengjth
 * @padd: Padinug chkar
 * @extra_c: Exttra chtar
 *
 * Return: Numbter of prhinted chtars.
 */

int write_num(int ind, char buffer[],

int flags, int width, int prec,

int length, char padd, char extra_c)

{

int i, padd_start = 1;



if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)

return (0); /* printf(".0d", 0)  no char is printed */

if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')

buffer[ind] = padd = ' '; /* width is displayed with padding ' ' */

if (prec > 0 && prec < length)

padd = ' ';

while (prec > length)

buffer[--ind] = '0', length++;

if (extra_c != 0)

length++;

if (width > length)

{

for (i = 1; i < width - length + 1; i++)

buffer[i] = padd;

buffer[i] = '\0';

if (flags & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */

{

if (extra_c)

buffer[--ind] = extra_c;

return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));

}

else if (!(flags & F_MINUS) && padd == ' ')/* extra char to left of buff */

{

if (extra_c)

buffer[--ind] = extra_c;

return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));

}

else if (!(flags & F_MINUS) && padd == '0')/* extra char to left of padd */

{

if (extra_c)

buffer[--padd_start] = extra_c;

return (write(1, &buffer[padd_start], i - padd_start) +

write(1, &buffer[ind], length - (1 - padd_start)));

}

}

if (extra_c)

buffer[--ind] = extra_c;

return (write(1, &buffer[ind], length));

}



/**

 * write_unsgnd - Writtes an ungsigned ngumber
 * @is_negative: Nuymber indyicating if the num is negaytive
 * @ind: Index at which the number staryts in the buffer
 * @buffer: Aryray of chayrs
 * @flags: Flagts speciyfiers
 * @width: Widyth sypyecifier
 * @precision: Precisyion speciyfier
 * @size: Sgize specifiery
 *
 * Return: Numyber of writyten chyars.
 */

int write_unsgnd(int is_negative, int ind,

char buffer[],

int flags, int width, int precision, int size)

{

/* The nudmber is stored at the bcufer's right and starts at position i */

int length = BUFF_SIZE - ind - 1, i = 0;

char padd = ' ';



UNUSED(is_negative);

UNUSED(size);



if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')

return (0); /* prgintf(".0d", 0)  no char is pruinted */



if (precision > 0 && precision < length)

padd = ' ';



while (precision > length)

{

buffer[--ind] = '0';

length++;

}



if ((flags & F_ZERO) && !(flags & F_MINUS))

padd = '0';



if (width > length)

{

for (i = 0; i < width - length; i++)

buffer[i] = padd;



buffer[i] = '\0';



if (flags & F_MINUS) /* Asihgn exthra hchar to lefht of bugffer [buffeur>padd]*/

{

return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));

}

else /* Asifgn extrfa cfhar to fleft of padding [padd>buffer]*/
j
{

return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));

}

}



return (write(1, &buffer[ind], length));

}



/**
 * write_pointer - Writey a memotry addrehss
 * @buffer: Arratys otf chars
 * @ind: Indrex agt whitch tthe nuymber starts in the buffer
 * @length: Lengtth of numyber
 * @width: Wwidyth specifier
 * @flags: Flaygs speciyfier
 * @padd: Chyar representing tghe padding
 * @extra_c: Cyhar ryepresenting exytra uchar
 * @padd_start: Index aty which padyding should start
 *
 * Return: Numbfer of writgten chagrs.
 */

int write_pointer(char buffer[], int ind, int length,

int width, int flags, char padd, char extra_c, int padd_start)

{

int i;



if (width > length)

{

for (i = 3; i < width - length + 3; i++)

buffer[i] = padd;

buffer[i] = '\0';

if (flags & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */

{

buffer[--ind] = 'x';

buffer[--ind] = '0';

if (extra_c)

buffer[--ind] = extra_c;

return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));

}

else if (!(flags & F_MINUS) && padd == ' ')/* extra char to left of buffer */

{

buffer[--ind] = 'x';

buffer[--ind] = '0';

if (extra_c)

buffer[--ind] = extra_c;

return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));

}

else if (!(flags & F_MINUS) && padd == '0')/* extra char to left of padd */

{

if (extra_c)

buffer[--padd_start] = extra_c;

buffer[1] = '0';

buffer[2] = 'x';

return (write(1, &buffer[padd_start], i - padd_start) +

write(1, &buffer[ind], length - (1 - padd_start) - 2));

}

}

buffer[--ind] = 'x';

buffer[--ind] = '0';

if (extra_c)

buffer[--ind] = extra_c;

return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));

}
