 /*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:35:18 by jtoty             #+#    #+#             */
/*   Updated: 2026/05/18 21:30:27  

#include <stdlib.h>
#include <unistd.h>
#include "../../../libft.h"

void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int		main(int argc, const char *argv[])
{
	char	str[] = "lorem ipsum dolor sit amet";
	char	*strsub;
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		if (!(strsub = ft_substr(str, 0, 10)))
			ft_print_result("NULL");
		else
			ft_print_result(strsub);
		if (str == strsub)
			ft_print_result("\nA new string was not returned");
	}
	else if (arg == 2)
	{
		if (!(strsub = ft_substr(str, 7, 10)))
			ft_print_result("NULL");
		else
			ft_print_result(strsub);
		if (str == strsub)
			ft_print_result("\nA new string was not returned");
	}
	else if (arg == 3)
	{
		if (!(strsub = ft_substr(str, 7, 0)))
			ft_print_result("NULL");
		else
			ft_print_result(strsub);
		if (str == strsub)
			ft_print_result("\nA new string was not returned");
	}
	else if (arg == 4)
	{
		if (!(strsub = ft_substr(str, 0, 0)))
			ft_print_result("NULL");
		else
			ft_print_result(strsub);
		if (str == strsub)
			ft_print_result("\nA new string was not returned");
	}
	else if (arg == 5)
	{
		char *bullshit;
		if (!(strsub = ft_substr(str, 400, 20)))
			ft_print_result("NULL");
		else
		{
			bullshit = (char *)&strsub[30];
			bullshit = "FULL BULLSHIT";
			if (strsub)
				ft_print_result(strsub);
			else
				ft_print_result("rip");
		}
		if (str == strsub)
			ft_print_result("\nA new string was not returned");
		(void)bullshit;
	}
	    else if (arg == 6)
    {
        if (!(strsub = ft_substr(str, 18, 50)))
            ft_print_result("NULL");
        else
            ft_print_result(strsub);
        if (str == strsub)
            ft_print_result("\nA new string was not returned");
    }
    else if (arg == 7)
    {
        if (!(strsub = ft_substr(str, 26, 10)))
            ft_print_result("NULL");
        else
            ft_print_result(strsub);
        if (str == strsub)
            ft_print_result("\nA new string was not returned");
    }
    else if (arg == 8)
    {
        if (!(strsub = ft_substr(str, 25, 10)))
            ft_print_result("NULL");
        else
            ft_print_result(strsub);
        if (str == strsub)
            ft_print_result("\nA new string was not returned");
    }
    else if (arg == 9)
    {
        if (!(strsub = ft_substr("", 0, 10)))
            ft_print_result("NULL");
        else
            ft_print_result(strsub);
    }
    else if (arg == 10)
    {
        if (!(strsub = ft_substr(str, 0, 100)))
            ft_print_result("NULL");
        else
            ft_print_result(strsub);
        if (str == strsub)
            ft_print_result("\nA new string was not returned");
    }
    else if (arg == 11)
    {
        char    str2[] = "abcdef";

        if (!(strsub = ft_substr(str2, 2, 3)))
            ft_print_result("NULL");
        else
        {
            str2[2] = 'Z';
            ft_print_result(strsub);
        }
        if (str2 == strsub)
            ft_print_result("\nA new string was not returned");
    }
	return (0);
}
