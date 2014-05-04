/*~~~ FMQ LL(1) Error Repair Algorithm is used in this program~~~ */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*UNICODE FORMAT
/+ACo- FMQ LL(1) Error Repair Algorithm is used in this program +ACo-/
+ACM-include+ADw-stdio.h+AD4-
+ACM-include+ADw-ctype.h+AD4-
static boolean parse+AF8-error(symbol stack+AF8-top, terminal current+AF8-token)
+AHs-
	if(stack+AF8-top +Igg- x)
		return T+AFs-stack+AF8-top+AF0AWw-current+AF8-token+AF0APQA9-ERROR+ADs-
	else
		/+ACo-stack+AF8-top +Igg- y +ACo-/
		return stack+AF8-top+ACEAPQ-current+AF8-token+ADs-
+AH0-
void ll+AF8-recovery(void)
+AHs-
	/+ACo-let 's' be the parse stack, 'a' be the current input token+ACo-/
	while(parse+AF8-error(top(s), a))
	+AHs-
		if(top(s) +Igg- x)
		+AHs-
			/+ACo-top1 peeks at top(pop(s))+ACo-/
			if(parse+AF8-error(top1(s), a) +ACYAJg- +ACE- (a +Igg- header+AF8-set))
				scanner(a)+ADs- /+ACo-skip current token+ACo-/
			else /+ACo-remove top stack symbol+ACo-/
				pop(s)+ADs-
		+AH0-
		else
		+AHs-
			/+ACo-top(s) +Igg- y +ACo-/
			if(top(s)+AD0APQ-SCANEOF)
				scanner(+ACY-a)+ADs-
			/+ACo-never skip past end maker+ACo-/
			else
				pop(s)+ADs-
			/+ACo-match expected terminal+ACo-/
			/+ACo-then, try again+ACo-/
		+AH0-
	+AH0-
+AH0-
------end of unicode format*/
/*-----------------------------------------*/
/*-----------Programming format (English)---------------------------*/
#include<stdio.h>
#include<ctype.h>
static boolean parse_error(symbol stack_top, terminal current_token)
{
	if(stack_top ∈ x)
		return T[stack_top][current_token]==ERROR;
	else
		/*stack_top ∈ y */
		return stack_top!=current_token;
}
void ll_recovery(void)
{
	/*let 's' be the parse stack, 'a' be the current input token*/
	while(parse_error(top(s), a))
	{
		if(top(s) ∈ x)
		{
			/*top1 peeks at top(pop(s))*/
			if(parse_error(top1(s), a) && ! (a ∈ header_set))
				scanner(a); /*skip current token*/
			else /*remove top stack symbol*/
				pop(s);
		}
		else
		{
			/*top(s) ∈ y */
			if(top(s)==SCANEOF)
				scanner(&a);
			/*never skip past end maker*/
			else
				pop(s);
			/*match expected terminal*/
			/*then, try again*/
		}
	}
}
/*-------AshuMeow-----*/
