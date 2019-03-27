#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _employee
{
    char name[32];
    int age;
} Employee;
typedef struct _node
{
    void *data;
    struct _node *next;
} Node;
typedef struct _linkedlist
{
    Node *head;
    Node *tail;
    int size;
} Linkedlist;
typedef void (*DISPLAY)(void *);
typedef int (*COMPARE)(void *, void *);

// Node *getNode(Linkedlist *m COMPARE, void *);
void initializeList(Linkedlist *);
void addHead(Linkedlist *, void *);
void addTail(Linkedlist *, void *);
void deleteNode(Linkedlist *, Node *);
Node *getNode(Linkedlist *, COMPARE, void *);
int compareEmployee(Employee *, Employee *);
void displayEmployee(Employee *);
void displayLinkedList(Linkedlist *, DISPLAY);

int main()
{
    Linkedlist ll;
    Employee *migu = (Employee *)malloc(sizeof(Employee));
    strcpy(migu->name, "Migu");
    migu->age = 31;

    Employee *esther = (Employee *)malloc(sizeof(Employee));
    strcpy(esther->name, "Esther");
    esther->age = 27;

    Employee *aranzi = (Employee *)malloc(sizeof(Employee));
    strcpy(aranzi->name, "Aranzi");
    aranzi->age = 3;

    Employee *gabby = (Employee *)malloc(sizeof(Employee));
    strcpy(gabby->name, "Gabby");
    gabby->age = 28;

    Employee *maggie = (Employee *)malloc(sizeof(Employee));
    strcpy(maggie->name, "Maggie");
    maggie->age = 26;

    Employee *polly = (Employee *)malloc(sizeof(Employee));
    strcpy(polly->name, "Polly");
    polly->age = 29;

    initializeList(&ll);
    addHead(&ll, migu);
    addHead(&ll, esther);
    addHead(&ll, aranzi);
    addTail(&ll, gabby);
    addTail(&ll, polly);
    addTail(&ll, maggie);
    Node *del_node = getNode(&ll, (int (*)(void *, void *))compareEmployee, esther);
    deleteNode(&ll, del_node);
    displayLinkedList(&ll, (DISPLAY)displayEmployee);

    return 0;
}
void initializeList(Linkedlist *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}
void addTail(Linkedlist *ll, void *data)
{

    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    Node *cur = ll->tail;
    if (cur == NULL)
    {
        ll->head = node;
        ll->tail = node;
        ll->size += 1;
    }
    else
    {
        cur->next = node;
        ll->tail = node;
        ll->size += 1;
    }
}
Node *getNode(Linkedlist *ll, COMPARE compare, void *data)
{
    Node *cur = ll->head;
    while (cur != NULL)
    {
        if (compare(cur->data, data) == 0)
        {
            printf("%s\n", data);
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}
void deleteNode(Linkedlist *ll, Node *node)
{
    if (ll->head == NULL)
        return;

    Node *pre = NULL;
    Node *cur = ll->head;
    int isfind = 0;
    while (cur != NULL)
    {
        if (cur->data == node->data)
        {
            isfind = 1;
            break;
        }
        pre = cur;
        cur = cur->next;
    }
    if (!isfind)
    {
        printf("No this node\n");
        return;
    }
    //deleate
    //1. head 2.middle 3. tail
    if (cur->data == ll->head->data)
    {
        //1.head -> (1)head->next is NULL (2)head->next is not NULL
        if (cur->next == NULL)
        {
            ll->head = NULL;
            ll->tail == NULL;
            ll->size -= 1;
        }
        else
        {
            cur->next = ll->head;
            ll->size -= 1;
        }
    }
    else
    {
        if (cur->next == NULL)
        {
            pre->next = NULL;
            ll->size -= 1;
        }
        else
        {
            pre->next = cur->next;
            ll->size -= 1;
        }
    }
    free(node);
}
int compareEmployee(Employee *data1, Employee *data2)
{
    return strcmp(data1->name, data2->name);
}
void displayEmployee(Employee *e)
{
    printf("%s \t%d\n", e->name, e->age);
}
void displayLinkedList(Linkedlist *ll, DISPLAY display)
{
    printf("\n --Linked List-- \n");
    Node *cur = ll->head;
    while (cur != NULL)
    {
        display(cur->data); //employee
        cur = cur->next;
    }
    printf("\nhead: ");
    display(ll->head->data);
    printf("tail: ");
    display(ll->tail->data);
    printf("size: %d", ll->size);
}

void addHead(Linkedlist *ll, void *data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    if (ll->head == NULL)
    {
        ll->tail = node;
        node->next = NULL;
        ll->size += 1;
    }
    else
    {
        node->next = ll->head;
        ll->size += 1;
    }
    ll->head = node;
}
// int arr[3][2] = {{10, 20}, {30, 40}, {50, 60}};
// int *p = *arr;
// printf("*(*arr + 0):%d\n", *(*arr + 0));
// printf("*(*arr + 1):%d\n", *(*arr + 1));
// printf("*(*(arr + 1) + 0):%d\n", *(*(arr + 1) + 0));
// printf("*(*(arr + 1) + 1):%d\n", *(*(arr + 1) + 1));
// printf("*(*(arr + 1) + 1):%d\n", *(*(arr + 2) + 0));
// printf("*(*(arr + 1) + 1):%d\n", *(*(arr + 2) + 1));
