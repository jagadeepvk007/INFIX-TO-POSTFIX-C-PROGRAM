#include<stdio.h>
#include<conio.h>
#include<string.h>
#define size 100
#define leftparen 10
#define rightparen 20
#define operand 30
#define operater 40
 char infix[size],postfix[size],s[size];
 int top=-1;
  void push(char sym)
   {
     if(top==(size-1))
      printf("stack overflow\n");
     else
      s[++top]=sym;
   }

 char pop()
  {
    if(top==-1)
     printf("stack underflow\n");
    else
     return(s[top--]);
  }

 int get_type(char sym)
  {
   switch(sym)
    {
      case '+':
      case '-':
      case '*':
      case '/':
      case '^':
      case '%':return operater;
      case '(':return leftparen;
      case ')':return rightparen;
      default:return operand;
    }
  }

 int get_precedence(char sym)
  {
   switch(sym)
    {
      case '(':return 0;
      case '+':
      case '-':return 1;
      case '*':
      case '/':
      case '%':
      case '^':return 2;
      case ')':return 999;
    }
  }

 void infix_to_postfix()
  {
    int i,p,len,type,pr;
    char next;
    i=p=0;
    len=strlen(infix);
     while(i<len)
      {
       type=get_type(infix[i]);
        switch(type)
         {
           case operand:postfix[p++]=infix[i];
		        break;
           case leftparen:push(infix[i]);
		        break;
           case rightparen:while((next=pop())!='(')
		           postfix[p++]=next;
		        break;
           case operater:pr=get_precedence(infix[i]);
		         while(top>-1&&pr<=get_precedence(s[top]))
		         postfix[p++]=pop();
		         push(infix[i]);
		       break;
          }
       i++;
     }
  while(top>-1)
    postfix[p++]=pop();
  postfix[p]='\0';
 }
void main()
 {
    clrscr();
    printf("enter the valid infix expression\n");
    scanf("%s",infix);
    infix_to_postfix();
    printf("the resultant postfix expression is %s",postfix);
 getch();
 }
