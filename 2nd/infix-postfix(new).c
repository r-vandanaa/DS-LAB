#include <stdio.h>
#include <ctype.h>

#define MAX 50

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int pr(char operands){
    if (operands == '^')
    {
        return(3);
    }
    else if (operands == '*' || operands == '%')
    {
        return(2);
    }
    else if (operands == '+' || operands == '-')
    {
        return(1);
    }
    else{
        return (0);
    }
}

//main func
int main(){
    char postfix[50], infix[50], ch, c;
    int i,k = 0;
    printf("enter infix expression: ");
    scanf("%s", infix);
    push('#');
    while((ch=infix[i++]) != '\0'){
        if (ch == '(')
        {
            push(ch);
        }
        else if(isalnum(ch))
        {
            postfix[k++] = ch;
        }
        else if(ch ==')'){
            while (stack[top] != '(')
                {
                    postfix[k++] = pop();

                }
                pop();

        }
        else
        {
            while (pr(stack[top]) >= pr(ch))
            {
                postfix[k++] = pop();

            }
            push(ch);
        }


    }
    while (stack[top] != '#')
    {
    postfix[k++] = pop();
    }
    postfix[k] = '\0';
    printf("\n Postfix Expression = %s", postfix);
}
