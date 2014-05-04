/*For recognizing operators, comments and delimiters*/
#include<stdio.h>
#include<ctype.h>
int in_char, c;
while((in_char=getchar())!=EOF)
{
if(isspace(in_char))
	/*do nothing*/
continue;
else if(isalpha(in_char))
	/*code to recognize identifiers goes here*/
else if(isdigit(in_char))
/*code to recognize int literals goes here*/
else if(in_char=='(')
return LPAREN;
else if(in_char==')')
	return RPAREN;
else if(in_char==';')
	return SEMICOLON;
else if(in_char=',')
	return COMMA;
else if(in_char=='+')
	return PLUSOP;
else if(in_char==':')
{
	/*looking for ':=' */
	c=getchar();
if(c=='=')
	return ASSIGNOP;
else
{
	ungetc(c,stdin);
	lexical_error(in_char)l
}
}
else if(in_char=='-')
{
	/*looking for --, comment line start*/
	c=getchar();
	if(c=='-')
	{
		while((in_char=getchar())!='\n');
	}
	else
	{
		ungetc(c,stdin);
		return MINUSOP;
	}
	}
else
	lexical_error(in_char);
}
