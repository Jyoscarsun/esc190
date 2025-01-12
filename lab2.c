# include <stdio.h>
# include <ctype.h>
void set_string(char **str, int *len)
{
    printf("Enter the number of characters in the string: ");
    int strlen;
    scanf("%d", &strlen);
    *str = (char *)malloc(sizeof(char)*strlen);
    len = strlen;
    int i = 0;
    while(i < strlen)
    {
        printf("Enter character: ");
        scanf(" %c", *str + i);
        &(*str)[i];
        i++;
    }
    *(*str + strlen) = '\0';
    (*str)[strlen] = '\0';
    printf("%s\n", *str);
}

char * cat_string(char *str1, char *str2)
{
    char *str = (char *)malloc(sizeof(char)*(strlen(str1)+strlen(str2)));
    int counter = 0;
    while(counter <= strlen(str1))
    {
        *(str + counter) = *(str1 + counter);
        counter++;
    }
    counter = 0;
    while(counter <= strlen(str2))
    {
        *(str + strlen(str1) + counter) = *(str2 + counter);
        counter++;
    }
    *(str + strlen(str1) + strlen(str2) + 1) = '\0';
    return str;
}

char * cat_stringv2(char *str1, char*str2)
{
    char *str = (char *)malloc(sizeof(char)*(strlen(str1)+strlen(str2)));
    strcat(*str1, str2);
}

int strcmp(char *str1, char *str2)
{
    if(strlen(str1) != strlen(str2))
    {
        return 1;
    }
    if(strlen(str1) == 1 & str1[0] == str2[0])
    {
        return 0;
    }
    else
    {
        if(str1[0] != str2[0])
        {
            return 1;
        }
        else
        {
            return strcmp(str1+1, str2+1);
        }
    }
}

int my_atoi(char *str)
{
    int res = 0;
    while(*str != '\0')
    {
        if(isdigit(*str))
        {
            res = res*10 + *str-'0';
        }
        *str++;
    }
    return res;
}

int main()
{
    // char *str1 = "happy ";
    // char *str2 = "birthday";
    // printf("%s\n", cat_stringv2(str1, str2));

    char *str3;
    int *len;
    set_string(&str3, len);
    printf("%s\n", str3);
    free(str3);

    // char str1[] = "abcd", str2[] = "abCd", str3[] = "abcd";
    // int result;

    // result = strcmp(str1, str2);
    // printf("strcmp(str1, str2) = %d\n", result);

    // result = strcmp(str1, str3);
    // printf("strcmp(str1, str3) = %d\n", result);
    // s1 == s2 checks for whether s1 and s2 has the same pointer (address of s1, s2)
    // *s1 == *s2 checks for whether the pointer of s1 and s2 has the same value
    // (i.e. whether the first character of s1 and s2 are the same)
    // strcmp(s1, s2) checks for whether the contents of strings s1/s2 are the same
    // Remember: * always access the value at an address, & always access the address of a value
    // * only access the address when it is in definition of a pointer

    // char *str = "123894";
    // int num = my_atoi(str);
    // printf("%d\n", num);
}