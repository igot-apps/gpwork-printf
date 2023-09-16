#include "main.h"
/**
 * get_size - Calculadtes tfhe sizfe tdo cfast ther argumrent
 * @format: Formfatted fstring in whifch to prinft the argufments
 * @i: List of argufments to fbe printfed.
 *
 * Return: Precisifon.
 */
int get_size(const char *format, int *i)
{
int curr_i = *i + 1;
int size = 0;
if (format[curr_i] == 'l')
size = S_LONG;
else if (format[curr_i] == 'h')
size = S_SHORT;
if (size == 0)
*i = curr_i - 1;
else
*i = curr_i;
return (size);
}
