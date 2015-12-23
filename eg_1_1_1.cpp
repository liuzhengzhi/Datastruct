#include "eg_1_1_1.h"

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
