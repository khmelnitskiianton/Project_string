#include "head.h" 

const size_t LEN = 100;

FILE * fileopening (void)
{
    FILE *file_testing = NULL;
    if ((file_testing = fopen ("tests.txt", "r")) == NULL) //check for opening
    {
        assert(0);
    }
    return file_testing;
}

int test_solofile (int *n, char test_str[])
{   
    const char *ptr1 = my_strchr (test_str, 'a');
    my_puts (test_str);
    size_t leng = my_strlen (test_str);
    char arr2[40] = {};
    my_strcpy (arr2,test_str);
    char arr3[40] = {};
    my_strncpy (arr3,test_str, 5);
    char arr4[40] = "abcde_";
    my_strcat (arr4, test_str);
    char arr5[40] = "abcde_";
    my_strncat (arr5, test_str, 5);
    int flag = my_strcmp (test_str, "kitty");
    char *ptr2 = my_strdup(test_str);

    printf("MY --- Find \'a\': %p. Length: %d. Copy: %s. Copy,5symbols: %s. Summ: %s. Summ,5symbols: %s.str == \"kitty\"?: %d. Copy malloc: %p.\n", ptr1, leng, arr2, arr3, arr4, arr5, flag, ptr2);

    const char *ptr11 = strchr (test_str, 'a');
    size_t leng1 = strlen (test_str);
    char arr22[40] = {};
    strcpy (arr22,test_str);
    char arr33[40] = {};
    strncpy (arr33,test_str, 5);
    char arr44[40] = "abcde_";
    strcat (arr44, test_str);
    char arr55[40] = "abcde_";
    strncat (arr55, test_str, 5);
    int flag1 = strcmp (test_str, "kitty");
    char *ptr22 = my_strdup(test_str);

    printf("STD --- Find \'a\': %p. Length: %d. Copy: %s. Copy,5symbols: %s. Summ: %s. Summ,5symbols: %s.str == \"kitty\"?: %d. Copy malloc: %p.\n", ptr11, leng1, arr22, arr33, arr44, arr55, flag1, ptr22);
    
    free(ptr2);
    free(ptr22);

    /*if (strcmp())
    {
        printf ("TEST %d FAILED\n", *n);
    }
    else
    {
        printf ("TEST %d IS OK!!!\n", *n);
    }
    */
    return 1;    
}

int test_allfile (void)
{
    int counter = 1;
    FILE *file_testing = NULL;
    int lot = 0;
    
    char stroka[LEN] = "";

    file_testing = fileopening ();

    fscanf (file_testing, "%d", &lot);

    for (int i = 0; i < lot; i++)
    {   
        fscanf (file_testing, "%s", stroka);
        counter += test_solofile (&counter, stroka);
        clean_str (stroka, LEN);

    }
    if (fclose (file_testing) != 0) printf ("ERROR OF CLOSING!\n"); 

    return counter;        
}

void clean_str (char stroka[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        stroka[i] = '\0';
    }
}