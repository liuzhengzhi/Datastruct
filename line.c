#include <stdio.h>
#include <stdlib.h>

struct node{
	int a;
	char b;
	double c;
	struct node* next;
}root;

void reverse(struct node** head_ref)
{
    struct node* prev   = NULL;
    struct node* current = *head_ref;
    struct node* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
void printList(struct node *head,int n)
{
    struct node *temp = head;
	if (n==1)
    while(temp != NULL)
    {
        printf("%d ", temp->a);    
        temp = temp->next;  
    }
	if (n==2)
    while(temp != NULL)
    {
        printf("%c ", temp->b);    
        temp = temp->next;  
    }
	if (n==3)
    while(temp != NULL)
    {
        printf("%lf ", temp->c);    
        temp = temp->next;  
    }
	printf("\n");
}    

void deleteNode(struct node **head_ref, int key)
{
    // Store head node
    struct node* temp = *head_ref, *prev;
 
    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->a == key)
    {
        *head_ref = temp->next;   // Changed head
        free(temp);               // free old head
        return;
    }
 
    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->a != key)
    {
        prev = temp;
        temp = temp->next;
    }
 
    // If key was not present in linked list
    if (temp == NULL) return;
 
    // Unlink the node from linked list
    prev->next = temp->next;
 
    free(temp);  // Free memory
}

void deleteNode2(struct node **head_ref, char key)
{
    // Store head node
    struct node* temp = *head_ref, *prev;
 
    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->b == key)
    {
        *head_ref = temp->next;   // Changed head
        free(temp);               // free old head
        return;
    }
 
    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->b != key)
    {
        prev = temp;
        temp = temp->next;
    }
 
    // If key was not present in linked list
    if (temp == NULL) return;
 
    // Unlink the node from linked list
    prev->next = temp->next;
 
    free(temp);  // Free memory
}

void deleteNode3(struct node **head_ref, double key)
{
    // Store head node
    struct node* temp = *head_ref, *prev;
 
    // If head node itself holds the key to be deleted
    if (temp != NULL && (temp->c-key>-1e-5 && temp->c-key<1e-5))
    {
        *head_ref = temp->next;   // Changed head
        free(temp);               // free old head
        return;
    }
 
    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && !(temp->c-key>-1e-5 && temp->c-key<1e-5))
    {
        prev = temp;
        temp = temp->next;
    }
 
    // If key was not present in linked list
    if (temp == NULL) return;
 
    // Unlink the node from linked list
    prev->next = temp->next;
 
    free(temp);  // Free memory
}

int main(void)
{
	struct node* cur = &root;
	int n;
	scanf("%d",&n);
	while(n!=0)
	{
		struct node* tmp=(struct node*)malloc(sizeof(struct node));
		n--;
		scanf(" %d",&tmp->a);
		cur->next = tmp;
		cur = tmp;
		cur->next = NULL;
	}
	
	struct node* proot = root.next;
	struct node** head_ref = &proot;
	reverse(head_ref);
	printList(proot,1);
	int x;
	scanf(" %d",&x);
	deleteNode(head_ref,x);
	printList(proot,1);


	cur = &root;
	scanf("%d",&n);
	while(n!=0)
	{
		struct node* tmp=(struct node*)malloc(sizeof(struct node));
		n--;
		scanf(" %c",&tmp->b);
		cur->next = tmp;
		cur = tmp;
		cur->next = NULL;
	}
	
	proot = root.next;
	head_ref = &proot;
	reverse(head_ref);
	printList(proot,2);
	char cx;
	scanf(" %c",&cx);
	deleteNode2(head_ref,cx);
	printList(proot,2);



	cur = &root;
	scanf("%d",&n);
	while(n!=0)
	{
		struct node* tmp=(struct node*)malloc(sizeof(struct node));
		n--;
		scanf(" %lf",&tmp->c);
		cur->next = tmp;
		cur = tmp;
		cur->next = NULL;
	}
	
	proot = root.next;
	head_ref = &proot;
	reverse(head_ref);
	printList(proot,3);
	double dx;
	scanf(" %lf",&dx);
	deleteNode3(head_ref,dx);
	printList(proot,3);

	return 0;
}
