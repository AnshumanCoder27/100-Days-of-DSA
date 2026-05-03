/**/
typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct {
    node *top;
    node *min;
} MinStack;

MinStack* minStackCreate() {
    MinStack *s = (MinStack*)malloc(sizeof(MinStack));
    s->top = NULL;
    s->min = NULL;
    return s;
}

void minStackPush(MinStack* obj, int val) {
    node *t = (node*)malloc(sizeof(node));
    t->data = val;
    t->next = obj->top;
    obj->top = t;

    node *m = (node*)malloc(sizeof(node));
    if (obj->min == NULL || val <= obj->min->data)
        m->data = val;
    else
        m->data = obj->min->data;
    m->next = obj->min;
    obj->min = m;
}

void minStackPop(MinStack* obj) {
    node *t = obj->top;
    obj->top = obj->top->next;
    free(t);

    node *m = obj->min;
    obj->min = obj->min->next;
    free(m);
}

int minStackTop(MinStack* obj) {
    return obj->top->data;
}

int minStackGetMin(MinStack* obj) {
    return obj->min->data;
}

void minStackFree(MinStack* obj) {
    node *t;
    while (obj->top) { t = obj->top; obj->top = obj->top->next; free(t); }
    while (obj->min) { t = obj->min; obj->min = obj->min->next; free(t); }
    free(obj);
}