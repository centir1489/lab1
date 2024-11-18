#pragma once
#ifndef STACK
#define STACK

#include<iostream>
#include<string>

    struct SNode{
	    std::string Data;
	    SNode* next = nullptr;
    };
    struct Stack{
        SNode* Top = nullptr;
    };
    
    bool IsEmpty(Stack stack);
    size_t SSize(Stack stack);
    std::string Top(Stack stack);
    void SPUSH(Stack& stack, std::string Value);
    void SPOP(Stack& stack);
    void SGET(Stack stack);



#endif


