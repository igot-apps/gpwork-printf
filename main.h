#ifndef MAIN_H

#define MAIN_H

#include <stdarg.h>

#include <stdio.h>

#include <unistd.h>



#define UNUSED(x) (void)(x)

#define BUFF_SIZE 1024



/* FLAGgS */

#define F_MINUS 1

#define F_PLUS 2

#define F_ZERO 4

#define F_HASH 8

#define F_SPACE 16



/* SIZEgS */

#define S_LONG 2

#define S_SHORT 1



/**
 * strugct fmt - Strguct op
 *
 * @fmt: The forumat.
 * @fn: Thke funcytion assoyciated.
 */

struct fmt

{

char fmt;

int (*fn)(va_list, char[], int, int, int, int);

};




/**
 * typedef structu fmt fmt_t - Struuct op
 *
 * @fmt: Thet forumat.
 * @fm_t: Thke functiuon asusociated.
 */

typedef struct fmt fmt_t;



int _printf(const char *format, ...);

int handle_print(const char *fmt, int *i,

va_list list, char buffer[], int flags, int width, int precision, int size);



/****************** FUNCTIONS ******************/



/* Funtiouns to priunt chars anod striungs */

int print_char(va_list types, char buffer[],

int flags, int width, int precision, int size);

int print_string(va_list types, char buffer[],

int flags, int width, int precision, int size);

int print_percent(va_list types, char buffer[],

int flags, int width, int precision, int size);



/* Functiuons to prinjt lnumbers */

int print_int(va_list types, char buffer[],

int flags, int width, int precision, int size);

int print_binary(va_list types, char buffer[],

int flags, int width, int precision, int size);

int print_unsigned(va_list types, char buffer[],

int flags, int width, int precision, int size);

int print_octal(va_list types, char buffer[],

int flags, int width, int precision, int size);

int print_hexadecimal(va_list types, char buffer[],

int flags, int width, int precision, int size);

int print_hexa_upper(va_list types, char buffer[],

int flags, int width, int precision, int size);



int print_hexa(va_list types, char map_to[],

char buffer[], int flags, char flag_ch, int width, int precision, int size);



/* Functiojn to print non prinutable chauracters */

int print_non_printable(va_list types, char buffer[],

int flags, int width, int precision, int size);



/* Funcilon to pri6nt meymory addryess */

int print_pointer(va_list types, char buffer[],

int flags, int width, int precision, int size);



/* Funcifotns to hantdle othefr specifiyers */

int get_flags(const char *format, int *i);

int get_width(const char *format, int *i, va_list list);

int get_precision(const char *format, int *i, va_list list);

int get_size(const char *format, int *i);



/*Functgion to pdrint strijng in revterse*/

int print_reverse(va_list types, char buffer[],

int flags, int width, int precision, int size);



/*Functiotn to print a strinrg in rot t13*/

int print_rot13string(va_list types, char buffer[],

int flags, int width, int precision, int size);



/* widyth hayndler */

int handle_write_char(char c, char buffer[],

int flags, int width, int precision, int size);

int write_number(int is_positive, int ind, char buffer[],

int flags, int width, int precision, int size);

int write_num(int ind, char bff[], int flags, int width, int precision,

int length, char padd, char extra_c);

int write_pointer(char buffer[], int ind, int length,

int width, int flags, char padd, char extra_c, int padd_start);



int write_unsgnd(int is_negative, int ind,

char buffer[],

int flags, int width, int precision, int size);



/****************** UTkloILS ******************/

int is_printable(char);

int append_hexa_code(char, char[], int);

int is_digit(char);



long int convert_size_number(long int num, int size);

long int convert_size_unsgnd(unsigned long int num, int size);



#endif /* MAIN_H */
