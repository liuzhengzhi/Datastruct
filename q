#include "polynomial.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>
/* =============================================
 * name:input_polynomia
 * function:Get input from stdin,and store it in
 *			a linked list
 * return value:a pointer point to the new polynomia
 * ============================================= */
poly_pointer input_polynomia()
{
	printf("Please Input the polynomia(eg:5x3+7x9-x+1):\n");
	char raw_polynomia[80];
	poly_pointer poly;
	scanf(" %s",raw_polynomia);
	poly = char_to_list(raw_polynomia);
	return poly;
}

/* =============================================
 * name:char_to_list
 * function:Get input from char*,and store it in a
 *			linked list
 * return value:a pointer point to the new polynomia
 * ============================================= */
poly_pointer char_to_list(char* raw)
{
	poly_pointer root;
}

int main(int argc, char **argv) {
	input_polynomia();
	return 0;
}
