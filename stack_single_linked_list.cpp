#include <iostream>
#include <string>

using namespace std;

struct sll_node
{
    int Value;
    sll_node* prev;
};

struct sll_controller
{
    sll_node* head;
    sll_node* tail;
    int count;
};

sll_controller Sll_newcontroller(void);
void sll_free(sll_controller* controller);
sll_node* sll_insert(sll_controller* controller, int value);
sll_node* sll_makenode(int value);
int sll_remove_node(sll_controller* controller, int index);

sll_controller Sll_newcontroller(void)
{
    sll_controller new_controller;
    new_controller.count = 0;
    new_controller.head = NULL;
    new_controller.tail = NULL;
    return new_controller;
}

sll_node* sll_makenode(int value)
{
    sll_node* new_node = new sll_node;
    if (!new_node)
    {
        return NULL;
    }
    new_node->Value = value;
    new_node->prev = NULL;
    return new_node;
}

sll_node* sll_insert(sll_controller* controller, int value)
{
    sll_node* node = sll_makenode(value);
    if (!node)
    {
        return NULL;
    }
    if (controller->count == 0)
    {
        controller->head = node;
        controller->tail = node;
    }
    else
    {
        node->prev = controller->head;
        controller->head = node;
    }

    controller->count++;
    return node;
}

int sll_remove_node(sll_controller* controller, int index)
{
    if (index < 0 || index >= controller->count)
    {
        return -1; // Index out of bounds
    }

    sll_node* temp_node = controller->head;
    if (index == 0)
    {
        controller->head = temp_node->prev;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            temp_node = temp_node->prev;
        }
        sll_node* old_temp_node = temp_node;
        temp_node = temp_node->prev;

        if (index == controller->count - 1)
        {
            old_temp_node->prev = NULL;
            controller->tail = old_temp_node;
        }
        else
        {
            old_temp_node->prev = temp_node->prev;
        }
    }
    delete temp_node;
    controller->count--;
    return 0;
}

struct sll_stack
{
    sll_controller stack_controller = Sll_newcontroller();
};

int stack_push(sll_stack& stack, int value)
{
    sll_node* node = sll_insert(&stack.stack_controller, value);
    if (!node)
    {
        return -1;
    }
    return 0;
}

int stack_pop(sll_stack& stack)
{
    sll_remove_node(&stack.stack_controller, 0);
    return 0;
}

bool stack_isEmpty(sll_stack& stack)
{
    return stack.stack_controller.count == 0;
}

int sizeof_stack(sll_stack& stack)
{
    return stack.stack_controller.count;
}

int stack_top(sll_stack& stack)
{
    return stack.stack_controller.head->Value;
}
void sll_free(sll_controller* controller)
{
    sll_node* current = controller->head;
    while (current != NULL)
    {
        sll_node* temp = current;
        current = current->prev;
        delete temp;
    }
    controller->head = NULL;
    controller->tail = NULL;
    controller->count = 0;
}

int main()
{
    sll_stack stack;
    string command;
    int value;
    cout << "Enter a command: ";
    cin >> command;
    while (command != "exit")
    {
        if (command == "push")
        {
            cout << "Enter a value: ";
            cin >> value;
            stack_push(stack, value);
        }
        else if (command == "pop")
        {
            stack_pop(stack);
            cout << "Pop operation successful." << endl;
        }
        else if (command == "isempty")
        {
            if (!stack_isEmpty(stack))
            {
                cout << "Stack is not empty" << endl;
            }
            else
            {
                cout << "Stack is empty" << endl;
            }
        }
        else if (command == "size")
        {
            cout << "Size: " << sizeof_stack(stack) << endl;
        }
        else if (command == "top")
        {
            cout << "Top value: " << stack_top(stack) << endl;
        }
        else
        {
            cout << "Invalid command" << endl;
        }
        cout << "Enter a command: ";
        cin >> command;
    }
    sll_free(&stack.stack_controller);
    return 0;
}
