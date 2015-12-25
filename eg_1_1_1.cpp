#include "eg_1_1_1.h"

//add student
void add_student(Student& rhs)
{
	for(auto i = &root; ; i=i->next)
	{
		if(i->next == NULL)
		{
			Student* tmp = new Student;	
			*tmp = rhs;
			i->next =	tmp;
			tmp->next = NULL;
			break;
		}
	}	
}

//search student by their name or id number
void search_student(string& rhs)
{
	for(auto i = (&root)->next; i != NULL; i = i->next)
	{
		if(i->name == rhs || i->IDnumber == rhs)
		{
			cout << "Find" << i->name <<" " << i->IDnumber << " "<< i->math << i->english << " " << i->chinese << endl;
			return ;
		}
	}
	cout << "No such student" <<endl;
}

//delete student infomation by name or id number
void delete_student(string& rhs)
{
	for(auto i = (&root)->next , j = &root; i != NULL; i=i->next,j=j->next)
	{
		
		if(i->name == rhs || i->IDnumber == rhs)
		{
			cout << "Delete" << i->name <<" " << i->IDnumber << " "<< i->math << i->english << " " << i->chinese << endl;
			j->next = i->next;
			delete i;
			return;
		}
	}
}

//How to sort will be shown in the last homework.
