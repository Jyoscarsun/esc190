#include <stdio.h>
#include <string.h>
#include "student1.h"
#include <stdlib.h>
// Would have no impact on the value of x
void set_int1(int x)
{
    x = 42;
    // Change the local variable value of x, 
    // does not change global value of x passed into the function
}

// Would be impactful
void set_int2(int *p_x)
{
    *p_x = 42;
    // Pass in the memory location of x
    // Go the memory location of x and change the value there to 42
}

typedef struct student2{
    char *name;
    char *student_number;
    int year;
} student2;

void print_student(student1 s)
{
    printf("Name: %s\n", s.name);
    printf("Student Number: %s\n", s.student_number);
    printf("Year: %d\n", s.year);
}

void set_default_name(student1 *p_s)
{
    strcpy(p_s->name, "Default Student");
    p_s->year = 0;
}

// void set_default_name_wrong(student1 s)
// {
//     s.name = "Default Student"; //This is wrong, cannot change the name
//     s.year = 0; //This is wrong, have to pass the memory location of s
// }

student1 * create_block1(student1 **p_p_s, int n_students)
{
    student1 *student_arr = (student1 *)malloc(sizeof(student1)*n_students);
    *p_p_s = student_arr;
    return student_arr;
}

void set_name(student1 *p_s, char *newname)
{
    if(strlen(newname) > 199){
        newname[199] = '\0';
    } else {
        strcpy(p_s->name, newname);
    }
}

void destroy_block1(student1 *p_p_s)
{
    free(p_p_s);
}

student2 * create_block2(student2 **p_p_s, int num_students)
{
    student2 *student_arr = (student2 *)malloc(sizeof(student2)*num_students);
    *p_p_s = student_arr;
    for(int i = 0; i < num_students; i++)
    {
        student_arr[i].name = "0";
        student_arr[i].student_number = "0";
    }
    return student_arr;
}

void set_name2(student2 *p_s, char *newname)
{
    p_s->name = (char *)malloc(sizeof(char)*strlen(newname)+1);
    strcpy(p_s->name, newname);
}

void destroy_block2(student2 *p_s, int num_students)
{
    for(int i = 0; i < num_students; i++)
    {
        free(p_s[i].name);
        free(p_s[i].student_number);
    }
    free(p_s);
}

void setname(student1 *p_s1, student2 *p_s2, char *newname)
{
    // p_s1->name = newname; 
    // This would not work because p_s1-> name is an array of characters
    // cannot reassign an string to an array
    p_s2->name = newname;
    // This would work because p_s2->name is a pointer to a character
    // Can reassign new characters to the same pointer 
}

void readfile(char *filename)
{
    char line[10000];
    FILE *fp = fopen(filename, "r");
    while(fgets(line, 10000, fp) != NULL)
    {
        printf("%s", line);
    }
    fclose(fp);
}

double average(char *filename)
{
    char line[200];
    FILE *fp = fopen(filename, "r");
    int sum = 0;
    int line_count = 0;
    while(fgets(line, sizeof(line), fp))
    {
        sum += atoi(line);
        line_count++;
    }
    fclose(fp);
    return sum/line_count;
}

int main()
{
    struct student1 s = {"Jenny", "12345678901", 9};

    set_default_name(&s);
    print_student(s);

    student1 *p_p_s;
    student1 *student_arr = create_block1(&p_p_s, 10);
    set_name(&student_arr[0], "Alice");
    printf("Name: %s\n", student_arr[0].name);

    student2 *p_p_s2;
    student2 *student_arr2 = create_block2(&p_p_s2, 10);
    set_name2(&student_arr2[0], "Isabella");
    printf("Name: %s\n", student_arr2[0].name);

    // printf("Average: %f\n", average("\Users\DELL\esc190\lecturenotes\numbers.txt");
}
