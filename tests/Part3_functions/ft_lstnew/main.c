#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "../../../libft.h"

typedef struct s_payload
{
	int		n;
	char	c;
}t_payload;

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

int	main(int argc, const char *argv[])
{
	t_list		*elem;
	t_list		*elem2;
	char		str[] = "lorem ipsum dolor sit";
	int			i;
	char		c;
	char		empty[] = "";
	char		mutable[] = "42";
	char		*literal;
	unsigned char	buf[4];
	t_payload	payload;

	alarm(5);
	if (argc == 1)
		return (0);
	else if (atoi(argv[1]) == 1)
	{
		elem = ft_lstnew(str);
		if (!elem)
			print_ko("string content");
		else if (elem->content == str && elem->next == NULL)
			print_ok("string content");
		else
			print_ko("string content");
		free(elem);
	}
	else if (atoi(argv[1]) == 2)
	{
		i = 42;
		elem = ft_lstnew(&i);
		if (!elem)
			print_ko("int pointer content");
		else if (elem->content == &i && *(int *)elem->content == 42 && elem->next == NULL)
			print_ok("int pointer content");
		else
			print_ko("int pointer content");
		free(elem);
	}
	else if (atoi(argv[1]) == 3)
	{
		elem = ft_lstnew(NULL);
		if (!elem)
			print_ko("NULL content");
		else if (elem->content == NULL && elem->next == NULL)
			print_ok("NULL content");
		else
			print_ko("NULL content");
		free(elem);
	}
	else if (atoi(argv[1]) == 4)
	{
		c = 'A';
		elem = ft_lstnew(&c);
		if (!elem)
			print_ko("char pointer content");
		else if (elem->content == &c && *(char *)elem->content == 'A' && elem->next == NULL)
			print_ok("char pointer content");
		else
			print_ko("char pointer content");
		free(elem);
	}
	else if (atoi(argv[1]) == 5)
	{
		elem = ft_lstnew(empty);
		if (!elem)
			print_ko("empty string content");
		else if (elem->content == empty && ((char *)elem->content)[0] == '\0' && elem->next == NULL)
			print_ok("empty string content");
		else
			print_ko("empty string content");
		free(elem);
	}
	else if (atoi(argv[1]) == 6)
	{
		elem = ft_lstnew(mutable);
		mutable[0] = '9';
		if (!elem)
			print_ko("content is not copied");
		else if (elem->content == mutable && strcmp((char *)elem->content, "92") == 0 && elem->next == NULL)
			print_ok("content is not copied");
		else
			print_ko("content is not copied");
		free(elem);
	}
	else if (atoi(argv[1]) == 7)
	{
		payload.n = 7;
		payload.c = 'z';
		elem = ft_lstnew(&payload);
		if (!elem)
			print_ko("struct pointer content");
		else if (elem->content == &payload && ((t_payload *)elem->content)->n == 7
			&& ((t_payload *)elem->content)->c == 'z' && elem->next == NULL)
			print_ok("struct pointer content");
		else
			print_ko("struct pointer content");
		free(elem);
	}
	else if (atoi(argv[1]) == 8)
	{
		buf[0] = 1;
		buf[1] = 0;
		buf[2] = 2;
		buf[3] = 3;
		elem = ft_lstnew(buf);
		if (!elem)
			print_ko("binary buffer pointer");
		else if (elem->content == buf && ((unsigned char *)elem->content)[0] == 1
			&& ((unsigned char *)elem->content)[1] == 0 && ((unsigned char *)elem->content)[2] == 2
			&& ((unsigned char *)elem->content)[3] == 3 && elem->next == NULL)
			print_ok("binary buffer pointer");
		else
			print_ko("binary buffer pointer");
		free(elem);
	}
	else if (atoi(argv[1]) == 9)
	{
		literal = "abc";
		elem = ft_lstnew(literal);
		if (!elem)
			print_ko("string literal pointer");
		else if (elem->content == literal && strcmp((char *)elem->content, "abc") == 0 && elem->next == NULL)
			print_ok("string literal pointer");
		else
			print_ko("string literal pointer");
		free(elem);
	}
	else if (atoi(argv[1]) == 10)
	{
		i = 123;
		elem = ft_lstnew(&i);
		elem2 = ft_lstnew(&i);
		if (!elem || !elem2)
			print_ko("distinct node allocations");
		else if (elem != elem2 && elem->content == &i && elem2->content == &i
			&& elem->next == NULL && elem2->next == NULL)
			print_ok("distinct node allocations");
		else
			print_ko("distinct node allocations");
		free(elem);
		free(elem2);
	}
	else if (atoi(argv[1]) == 11)
	{
		str[0] = 'L';
		elem = ft_lstnew(str);
		if (!elem)
			print_ko("preserves exact pointer identity");
		else if (elem->content == (void *)str && &((char *)elem->content)[0] == &str[0] && elem->next == NULL)
			print_ok("preserves exact pointer identity");
		else
			print_ko("preserves exact pointer identity");
		free(elem);
	}
	else if (atoi(argv[1]) == 12)
	{
		c = 'Z';
		elem = ft_lstnew(&c);
		if (!elem)
			print_ko("single byte local variable");
		else if (elem->content == &c && *(char *)elem->content == 'Z' && elem->next == NULL)
			print_ok("single byte local variable");
		else
			print_ko("single byte local variable");
		free(elem);
	}
	return (0);
}