#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	numlength(long long int n)
{
	int	length;

	length = 0;
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	if (!s || !fd)
		return ;
	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	i;

	i = n;
	if (i < 0)
	{
		ft_putchar_fd('-', fd);
		i = -i;
	}
	if (i > 9)
	{
		ft_putnbr_fd(i / 10, fd);
		i = i % 10;
	}
	if (i <= 9)
		ft_putchar_fd(i + '0', fd);
}

int	printdec(int n)
{
	int	length;

	ft_putnbr_fd(n, 1);
	length = 0;
	if (n < 0)
		length++;
	length += numlength(n);
	return (length);
}

int	printundec(unsigned int n)
{
	int	length;

	length = numlength(n);
	if (n > 9)
	{
		printundec(n / 10);
		n %= 10;
	}
	if (n <= 9)
		ft_putchar_fd(n + 48, 1);
	return (length);
}

int	printhex(unsigned long n, char type)
{
	char			*hex;
	int				length;
	unsigned int	aux;
	int				i;

	length = numlength(n);
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (length);
	}
	hex = malloc(sizeof(char) * (length + 1));
	i = 0;
	while (n != 0)
	{
		aux = n % 16;
		if (aux <= 9)
			hex[i++] = aux + 48;
		else if (aux > 9 && type == 'X')
			hex[i++] = aux + 55;
		else if (aux > 9 && type == 'x')
			hex[i++] = aux + 87;
		n /= 16;
	}
	hex[i] = '\0';
	i--;
	while (i >= 0)
		ft_putchar_fd(hex[i--], 1);
	free(hex);
	return (length);
}

static int	printchr(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

static int	printstr(char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (0);
	}
	else
		ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

static int	printpointer(unsigned long long ptr)
{
	int	length;

	ft_putstr_fd("0x", 1);
	length = printhex(ptr, 'x');
	return (length);
}

static int	checktype(va_list args, char type)
{
	int	length;

	length = 0;
	if (type == 'c')
		length += printchr(va_arg(args, int));
	else if (type == 's')
		length += printstr(va_arg(args, char *));
	else if (type == 'p')
		length += printpointer(va_arg(args, unsigned long long));
	else if (type == 'd' || type == 'i')
		length += printdec(va_arg(args, int));
	else if (type == 'u')
		length += printundec(va_arg(args, unsigned int));
	else if (type == 'x' || type == 'X')
		length += printhex(va_arg(args, unsigned int), type);
	else if (type == '%')
		length += printchr('%');
	return (length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		length;
	va_list	args;

	va_start(args, str);
	i = 0;
	length = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			length += checktype(args, str[i + 1]);
			i += 2;
			continue ;
		}
		ft_putchar_fd(str[i], 1);
		length++;
		i++;
	}
	return (length);
}

int	main(void)
{
	int				n;
	char			c;
	char			*str;
	unsigned int	un;

	n = 0;
	un = 9;
	str = NULL;
	c = 'L';
	printf("char: %c\n", c);
	ft_printf("my char: %c\n", c);
	printf("string: %s\n", str);
	ft_printf("my string: %s\n", str);
	printf("pointer: %p\n", (void *)&n);
	ft_printf("my pointer: %p\n", (void *)&n);
	printf("decimal: %d\n", n);
	ft_printf("my decimal: %d\n", n);
	printf("int: %i\n", n);
	ft_printf("my int: %i\n", n);
	printf("unsigned: %u\n", un);
	ft_printf("my unsigned: %u\n", un);
	printf("hex low: %x\n", 0);
	ft_printf("my hex low: %x\n", 0);
	printf("hex up: %X\n", 0);
	ft_printf("my hex up: %X\n", 0);
	printf("percent: %%\n");
	ft_printf("my percent: %%\n");
}