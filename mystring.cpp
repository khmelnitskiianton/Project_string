
#include "head.h"

int my_puts (const char word[])
{
    size_t i = 0;
    while (word[i] != '\0')
    { 
        if (putchar (word[i]) == EOF)
            return EOF;
        i++;
    }
    putchar ('\n');
    return 0;
}

const char* my_strchr (const char word[], int symbol)
{
    size_t i = 0;

    for (i = 0; (word[i] != symbol)&&(word[i] != '\0'); ++i)
    {}

    if (word[i] == '\0')
        return nullptr;

    return &word[i];

}

size_t my_strlen (const char word[])
{
    size_t i = 0;
    for (i = 0; word[i]; ++i)
    {}
    return i;
}

char* my_strcpy (char dest[], const char src[])
{
    size_t i = 0;

    for (i = 0; src[i]; ++i)
        dest[i] = src[i];

    dest[i] = '\0';
    return dest;
}

char* my_strncpy (char dest[], const char src[], size_t num)
{
    size_t i = 0;
    for (i = 0; (src[i] != '\0') && (i < num); ++i)
        dest[i] = src[i];

    if (src[i] == '\0')
        dest[i] = '\0';
    return dest;
}

char* my_strcat (char dest[], const char src[])
{
    size_t i = 0;
    for (i = 0; dest[i]; ++i) 
    {}

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

char* my_strncat (char dest[], const char src[], size_t num)
{
    size_t i = 0;
    for (i = 0; dest[i]; ++i) 
    {}

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

char* my_fgets ( char word[], size_t num, FILE * filestream )
{
    size_t i = 0;
    int flag = 1; 
    char ch = 0;
    while ((i < num) && flag )
    {
        ch = getc(filestream);
        if (ch == EOF)
            return nullptr;

        if (ch == '\n')
            flag = 0;
        word[i] = ch;
        i++;
    }
    word[i] = '\0';
    return word;
}

int my_strcmp (const char str1[], const char str2[])
{
    size_t i = 0;
    for (i = 0; (str1[i] != '\0') && (str2[i] != '\0'); ++i)
    {
        if (str1[i] != str2[i]) 
        {  
            if (str2[i] > str1[i])
                return -1;
            else
                return 1;
        }
    }

    if ((str1[i] == '\0') && (str2[i] == '\0'))
        return 0;

    if (str1[i] == '\0')
        return -1;

    if (str2[i] == '\0')
        return 1;
}

char* my_strdup (const char * src)
{
    if (src == NULL)
        return NULL;
        
	size_t j = 0;
	for (j = 0; src[j]; ++j)
    {}

	size_t length = j+1;

	char *ptr = (char *) malloc (length * sizeof (char));

    if (ptr == NULL)
        return NULL;

	for (size_t i = 0; i < length; i++)
		ptr[i] = src[i];

    ptr[length-1] = '\0';

	return ptr; 
}
