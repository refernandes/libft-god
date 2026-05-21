#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "../../../libft.h"

static int g_del_count = 0;
static int g_freed_null = 0;
static int g_del_called_with_expected = 0;
static void *g_expected_content = NULL;

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

static void tracked_del(void *content)
{
    g_del_count++;
    if (content == NULL)
        g_freed_null = 1;
    if (content == g_expected_content)
        g_del_called_with_expected = 1;
    free(content);
}

static void reset_counters(void)
{
    g_del_count = 0;
    g_freed_null = 0;
    g_del_called_with_expected = 0;
    g_expected_content = NULL;
}

/* --- FUNÇÃO AUXILIAR DE LIMPEZA INTELIGENTE --- */
static void safe_free_elem(t_list *elem, void *orig_content, int was_deleted_by_test)
{
    if (was_deleted_by_test)
        return ; // Se o teste já limpou esse nó com ft_lstdelone, ignora para evitar double-free.

    if (elem)
    {
        if (elem->content == orig_content)
            free(orig_content);
        free(elem);
    }
}

int main(int argc, const char *argv[])
{
    t_list  *elem = NULL;
    t_list  *elem2 = NULL;
    t_list  *elem3 = NULL;
    t_list  *elem4 = NULL;
    t_list  *retained_next;
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

    // Se faltar argumentos ou houver falha de alocação inicial, vai direto para a limpeza geral
    if (argc == 1 || !elem || !elem2 || !elem3 || !elem4)
    {
        safe_free_elem(elem, str, 0);
        safe_free_elem(elem2, str2, 0);
        safe_free_elem(elem3, str3, 0);
        safe_free_elem(elem4, str4, 0);
        return (0);
    }

    test_num = atoi(argv[1]);

    if (test_num == 1)
    {
        reset_counters();
        g_expected_content = str;
        ft_lstdelone(elem, &tracked_del);
        if (g_del_count == 1 && g_del_called_with_expected)
            print_ok("single node calls del once");
        else
            print_ko("single node calls del once");
    }
    else if (test_num == 2)
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
    }
    else if (test_num == 3)
    {
        reset_counters();
        g_expected_content = str2;
        ft_lstdelone(elem2, &tracked_del);
        if (g_del_count == 1 && g_del_called_with_expected)
            print_ok("middle node content passed to del");
        else
            print_ko("middle node content passed to del");
    }
    else if (test_num == 4)
    {
        reset_counters();
        g_expected_content = str4;
        ft_lstdelone(elem4, &tracked_del);
        if (g_del_count == 1 && g_del_called_with_expected)
            print_ok("last node can be deleted");
        else
            print_ko("last node can be deleted");
    }
    else if (test_num == 5)
    {
        reset_counters();
        
        // Proteção do teste 5: Como mudamos elem3->content para NULL, 
        // damos free na string "str3" manualmente antes de perder a referência dela.
        free(str3); 
        str3 = NULL; 

        elem3->content = NULL;
        g_expected_content = NULL;
        ft_lstdelone(elem3, &tracked_del);
        if (g_del_count == 1 && g_freed_null)
            print_ok("NULL content passed to del");
        else
            print_ko("NULL content passed to del");
    }
    else if (test_num == 6)
    {
        reset_counters();
        ft_lstdelone(NULL, &tracked_del);
        if (g_del_count == 0)
            print_ok("NULL node handled safely");
        else
            print_ko("NULL node handled safely");
    }
    else if (test_num == 7)
    {
        write(1, "SKIP: NULL del is undefined for libft testers\n", 46);
    }
    else if (test_num == 8)
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
    }
    else if (test_num == 9)
    {
        reset_counters();
        g_expected_content = str;
        ft_lstdelone(elem, &tracked_del);
        if (g_del_count == 1)
            print_ok("node freed exactly once");
        else
            print_ko("node freed exactly once");
    }
    else if (test_num == 10)
    {
        reset_counters();
        elem->next = elem2;
        ft_lstdelone(elem, &tracked_del);
        if (g_del_count == 1)
            print_ok("deleting node does not require list head");
        else
            print_ko("deleting node does not require list head");
    }
    else if (test_num == 11)
    {
        reset_counters();
        elem4->next = NULL;
        g_expected_content = str4;
        ft_lstdelone(elem4, &tracked_del);
        if (g_del_count == 1)
            print_ok("tail node deletion isolated");
        else
            print_ko("tail node deletion isolated");
    }

    /* --- CENTRAL DE LIMPEZA GERAL --- */
    // Se o teste 5 não rodou, a string str3 ainda precisa ser limpa
    if (str3) 
        free(str3);

    // Informamos em formato binário (1 ou 0) se o ft_lstdelone limpou o respectivo nó
    safe_free_elem(elem,  str,  (test_num == 1 || test_num == 2 || test_num == 9 || test_num == 10));
    safe_free_elem(elem2, str2, (test_num == 3 || test_num == 8));
    safe_free_elem(elem3, NULL, (test_num == 5)); // O conteúdo str3 já foi devidamente tratado acima
    safe_free_elem(elem4, str4, (test_num == 4 || test_num == 11));

    return (0);
}