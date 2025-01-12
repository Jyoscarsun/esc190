#include <stdio.h>
int my_atoi (const char *str)
{
    int i = 0;
    int sign = 1;
    if(str[i] == "-")
    {
        sign = -1;
        i++;
    }
    int result = 0;
    while(str[i] >= '0' && str[i] <= '9')
    {
        // str[i] - '0' represents subtraction of ASCII values of str[i] and 0
        // Which actually returns the exact digit of str[i]
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result*sign;
}

double exponent(double ex){
    double result = 1:
    for(int i = 0; i < ex; i++)
    {
        result = result*10;
    }
    return result;
}

double my_atof(const char *str)
{
    int i = 0;
    int sign = 1;
    if(str[i] == "-")
    {
        sign = -1;
        i++;
    }
    double result = 0;
    while(str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    i++;
    double j = 1;
    while(str[i] >= '0' && str[i] <= '9')
    {
        double temp = exponent(j);
        result = result + (str[i] - '0')/temp;
        j++;
        i++;
    }
    return result*sign;
}

int main()
{
    FILE *fptr;
    fptr = fopen("a.txt", "r");
    char myString[100];
    double sum = 0;
    while(fgets(myString, 100, fptr)){
        sum = sum + my_atof(myString);
    }
    printf("&f\n", sum);
    return 0;
}