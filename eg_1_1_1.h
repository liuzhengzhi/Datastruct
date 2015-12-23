#ifndef __EG_1_1_1_H__
#     define __EG_1_1_1_H__
#include <iostream>
#include <string>

using namespace std;

//using struct to store student information
struct Student
{
	string IDnumber;	//student id number
	string name;		//student name
	int math;			//student's math grade
	int english;		//student's english grade
	int chinese;		//student's chines grade
	Student* next;		//pointer to next student
}root;

void add_student(Student&);
void search_student(string&);
void delete_student(string&);
void modify_student(string&);
void sort_grade(int);
void search_grade(int,int);

void show_menu();
#endif /* __EG_1_1_1_H__ */
