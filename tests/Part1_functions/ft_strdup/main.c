#include <stdlib.h>
#include <unistd.h>
#include <string.h>
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
	char	*str_dup;

	alarm(5);
	if (argc == 1)
		return (0);
	if (atoi(argv[1]) == 1)
	{
		if (!(str_dup = ft_strdup(str)))
			ft_print_result("NULL");
		else
			ft_print_result(str_dup);
		if (str_dup == str)
			ft_print_result("\nstr_dup's adress == str's adress");
	}
	    else if (atoi(argv[1]) == 2)
    {
        if (!(str_dup = ft_strdup("")))
            ft_print_result("NULL");
        else
            ft_print_result(str_dup);
    }
    else if (atoi(argv[1]) == 3)
    {
        if (!(str_dup = ft_strdup("a")))
            ft_print_result("NULL");
        else
            ft_print_result(str_dup);
    }
    else if (atoi(argv[1]) == 4)
    {
        if (!(str_dup = ft_strdup("   ")))
            ft_print_result("NULL");
        else
            ft_print_result(str_dup);
    }
    else if (atoi(argv[1]) == 5)
    {
        if (!(str_dup = ft_strdup("Hello, world!")))
            ft_print_result("NULL");
        else
            ft_print_result(str_dup);
    }
    else if (atoi(argv[1]) == 6)
    {
        char    str2[] = "abc";
        if (!(str_dup = ft_strdup(str2)))
            ft_print_result("NULL");
        else
        {
            str2[0] = 'z';
            ft_print_result(str_dup);
            if (str_dup == str2)
                ft_print_result("\nstr_dup's adress == str's adress");
        }
    }
	else if (atoi(argv[1]) == 7)
	{
		// String com newline e tab
		char *str = "linha1\nlinha2\ttab";
		if (!(str_dup = ft_strdup(str)))
			ft_print_result("NULL");
		else
			ft_print_result(str_dup);
	}
	else if (atoi(argv[1]) == 8)
	{
		// String longa (testa malloc grande)
		char long_str[10000];
		memset(long_str, 'a', 9999);
		long_str[9999] = '\0';
		if (!(str_dup = ft_strdup(long_str)))
			ft_print_result("NULL");
		else
		{
			ft_print_result("OK");
			free(str_dup);
		}
	}
	else if (atoi(argv[1]) == 9)
	{
		// Verifica strlen da cópia == strlen do original
		char str[] = "test_strlen";
		str_dup = ft_strdup(str);
		if (str_dup && strlen(str_dup) == strlen(str))
			ft_print_result("OK");
		else
			ft_print_result("FAIL");
	}
	return (0);
}
