#include <stdlib.h>
#include "../../../libft.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>

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

static int	ptr_eq(void *a, void *b)
{
	return (a == b);
}

int	main(int argc, const char *argv[])
{
	t_list	*begin;
	t_list	*elem;
	t_list	*elem2;
	t_list	*elem3;
	t_list	*elem4;
	t_list	*tmp;
	char	*str = strdup("lorem");
	char	*str2 = strdup("ipsum");
	char	*str3 = strdup("dolor");
	char	*str4 = strdup("sit");

	elem = ft_lstnewone(str);
	elem2 = ft_lstnewone(str2);
	elem3 = ft_lstnewone(str3);
	elem4 = ft_lstnewone(str4);
	alarm(5);
	if (argc == 1)
		return (0);

	else if (atoi(argv[1]) == 1)
	{
		begin = NULL;
		ft_lstadd_front(&begin, elem);
		if (ptr_eq(begin, elem) && begin->next == NULL)
			print_ok("empty list + one node");
		else
			print_ko("empty list + one node");
	}

	else if (atoi(argv[1]) == 2)
	{
		begin = elem;
		ft_lstadd_front(&begin, elem2);
		if (ptr_eq(begin, elem2) && ptr_eq(begin->next, elem) && elem->next == NULL)
			print_ok("one node list");
		else
			print_ko("one node list");
	}

	else if (atoi(argv[1]) == 3)
	{
		begin = elem;
		elem->next = elem2;
		elem2->next = elem3;
		elem3->next = NULL;
		ft_lstadd_front(&begin, elem4);
		if (ptr_eq(begin, elem4)
			&& ptr_eq(begin->next, elem)
			&& ptr_eq(begin->next->next, elem2)
			&& ptr_eq(begin->next->next->next, elem3)
			&& begin->next->next->next->next == NULL)
			print_ok("multi node list preserves order");
		else
			print_ko("multi node list preserves order");
	}

	else if (atoi(argv[1]) == 4)
	{
		begin = NULL;
		ft_lstadd_front(&begin, elem4);
		ft_lstadd_front(&begin, elem3);
		ft_lstadd_front(&begin, elem2);
		ft_lstadd_front(&begin, elem);
		if (ptr_eq(begin, elem)
			&& ptr_eq(begin->next, elem2)
			&& ptr_eq(begin->next->next, elem3)
			&& ptr_eq(begin->next->next->next, elem4)
			&& begin->next->next->next->next == NULL)
			print_ok("several pushes to front");
		else
			print_ko("several pushes to front");
	}

	else if (atoi(argv[1]) == 5)
	{
		begin = elem;
		tmp = begin;
		ft_lstadd_front(&begin, elem2);
		if (ptr_eq(begin->next, tmp))
			print_ok("old head becomes new->next");
		else
			print_ko("old head becomes new->next");
	}

	else if (atoi(argv[1]) == 6)
	{
		begin = NULL;
		ft_lstadd_front(NULL, elem);
		print_ok("lst == NULL did not crash");
	}

	else if (atoi(argv[1]) == 7)
	{
		begin = NULL;
		ft_lstadd_front(&begin, NULL);
		if (begin == NULL)
			print_ok("new == NULL handled safely");
		else
			print_ko("new == NULL handled safely");
	}

	else if (atoi(argv[1]) == 8)
	{
		begin = elem;
		elem->next = elem2;
		ft_lstadd_front(&begin, NULL);
		if (ptr_eq(begin, elem) && ptr_eq(begin->next, elem2))
			print_ok("new == NULL does not alter existing list");
		else
			print_ko("new == NULL does not alter existing list");
	}

	else if (atoi(argv[1]) == 9)
	{
		begin = elem;
		elem4->next = elem3;
		ft_lstadd_front(&begin, elem4);
		if (ptr_eq(begin, elem4) && ptr_eq(begin->next, elem))
			print_ok("new->next overwritten correctly");
		else
			print_ko("new->next overwritten correctly");
	}

	else if (atoi(argv[1]) == 10)
	{
		begin = elem;
		ft_lstadd_front(&begin, elem2);
		if (ptr_eq(begin->content, str2) && ptr_eq(begin->next->content, str))
			print_ok("content preserved");
		else
			print_ko("content preserved");
	}

	else if (atoi(argv[1]) == 11)
	{
		elem4->content = NULL;
		begin = elem;
		ft_lstadd_front(&begin, elem4);
		if (ptr_eq(begin, elem4) && begin->content == NULL && ptr_eq(begin->next, elem))
			print_ok("node with NULL content");
		else
			print_ko("node with NULL content");
	}
	free(str);
	free(str2);
	free(str3);
	free(str4);
	free(elem);
	free(elem2);
	free(elem3);
	free(elem4);
	return (0);
}