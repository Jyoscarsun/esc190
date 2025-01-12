# include<stdio.h>
# include<stdlib.h>
# include<string.h>

// PART 1
// Solution for Q5
void change_value(int *p_a)
{
    *p_a = 200;
}

// Solution for Q10
void change_value_pt2(int **p_p_a)
{
    **p_p_a = 46;
}

// Solution for Q11
void change_int_ptr(int **p_p_a)
{
    *p_p_a = malloc(sizeof(int));
}

// Solution for Q16
void change_second_element(int *arr)
{
    arr[1] = 8;
}

// Solution for Q21
typedef struct student{
    char *name;
    int age;
} student;

// Solution to 27
void change_name(student *p_s)
{
    p_s->name = "Jenny";
}

// Solution to 28
void change_age(student *p_s)
{
    p_s->age = 20;
}

// Solution to self-made Q1
void switch_name(student *p_s)
{
    int temp = p_s[1].age;
    p_s[1].age = p_s[2].age;
    p_s[2].age = temp;
}

int main()
{
    // Solution for Q1
    int a = 42;
    // Solution for Q2
    int *p_a = &a;
    // Solution for Q3
    *p_a = 43;
    // Solution for Q4
    int rand = 44;
    p_a = &rand;
    // Solution to Q6
    change_value(&a);
    printf("%d\n", a);
    // Solution to Q7
    change_value(p_a);
    printf("%d\n", *p_a);
    // Solution to Q8
    int **p_p_a;
    // Solution to Q9
    p_p_a = &p_a;
    // Solution to Q12
    change_value_pt2(p_p_a);
    change_value_pt2(&p_a);
    // Solution to Q13
    change_int_ptr(&p_a);
    // Solution to Q14
    change_int_ptr(p_p_a);
    // Solution to Q15
    int arr[3] = {5, 6, 7};
    // Solution to Q17
    change_second_element(&arr);
    // Solution to Q18
    int *p_block = malloc(3*sizeof(int));
    change_second_element(p_block);
    // Solution to Q19
    change_value(p_block);
    // Solution to Q20
    change_int_ptr(&p_block);
    // Solution to Q21
    student s;
    // Solution to Q22
    s.name = "Jennifer";
    // Solution to Q23
    s.age = 21;
    // Solution to Q24
    student *p_s = &s;
    // Solution to Q25
    p_s->name = "Jenny";
    // Solution to Q26
    p_s->age = 20;
    // Solution to Q29
    change_name(p_s);
    // Solution to Q30
    change_age(p_s);
    // Solution to Q31
    student student_arr[5];
    student_arr[1].name = "Leo";
    student_arr[1].age = 20;
    // Solution to Q32
    change_name(&student_arr[1]);
    change_age(&student_arr[1]);


    // PART 2
    /*
    1. Write a function that switches the age of the second and third student in the array
    by passing in the pointer into the function
    2. Implement the function written above
    */

   // Solution to self-made Q2
    student_arr[2].name = "Sofia";
    student_arr[2].age = 19;
    switch_name(&student_arr);
}