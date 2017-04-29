#include "TemplateTree.h"

void VersionInstruction(void){
    cout<<"\nWant to Save Int Then input 1"<<endl
        <<"Want to Save Float Then input 2"<<endl
        <<"Want to Save Book Then input 3"<<endl
        <<"Want to Exit Then input 4"<<endl
        <<"Please input:";
    return;
}

void Instruction(void){
    cout<<"\nWant to Input Data Then input 1"<<endl
        <<"Want to print Data By inorder Then input 2"<<endl
        <<"Want to print Data By preorder Then input 3"<<endl
        <<"Want to print Data By postorder Then input 4"<<endl
        <<"Want to Exit from this Version Then input 5"<<endl
        <<"Please input:";
}

void Version1(){
    int OptionChoice = 0, Value = -1;
    treeNodeTP<int> * RootPtr = NULL;
    Instruction();
    cin>>OptionChoice;
    while(OptionChoice != 5){
        switch(OptionChoice){
            case 1:
                cout<<"Please Input Value:";
                cin>>Value;
                insertNodeTP(RootPtr, Value);
                break;
            case 2:
                inOrderTP(RootPtr);
                break;
            case 3:
                preOrderTP(RootPtr);
                break;
            case 4:
                postOrderTP(RootPtr);
                break;
            default:
                cout<<"Please Input Again!"<<endl;
        }
        cin>>OptionChoice;
    }
}

void Version2(){
    int OptionChoice = 0;
    float Value = -1;
    treeNodeTP<float> * treeRootptr = NULL;
    Instruction();
    cin>>OptionChoice;
    while(OptionChoice != 5){
        switch(OptionChoice){
            case 1:
                cout<<"Please Input Value:";
                cin>>Value;
                insertNodeTP(treeRootptr, Value);
                break;
            case 2:
                inOrderTP(treeRootptr);
                break;
            case 3:
                preOrderTP(treeRootptr);
                break;
            case 4:
                postOrderTP(treeRootptr);
                break;
            default:
                cout<<"Please Input Again!"<<endl;
        }
        cin>>OptionChoice;
    }
}

void Version3(){
    int OptionChoice = 0;
    int Counter = 0;
    treeNodeTP<book> * rootPtr = NULL;
    book NewBook[50];
    Instruction();
    cin>>OptionChoice;
    while(OptionChoice != 5){
        int price = 0;
        char BookName[50];
        char author[50];
        switch(OptionChoice){
            case 1:
                cout<<"Please Input BookName:";
                cin>>BookName;
                cout<<"Please Input Author:";
                cin>>author;
                cout<<"Please Input Price:";
                cin>>price;
                NewBook[Counter].bookName = new char[strlen(BookName)];
                NewBook[Counter].bookName = BookName;
                NewBook[Counter].authors = new char[strlen(author)];
                NewBook[Counter].authors = author;
                NewBook[Counter].price = price;
                insertNodeTP(rootPtr, NewBook[Counter]);
                Counter += 1;
                break;
            case 2:
                inOrderTP(rootPtr);
                break;
            case 3:
                preOrderTP(rootPtr);
                break;
            case 4:
                postOrderTP(rootPtr);
                break;
            default:
                cout<<"Please Input Again!"<<endl;
        }
        cin>>OptionChoice;
    }
}

int compareFun(int treeData, int Value){
    if(Value >= treeData)return 1;
    else return 0;
}
int compareFun(float treeData, float Value){
    if(Value >= treeData)return 1;
    else return 0;
}

int compareFun(book treeData, book Value){
    int treeLength = (char)strlen(treeData.bookName);
    int NewBookLength = (char)strlen(Value.bookName);
    for(int Counter = 0;Counter < treeLength && Counter < NewBookLength;Counter++){
        if(Value.bookName[Counter] > treeData.bookName[Counter])return 1;
        else if(Value.bookName[Counter] < treeData.bookName[Counter])return 0;
    }
    if(NewBookLength >= treeLength)return 1;
    else return 0;
}

void printFun(int Value){
    cout<<Value<<"  ";
    return;
}

void printFun(float Value){
    cout<<Value<<"  ";
    return;
}

inline void printFun(book BookData){
    cout<<"BookName: "<<BookData.bookName<<"\tAuthor: "<<BookData.authors<<"\t Price: "<<BookData.price<<endl;
    return;
}
