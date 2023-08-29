#include "mystring.h"


void my_puts(const char word[])
{
    int i = 0;
    char ch = '\n';
    while ((ch = word[i]) != '\0')
    {
        putchar (ch);
        i++;
    }
    putchar ('\n');
}

const char * my_strchr (const char word[], int symbol)
{
    int i = 0;
    char ch = 0;
    while ( (ch = word[i]) != symbol)
        i++;
    return &word[i];
}

size_t my_strlen(const char word[])
{
    int i = 0;
    char ch = 0;
    while ((ch = word[i]) != '\0')
        i++;
    return i;
}

char * my_strcpy(char dest[], const char src[])
{
    size_t i = 0;
    while(src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }    
    dest[i] = '\0';
    return dest;
}

char * my_strncpy(char dest[], const char src[], size_t num)
{
    size_t i = 0;
    while ((src[i] != '\0') && (i < num))
    {
        dest[i] = src[i];
        i++;
    }
    if (src[i] == '\0')
        dest[i] = '\0';
    return dest;
}

char * my_strcat(char dest[], const char src[])
{
    size_t i = 0;
    while (dest[i] != '\0')
        i++;
    size_t j = 0;
    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}

char * my_strncat( char dest[], const char src[], size_t num)
{
    size_t i = 0;
    while (dest[i] != '\0')
        i++;
    size_t j = 0;
    while ((src[j] != '\0')&&(j < num))
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}

char * my_fgets( char word[], size_t num, FILE * filestream )
{
    size_t i = 0;
    int flag = 1; 
    char ch = 0;
    while ((i < num) && flag )
    {
        ch = getc(filestream);
        if (ch == '\n')
            flag = 0;
        word[i] = ch;
        i++;
    }
    word[i] = '\0';
    return word;
}

int my_strcmp(const char str1[], const char str2[])
{
    size_t i = 0;

    while ((str1[i] != '\0') && (str2[i] != '\0'))
    {
        if (str1[i] != str2[i]) 
        {  
            if (str2[i] > str1[i])
                return -1;
            else
                return 1;
        }
        i++;
    }

    if (str1[i] == '\0') 
        return -1;
    if (str2[i] == '\0')
        return 1;

    return 0;
}
