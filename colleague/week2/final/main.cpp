#include "struct.h"

int main()
{
    int FuncOption;
    const int CardMax = 52;
    Card Deck[CardMax];
    DealCard(Deck);
    cout<<"�п�J�Ʀr1~6\n1.��@�I��J�P�H���~�P"
        <<"\n2.��P�Ƨ�(�����ƦC)\n3.��P�Ƨ�(�Ʀr���ƦC)"
        <<"\n4.��P����4��(�C��13) �C�դ��O�Ƨ�(�����ƦC)"
        <<"\n5.��P����4��	�C�դ��O�Ƨ�(�Ʀr���ƦC)"
        <<"\n6.�{������"<<endl;
    cin>>FuncOption;
    while(FuncOption!=6)
    {
        switch(FuncOption)
        {
            case 1:
                cout<<endl;
                Shuffle(Deck);
                break;
            case 2:
                SuitSpadesNumbig(Deck);
                break;
            case 3:
                NumbigSuitSpades(Deck);
                break;
            case 4:
                TeamSuitSpadesNumbig(Deck, 0);
                cout<<endl;
                TeamSuitSpadesNumbig(Deck, 13);
                cout<<endl;
                TeamSuitSpadesNumbig(Deck, 26);
                cout<<endl;
                TeamSuitSpadesNumbig(Deck, 39);
                cout<<endl;
                break;
            case 5:
                TeamNumbigSuitSpades(Deck, 0);
                cout<<endl;
                TeamNumbigSuitSpades(Deck, 13);
                cout<<endl;
                TeamNumbigSuitSpades(Deck, 26);
                cout<<endl;
                TeamNumbigSuitSpades(Deck, 39);
                cout<<endl;
                break;
            default:
                cout<<"��J�L�ļƦr"<<endl;
        }
        cout<<"�п�J�Ʀr1~6: ";
        cin>>FuncOption;
    }
}
