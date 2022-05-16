// MOHAMMED RAFIQ HAMA SALIH
// SN: 2010213624
// Q3
/*In a linear linked list, write a function that deletes the element in the middle of the list (free this
memory location) (if the list has 100 or 101 elements, it will delete the 50th element). The function will
take a list as a parameter and return the updated list.*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int number;
    struct node * next;
};

typedef struct node node;
node *head;

node* createlist();
int traverselist(node* head);
node* deletemiddle(node* head,int count);

node* createlist(){
    node*p;
    int n,k;
    printf("how many numbers do you enter : ");
    scanf("%d",&n);

    for(k=0;k<n;k++){
        if(k==0){
            head=(node*)malloc(sizeof(node));
            p=head;
        }
        else{
            p->next=(node*)malloc(sizeof(node));
            p=p->next;
        }
        printf("Enter number: ");
        scanf("%d",&p->number);
    }

    p->next=NULL;
    return head;

}

int traverselist(node*head){
    node*p;
    p=head;
    int counter;
    while(p!=NULL){
        printf("%4d",p->number);
        p=p->next;
        counter++;
    }
    return counter;
}
node* deletemiddle(node* head,int count){
    node *p,*temp;
    p=head;
    int k=1;
    int mid=count/2;

    if(mid<=1){
        head=p->next;
        free(p);
    }
    else{
        while(k!=mid){
            temp=p;
            p=p->next;
            k++;
        }
        temp->next=p->next;
        free(p);
    }
 return head;
}


int main(){
    int count;
    head=createlist();
    count=traverselist(head);
    head=deletemiddle(head,count);
    count=traverselist(head);
 return 0;
}
