#include<iostream>

typedef struct sll_node
{
    int Value;
    struct sll_node* prev;
}sll_node;

typedef struct sll_controller
{
    sll_node* head;
    sll_node* tail;
    int count;
}sll_controller;

sll_controller Sll_newcontroller(void);
void Sll_free(sll_controller* controller);
sll_node* sll_insert(sll_controller* controller,auto value);
sll_node* sll_makenode(int value);
int sll_remove_node(sll_controller* controller, int index);

sll_controller Sll_newcontroller(void)
{
    sll_controller new_controller;
    new_controller.count = 0;
    new_controller.head = NULL;
    return new_controller;
}
sll_node* sll_makenode(int value)
{
    sll_node* new_node {new sll_node};
    if(!new_node)
    {
        return NULL;
    }
    new_node->Value= value;
    new_node->prev = NULL;
    return new_node;
}
sll_node* sll_insert(sll_controller* controller,auto value)
{
    sll_node* node = sll_makenode(value);
    if(!node)
    {
        return NULL;
    } 
    if(controller->count==0)
    {
        controller->head = node;
        controller->tail = node;
    }
    else
    {
        node->prev = controller.head;
        controller.head = node;
    }
    
    controller.count++;
    return node;
}
int sll_remove_node(sll_controller* controller, int index)
{
    sll_node* temp_node = controller->head;
    sll_node* old_temp_node;
    for(int i = 0; i<index; i++)
    {
        old_temp_node = temp_node;
        temp_node = temp_node->prev;
    }
    if(index == 0)
    {
        controller->head = temp_node->prev;
    }
    else if(index+1 == controller->count)
    {
        old_temp_node->prev = NULL;
        controller->tail = old_temp_node;
    }
    else
    {
        old_temp_node->prev = temp_node->prev;
    }
    delete []temp_node;
    delete temp_node;
    return 0;
}
