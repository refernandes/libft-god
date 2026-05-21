#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "../../../libft.h"

static int g_iter_calls = 0;

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

static t_list	*ft_lstnewone(void *content)
{
	t_list	*elem;
	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}

static char	*dupstr(const char *s)
{
	size_t	len;
	char	*out;
	len = strlen(s);
	out = (char *)malloc(len + 1);
	if (!out)
		return (NULL);
	memcpy(out, s, len + 1);
	return (out);
}

static void	reset_counter(void)
{
	g_iter_calls = 0;
}

static void	iter_replace_with_d(void *content)
{
	char	*s;
	int		i;
	g_iter_calls++;
	if (content == NULL)
		return ;
	s = (char *)content;
	i = 0;
	while (s[i])
	{
		s[i] = 'd';
		i++;
	}
}

static void	iter_count_only(void *content)
{
	(void)content;
	g_iter_calls++;
}

static int	str_eq(char *a, char *b)
{
	if (!a || !b)
		return (0);
	return (strcmp(a, b) == 0);
}

int	main(int argc, const char *argv[])
{
	t_list	*elem;
	t_list	*elem2;
	t_list	*elem3;
	t_list	*elem4;
	t_list	*saved_next1;
	t_list	*saved_next2;
	t_list	*saved_next3;
	char	*str;
	char	*str2;
	char	*str3;
	char	*str4;

	str = dupstr("lorem");
	str2 = dupstr("ipsum");
	str3 = dupstr("dolor");
	str4 = dupstr("sit");
	elem = ft_lstnewone(str);
	elem2 = ft_lstnewone(str2);
	elem3 = ft_lstnewone(str3);
	elem4 = ft_lstnewone(str4);
	alarm(5);
	if (argc == 1 || !elem || !elem2 || !elem3 || !elem4)
		return (0);
	elem->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;
	if (atoi(argv[1]) == 1)
	{
		reset_counter();
		ft_lstiter(elem, &iter_replace_with_d);
		if (str_eq(elem->content, "ddddd") && str_eq(elem2->content, "ddddd")
			&& str_eq(elem3->content, "ddddd") && str_eq(elem4->content, "ddd"))
			print_ok("applies function to all nodes");
		else
			print_ko("applies function to all nodes");
	}
	else if (atoi(argv[1]) == 2)
	{
		reset_counter();
		ft_lstiter(NULL, &iter_replace_with_d);
		if (g_iter_calls == 0)
			print_ok("NULL list handled safely");
		else
			print_ko("NULL list handled safely");
	}
	else if (atoi(argv[1]) == 3)
	{
		reset_counter();
		ft_lstiter(elem, NULL);
		if (g_iter_calls == 0 && str_eq(elem->content, "lorem") && str_eq(elem2->content, "ipsum"))
			print_ok("NULL f handled safely");
		else
			print_ko("NULL f handled safely");
	}
	else if (atoi(argv[1]) == 4)
	{
		reset_counter();
		ft_lstiter(elem4, &iter_replace_with_d);
		if (str_eq(elem4->content, "ddd") && str_eq(elem->content, "lorem") && g_iter_calls == 1)
			print_ok("single tail node iteration");
		else
			print_ko("single tail node iteration");
	}
	else if (atoi(argv[1]) == 5)
	{
		reset_counter();
		ft_lstiter(elem2, &iter_replace_with_d);
		if (str_eq(elem->content, "lorem") && str_eq(elem2->content, "ddddd")
			&& str_eq(elem3->content, "ddddd") && str_eq(elem4->content, "ddd") && g_iter_calls == 3)
			print_ok("iterates from middle node onward");
		else
			print_ko("iterates from middle node onward");
	}
	else if (atoi(argv[1]) == 6)
	{
		reset_counter();
		elem3->content = NULL;
		ft_lstiter(elem, &iter_replace_with_d);
		if (str_eq(elem->content, "ddddd") && str_eq(elem2->content, "ddddd")
			&& elem3->content == NULL && str_eq(elem4->content, "ddd") && g_iter_calls == 4)
			print_ok("NULL content node tolerated by callback");
		else
			print_ko("NULL content node tolerated by callback");
	}
	else if (atoi(argv[1]) == 7)
	{
		reset_counter();
		saved_next1 = elem->next;
		saved_next2 = elem2->next;
		saved_next3 = elem3->next;
		ft_lstiter(elem, &iter_count_only);
		if (elem->next == saved_next1 && elem2->next == saved_next2 && elem3->next == saved_next3 && g_iter_calls == 4)
			print_ok("does not modify list links");
		else
			print_ko("does not modify list links");
	}
	else if (atoi(argv[1]) == 8)
	{
		reset_counter();
		ft_lstiter(elem, &iter_count_only);
		if (g_iter_calls == 4)
			print_ok("f called once per node");
		else
			print_ko("f called once per node");
	}
	else if (atoi(argv[1]) == 9)
	{
		reset_counter();
		ft_lstiter(elem, &iter_replace_with_d);
		if (str_eq(elem->content, "ddddd") && str_eq(elem2->content, "ddddd"))
			print_ok("content modified in place");
		else
			print_ko("content modified in place");
	}
	else if (atoi(argv[1]) == 10)
	{
		reset_counter();
		ft_lstiter(elem, &iter_count_only);
		ft_lstiter(elem, &iter_count_only);
		if (g_iter_calls == 8)
			print_ok("repeatable traversal");
		else
			print_ko("repeatable traversal");
	}
	else if (atoi(argv[1]) == 11)
	{
		reset_counter();
		elem->next = NULL;
		ft_lstiter(elem, &iter_replace_with_d);
		if (str_eq(elem->content, "ddddd") && g_iter_calls == 1)
			print_ok("single node head iteration");
		else
			print_ko("single node head iteration");
	}
	free(str);
	free(str2);
	free(str3);
	free(str4);
	free(elem4);
	free(elem3);
	free(elem2);
	free(elem);
	return (0);
}