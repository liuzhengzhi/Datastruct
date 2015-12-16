#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__
/*======================================
 *polynomial node define,using linked list
========================================*/
typedef struct poly_node* poly_pointer;
struct poly_node
{
	double			coef;
	int				expon;
	poly_pointer	next;
};

poly_pointer add(poly_node A,poly_pointer B);
poly_pointer sub(poly_node A,poly_pointer B);
poly_pointer input_polynomia();
void char_to_list(char *raw,poly_pointer);
void output_polynomia(poly_pointer A);
double value(poly_pointer A,double x);
poly_pointer multiplication(poly_pointer A, poly_pointer B);
void division(poly_pointer A, poly_pointer B);
void insert(poly_node node,poly_pointer);
#endif /* __POLYNOMIAL_H__ */
