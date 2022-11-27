#include "ft_printf.h"

size_t printchr(char c)
{
    ft_putchar(c)
    return (1);
}

size_t  printstr(char *str)
{
    ft_putstr_fd(str, 1);
    return (ft_strlen(str));
}

size_t  printpointer(void *ptr)
{

}

size_t  printdec(int n)
{
    size_t  length;

    ft_putnbr_fd(n, 1);
    length = 0;
    if (n < 0)
        length++;
    while (n != 0)
    {
        n /= 10;
        length++;
    }
    return (length);
}

size_t  printundec(unsigned int n)
{

}

size_t  printhex(int n)
{

}
