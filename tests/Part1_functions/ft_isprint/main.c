#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include "../../../libft.h"


void    ft_print_result(int n)
{
    if (n)
        write(1, "1", 1);
    else
        write(1, "0", 1);
}


int     main(int argc, const char *argv[])
{
    int     i;
    int     arg;


    alarm(5);
    if (argc == 1)
        return (0);
    else if ((arg = atoi(argv[1])) == 1)
    {
        i = 0;
        while (i <= 47)
        {
            ft_print_result(ft_isprint(i));
            i++;
        }
    }
    else if (arg == 2)
    {
        i = '0';
        while (i <= '9')
        {
            ft_print_result(ft_isprint(i));
            i++;
        }
    }
    else if (arg == 3)
    {
        i = 58;
        while (i <= 64)
        {
            ft_print_result(ft_isprint(i));
            i++;
        }
    }
    else if (arg == 4)
    {
        i = 'A';
        while (i <= 'Z')
        {
            ft_print_result(ft_isprint(i));
            i++;
        }
    }
    else if (arg == 5)
    {
        i = 91;
        while (i <= 96)
        {
            ft_print_result(ft_isprint(i));
            i++;
        }
    }
    else if (arg == 6)
    {
        i = 'a';
        while (i <= 'z')
        {
            ft_print_result(ft_isprint(i));
            i++;
        }
    }
    else if (arg == 7)
    {
        i = 123;
        while (i <= 127)
        {
            ft_print_result(ft_isprint(i));
            i++;
        }
    }
    else if (arg == 8)
    {
        i = -128;
        while (i <= -1)
        {
            ft_print_result(ft_isprint(i));
            i++;
        }
    }
    else if (arg == 9)
    {
        i = 128;
        while (i <= 255)
        {
            ft_print_result(ft_isprint(i));
            i++;
        }
    }
    else if (arg == 10)
    {
        ft_print_result(ft_isprint(-1000));
        ft_print_result(ft_isprint(1000));
    }
    else if (arg == 11)
    {
        ft_print_result(ft_isprint(-1));
    }
    else if (arg == 12)
    {
        char    c;


        c = (char)-1;
        ft_print_result(ft_isprint((unsigned char)c));
    }
    else if (arg == 13)
    {
        unsigned char   c;


        c = (unsigned char)255;
        ft_print_result(ft_isprint(c));
    }
    else if (arg == 14)
    {
        unsigned char   c;


        c = (unsigned char)0;
        ft_print_result(ft_isprint(c));
    }
    else if (arg == 15)
    {
        unsigned char   c;


        c = (unsigned char)127;
        ft_print_result(ft_isprint(c));
    }
    else if (arg == 16)
    {
        unsigned char   c;


        c = (unsigned char)'A';
        ft_print_result(ft_isprint(c));
    }
    return (0);
    
}