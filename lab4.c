# include<stdio.h>
typedef struct student1{
    char name[3];
    int age;
    // Does not have an equivalent in Python
    // Python objects have to have attributes passed into them when creating the object
    // C just has to have the attributes declared in the struct, the attributes could be left empty in object declaration
} student1;


void change_name1_wrong(student1 s)
{
    s.name[0] = 'b';
    /*
    Does not have an equivalent in Python
    In Python, if a list is passed into a function, any modification within the function
    would change the elemental value in the array because Python changes the value at the memory location
    This would not work for C, however, because all modifications are local, makes a copy of student1 
    */

}

void change_name1_right_a(student1 *p_s)
{
    p_s->name[0] = 'b';
    /*
    Does not have an equivalent in Python
    Any modification done in C functions require the memory address
    to be passed into the function such that C can modify
    It is not possible to pass memory addresses into Python function
    */
}
void change_name1_right_b(student1 *p_s)
{
    strcpy(p_s->name, "b");
    /*
    Does not have an equivalent in Python
    Also pass memory location into the function, but instead of character changes
    The character "b" is passed in as a string
    */
}

void change_name(student1 *p_s, char *new_name)
{
    strcpy(p_s->name, new_name);
}

int main()
{
    student1 s1 = {"Jiayu Li", 69};
    change_name(&s1, "John");
    printf("%s\n", s1.name);
}
