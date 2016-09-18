#include <stdio.h>
#include <stdlib.h>

struct node
{
        int num;
        struct node * next;
};

void node_print(struct node * head)
{
        struct node * point = NULL;

        for(point = head; point != NULL; point = point->next) {
                printf("%d -> ", point->num);
        }
}

int main()
{
        int T,N;
        int i;

        printf("Kach sayi girilecek: ");
        scanf("%d",&T);

        struct node * head = NULL;
        struct node * tail = NULL;
        struct node * point = NULL;

        for(i=0; i<T; i++) {
                printf("%d sayi giriniz: ",i+1);
                scanf("%d",&N);

                if(head != NULL){
                        point = tail;
                        tail = (struct node *)malloc(sizeof(struct node));
                        tail->num = N;
                        tail->next = NULL;
                        point->next = tail;
                } else {
                        head = (struct node *)malloc(sizeof(struct node));
                        head->num = N;
                        head->next = NULL;
                        tail = head;
                }
        }

        node_print(head);

        return 0;
}
