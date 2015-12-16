#include "thread_binary.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>

/**
 * creat a binary
 */
binary_pointer creat_binary()
{
	binary_pointer root = new binary_node;	
	binary_pointer tmp = root;
	binary_pointer tmp2;
	root->data = '0';
	root->left_thread = false;
	root->right_thread = false;
	root->left_child = new binary_node;
	root->right_child = root;
	tmp = root->left_child;
	tmp->data = 'A';
	tmp->left_thread = false;
	tmp->left_child = new binary_node;
	tmp->right_thread = false;
	tmp->right_child = new binary_node;
	tmp->right_child->data = 'C';
	tmp->right_child->left_thread = false;
	tmp->right_child->right_thread = false;
	tmp->right_child->left_child = new binary_node;
	tmp->right_child->right_child = new binary_node;
	//
	tmp2 = tmp->right_child->right_child;
	tmp2->data = 'F';
	tmp2->left_thread = true;
	tmp2->right_thread = true;
	tmp2->right_child = root;
	tmp2->left_child = tmp->right_child;
	//
	tmp2 = tmp->right_child->left_child;
	tmp2->data = 'E';
	tmp2->left_thread = true;
	tmp2->right_thread = true;
	tmp2->right_child = tmp->right_child;
	tmp2->left_child = tmp;
	//
	tmp2 = tmp->left_child;
	tmp2->data = 'B';
	tmp2->left_thread = true;	
	tmp2->left_child = root;
	tmp2->right_thread =true;
	tmp2->right_child = tmp;
	return root;
}

bool isempty(binary_pointer ptr)
{
	return ptr->left_thread;
}

void binary_show(binary_pointer ptr)
{
	binary_pointer cur = ptr;
	std::cout << cur->data;
	if(!cur->left_thread)
	{	
		std::cout << "(";
		binary_show(cur->left_child);
		std::cout<<",";
	}
	if(!cur->right_thread)
	{
		binary_show(cur->right_child);
		std::cout<<")";
	}
}

void show_thread(binary_pointer ptr)
{
	if(ptr->left_thread)
	{
		std::cout<<ptr->data<<" left_thread:"<<ptr->left_child->data<<std::endl;
	}	
	else
	{
		show_thread(ptr->left_child);
	}
	if(ptr->right_thread)
	{
		std::cout<<ptr->data<<" right_thread:"<<ptr->right_child->data<<std::endl;
	}	
	else
	{
		show_thread(ptr->right_child);
	}
}

binary_pointer show_next(binary_pointer ptr)
{
	binary_pointer temp = ptr->right_child;
	if(!ptr->right_thread)
	{
		while(!temp->left_thread)
		{
			temp = temp->left_child;
		}
	}
	return temp;
}

binary_pointer show_pre(binary_pointer ptr)
{
	binary_pointer temp = ptr->left_child;
	if(!ptr->left_thread)
	{
		while(!temp->right_thread)
		{
			temp = temp->right_child; 
		}
	}
	return temp;
}

void tinorder(binary_pointer ptr)
{
	binary_pointer temp = ptr;
	for(;;)
	{
		temp = show_next(temp);
		if(temp == ptr)
		{
			break;
		}
		std::cout<<temp->data<<"  ";
	}
	std::cout<<std::endl;
}
int main(int argc, char **argv) {
	binary_pointer root = creat_binary();
	binary_show(root->left_child);
	std::cout<<std::endl;
	show_thread(root->left_child);
	binary_pointer insucc = show_pre(root->left_child);
	std::cout << insucc->data<<std::endl;
	insucc = show_next(root->left_child);
	std::cout << insucc->data<<std::endl;
	tinorder(root);
	return 0;
}
