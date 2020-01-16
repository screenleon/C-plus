#include "struct.h"

int main()
{
    int FuncOption;
    const int CardMax = 52;
    Card Deck[CardMax];
    DealCard(Deck);
    cout<<"請輸入數字1~6\n1.把一付樸克牌隨機洗牌"
        <<"\n2.把牌排序(花色先排列)\n3.把牌排序(數字先排列)"
        <<"\n4.把牌分成4組(每組13) 每組分別排序(花色先排列)"
        <<"\n5.把牌分成4組	每組分別排序(數字先排列)"
        <<"\n6.程式結束"<<endl;
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
                cout<<"輸入無效數字"<<endl;
        }
        cout<<"請輸入數字1~6: ";
        cin>>FuncOption;
    }
}
