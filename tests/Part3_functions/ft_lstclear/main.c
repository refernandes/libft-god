#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "../../../libft.h"

static int g_del_count = 0;
static int g_del_null_count = 0;
static int g_expected_hits = 0;
static void *g_expected[8];
static int g_expected_len = 0;

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

static void	reset_counters(void)
{
	g_del_count = 0;
	g_del_null_count = 0;
	g_expected_hits = 0;
	g_expected_len = 0;
}

static void	set_expected(void **arr, int len)
{
	int i;

	i = 0;
	g_expected_len = len;
	while (i < len)
	{
		g_expected[i] = arr[i];
		i++;
	}
}

static void	tracked_del(void *content)
{
	int i;

	g_del_count++;
	if (content == NULL)
		g_del_null_count++;
	i = 0;
	while (i < g_expected_len)
	{
		if (g_expected[i] == content)
			g_expected_hits++;
		i++;
	}
	free(content);
}

int	main(int argc, const char *argv[])
{
	t_list	*head;
	t_list	*elem;
	t_list	*elem2;
	t_list	*elem3;
	t_list	*elem4;
	t_list	*elem5;
	char	*str;
	char	*str2;
	char	*str3;
	char	*str4;
	char	*str5;
	void	*expected[5];

	str = dupstr("lorem");
	str2 = dupstr("ipsum");
	str3 = dupstr("dolor");
	str4 = dupstr("sit");
	str5 = dupstr("amet");
	elem = ft_lstnewone(str);
	elem2 = ft_lstnewone(str2);
	elem3 = ft_lstnewone(str3);
	elem4 = ft_lstnewone(str4);
	elem5 = ft_lstnewone(str5);
	alarm(5);
	if (argc == 1 || !elem || !elem2 || !elem3 || !elem4 || !elem5)
		return (0);
	if (atoi(argv[1]) == 1)
	{
		reset_counters();
		head = NULL;
		ft_lstclear(&head, &tracked_del);
		if (head == NULL && g_del_count == 0)
			print_ok("NULL list pointer target");
		else
			print_ko("NULL list pointer target");
		free(elem->content); free(elem);
		free(elem2->content); free(elem2);
		free(elem3->content); free(elem3);
		free(elem4->content); free(elem4);
		free(elem5->content); free(elem5);
	}
	else if (atoi(argv[1]) == 2)
	{
		reset_counters();
		head = elem;
		expected[0] = str;
		set_expected(expected, 1);
		ft_lstclear(&head, &tracked_del);
		if (head == NULL && g_del_count == 1 && g_expected_hits == 1)
			print_ok("single node cleared");
		else
			print_ko("single node cleared");
		free(elem2->content); free(elem2);
		free(elem3->content); free(elem3);
		free(elem4->content); free(elem4);
		free(elem5->content); free(elem5);
	}
	else if (atoi(argv[1]) == 3)
	{
		reset_counters();
		head = elem;
		elem->next = elem2;
		expected[0] = str;
		expected[1] = str2;
		set_expected(expected, 2);
		ft_lstclear(&head, &tracked_del);
		if (head == NULL && g_del_count == 2 && g_expected_hits == 2)
			print_ok("two nodes cleared");
		else
			print_ko("two nodes cleared");
		free(elem3->content); free(elem3);
		free(elem4->content); free(elem4);
		free(elem5->content); free(elem5);
	}
	else if (atoi(argv[1]) == 4)
	{
		reset_counters();
		head = elem;
		elem->next = elem2;
		elem2->next = elem3;
		elem3->next = elem4;
		expected[0] = str;
		expected[1] = str2;
		expected[2] = str3;
		expected[3] = str4;
		set_expected(expected, 4);
		ft_lstclear(&head, &tracked_del);
		if (head == NULL && g_del_count == 4 && g_expected_hits == 4)
			print_ok("four nodes cleared");
		else
			print_ko("four nodes cleared");
		free(elem5->content); free(elem5);
	}
	else if (atoi(argv[1]) == 5)
	{
		reset_counters();
		head = elem3;
		elem3->next = elem4;
		elem4->next = elem5;
		expected[0] = str3;
		expected[1] = str4;
		expected[2] = str5;
		set_expected(expected, 3);
		ft_lstclear(&head, &tracked_del);
		if (head == NULL && g_del_count == 3 && g_expected_hits == 3)
			print_ok("clear from middle node onward");
		else
			print_ko("clear from middle node onward");
		free(elem->content); free(elem);
		free(elem2->content); free(elem2);
	}
	else if (atoi(argv[1]) == 6)
	{
		reset_counters();
		head = elem;
		elem->next = elem2;
		elem2->next = elem3;
		elem3->content = NULL;
		expected[0] = str;
		expected[1] = str2;
		expected[2] = NULL;
		set_expected(expected, 3);
		ft_lstclear(&head, &tracked_del);
		if (head == NULL && g_del_count == 3 && g_del_null_count == 1)
			print_ok("NULL content nodes cleared");
		else
			print_ko("NULL content nodes cleared");
		free(elem4->content); free(elem4);
		free(elem5->content); free(elem5);
	}
	else if (atoi(argv[1]) == 7)
	{
		reset_counters();
		ft_lstclear(NULL, &tracked_del);
		if (g_del_count == 0)
			print_ok("NULL lst handled safely");
		else
			print_ko("NULL lst handled safely");
		free(elem->content); free(elem);
		free(elem2->content); free(elem2);
		free(elem3->content); free(elem3);
		free(elem4->content); free(elem4);
		free(elem5->content); free(elem5);
	}
	else if (atoi(argv[1]) == 8)
	{
		write(1, "SKIP: NULL del is undefined for libft testers\n", 46);
		free(elem->content); free(elem);
		free(elem2->content); free(elem2);
		free(elem3->content); free(elem3);
		free(elem4->content); free(elem4);
		free(elem5->content); free(elem5);
	}
	else if (atoi(argv[1]) == 9)
	{
		reset_counters();
		head = elem;
		elem->next = elem2;
		elem2->next = elem3;
		ft_lstclear(&head, &tracked_del);
		if (head == NULL)
			print_ok("head pointer reset to NULL");
		else
			print_ko("head pointer reset to NULL");
		free(elem4->content); free(elem4);
		free(elem5->content); free(elem5);
	}
	else if (atoi(argv[1]) == 10)
	{
		reset_counters();
		head = elem2;
		elem2->next = elem3;
		elem3->next = elem4;
		ft_lstclear(&head, &tracked_del);
		if (head == NULL && g_del_count == 3)
			print_ok("does not require original head");
		else
			print_ko("does not require original head");
		free(elem->content); free(elem);
		free(elem5->content); free(elem5);
	}
	else if (atoi(argv[1]) == 11)
	{
		reset_counters();
		head = elem;
		elem->next = elem2;
		elem2->next = NULL;
		ft_lstclear(&head, &tracked_del);
		if (head == NULL && g_del_count == 2)
			print_ok("repeatable after becoming NULL");
		else
			print_ko("repeatable after becoming NULL");
		reset_counters();
		ft_lstclear(&head, &tracked_del);
		if (head == NULL && g_del_count == 0)
			print_ok("second clear on NULL safe");
		else
			print_ko("second clear on NULL safe");
		free(elem3->content); free(elem3);
		free(elem4->content); free(elem4);
		free(elem5->content); free(elem5);
	}
	return (0);
}