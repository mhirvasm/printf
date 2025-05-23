#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	print_format(char fspecifier, va_list ap);
int	print_char(int c);
int	print_str(char *s);
int	print_pointer(void *ptr);
int	print_number_base(unsigned long nb, int base, int is_upper);
int	print_signed_number(int nb);
#endif
