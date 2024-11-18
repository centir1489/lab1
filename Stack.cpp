
#include"Stack.h"

bool IsEmpty(Stack stack){
    return stack.Top == nullptr;
}

size_t SSize(Stack stack){
    if(IsEmpty(stack)){
        return 0;
    }
    SNode* ptr = stack.Top;
    size_t size = 0;
    while(ptr){
        size++;
        ptr = ptr -> next;
    }
    return size;
}

std::string Top(Stack stack){
    if(IsEmpty(stack)){
        return "";
    }
    return stack.Top -> Data;
}

void SPUSH(Stack& stack, std::string Value){
    SNode* ptr = new SNode{Value, stack.Top};
    stack.Top = ptr;
}

void SPOP(Stack& stack){
    if(IsEmpty(stack)){
        return;
    }
    SNode* ptr = stack.Top;
    stack.Top = ptr -> next;
    delete ptr; 
}

void SGET(Stack stack){
    if(IsEmpty(stack)){
        return;
    }
    SNode* ptr = stack.Top;
    while(ptr){
        std::cout << ptr -> Data << ' ';
        ptr = ptr -> next;
    }
    std::cout << '\n';
}
