/*
* The function allocates (with malloc(3)) and returns a new
* string, which is the result of the concatenation of ’s1’ and ’s2’.
* Return: the new string, NULL if the allocation fails.
*/
#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *str;
    size_t  s1_len;
    size_t  s2_len;

    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);

    str = malloc(s1_len + s2_len + 1);
    if (!str)
    {
        return (NULL);
    }
    ft_memcpy(str, s1, s1_len);
    ft_memcpy(str + s1_len, s2, s2_len);
    str[s1_len + s2_len] = '\0';
    return (str);
}