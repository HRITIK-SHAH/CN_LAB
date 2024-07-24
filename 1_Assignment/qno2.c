#include <stdio.h>
#include <string.h>

struct dob {
    int date;
    int month;
    int year;
};

struct student_info {
    int roll_no;
    char name[50];
    float CGPA;
    struct dob age;
};

void print_student_info_value(struct student_info student) {
    printf("Roll No: %d\n", student.roll_no);
    printf("Name: %s\n", student.name);
    printf("CGPA: %.2f\n", student.CGPA);
    printf("Date of Birth: %d/%d/%d\n", student.age.date, student.age.month, student.age.year);
}

void print_student_info_address(struct student_info *student) {
    printf("Roll No: %d\n", student->roll_no);
    printf("Name: %s\n", student->name);
    printf("CGPA: %.2f\n", student->CGPA);
    printf("Date of Birth: %d/%d/%d\n", student->age.date, student->age.month, student->age.year);
}

int main() {
    struct student_info student;

    student.roll_no = 22054331;
    strcpy(student.name, "HRITIK SHAH");
    student.CGPA = 9.15;
    student.age.date = 21;
    student.age.month = 6;
    student.age.year = 2004;

    printf("Printing student info (call-by-value):\n");
    print_student_info_value(student);

    printf("\nPrinting student info (call-by-address):\n");
    print_student_info_address(&student);

    return 0;
}

