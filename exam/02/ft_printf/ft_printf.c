#include <stdarg.h>
#include <unistd.h>

int r;

void	ft_putnbr(long dig, int len, char *sign)
{
	if (dig >= len)
		ft_putnbr(dig/len, len, sign);
	write(1, &sign[dig % len], 1);
	r++;
}

void	ft_puthex(unsigned dig, unsigned len, char *sign)
{
	if (dig >= len)
		ft_puthex(dig/len, len, sign);
	write(1,&sign[dig % len], 1);
	r++;
}

void	case_s(va_list ap)
{
	int		len;
	char	*str;

	len = 0;
	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	while (str[len])
		len++;
	r += len;
	write(1, str, len);
}

void	case_d(va_list ap)
{
	long long	num;

	num = va_arg(ap, int);
	if (num < 0)
	{
		write(1, "-", 1);
		r++;
		num -= num;
	}
	ft_putnbr(num, 10, "0123456789");
}

void	case_x(va_list ap)
{
	int	num;

	num = va_arg(ap, int);
	ft_puthex(num, 16, "0123456789abcdef");
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	
	r = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
				case_s(ap);
			else if (*format == 'd')
				case_d(ap);
			else if (*format == 'x')
				case_x(ap);
			format++;
		}
		else
			r += write(1, format++, 1);
	}
	va_end(ap);
	return (r);
}

//#include <stdio.h>
//int main(void)
//{
// 	printf("I - %d\n", printf("qwerty %s\t%d\t%x\n", "stroka1", 2147148145, -42));
// 	printf("II - %d\n", ft_printf("qwerty %s\t%d\t%x\n", "stroka2", 2147148145, -42));
// 	return 0;
//}
