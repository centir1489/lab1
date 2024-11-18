#pragma once
#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>

using namespace std;

    struct LNode {
        std::string Data;
        LNode* next = nullptr;
    };

    struct LinkedList{
        LNode* Head = nullptr;
        LNode* Tail = nullptr;
    };

    bool IsEmpty(LinkedList List);
    size_t LSize(LinkedList List);
    std::string LFront(LinkedList List);
    void LPUSH_BACK(LinkedList& List, std::string Value);
    void LPUSH_FRONT(LinkedList& List, std::string Value);
    void LGET(LinkedList& List);
    std::string LFIND(LinkedList List, std::string Value);
    void LPOP_FRONT(LinkedList& List);
    void LPOP_BACK(LinkedList& List);
    void LREMOVE_VALUE(LinkedList& List, std::string Value);

#endif