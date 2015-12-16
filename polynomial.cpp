#include "polynomial.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cmath>

/* =============================================
 * name:input_polynomia
 * function:Get input from stdin,and store it in
 *			a linked list
 * return value:none
 * ============================================= */
poly_pointer input_polynomia()
{
	poly_pointer root = (poly_pointer)malloc(sizeof(poly_node));
	root->next = root;
	printf("Please Input the polynomia(eg:5x3+7x9-x+1):(no more than 80 char)\n");
	char raw_polynomia[80];
	scanf(" %s",raw_polynomia);
	char_to_list(raw_polynomia,root);
	return root;
}

/* =============================================
 * name:char_to_list
 * function:Get input from char*,and store it in a
 *			linked list
 * return value:none
 * ============================================= */
void char_to_list(char* raw,poly_pointer root)
{
	poly_node tmp;
	char* cur = raw;
	char* pre = raw;
	bool has_x = false;
	bool flag = true;
	while(*cur!='\0')
	{
		if(*cur=='x'&&flag)
		{
			has_x = true;
			if(cur==pre)
			{
				tmp.coef = 1;
				cur++;
				pre++;
			}	
			else
			{
				*cur = '\0';
				tmp.coef=atof(pre);
				cur++;
				if(*cur=='\0')
				{
					tmp.expon = 1;
					insert(tmp,root);
					return ;
				}
				pre = cur;
			}
		}
		if(*cur=='+' || *cur=='-')
		{
			if(cur==raw)
			{
				cur++;
				continue;
			}
			flag = true;
			char sign = *cur;
			if(!has_x)
			{
				*cur='\0';
				tmp.coef =atof(pre);
				tmp.expon = 0;
				insert(tmp,root);
			}
			else
			{
				if(cur==pre)
				{
					tmp.expon = 1;
					insert(tmp,root);
				}
				else
				{
					*cur = '\0';
					tmp.expon = atof(pre);
					insert(tmp,root);
				}
			}
			pre = cur;
			*pre = sign;
			has_x = false;
			if(cur[1]=='x')
			{
				has_x=true;
				flag =  false;
				tmp.coef = (sign=='+'?1:-1);
				pre = &cur[2];
			}
		}
		cur++;
		if(*cur=='\0')
		{
			if(has_x)
			{
				if(pre==cur)
					tmp.expon = 1;
				else
					tmp.expon = atof(pre);
				insert(tmp,root);
			}
			else
			{
				tmp.coef = atof(pre);
				tmp.expon = 0;
				insert(tmp,root);
			}
		}
	}
}

/*============================================
 * name: insert
 * function: insert element into list
 * return value: none
 ==============================================*/
void insert(poly_node node,poly_pointer root)
{
	poly_pointer cur = root->next;
	poly_pointer tmp = (poly_pointer)malloc(sizeof(node));
	tmp->coef = node.coef;
	tmp->expon = node.expon;
	if(root == root->next)
	{
		root->next = tmp;
		tmp->next = root;
	}
	else
	{
		if(tmp->expon > cur->expon)
		{
			tmp->next = cur;
			root->next = tmp;
			return;
		}
		while(cur->next!=root)
		{
			if(tmp->expon == cur->expon)
			{
				cur->coef = tmp->coef+cur->coef;
				return;
			}
			if(tmp->expon < cur->expon && tmp->expon >cur->next->expon)
			{
				tmp->next = cur->next;
				cur->next = tmp;
				return;
			}
			cur=cur->next;
		}		
		if(cur->next == root)
		{
			if(tmp->expon == cur->expon)
			{
				cur->coef = tmp->coef+cur->coef;
				return;
			}
			cur->next = tmp;
			tmp->next = root;
			return;
		}
	}
}

/*==================================================
 * name:output_polynomia()
 * function:output polynomia
 * return: none
 *=================================================*/
void output_polynomia(poly_pointer A)
{
	if(A==A->next)
	{
		perror("Empty polynomia");	
		return;
	}
	for(poly_pointer begin = A->next; begin!=A; begin=begin->next)
	{
		if(begin->expon==1)
		{
			if(begin->coef !=1 && begin->coef!=-1)
				printf("%+.1lfx", begin->coef);
			else if(begin->coef==1)
			{
				printf("+x");
			}
			else
			{
				printf("-x");
			}
		}
		else if(begin->expon==0)
		{
			printf("%+.1lf", begin->coef);
		}
		else
		{
			//TODO:need modify
			if(begin->coef!=1 || begin->coef!=-1)
				printf("%+.1lfx%d", begin->coef, begin->expon);
			else if(begin->coef==1)
			{
				printf("x%d", begin->expon);
			}
			else
			{
				printf("-x%d", begin->expon);
			}
		}
	}	
	printf("\n");
}

/**
 * name :+
 * function: add
 * return : poly_pointer
 */
poly_pointer add(poly_pointer A,poly_pointer B)
{
	poly_pointer A_cur = A->next;
	poly_pointer B_cur = B->next;
	poly_node tmp;
	poly_pointer sum = (poly_pointer)malloc(sizeof(poly_node));	
	sum->next = sum;
	if(sum == NULL)
	{
		perror("Memery");
	}
	while(A_cur != A && B_cur != B  )
	{
		if(A_cur->expon > B_cur->expon)
		{
			insert(*A_cur,sum);
			A_cur = A_cur->next;
		}
		else if(A_cur->expon == B_cur->expon)
		{
			tmp.expon = B_cur->expon;	
			if(A_cur->coef + B_cur->coef > 1e-4 || A_cur->coef + B_cur->coef < -1e-4)
			{
				tmp.coef = A_cur->coef + B_cur->coef;
				insert(tmp,sum);
			}
			B_cur = B_cur->next;
			A_cur = A_cur->next;
		}
		else
		{
			insert(*B_cur,sum);
			B_cur = B_cur->next;
		}
	}
	if(A_cur == A)
	{
		while(B_cur != B)
		{
			insert(*B_cur,sum);
			B_cur=B_cur->next;
		}
	}
	else
	{
		while(A_cur != A)
		{
			insert(*A_cur,sum);
			A_cur = A_cur->next;
		}
	}
	return sum;
}


poly_pointer sub(poly_pointer A,poly_pointer B)
{
	poly_pointer A_cur = A->next;
	poly_pointer B_cur = B->next;
	poly_node tmp;
	poly_pointer sum = (poly_pointer)malloc(sizeof(poly_node));	
	sum->next = sum;
	if(sum == NULL)
	{
		perror("Memery");
	}
	while(A_cur != A && B_cur != B)
	{
		if(A_cur->expon > B_cur->expon)
		{
			insert(*A_cur,sum);
			A_cur = A_cur->next;
		}
		else if(A_cur->expon == B_cur->expon)
		{
			tmp.expon = A_cur->expon;
			if(A_cur->coef - B_cur->coef > 1e-4 || A_cur->coef - B_cur->coef < -1e-4)
			{
				tmp.coef = A_cur->coef - B_cur->coef;
				insert(tmp,sum);
			}
			A_cur = A_cur->next;
			B_cur = B_cur->next;
		}
		else
		{
			tmp.expon = B_cur->expon;
			tmp.coef = -B_cur->coef;
			insert(tmp,sum);
			B_cur = B_cur->next;
		}
	}	
	if(B_cur == B)
	{
		while(A_cur != A)
		{
			insert(*A_cur,sum);
			A_cur = A_cur->next;
		}
	}
	else
	{
		while(B_cur != B)
		{
			tmp.coef = -B_cur->coef;
			tmp.expon = B_cur->expon;
			insert(tmp,sum);
		}
	}
	return sum;
}

poly_pointer multiplication(poly_pointer A, poly_pointer B)
{
	poly_pointer copy = (poly_pointer)malloc(sizeof(poly_node));	
	poly_pointer result = (poly_pointer)malloc(sizeof(poly_node));	
	if(copy == NULL || result == NULL)
	{
		perror("Memery");
	}
	copy->next = copy;
	result->next = result;
	copy = add(copy, A);
	//Above is right
	poly_pointer tmp_copy=copy;
	poly_pointer B_start = B;
	B = B->next;
	while(B!=B_start)
	{
		copy = copy->next;
		A = A->next;
		while(copy!=tmp_copy)
		{
			copy->expon = A->expon + B->expon;
			copy->coef = A->coef * B->coef;
			copy = copy->next;
			A = A->next;
		}	
		B = B->next;
		result = add(result,copy);
	}
	//free copy
	//======================================================
	//======================================================
	return result;
}

//TODO:
void division(poly_pointer A, poly_pointer B)
{
	poly_node tmp;
	poly_pointer B_start = B;
	poly_pointer quotient=(poly_pointer)malloc(sizeof(poly_node));
	if(quotient==NULL)
	{
		perror("Memery");
	}
	quotient->next = quotient;
	A = A->next;
	B = B->next;
	while(A->expon >= B->expon)
	{
		tmp.expon = A->expon - B->expon;	
		tmp.coef = A->coef / B->coef;
		while(B != B_start)
		{
			B->next->expon += tmp.expon;
			B->next->coef *= tmp.coef;
			B = B->next;
		}
		A = sub(A,B_start);
		insert(tmp,quotient);
	}
	printf("The quotient is:");
	output_polynomia(quotient);
	printf("The remainder is:");
	output_polynomia(A);
}

double value(poly_pointer A,double x)
{
	double sum = 0.0;	
	A->expon = 0;
	A->coef = 0;
	poly_pointer A_cur = A->next;
	sum = A_cur->coef;
	while(A_cur != A)
	{
		sum = sum*pow(x,A_cur->expon-A_cur->next->expon)+A_cur->next->coef;
		A_cur = A_cur->next;
	}
	return sum;
}

int main(int argc, char **argv) {
	poly_pointer A=input_polynomia();
	output_polynomia(A);
	poly_pointer B=input_polynomia();
	output_polynomia(B);
	printf("add:\n");
	poly_pointer C=add(A,B);
	output_polynomia(C);
	printf("sub:\n");
	poly_pointer D=sub(A,B);
	output_polynomia(D);
	printf("multiplies:\n");
	poly_pointer E=multiplication(A,B);
	output_polynomia(E);
	printf("value:");
	double sum=value(A,1);
	printf("%lf\n", sum);
	printf("division:\n");
	division(A,B);
	return 0;
}
