#pragma once
#include"AuxiliaryFile.h"
#include<cstdlib>

Massiv<std::string> LISTCOMMAND = {
    "MPUSH", "MPUSHINDEX", "MPOP", "MLENGTH", "MGET",
    "LPUSH_FRONT", "LPUSH_BACK", "LPOP_FRONT", "LPOP_BACK", "LREMOVE_VALUE", "LFIND", "LGET",
    "DPUSH_FRONT", "DPUSH_BACK", "DPOP_FRONT", "DPOP_BACK", "DREMOVE_VALUE", "DFIND", "DGET",
    "SPUSH", "SPOP", "SGET",
    "QPUSH", "QPOP", "QGET",
    "HPUSH", "HDEL", "HFIND", "HGET",
    "TPUSH", "TDEL", "TFIND", "TGET",   
    "USETADD", "USETDELL", "USET_AT", "USETLENGTH", "USETGET", "USETGETLINE"
};

enum EnumStructurs{
    _Massiv = 1,
    _LinkedList = 2,
    _DoubleLinkedList = 3,
    _Stack = 4,
    _Queue = 5,
    _Set = 8
};


//const filesystem::path STARTEDPATH = "/home/lendell/Документы/Университет/2 Курс/Семестр 3/1. Программирование/repa/lab1/datajson/";


// преобразование входных значений в массив
Massiv<std::string> argvToMass(int argc, char* argv[]){
    Massiv<std::string> retMass;
    if(argc < 4 || argc > 8){
        cerr << "Неверный ввод команды!\n\n";
    }
    for(size_t q = 1; q < argc; q++){
        retMass.MPUSH(argv[q]);
    }
    return retMass;
}
// std::string NameFile, Command, NameStructur, Value1, Value2;
//./dbms --file file.data --query SPUSH mystack item
void assignmentProcess(Massiv<std::string> controlMass, std::string& NameFile, std::string& Command, std::string& NameStructur, std::string& Value1, std::string& Value2){
    if(controlMass[0] == "--file"){
        NameFile = controlMass[1]; // имя файла
    }
    else{
        cerr << "Ошибка! Некоректное использование --file\n";
        return;
    }
    if(controlMass[2] == "--query"){
        Command = controlMass[3];
        if(Command == "HPUSH" || Command == "MPUSHINDEX"){
            if(controlMass.Size != 7){
                cerr << "Ошибка! Некоректное создание пары <ключ, значение>\n";
                return;
            }
            NameStructur = controlMass[4];
            Value1 = controlMass[5];
            Value2 = controlMass[6];
        }
        else if(controlMass.MLength() > 5){
            NameStructur = controlMass[4];
            Value1 = controlMass[5];
        }
        else{
            NameStructur = controlMass[4];
        }    
    }
    else{
        cerr << "Ошибка! Некоректное использование --query\n";
        return;
    }
}

void CheckCommand(std::string Command){
    for(size_t q = 0; q < LISTCOMMAND.MLength(); q++){
        if(Command == LISTCOMMAND[q]){
            return;
        }
    }
    cerr << "Данная команда либо неправильная, либо не поддерживается!\n";
}

size_t assignmentEntry(std::string Command){
    size_t choice;
    if(Command[0] == 'H'){
        return 2;
    }  
    else if(Command[0] == 'T'){
        return 3;
    }
    return 1;
}

size_t concrectAssigmentStruct(std::string Command){
    char symb = Command[0];
    if(symb == 'M'){
        return 1;
    }
    else if(symb == 'L'){
        return 2;
    }
    else if(symb == 'D'){
        return 3;
    }
    else if(symb == 'S'){
        return 4;
    }
    else if(symb == 'Q'){
        return 5;
    }
    else if(symb == 'H'){
        return 6;
    }
    else if(symb == 'T'){
        return 7;
    }
    else if(symb == 'U'){
        return 8;
    }
    return 0;
}


void CaseMassiv(Massiv<std::string>& mass, std::string Command, std::string Value1, std::string Value2){
    if(Command == "MPUSH"){
        mass.MPUSH(Value1);
    }
    else if(Command == "MPUSHINDEX"){
        mass.MPushIndex(atoi(Value1.c_str()), Value2);
    }
    else if(Command == "MPOP"){
        mass.MPOP(atoi(Value1.c_str()));
    }
    else if(Command == "MLENGTH"){
        std::cout << mass.MLength() << '\n';
    }
    else if(Command == "MGET"){
        mass.MGET();
    }
    else{
        cerr << "Что-то пошло не так\n";
    }
}


void CaseLinkedList(LinkedList& list, std::string Command, std::string Value){
    if(Command == "LPUSH_FRONT"){
        LPUSH_FRONT(list, Value);
    }
    else if(Command == "LPUSH_BACK"){
        LPUSH_BACK(list, Value);
    }
    else if(Command == "LPOP_FRONT"){
        LPOP_FRONT(list);
    }
    else if(Command == "LPOP_BACK"){
        LPOP_BACK(list);
    }
    else if(Command == "LREMOVE_VALUE"){
        LREMOVE_VALUE(list, Value);
    }
    else if(Command == "LFIND"){
        std::cout << LFIND(list, Value) << '\n';
    }
    else if(Command == "LGET"){
        LGET(list);
    }
    else{
        cerr << "Что-то пошло не так\n";
    }
}


void CaseDoubleLinkedList(DoubleLinkedList& list, std::string Command, std::string Value){
    if(Command == "DPUSH_FRONT"){
        DPUSH_FRONT(list, Value);
    }
    else if(Command == "DPUSH_BACK"){
        DPUSH_BACK(list, Value);
    }
    else if(Command == "DPOP_FRONT"){
        DPOP_FRONT(list);
    }
    else if(Command == "DPOP_BACK"){
        DPOP_BACK(list);
    }
    else if(Command == "DREMOVE_VALUE"){
        DREMOVE_VALUE(list, Value);
    }
    else if(Command == "DFIND"){
        std::cout << DFIND(list, Value) << '\n';
    }
    else if(Command == "DGET"){
        DGET(list);
    }
    else{
        cerr << "Что-то пошло не так\n";
    }
}


void CaseStack(Stack& stack, std::string Command, std::string Value){
    if(Command == "SPUSH"){
        SPUSH(stack, Value);
    }
    else if(Command == "SPOP"){
        SPOP(stack);
    }
    else if(Command == "SGET"){
        SGET(stack);
    }
}

void CaseQueue(Queue& queue, std::string Command, std::string Value){
    if(Command == "QPUSH"){
        QPUSH(queue, Value);
    }
    else if(Command == "QPOP"){
        QPOP(queue);
    }
    else if(Command == "QGET"){
        QGET(queue);
    }
}

void CaseSet(uSet& set, std::string Command, std::string Value1){
    if(Command == "USETADD"){
        set.SETADD(Value1);
    }
    else if(Command == "USETDEL"){
        set.SETDEL(Value1);
    }
    else if(Command == "USET_AT"){
        std::cout << set.SET_AT(Value1) << '\n';
    }
    else if(Command == "USETLENGTH"){
        std::cout << set.SETLength() << '\n';
    }
    else if(Command == "USETGET"){
        set.SETGET();
    }
    else if(Command == "USETGETLINE"){
        set.SETGETLINE();
    }
}

void CaseHashTable(HashTable& HT, std::string Command, std::string Value1, std::string Value2){
    if(Command == "HPUSH"){
        HT.HPUSH(Value1, Value2);
    }
    else if(Command == "HDEL"){
        HT.HDEL(Value1);
    }
    else if(Command == "HFIND"){
        std::cout << HT.HFIND(Value1) << '\n';
    }
    else if(Command == "HGET"){
        HT.HGET();
    }
}

void CaseAVLTree(ANode*& NTree, std::string Command, std::string Value){
    if(Command == "TPUSH"){
        TPUSH(NTree, atoi(Value.c_str()));
    }
    else if(Command == "TDEL"){
        TDEL(NTree, atoi(Value.c_str()));
    }
    else if(Command == "TFIND"){
        std::cout << TFIND(NTree, atoi(Value.c_str())) << '\n';
    }
    else if(Command == "TGET"){
        TGET(NTree);
    }
}



void CaseSPS(strData& entry, std::string Command, std::string Value1, std::string Value2, size_t codeStructu){
    switch(codeStructu){
        case EnumStructurs::_Massiv:{
            Massiv<std::string> mass = convertMassiv(entry);
            CaseMassiv(mass, Command, Value1, Value2);
            entry = MassToEntry(mass);
            break;

        }
        case EnumStructurs::_LinkedList:{
            LinkedList list = convertLinkedList(entry);
            CaseLinkedList(list, Command, Value1);
            entry = LinkedListToEntry(list);
            break;
        }
        case EnumStructurs::_DoubleLinkedList:{
            DoubleLinkedList list = converDoubletLinkedList(entry);
            CaseDoubleLinkedList(list, Command, Value1);
            entry = DoubleLinkedListToEntry(list);
            break;
        }
        case EnumStructurs::_Stack:{
            Stack stack = convertStack(entry);
            CaseStack(stack, Command, Value1);
            entry = StackToEntry(stack);
            break;
        }
        case EnumStructurs::_Queue:{
            Queue queue = convertQueue(entry);
            CaseQueue(queue, Command, Value1);
            entry = QueueToEntry(queue);
            break;
        }
        case EnumStructurs::_Set:{
            uSet set = convertSet(entry);
            CaseSet(set, Command, Value1);
            entry = SetToEntry(set);
            break;
        }
        default:{
            break;
        }
    }
}


void CaseCtrllHT(HData& entry, std::string Command, std::string Value1, std::string Value2){
    HashTable HT = convertHT(entry);
    CaseHashTable(HT, Command, Value1, Value2);
    entry = HTToEntry(HT);
}


void CaseCtrllAVLTree(IntegData& entry, std::string Command, std::string Value){
    ANode* NTree = convertAVLTree(entry);
    CaseAVLTree(NTree, Command, Value);
    entry = AVLTreeToEntry(NTree);
}

void WorkTerminal(std::string NameFile, std::string Command, std::string NameStructur, std::string Value1, std::string Value2){
    size_t codeStructu = concrectAssigmentStruct(Command);
    switch(assignmentEntry(Command)){
        case 1:{
            strData entry = readstrJSON(NameFile, NameStructur, codeStructu);
            entry.Structu = definieTypeStructu(codeStructu);
            CaseSPS(entry, Command, Value1, Value2, codeStructu);

            entry.Name = NameStructur;
            PushJSON(NameFile, entry);
            
            break;
        }
        case 2:{
            HData entry = readHTJSON(NameFile, NameStructur, codeStructu);
            entry.Structu = definieTypeStructu(codeStructu);
            
            CaseCtrllHT(entry, Command, Value1, Value2);
            entry.Name = NameStructur;
            PushJSON(NameFile, entry);
            break;
        }
        case 3:{
            IntegData entry = readintegJSON(NameFile, NameStructur, codeStructu);
            entry.Structu = definieTypeStructu(codeStructu);
            CaseCtrllAVLTree(entry, Command, Value1);
            entry.Name = NameStructur;
            PushJSON(NameFile, entry);
            break;
        }
        default:{
            break;
        }
    } 
}