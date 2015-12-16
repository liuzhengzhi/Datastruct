#include <cstdio>
#include <cstdlib>

struct node
{
	int coef;
	int exon;
	node* next;
};

void insert(node temp,node* root)
{
	node* cur = root->next;
	node* tmp = (node*)malloc(sizeof(node));
	tmp->coef = temp.coef;
	tmp->exon = temp.exon;
	if(root == root->next)
	{
		root->next = tmp;
		tmp->next = root;
	}
	else
	{
		if(tmp->exon > cur->exon)
		{
			tmp->next = cur;
			root->next = tmp;
			return;
		}
		while(cur->next!=root)
		{
			if(tmp->exon == cur->exon)
			{
				cur->coef = tmp->coef+cur->coef;
				return;
			}
			if(tmp->exon < cur->exon && tmp->exon >cur->next->exon)
			{
				tmp->next = cur->next;
				cur->next = tmp;
				return;
			}
			cur=cur->next;
		}		
		if(cur->next == root)
		{
			if(tmp->exon == cur->exon)
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
node* input_polynomia()
{
	node* root = (node *)malloc(sizeof(node));
	root->next = root;	
	node temp;
	while(scanf("%d %d",&temp.coef,&temp.exon)==2 && !(temp.coef == 0 && temp.exon == -1))
	{
		insert(temp,root);
	}
	return root;
}
//================================加法部分=====================================================================================================================
node* add(node* A,node* B)
{
	node* A_cur = A->next;
	node* B_cur = B->next;
	node tmp;
	node* sum = (node*)malloc(sizeof(node));	
	sum->next = sum;
	if(sum == NULL)
	{
		perror("Memery");
	}
	while(A_cur != A && B_cur != B  )
	{
		if(A_cur->exon > B_cur->exon)
		{
			insert(*A_cur,sum);
			A_cur = A_cur->next;
		}
		else if(A_cur->exon == B_cur->exon)
		{
			tmp.exon = B_cur->exon;	
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
//=============================================================================================================================================================

//乘法部分,要用加法!!!
node* multiplication(node* A, node* B)
{
	node* copy = (node*)malloc(sizeof(node));	
	node* result = (node*)malloc(sizeof(node));	
	if(copy == NULL || result == NULL)
	{
		perror("Memery");
	}
	copy->next = copy;
	result->next = result;
	copy = add(copy, A);
	//Above is right
	node* tmp_copy=copy;
	node* B_start = B;
	B = B->next;
	while(B!=B_start)
	{
		copy = copy->next;
		A = A->next;
		while(copy!=tmp_copy)
		{
			copy->exon = A->exon + B->exon;
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

void output_polynomia(node* A)
{
	if(A==A->next)
	{
		perror("Empty polynomia");	
		return;
	}
	int times = 1;
	for(node* begin = A->next; begin!=A; begin=begin->next)
	{
		if(begin->exon==1)
		{
			if(begin->coef !=1 && begin->coef!=-1)
			{
				if(times==1) {
					printf("%dx", begin->coef);
					times=0;
				}
				else
				printf("%+dx", begin->coef);
			}
			else if(begin->coef==1)
			{
				if(times==1)
				{
					printf("x");
					times=0;
				}
				else
				printf("+x");
			}
			else
			{
				printf("-x");
				times=0;
			}
		}
		else if(begin->exon==0)
		{
			if(times==1)
			{
				times=0;	
				printf("%d", begin->coef);
			}
			else
			printf("%+d", begin->coef);
		}
		else
		{
			if(begin->coef!=1 && begin->coef!=-1)
			{
				if(times==1)
				{
					printf("%dx^%d", begin->coef, begin->exon);
					times=0;
				}
				else
				printf("%+dx^%d", begin->coef, begin->exon);
			}
			else if(begin->coef==1)
			{
				if(times==1)
				{
				printf("x^%d", begin->exon);
				times=0;
				}
				else
				printf("+x^%d", begin->exon);
			}
			else
			{
				printf("-x^%d", begin->exon);
				times=0;
			}
		}
	}	
	printf("\n");
}


int main(int argc, char **argv) {
	node* A=input_polynomia();
	node* B=input_polynomia();
	output_polynomia(A);
	output_polynomia(B);
	//=====add=======================
	node* C=add(A,B);
	output_polynomia(C);
	//======add=======================
	node* D=multiplication(A,B);
	output_polynomia(D);
	return 0;
}
