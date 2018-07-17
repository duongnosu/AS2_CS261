/*	stack.c: Stack application. */
/*********************************************************************
** Program Filename: stackapp.c
** Author: Nhu Duong
** Date: July 16, 2018
** Description: Using functions and stack to check the string balance
*********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string
	pre: s is not null
*/
char nextChar(char* s)
{
	static int i = -1;
	char c;
	++i;
	c = *(s+i);
	if ( c == '\0' )
		return '\0';
	else
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string
	pre: s is not null
	post:
*/
int isBalanced(char* s)
{
	DynArr *stack;
	stack = newDynArr(2);
	char cur_char;
	char top_stack;
	cur_char = nextChar(s);
	while (cur_char!= '\0'){
		if (cur_char == '(' || cur_char == '[' || cur_char=='{'){
			pushDynArr(stack, cur_char);
		}
		 if (cur_char == ')' || cur_char == ']'|| cur_char =='}' ){
		// 	popDynArr(stack);
			int sj;
			sj= sizeDynArr(stack);
			if (sj ==0){
				return 0;
			}
			top_stack = topDynArr(stack);
			popDynArr(stack);
		}

     //
		if (cur_char == ')' &&  top_stack != '('){
			return 0;
		}
		else if (cur_char == ']' && top_stack != '['){
		return 0;
		}
		else if (cur_char == '}' && top_stack != '{'){
			return 0;
		}

		cur_char = nextChar(s);
	 }

	 return 1;
     //
	// if (isEmptyDynArr(stack)== 1){
	// 	return 1;
	// }
	// return 0;
}

int main(int argc, char* argv[]){

	char* s=argv[1];
	int res;

	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else
		printf("The string %s is not balanced\n",s);

	return 0;
}
