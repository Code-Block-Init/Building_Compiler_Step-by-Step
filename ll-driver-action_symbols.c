/* LL(1) parser driver that handles action symbols */
#include<stdio.h>
#include<ctype.h>
void lldriver(void)
{
	/*Push the start symbol onto an empty stack*/
	push(s);
	while(! stack_empty())
	{
		/*Let the 'x' be the top stack symbol and 'a' be the current input token*/
		if(is_nonterminal(x) && T[x][a] == x -> y ...)
		{
			/*expand non-terminal*/
			replace x with y ... on the stack;
	}
	else if(is_terminal(x) && x == a)
	{
		pop(1); /*Match of x worked*/
		scanner(&a); /*Get next token*/
		}
	else if(is_action_symbol(x))
	{
		pop(1);
		Call semantic routine corresponding to x;
	}
	else
		/*Process the syntax error*/
}
}
