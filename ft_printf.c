#include <stdio.h> //testing
#include <stdlib.h> //malloc and free
#include <unistd.h> //write 
#include <stdarg.h> // va list

int	print_number_base(unsigned int nb, int base, int is_upper)
{
	int		count;
	char	*digits;
	char	c;
	if (nb == 0)
		return (write(1, "0", 1));

	count = 0;
	if (is_upper)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	
		
	if (nb >= (unsigned int)base)
		count += print_number_base(nb / base, base, is_upper);
	c = digits[nb % base];
	count += write(1, &c, 1);
	return (count);
}

//• Your function has to handle the following conversions: cspdiuxX%
// %% Prints a percent sign.

int	print_format(char fspecifier, va_list ap)
{
	int	count;

	count = 0;
	//if (fspecifier == 'c')
	//	count += print_char(va_arg(ap, int)); // type promotions!!
	//else if (fspecifier == 's')
	//	count += print_str(va_arg(ap, char*));
	//else if (fspecifier == 'p')
//		count += print_pointer(va_arg(ap, void*));	
	if (fspecifier == 'd')
		count += print_number_base(va_arg(ap, int), 10, 0);
	else if (fspecifier == 'i')
		count += print_number_base(va_arg(ap, int), 10, 0);
	else if (fspecifier == 'u')
		count += print_number_base(va_arg(ap, unsigned int), 10, 0);
	else if (fspecifier == 'x')
		count += print_number_base(va_arg(ap, unsigned int), 16, 0); //why unsigned?
	else if (fspecifier == 'X')
		count += print_number_base(va_arg(ap, unsigned int), 16, 1); // flags for lower and upper 
	else
	{
		write(1, "%", 1);
		count += write(1, &fspecifier, 1);
	}
	return (count);	
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	int		count;

	va_start(ap, format);
	count = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += print_format(*format, ap);
		}
		else
			count += write(1, format, 1);
	format++;
	}
	va_end(ap);
	return(count);
}

#include <stdio.h>

int main(void)
{
	int a = printf("OGPRINTF: Num: %X\n",255);
	int b = ft_printf("MYPRINTF: Num: %X\n", 255);

	printf("STD printf returned: %d\n", a);
	printf("FT_ printf returned: %d\n", b);
}