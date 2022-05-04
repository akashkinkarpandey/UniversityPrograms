//postfix using stack
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
char a[100];
//len=strlen(a);
int top=-1;
 //insert element
void push(int x){
	//max sized reached overflow condition
	if(top==99){
		printf("\n\tOVERFLOW\n");
		return;
	}
	a[++top]=x;//inserting
	return;}
int pop(){
		if (empty()){
		printf("\n\tARRAY IS EMPTY\n");
		return;
	}
	int t=a[top];

	top--;
	return t;
	
}
int empty(){
return(top==-1);
}
int size(){
		if (empty()){
		printf("\n\tARRAY IS EMPTY\n");
		return;
	}
	return (top+1);
}
void print(){
	int i;
	if (empty()){
		printf("\n\tARRAY IS EMPTY\n");
		return;
	}

	 
	//as we want to print top of the element
	for(i=top;i>=0;i--){
	
	printf("%d|",a[i]);}
	printf("\n");
}
//postfix operation
bool isnumeric(char c){
	if(c>='0'&&c<='9')
	return true;
	else
	return false;
}
bool isoperator(char c){
	if(c=='+'||c=='-'||c=='*'||c=='/')
	return true;
	else
	return false;
}
int operation(char c,int opr1,int opr2){
	if(c=='+')
	return opr1+opr2;
	else if(c=='-' )
	return opr1-opr2;
	else if(c=='*' )
	return opr1*opr2;
	else if(c=='/' )
	return opr1/opr2;
	else
	printf("\t\ninvalid syntax\n");
	return -1;
}
int postfixoper(int len){
	int i;
	for(i=0;i<len;++i){
		if(a[i]==' '||a[i]==',')
		continue;
		else if(isoperator(a[i])){
		
		int res;
		int opr2=pop();
		int opr1=pop();
		res=operation(a[i],opr1,opr2);
		push(res);
		}
	 else if(isnumeric(a[i]))
	 	{
int operand = 0;
while(i<len && isnumeric((a[i])))
{
operand = (a[i]-'0');
push(operand);
i++;

}
i--;

}
	 	
	}
	return a[top];
}
int main(){
	int res,len;
	
	printf("enter the postfix expression: ");
gets(a);
len=strlen(a);
//puts(a);
//length = strlen(arr);
printf("%d\n",len);
res = postfixoper(len);
printf("result = %d",res);
}