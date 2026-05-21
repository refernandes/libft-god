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

int	main(int argc, const char *argv[])
{
	t_list	*val;
	t_list	*elem;
	t_list	*elem2;
	t_list	*elem3;
	t_list	*elem4;
	t_list	*elem5;
	char	*str = strdup("lorem");
	char	*str2 = strdup("ipsum");
	char	*str3 = strdup("dolor");
	char	*str4 = strdup("sit");
	char	*str5 = strdup("amet");

	elem = ft_lstnewone(str);
	elem2 = ft_lstnewone(str2);
	elem3 = ft_lstnewone(str3);
	elem4 = ft_lstnewone(str4);
	elem5 = ft_lstnewone(str5);
	alarm(5);
	if (argc == 1)
		return (0);
	else if (atoi(argv[1]) == 1)
	{
		val = ft_lstlast(NULL);
		if (val == NULL)
			print_ok("NULL list");
		else
			print_ko("NULL list");
	}
	else if (atoi(argv[1]) == 2)
	{
		val = ft_lstlast(elem);
		if (val == elem)
			print_ok("single node returns head");
		else
			print_ko("single node returns head");
	}
	else if (atoi(argv[1]) == 3)
	{
		elem->next = elem2;
		val = ft_lstlast(elem);
		if (val == elem2)
			print_ok("two nodes returns second");
		else
			print_ko("two nodes returns second");
	}
	else if (atoi(argv[1]) == 4)
	{
		elem->next = elem2;
		elem2->next = elem3;
		elem3->next = elem4;
		val = ft_lstlast(elem);
		if (val == elem4)
			print_ok("four nodes returns last");
		else
			print_ko("four nodes returns last");
	}
	else if (atoi(argv[1]) == 5)
	{
		elem->next = elem2;
		elem2->next = elem3;
		elem3->next = elem4;
		elem4->next = elem5;
		val = ft_lstlast(elem2);
		if (val == elem5)
			print_ok("start from middle node");
		else
			print_ko("start from middle node");
	}
	else if (atoi(argv[1]) == 6)
	{
		elem4->content = NULL;
		elem->next = elem2;
		elem2->next = elem3;
		elem3->next = elem4;
		val = ft_lstlast(elem);
		if (val == elem4 && val->content == NULL)
			print_ok("last node with NULL content");
		else
			print_ko("last node with NULL content");
	}
	else if (atoi(argv[1]) == 7)
	{
		elem->next = elem2;
		elem2->next = NULL;
		ft_lstlast(elem);
		if (elem->next == elem2 && elem2->next == NULL)
			print_ok("does not modify two node list");
		else
			print_ko("does not modify two node list");
	}
	else if (atoi(argv[1]) == 8)
	{
		elem->next = elem2;
		elem2->next = elem3;
		elem3->next = elem4;
		ft_lstlast(elem);
		if (elem->next == elem2 && elem2->next == elem3
			&& elem3->next == elem4 && elem4->next == NULL)
			print_ok("does not modify multi node list");
		else
			print_ko("does not modify multi node list");
	}
	else if (atoi(argv[1]) == 9)
	{
		elem->next = elem2;
		elem2->next = elem3;
		val = ft_lstlast(elem);
		if (val == elem3 && val->next == NULL)
			print_ok("returned node is true tail");
		else
			print_ko("returned node is true tail");
	}
	else if (atoi(argv[1]) == 10)
	{
		elem->next = elem2;
		elem2->next = elem3;
		if (ft_lstlast(elem) == elem3 && ft_lstlast(elem) == elem3)
			print_ok("repeatable result");
		else
			print_ko("repeatable result");
	}
	else if (atoi(argv[1]) == 11)
	{
		elem->next = NULL;
		val = ft_lstlast(elem);
		if (val == elem && val->content == str)
			print_ok("single node content preserved");
		else
			print_ko("single node content preserved");
	}
	return (0);
}