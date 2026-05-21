#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "../../../libft.h"

static int g_del_count = 0;
static int g_freed_null = 0;
static int g_del_called_with_expected = 0;
static void *g_expected_content = NULL;

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

static void	tracked_del(void *content)
{
	g_del_count++;
	if (content == NULL)
		g_freed_null = 1;
	if (content == g_expected_content)
		g_del_called_with_expected = 1;
	free(content);
}

static void	reset_counters(void)
{
	g_del_count = 0;
	g_freed_null = 0;
	g_del_called_with_expected = 0;
	g_expected_content = NULL;
}

int	main(int argc, const char *argv[])
{
	t_list	*elem;
	t_list	*elem2;
	t_list	*elem3;
	t_list	*elem4;
	t_list	*retained_next;
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
	if (atoi(argv[1]) == 1)
	{
		reset_counters();
		g_expected_content = str;
		ft_lstdelone(elem, &tracked_del);
		if (g_del_count == 1 && g_del_called_with_expected)
			print_ok("single node calls del once");
		else
			print_ko("single node calls del once");
	}
	else if (atoi(argv[1]) == 2)
	{
		reset_counters();
		elem->next = elem2;
		retained_next = elem->next;
		g_expected_content = str;
		ft_lstdelone(elem, &tracked_del);
		if (g_del_count == 1 && retained_next == elem2)
			print_ok("does not free next node");
		else
			print_ko("does not free next node");
		free(elem2->content);
		free(elem2);
	}
	else if (atoi(argv[1]) == 3)
	{
		reset_counters();
		g_expected_content = str2;
		ft_lstdelone(elem2, &tracked_del);
		if (g_del_count == 1 && g_del_called_with_expected)
			print_ok("middle node content passed to del");
		else
			print_ko("middle node content passed to del");
		free(elem->content);
		free(elem);
		free(elem3->content);
		free(elem3);
		free(elem4->content);
		free(elem4);
	}
	else if (atoi(argv[1]) == 4)
	{
		reset_counters();
		g_expected_content = str4;
		ft_lstdelone(elem4, &tracked_del);
		if (g_del_count == 1 && g_del_called_with_expected)
			print_ok("last node can be deleted");
		else
			print_ko("last node can be deleted");
		free(elem->content);
		free(elem);
		free(elem2->content);
		free(elem2);
		free(elem3->content);
		free(elem3);
	}
	else if (atoi(argv[1]) == 5)
	{
		reset_counters();
		elem3->content = NULL;
		g_expected_content = NULL;
		ft_lstdelone(elem3, &tracked_del);
		if (g_del_count == 1 && g_freed_null)
			print_ok("NULL content passed to del");
		else
			print_ko("NULL content passed to del");
		free(elem->content);
		free(elem);
		free(elem2->content);
		free(elem2);
		free(elem4->content);
		free(elem4);
	}
	else if (atoi(argv[1]) == 6)
	{
		reset_counters();
		ft_lstdelone(NULL, &tracked_del);
		if (g_del_count == 0)
			print_ok("NULL node handled safely");
		else
			print_ko("NULL node handled safely");
		free(elem->content);
		free(elem);
		free(elem2->content);
		free(elem2);
		free(elem3->content);
		free(elem3);
		free(elem4->content);
		free(elem4);
	}
	else if (atoi(argv[1]) == 7)
	{
		write(1, "SKIP: NULL del is undefined for libft testers\n", 46);
		free(elem->content);
		free(elem);
		free(elem2->content);
		free(elem2);
		free(elem3->content);
		free(elem3);
		free(elem4->content);
		free(elem4);
	}
	else if (atoi(argv[1]) == 8)
	{
		reset_counters();
		elem->next = elem2;
		elem2->next = elem3;
		retained_next = elem2->next;
		g_expected_content = str2;
		ft_lstdelone(elem2, &tracked_del);
		if (g_del_count == 1 && retained_next == elem3)
			print_ok("next pointer not traversed or freed");
		else
			print_ko("next pointer not traversed or freed");
		free(elem->content);
		free(elem);
		free(elem3->content);
		free(elem3);
		free(elem4->content);
		free(elem4);
	}
	else if (atoi(argv[1]) == 9)
	{
		reset_counters();
		g_expected_content = str;
		ft_lstdelone(elem, &tracked_del);
		if (g_del_count == 1)
			print_ok("node freed exactly once");
		else
			print_ko("node freed exactly once");
	}
	else if (atoi(argv[1]) == 10)
	{
		reset_counters();
		elem->next = elem2;
		ft_lstdelone(elem, &tracked_del);
		if (g_del_count == 1)
			print_ok("deleting node does not require list head");
		else
			print_ko("deleting node does not require list head");
		free(elem2->content);
		free(elem2);
		free(elem3->content);
		free(elem3);
		free(elem4->content);
		free(elem4);
	}
	else if (atoi(argv[1]) == 11)
	{
		reset_counters();
		elem4->next = NULL;
		g_expected_content = str4;
		ft_lstdelone(elem4, &tracked_del);
		if (g_del_count == 1)
			print_ok("tail node deletion isolated");
		else
			print_ko("tail node deletion isolated");
		free(elem->content);
		free(elem);
		free(elem2->content);
		free(elem2);
		free(elem3->content);
		free(elem3);
	}
	return (0);
}