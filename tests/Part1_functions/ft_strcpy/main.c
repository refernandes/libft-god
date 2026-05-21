#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "../../../libft.h"

static void	print_ok(char *msg)
{
	write(1, "OK: ", 4);
	write(1, msg, strlen(msg));
	write(1, "\n", 1);
}

static void	print_ko(char *msg)
{
	write(1, "KO: ", 4);
	write(1, msg, strlen(msg));
	write(1, "\n", 1);
}

static int	buf_eq(char *a, char *b, size_t n)
{
	size_t i;
	i = 0;
	while (i < n)
	{
		if (a[i] != b[i])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, const char *argv[])
{
	char	*dest;
	char	*ret;
	char	stack_dest[6];
	char	overlap[32];

	alarm(5);
	if (argc == 1)
		return (0);
	dest = (char *)malloc(sizeof(*dest) * 20);
	if (!dest)
		return (0);
	memset(dest, 0, 20);
	memset(dest, 'f', 12);
	if (atoi(argv[1]) == 1)
	{
		ret = ft_strcpy(dest, "lorem");
		if (ret == dest && strcmp(dest, "lorem") == 0)
			print_ok("basic copy short string");
		else
			print_ko("basic copy short string");
	}
	else if (atoi(argv[1]) == 2)
	{
		ret = ft_strcpy(dest, "lorem ipsum");
		if (ret == dest && strcmp(dest, "lorem ipsum") == 0)
			print_ok("basic copy longer string");
		else
			print_ko("basic copy longer string");
	}
	else if (atoi(argv[1]) == 3)
	{
		ret = ft_strcpy(dest, "");
		if (ret == dest && dest[0] == '\0')
			print_ok("empty string copy");
		else
			print_ko("empty string copy");
	}
	else if (atoi(argv[1]) == 4)
	{
		ret = ft_strcpy(dest, "abc");
		if (ret == dest && dest[0] == 'a' && dest[1] == 'b' && dest[2] == 'c' && dest[3] == '\0')
			print_ok("copies terminating null byte");
		else
			print_ko("copies terminating null byte");
	}
	else if (atoi(argv[1]) == 5)
	{
		memset(dest, 'x', 20);
		dest[19] = '\0';
		ret = ft_strcpy(dest, "hi");
		if (ret == dest && dest[0] == 'h' && dest[1] == 'i' && dest[2] == '\0' && dest[3] == 'x')
			print_ok("stops writing after null terminator");
		else
			print_ko("stops writing after null terminator");
	}
	else if (atoi(argv[1]) == 6)
	{
		memset(stack_dest, 'z', sizeof(stack_dest));
		ret = ft_strcpy(stack_dest, "12345");
		if (ret == stack_dest && buf_eq(stack_dest, "12345\0", 6))
			print_ok("exact fit buffer");
		else
			print_ko("exact fit buffer");
	}
	else if (atoi(argv[1]) == 7)
	{
		ret = ft_strcpy(dest, "42");
		if (ret == dest && &ret[0] == &dest[0])
			print_ok("returns exact dest pointer");
		else
			print_ko("returns exact dest pointer");
	}
	else if (atoi(argv[1]) == 8)
	{
		char src[] = "42";
		ret = ft_strcpy(dest, src);
		src[0] = '9';
		if (ret == dest && strcmp(dest, "42") == 0)
			print_ok("copies bytes not source pointer");
		else
			print_ko("copies bytes not source pointer");
	}
	else if (atoi(argv[1]) == 9)
	{
		ret = ft_strcpy(dest, "a");
		if (ret == dest && dest[0] == 'a' && dest[1] == '\0')
			print_ok("single character copy");
		else
			print_ko("single character copy");
	}
	else if (atoi(argv[1]) == 10)
	{
		ret = ft_strcpy(dest, "abcdefghijkl");
		if (ret == dest && strcmp(dest, "abcdefghijkl") == 0)
			print_ok("multiple sequential bytes copy");
		else
			print_ko("multiple sequential bytes copy");
	}
	else if (atoi(argv[1]) == 11)
	{
		strcpy(overlap, "overlap-test");
		ft_strcpy(overlap, overlap);
		if (strcmp(overlap, "overlap-test") == 0)
			print_ok("same source and destination pointer");
		else
			print_ko("same source and destination pointer");
	}
	else if (atoi(argv[1]) == 12)
	{
		write(1, "SKIP: NULL src is undefined behavior for strcpy\n", 47);
	}
	else if (atoi(argv[1]) == 13)
	{
		write(1, "SKIP: NULL dest is undefined behavior for strcpy\n", 48);
	}
	free(dest);
	return (0);
}