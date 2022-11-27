#include "ft_printf.h"

size_t printchr(char c)
{
    ft_putchar_fd(c, 1)
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
    length += numlength(n);
    return (length);
}

size_t  printundec(unsigned int n)
{
    size_t          length;

    length = numlength(n);
    if (n > 9)
    {
        printundec(n / 10);
        n %= 10;
    }
    if (n <= 9)
        ft_putchar_fd(n + 48, 1);
    return(length);
}

size_t  printhex(unsigned int n, char type)
{
    char            *hex
    size_t          length;
    unsigned int    aux;
    int             i;

    length = numlength(n);
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
    while (i > 0)
        ft_putchar_fd(hex[i--], 1);
    return (length);

}

size_t  numlength(long long int n)
{
    size_t  length;

    length = 0;
    while (n != 0)
    {
        n /= 10;
        length++;
    }
    return (length);
}
