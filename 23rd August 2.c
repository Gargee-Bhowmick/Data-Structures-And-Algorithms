//-------REVERSE LINKED LIST-------- 
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int roll;
    struct node *next;
} * NODE;

NODE start = NULL;

NODE create(NODE start)
{
    NODE new_node;
    int x;
    printf("Enter -1 to End\n");
    printf("Enter the roll: ");
    scanf("%d", &x);
    while (x != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->roll = x;
        if (start == NULL)
        {
            start = new_node;
            new_node->next = NULL;
        }
        else
        {
            new_node->next = start;
            start = new_node;
        }
        printf("Enter the roll: ");
        scanf("%d", &x);
    }
    return start;
}

void display(NODE start)
{
    NODE ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf("%d ", ptr->roll);
        ptr = ptr->next;
    }
}

int count_node(NODE start)
{
    NODE ptr = start;
    int c = 0;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        c++;
    }
    return c;
}

NODE reverse(NODE start)
{
    NODE ptr=NULL,temp=NULL;
    while(start!=NULL)
    {
        temp=ptr;
        ptr=start;
        start=start->next;
        ptr->next=temp;
    }
    start=ptr;
    return start;
}

int main()
{
    NODE LL;
    LL = create(start);
    display(LL);
    printf("\n");
    NODE SLL;
    SLL = reverse(LL);
    display(SLL);
    printf("\n");
}
