#include "main.h"

/**
 * format_handler - handle the format
 * @args: args
 * @count: poiner to a count
 * @pres: precision
 */

void format_handler(va_list args, char pres, int *count)
{
	if (pres == 'c')
		print_c(va_arg(args, int), count);
	else if (pres == 's')
		print_s(va_arg(args, char*), count);
	else if (pres == '%')
		print_c('%', count);
	else if (pres == 'd' || pres == 'i')
		print_d(va_arg(args, int), count);
	else if (pres == 'r')
		print_r(va_arg(args, char*), count);
	else if (pres == 'x' || pres == 'X')
		print_base(va_arg(args, int), 16, pres, count);
	else if (pres == 'p')
	{
		print_s("0x", count);
		print_base(va_arg(args, int), 16, 'x', count);
	}
	else
		print_c(pres ,count);
}

/**
 * _printf - function printf
 * @format: format
 * Return: the number of bytes printed
 */

int _printf(const char *format, ...)
{
	int i = 0;
	int count = 0;
	va_list args;

	va_start(args, format);
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				return (-1);
			format_handler(args, format[i], &count);
		}
		else
			print_c(format[i], &count);
		i++;
	}
	va_end(args);
	return (count);
}
