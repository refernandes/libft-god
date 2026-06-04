#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../../../libft.h"

void ft_print_result(const char *s)
{
    int len = 0;
    while (s[len])
        len++;
    if (len > 0)
        write(1, s, len);
}

int main(int argc, const char *argv[])
{
    char    s1[32];
    char    s2[32];
    char    *strjoin = NULL;
    int     arg;

    alarm(5);
    if (argc == 1)
        return (0);

    arg = atoi(argv[1]);

    if (arg == 1)
    {
        s1[0] = '\0';
        s2[0] = '\0';
        ft_strlcpy(s1, "lorem ipsum", sizeof(s1));
        ft_strlcpy(s2, "dolor sit amet", sizeof(s2));
        if (!(strjoin = ft_strjoin(s1, s2)))
            ft_print_result("NULL");
        else
            ft_print_result(strjoin);
        if (strjoin == s1 || strjoin == s2)
            ft_print_result("\nA new string was not returned");
    }
    else if (arg == 2)
    {
        s1[0] = '\0';
        s2[0] = '\0';
        ft_strlcpy(s2, "dolor sit amet", sizeof(s2));
        if (!(strjoin = ft_strjoin(s1, s2)))
            ft_print_result("NULL");
        else
            ft_print_result(strjoin);
    }
    else if (arg == 3)
    {
        s1[0] = '\0';
        s2[0] = '\0';
        ft_strlcpy(s1, "lorem ipsum", sizeof(s1));
        if (!(strjoin = ft_strjoin(s1, s2)))
            ft_print_result("NULL");
        else
            ft_print_result(strjoin);
    }
    else if (arg == 4)
    {
        s1[0] = '\0';
        s2[0] = '\0';
        if (!(strjoin = ft_strjoin(s1, s2)))
            ft_print_result("NULL");
        else
            ft_print_result(strjoin);
    }
    else if (arg == 5)
    {
        char *s1 = "line1\nline2";
        char *s2 = "\ttabbed";
        if (!(strjoin = ft_strjoin(s1, s2)))
            ft_print_result("NULL");
        else
            ft_print_result(strjoin);
    }
    else if (arg == 6)
    {
        char *s1 = "São ";
        char *s2 = "Paulo";
        if (!(strjoin = ft_strjoin(s1, s2)))
            ft_print_result("NULL");
        else
            ft_print_result(strjoin);
    }
    else if (arg == 7)
    {
        // String longa gigante
        char *long1 = malloc(10001);
        char *long2 = malloc(10001);
        if (!long1 || !long2)
        {
            free(long1);
            free(long2);
            ft_print_result("NULL");
            return (0);
        }

        for (int i = 0; i < 10000; i++)
        {
            long1[i] = 'a';
            long2[i] = 'b';
        }
        long1[10000] = '\0';
        long2[10000] = '\0';

        if (!(strjoin = ft_strjoin(long1, long2)))
            ft_print_result("NULL");
        else
            ft_print_result(strjoin);   // ← AQUI é a STRING, não "OK"

        free(long1);
        free(long2);
    }
    else if (arg == 8)
    {
        char *s1 = "test";
        char *s2 = "123";
        strjoin = ft_strjoin(s1, s2);
        if (strjoin && ft_strlen(strjoin) == 7)  // 4 + 3
            ft_print_result("OK");
        else
            ft_print_result("FAIL");
    }
    else if (arg == 9)
    {
        char *s1 = "";
        char *s2 = "";
        strjoin = ft_strjoin(s1, s2);
        if (strjoin && strjoin[0] == '\0')
            ft_print_result("OK EMPTY");
        else
            ft_print_result("FAIL EMPTY");
    }
    else if (arg == 10)
    {
        char *s1 = "abc";
        char *s2 = "";
        strjoin = ft_strjoin(s1, s2);
        if (strjoin && strcmp(strjoin, "abc") == 0)
            ft_print_result("OK ABC");
        else
            ft_print_result("FAIL ABC");
    }
    if (strjoin != NULL)
        free(strjoin);
    return (0);
}
