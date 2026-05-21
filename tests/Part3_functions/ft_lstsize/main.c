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
		if (ft_lstsize(NULL) == 0)
			print_ok("NULL list");
		else
			print_ko("NULL list");
	}
	else if (atoi(argv[1]) == 2)
	{
		if (ft_lstsize(elem) == 1)
			print_ok("single node");
		else
			print_ko("single node");
	}
	else if (atoi(argv[1]) == 3)
	{
		elem->next = elem2;
		if (ft_lstsize(elem) == 2)
			print_ok("two nodes");
		else
			print_ko("two nodes");
	}
	else if (atoi(argv[1]) == 4)
	{
		elem->next = elem2;
		elem2->next = elem3;
		elem3->next = elem4;
		if (ft_lstsize(elem) == 4)
			print_ok("four nodes");
		else
			print_ko("four nodes");
	}
	else if (atoi(argv[1]) == 5)
	{
		elem->next = elem2;
		elem2->next = elem3;
		elem3->next = elem4;
		elem4->next = elem5;
		if (ft_lstsize(elem) == 5)
			print_ok("five nodes");
		else
			print_ko("five nodes");
	}
	else if (atoi(argv[1]) == 6)
	{
		elem->next = elem2;
		elem2->next = elem3;
		elem3->next = NULL;
		if (ft_lstsize(elem2) == 2)
			print_ok("count from middle node");
		else
			print_ko("count from middle node");
	}
	else if (atoi(argv[1]) == 7)
	{
		elem->content = NULL;
		elem2->content = NULL;
		elem->next = elem2;
		if (ft_lstsize(elem) == 2)
			print_ok("NULL content ignored");
		else
			print_ko("NULL content ignored");
	}
	else if (atoi(argv[1]) == 8)
	{
		elem->next = NULL;
		ft_lstsize(elem);
		if (elem->next == NULL)
			print_ok("does not modify single node list");
		else
			print_ko("does not modify single node list");
	}
	else if (atoi(argv[1]) == 9)
	{
		elem->next = elem2;
		elem2->next = elem3;
		elem3->next = elem4;
		ft_lstsize(elem);
		if (elem->next == elem2 && elem2->next == elem3
			&& elem3->next == elem4 && elem4->next == NULL)
			print_ok("does not modify multi node list");
		else
			print_ko("does not modify multi node list");
	}
	else if (atoi(argv[1]) == 10)
	{
		elem->next = elem2;
		elem2->next = elem3;
		if (ft_lstsize(elem3) == 1)
			print_ok("last node as head");
		else
			print_ko("last node as head");
	}
	else if (atoi(argv[1]) == 11)
	{
		elem->next = elem2;
		elem2->next = NULL;
		if (ft_lstsize(elem) == 2 && ft_lstsize(elem) == 2)
			print_ok("repeatable result");
		else
			print_ko("repeatable result");
	}
	if (str)  free(str);
    if (str2) free(str2);
    if (str3) free(str3);
    if (str4) free(str4);
    if (str5) free(str5);
    if (elem)  free(elem);
    if (elem2) free(elem2);
    if (elem3) free(elem3);
    if (elem4) free(elem4);
    if (elem5) free(elem5);
	return (0);
}
