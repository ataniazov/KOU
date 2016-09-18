#include <stdio.h>
#include <stdlib.h>

struct node {
        int num;
        struct node * next;
};

struct node * conv2list(int * dizi, int N);

int main() {

        int dizi[] = {1,2,3,4,5};
        int N = 5;

        struct node * head = conv2list(dizi,N);
        struct node * p = (struct node *)malloc(sizeof(struct node));

        for(p = head ; p != NULL; p=p->next){
                printf("%d->",p->num);
        }

        return 0;
}

struct node * conv2list(int * dizi, int N)
{
        struct node * head = (struct node *)malloc(sizeof(struct node));
        struct node * end;
        struct node * p;

        int i;

        head->num = *dizi;
        head->next = NULL;
        end = head;

        for(i=1; i<N; i++) {
                p = (struct node *)malloc(sizeof(struct node));
                p->num = * (dizi + i);
                p->next = NULL;
                end->next = p;
                end = p;
        }

        return head;
}
