#include "TemplateTree.h"

int main()
{
    int OptionChoice = 0;
    VersionInstruction();
    cin>>OptionChoice;
    while(OptionChoice != 4){
        switch(OptionChoice){
            case 1:
                Version1();
                break;
            case 2:
                Version2();
                break;
            case 3:
                Version3();
                break;
            default:
                cout<<"Please Input Again"<<endl;
        }
        cout<<endl;
        VersionInstruction();
        cin>>OptionChoice;
    }
    return 0;
}
