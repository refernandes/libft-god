#include <stdlib.h>
#include <unistd.h>
#include "../../../libft.h"

int		main(int argc, const char *argv[])
{
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		ft_putnbr_fd(0, 2);
	else if (arg == 2)
		ft_putnbr_fd(5, 1);
	else if (arg == 3)
		ft_putnbr_fd(-5, 2);
	else if (arg == 4)
		ft_putnbr_fd(21, 1);
	else if (arg == 5)
		ft_putnbr_fd(-57, 2);
	else if (arg == 6)
		ft_putnbr_fd(164189, 1);
	else if (arg == 7)
		ft_putnbr_fd(-987441, 2);
	else if (arg == 8)
		ft_putnbr_fd(2147483647, 1);
	else if (arg == 9)
		ft_putnbr_fd(-2147483648LL, 2);
	else if (arg == 10)
        ft_putnbr_fd(1, 1);
    else if (arg == 11)
        ft_putnbr_fd(-1, 2);
    else if (arg == 12)
        ft_putnbr_fd(10, 1);
    else if (arg == 13)
        ft_putnbr_fd(-10, 2);
    else if (arg == 14)
        ft_putnbr_fd(100100, 1);
    else if (arg == 15)
        ft_putnbr_fd(-100100, 2);
    else if (arg == 16)
        ft_putnbr_fd(21, -1);
    else if (arg == 17)
        ft_putnbr_fd(-21, 42);
    return (0);
}
