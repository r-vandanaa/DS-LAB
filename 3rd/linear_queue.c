#include<stdio.h>
#define n 5
int f=-1,r=-1;
queue[n];
void enqueue(x){
    if(r==n-1){
        printf("overflow");
    }
    else if(f==-1)
    {
        f=r=0;
        queue[r]=x;
    }
    else{
        r++;
        queue[r]=x;
    }
}
void dequeue(){
    if(f==-1 && r==-1){
        printf("empty");
    }
    else if(f==r)
    {
        f=r=-1;
    }
    else{
        f++;
    }
}
void display(){
    for(int i=f;i<=r;i++){
        printf("%d \n",queue[i]);
    }
}
int main(){
    int c,x;
    do{
        printf("enter the choice:\n 1.enqueue \n 2.dequeue \n 3. display \n 4.exit \n");
        scanf("%d",&c);
        switch(c){
            case 1:{
                printf("enter an ele:");
                scanf("%d",&x);
                enqueue(x);
                break;
            }
            case 2:{
                dequeue();
                break;
            }
            case 3:{
                display();
                break;
            }
        }
    }while(c!=4);
}


