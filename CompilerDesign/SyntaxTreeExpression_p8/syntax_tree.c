#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Blank ' '
#define Tab '\t'
#define MAX 100
int pop();
char expression[MAX], syntaxtree[MAX];
int stack[MAX];
int top;
void expression_to_syntaxtree();
int prec(char symbol);
void push(int symbol);
int pop();
int white_space(char symbol);
int main(){
 int value;
 char choice='y';

 do{
 top=0;
 printf("\nEnter Expression: ");
 scanf("%[^\n]", expression);
 getchar();
 expression_to_syntaxtree();
 printf("Expression Tree Format: %s \n",syntaxtree);
 printf("Want to continue(y/n): ");
 scanf(" %c",&choice);
 getchar();
 }while(choice=='y');
}
void expression_to_syntaxtree(){
 int i,p=0,type,precedence,len;
 char next;
 stack[top]='#';
 len=strlen(expression);
 expression[len]='#';
 for(i=0;expression[i]!='#';i++){
 if(!white_space(expression[i])){
 switch(expression[i]){
 case '(':
 push(expression[i]);
 break;
 case ')':
 while ((next=pop())!='(')
 syntaxtree[p++]=next;
 break;
 case '+':
 case '-':
 case '*':
 case '/':
 case '%':
 case '^':
 precedence=prec(expression[i]);
 while(stack[top]!='#'&& precedence<=prec(stack[top]))
 syntaxtree[p++]=pop();
 push(expression[i]);
 break;
 default:
 syntaxtree[p++]=expression[i];
 }
 }
 }
 while (stack[top]!='#')
 syntaxtree[p++]=pop();
 syntaxtree[p]='\0';

}
int prec(char symbol)
{
 switch (symbol)
 {
 case '(':
 case ')': return 0;
 case '+':
 case '-':
 return 1;
 case '*':
 case '/':
 return 2;
 case '^':
 return 3;
 }
}
void push(int symbol){
 if(top>MAX){
 printf("Stack overflow\n");
 exit(1);
 }
 else{
 top=top+1;
 stack[top] = symbol;
 }
}
int pop(){
 if(top==-1){
 printf("Stack underflow \n");
 exit(2);
 }
 else{
 return(stack[top--]);
 }
}
int white_space(char symbol){
 if(symbol == Blank ||symbol == Tab || symbol == '\0')
 return 1;
 else
 return 0;
}
// output
// enter expression id :id*id and id-id*id and id*(id+id)
