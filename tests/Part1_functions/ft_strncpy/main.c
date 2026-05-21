#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../../libft.h"


int     main(int argc, const char *argv[])
{
    char    *dest;
    int     arg;


    alarm(5);
    if (!(dest = (char *)malloc(sizeof(*dest) * 15)) || argc == 1)
        return (0);
    memset(dest, 0, 15);
    if ((arg = atoi(argv[1])) == 1)
    {
        memset(dest, 's', 13);
        if (dest != ft_strncpy(dest, "lorem", 6))
            write(1, "dest's adress was not returned\n", 31);
        write(1, dest, 15);
    }
    else if (arg == 2)
    {
        memset(dest, 's', 13);
        if (dest != ft_strncpy(dest, "lorem", 8))
            write(1, "dest's adress was not returned\n", 31);
        write(1, dest, 15);
    }
    else if (arg == 3)
    {
        memset(dest, 's', 13);
        if (dest != ft_strncpy(dest, "", 3))
            write(1, "dest's adress was not returned\n", 31);
        write(1, dest, 15);
    }
    else if (arg == 4)
    {
        memset(dest, 's', 13);
        if (dest != ft_strncpy(dest, "lorem ipsum", 3))
            write(1, "dest's adress was not returned\n", 31);
        write(1, dest, 15);
    }
    else if (arg == 5)
    {
        memset(dest, 's', 13);
        if (dest != ft_strncpy(dest, "lorem ipsum", 0))
            write(1, "dest's adress was not returned\n", 31);
        write(1, dest, 15);
    }
    else if (arg == 6)
    {
        memset(dest, 's', 5);
        if (dest != ft_strncpy(dest, "lorem ipsum", 10))
            write(1, "dest's adress was not returned\n", 31);
        write(1, dest, 15);
    }
    else if (arg == 7)
    {
        memset(dest, 's', 13);
        if (dest != ft_strncpy(dest, "lorem ipsum", 1))
            write(1, "dest's adress was not returned\n", 31);
        write(1, dest, 15);
    }
    else if (arg == 8)
    {
        memset(dest, 's', 13);
        if (dest != ft_strncpy(dest, "lorem", 5))
            write(1, "dest's adress was not returned\n", 31);
        write(1, dest, 15);
    }
    else if (arg == 9)
    {
        memset(dest, 's', 13);
        if (dest != ft_strncpy(dest, "lorem", 7))
            write(1, "dest's adress was not returned\n", 31);
        write(1, dest, 15);
    }
    else if (arg == 10)
    {
        memset(dest, 's', 13);
        if (dest != ft_strncpy(dest, "a", 10))
            write(1, "dest's adress was not returned\n", 31);
        write(1, dest, 15);
    }
    return (0);