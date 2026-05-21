#include <stdlib.h>
#include <unistd.h>
#include "../../../libft.h"

void    print_zero_check(unsigned char *p, size_t n)
{
    size_t i;

    if (n == 0)
    {
        if (!p)
            write(1, "NULL", 4);
        else
            write(1, "OK", 2);
        return ;
    }
    if (!p)
    {
        write(1, "NULL", 4);
        return ;
    }
    i = 0;
    while (i < n)
    {
        if (p[i] != 0)
        {
            write(1, "KO", 2);
            return ;
        }
        i++;
    }
    write(1, "OK", 2);
}

int     main(int argc, const char *argv[])
{
    alarm(5);
    if (argc == 1)
        return (0);
    else if (atoi(argv[1]) == 1)
        print_zero_check(ft_calloc(30, 1), 30);
    else if (atoi(argv[1]) == 2)
        print_zero_check(ft_calloc(1, 1), 1);
    else if (atoi(argv[1]) == 3)
        print_zero_check(ft_calloc(4, 8), 32);
    else if (atoi(argv[1]) == 4)
        print_zero_check(ft_calloc(0, 1), 0);
    else if (atoi(argv[1]) == 5)
        print_zero_check(ft_calloc(1, 0), 0);
    else if (atoi(argv[1]) == 6)
        print_zero_check(ft_calloc(0, 0), 0);
    else if (atoi(argv[1]) == 7)
        print_zero_check(ft_calloc((size_t)-1, 2), 0);
    else if (atoi(argv[1]) == 8)
        print_zero_check(ft_calloc((size_t)-1 / 2 + 1, 2), 0);
    return (0);
}