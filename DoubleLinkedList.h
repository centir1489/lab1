#pragma once
#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST
#include<iostream>

    struct DNode{
        std::string Data;
        DNode* next = nullptr;
        DNode* prev = nullptr;
    };

    struct DoubleLinkedList{
        DNode* Head = nullptr;
        DNode* Tail = nullptr;
    };

    bool IsEmpty(DoubleLinkedList List);
    size_t DSize(DoubleLinkedList List);
    std::string DFront(DoubleLinkedList List);
    void DGET(DoubleLinkedList DList);
    void DPUSH_BACK(DoubleLinkedList& DList, std::string Value);
    void DPUSH_FRONT(DoubleLinkedList& DList, std::string Value);
    void DPOP_FRONT(DoubleLinkedList& DList);
    void DPOP_BACK(DoubleLinkedList& DList);
    void DREMOVE_VALUE(DoubleLinkedList& List, std::string Value);
    std::string DFIND(DoubleLinkedList List, std::string Value);


#endif