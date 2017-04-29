#ifndef TEMPLATETREE.H
#define TEMPLATETREE.H

#include <iostream>
#include <cstring>

using namespace std;

struct book{
	char * bookName;  //書名當成 key 來比較大小
	char * authors;
	int price;
};

int compareFun(book, book);
inline void printFun(book);
int compareFun(int a, int b); 		//比較int資料大小
int compareFun(float a, float b);	//比較float資料大小
void printFun(int a);
void printFun(float a);
void Instruction(void);
void VersionInstruction(void);
void Version1(void);
void Version2(void);
void Version3(void);

template<typename T>
struct treeNodeTP {
	struct treeNodeTP *leftPtr;
	T data;
	struct treeNodeTP *rightPtr;
};

template<typename T>
void insertNodeTP ( treeNodeTP<T> * &treePtr, T value ){
    if(treePtr == NULL){
        treeNodeTP<T> * Temp = new treeNodeTP<T>;
        Temp->data = value;
        InitialLink(Temp);
        treePtr = Temp;
        return;
    }
    if(compareFun(treePtr->data, value)){
        insertNodeTP(treePtr->rightPtr, value);
    }else{
        insertNodeTP(treePtr->leftPtr, value);
    }
}

template<typename T>
void inOrderTP ( treeNodeTP<T> * treePtr ){
    if(treePtr == NULL)return;
    inOrderTP(treePtr->leftPtr);
    printFun(treePtr->data);
    inOrderTP(treePtr->rightPtr);
    return;
 }

template<typename T>
void preOrderTP ( treeNodeTP<T> * treePtr ){
    if(treePtr == NULL)return;
    printFun(treePtr->data);
    preOrderTP(treePtr->leftPtr);
    preOrderTP(treePtr->rightPtr);
    return;
 }

template<typename T>
void postOrderTP ( treeNodeTP<T> * treePtr ){
    if(treePtr == NULL)return;
    postOrderTP(treePtr->leftPtr);
    postOrderTP(treePtr->rightPtr);
    printFun(treePtr->data);
    return;
}


template<typename T>
void InitialLink(treeNodeTP<T> * &treeptr){
    treeptr->leftPtr = NULL;
    treeptr->rightPtr = NULL;
}

#endif // TEMPLATETREE
