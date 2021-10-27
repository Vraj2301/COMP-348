#include <stdio.h>
#include <stdlib.h>
typedef enum
{
    ATOM,
    LIST
} eltype;
typedef char atom;
struct _listnode;
typedef struct
{
    eltype type;
    union
    {
        atom a;
        struct _listnode *l;
    };
} element;
typedef struct _listnode
{
    element el;
    struct _listnode *next;
} * list;
const element NIL = {.type = LIST, .l = NULL};
element aasel(atom a);
element lasel(list l);
element car(element e);
list cdr(element e);
list cddr(element e);
list cons(element e, list l);
list append(list l1, list l2);
void lfreer(list l);
void print(element e);
int main()
{
    element a = aasel('a');
    element b = aasel('b');
    element c = aasel('c');
    element d = aasel('d');
    element e = aasel('e');
    list firs = cons(lasel(cons(b, cons(c, NULL))), NULL);
    list sec = cons(a, firs);
    list thir = append(sec, cons(d, NULL));

    list fin = append(thir, cons(e, NULL));

    print(lasel(fin));

    printf("\n");
    print(car(lasel(fin)));
    printf("\n");
    print(lasel(cdr(lasel(fin))));
    printf("\n");
    print((car(car(lasel(fin)))));
    return 0;
}
element aasel(atom a)
{
    element d;
    d.type = ATOM;
    d.a = a;
    return d;
}
element lasel(list l)
{
    element d;
    d.type = LIST;
    d.l = l;
    return d;
}
element car(element e)
{
    element d;
    if (e.type != LIST)
    {
        return NIL;
    }
    d = e.l->el;
    return d;
}
list cdr(element e)
{
    list d;
    if (e.type != LIST || (e.l->el.l) == NULL)
    {
        return NULL;
    }
    else
        return e.l->next;
}
list cddr(element e)
{
    list d;
    element ed;
    if (e.type != LIST)
    {
        return NULL;
    }
    if (e.l->next == NULL)
    {
        return NULL;
    }
    ed = e.l->el;
    if (ed.type != LIST)
    {
        return NULL;
    }
    if (ed.l->next == NULL)
    {
        return NULL;
    }
    d = ed.l;
    return d;
}
list cons(element e, list l)
{
    list new_list = malloc(sizeof(struct _listnode));
    new_list->el = e;
    new_list->next = l;
    return new_list;
}
void lfreer(list l)
{
    free(l);
}
list append(list l1, list l2)
{
    list new = malloc(sizeof(struct _listnode));
    list list1 = l1;
    list list2 = new;
    while (list1 != NULL)
    {
        list2->el = list1->el;
        list1 = list1->next;
        list2->next = malloc(sizeof(list));
        list2 = list2->next;
    }
    list1 = l2;
    while (list1 != NULL)
    {
        list2->el = list1->el;
        list1 = list1->next;
        list2->next = malloc(sizeof(list));
        list2 = list2->next;
    }
    return new;
}
void print(element e)
{
    if (e.l == NULL && e.type == LIST)
    {
        printf("NIL");
    }
    else if (e.type == ATOM)
    {
        printf("  %c  ", e.a);
    }
    else
    {
        printf("%c  ", '(');
        for (list dem = e.l; dem != NULL; dem = dem->next)
        {
            if (dem->el.type == LIST)
            {
                print(dem->el);
            }
            else
                printf("%c  ", dem->el.a);
        }
        printf(" %c ", ')');
    }
}