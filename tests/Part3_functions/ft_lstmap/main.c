#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "../../../libft.h"

static int g_map_calls = 0;
static int g_del_calls = 0;
static int g_fail_on_call = -1;
static int g_del_null_calls = 0;

static void print_ok(char *msg)
{
    write(1, "OK: ", 4);
    write(1, msg, strlen(msg));
    write(1, "\n", 1);
}

static void print_ko(char *msg)
{
    write(1, "KO: ", 4);
    write(1, msg, strlen(msg));
    write(1, "\n", 1);
}

static t_list   *ft_lstnewone(void *content)
{
    t_list  *elem;

    elem = (t_list *)malloc(sizeof(t_list));
    if (!elem)
        return (NULL);
    elem->content = content;
    elem->next = NULL;
    return (elem);
}

static char *dupstr(const char *s)
{
    size_t  len;
    char    *out;

    len = strlen(s);
    out = (char *)malloc(len + 1);
    if (!out)
        return (NULL);
    memcpy(out, s, len + 1);
    return (out);
}

static void reset_counters(void)
{
    g_map_calls = 0;
    g_del_calls = 0;
    g_fail_on_call = -1;
    g_del_null_calls = 0;
}

static void *map_dup_replace_o(void *content)
{
    char    *src;
    char    *dst;
    int     i;

    g_map_calls++;
    if (g_fail_on_call == g_map_calls)
        return (NULL);
    if (content == NULL)
        return (NULL);
    src = (char *)content;
    dst = dupstr(src);
    if (!dst)
        return (NULL);
    i = 0;
    while (dst[i])
    {
        if (dst[i] == 'o')
            dst[i] = 'a';
        i++;
    }
    return (dst);
}

static void tracked_del(void *content)
{
    g_del_calls++;
    if (content == NULL)
    {
        g_del_null_calls++;
        return ;
    }
    free(content);
}

static int  str_eq(char *a, char *b)
{
    if (!a || !b)
        return (0);
    return (strcmp(a, b) == 0);
}

int main(int argc, const char *argv[])
{
    t_list  *elem = NULL;
    t_list  *elem2 = NULL;
    t_list  *elem3 = NULL;
    t_list  *elem4 = NULL;
    t_list  *mapped = NULL;
    char    *str = NULL;
    char    *str2 = NULL;
    char    *str3 = NULL;
    char    *str4 = NULL;
    int     test_num = 0;

    str = dupstr("lorem");
    str2 = dupstr("ipsum");
    str3 = dupstr("dolor");
    str4 = dupstr("sit");
    elem = ft_lstnewone(str);
    elem2 = ft_lstnewone(str2);
    elem3 = ft_lstnewone(str3);
    elem4 = ft_lstnewone(str4);
    alarm(5);

    // Proteção contra leaks caso o programa feche no início
    if (argc == 1 || !elem || !elem2 || !elem3 || !elem4)
    {
        if (str)  free(str);
        if (str2) free(str2);
        if (str3) free(str3);
        if (str4) free(str4);
        if (elem)  free(elem);
        if (elem2) free(elem2);
        if (elem3) free(elem3);
        if (elem4) free(elem4);
        return (0);
    }

    elem->next = elem2;
    elem2->next = elem3;
    elem3->next = elem4;
    test_num = atoi(argv[1]);

    if (test_num == 1)
    {
        reset_counters();
        mapped = ft_lstmap(elem, &map_dup_replace_o, &tracked_del);
        if (mapped
            && mapped != elem
            && str_eq(mapped->content, "larem")
            && str_eq(mapped->next->content, "ipsum")
            && str_eq(mapped->next->next->content, "dalar")
            && str_eq(mapped->next->next->next->content, "sit"))
            print_ok("maps all nodes into a new list");
        else
            print_ko("maps all nodes into a new list");
        ft_lstclear(&mapped, &tracked_del);
    }
    else if (test_num == 2)
    {
        reset_counters();
        mapped = ft_lstmap(NULL, &map_dup_replace_o, &tracked_del);
        if (mapped == NULL && g_map_calls == 0 && g_del_calls == 0)
            print_ok("NULL list returns NULL");
        else
            print_ko("NULL list returns NULL");
    }
    else if (test_num == 3)
    {
        reset_counters();
        mapped = ft_lstmap(elem, NULL, &tracked_del);
        if (mapped == NULL)
            print_ok("NULL f handled safely");
        else
            print_ko("NULL f handled safely");
    }
    else if (test_num == 4)
    {
        reset_counters();
        mapped = ft_lstmap(elem, &map_dup_replace_o, NULL);
        if (mapped == NULL)
            print_ok("NULL del handled safely");
        else
            print_ko("NULL del handled safely");
        if (mapped)
            ft_lstclear(&mapped, &tracked_del);
    }
    else if (test_num == 5)
    {
        reset_counters();
        g_fail_on_call = 3;
        mapped = ft_lstmap(elem, &map_dup_replace_o, &tracked_del);
        if (mapped == NULL && g_map_calls == 3 && g_del_calls == 2)
            print_ok("allocation failure clears partial new list");
        else
            print_ko("allocation failure clears partial new list");
    }
    else if (test_num == 6)
    {
        reset_counters();
        mapped = ft_lstmap(elem, &map_dup_replace_o, &tracked_del);
        if (mapped && mapped->content != elem->content
            && mapped->next->content != elem2->content
            && mapped->next->next->content != elem3->content)
            print_ok("new contents are duplicated");
        else
            print_ko("new contents are duplicated");
        ft_lstclear(&mapped, &tracked_del);
    }
    else if (test_num == 7)
    {
        reset_counters();
        mapped = ft_lstmap(elem, &map_dup_replace_o, &tracked_del);
        if (mapped && str_eq(elem->content, "lorem") && str_eq(elem3->content, "dolor"))
            print_ok("original list unchanged");
        else
            print_ko("original list unchanged");
        ft_lstclear(&mapped, &tracked_del);
    }
    else if (test_num == 8)
    {
        reset_counters();
        
        free(str);
        str = NULL;

        elem->content = NULL;
        mapped = ft_lstmap(elem, &map_dup_replace_o, &tracked_del);
        if (mapped == NULL && g_map_calls == 1 && g_del_calls == 0)
            print_ok("NULL content in first node handled");
        else
            print_ko("NULL content in first node handled");
    }
    else if (test_num == 9)
    {
        reset_counters();
        mapped = ft_lstmap(elem2, &map_dup_replace_o, &tracked_del);
        if (mapped
            && str_eq(mapped->content, "ipsum")
            && str_eq(mapped->next->content, "dalar")
            && str_eq(mapped->next->next->content, "sit")
            && mapped->next->next->next == NULL)
            print_ok("maps from middle node onward");
        else
            print_ko("maps from middle node onward");
        ft_lstclear(&mapped, &tracked_del);
    }
    else if (test_num == 10)
    {
        reset_counters();
        mapped = ft_lstmap(elem4, &map_dup_replace_o, &tracked_del);
        if (mapped && mapped->next == NULL && str_eq(mapped->content, "sit"))
            print_ok("single tail node mapping");
        else
            print_ko("single tail node mapping");
        ft_lstclear(&mapped, &tracked_del);
    }
    else if (test_num == 11)
    {
        reset_counters();
        mapped = ft_lstmap(elem, &map_dup_replace_o, &tracked_del);
        if (mapped && g_map_calls == 4)
            print_ok("f called once per node");
        else
            print_ko("f called once per node");
        ft_lstclear(&mapped, &tracked_del);
    }

    /* --- CENTRAL DE LIMPEZA GERAL --- */
    if (str)  free(str);
    if (str2) free(str2);
    if (str3) free(str3);
    if (str4) free(str4);

    if (elem)  free(elem);
    if (elem2) free(elem2);
    if (elem3) free(elem3);
    if (elem4) free(elem4);

    return (0);
}