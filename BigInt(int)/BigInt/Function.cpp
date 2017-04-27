#include "BigInt.h"

BigInt::BigInt(string Value, int NumberSize){
    Number = new int[NumberSize];
    Size = NumberSize;
    Zero();
    InputNumber(Value);
}

BigInt::BigInt(int Value, int NumberSize){
    Number = new int[NumberSize];
    Size = NumberSize;
    Zero();
    InputNumber(Value);
}

BigInt::BigInt(){
    const int NumberSize = 100;
    Number = new int[NumberSize];
    Size = NumberSize;
    Zero();
}

BigInt::BigInt(BigInt & a){
    LargeInt Input;
    Input = a.GetBigInt();
    const int NumberSize = 100;
    Number = new int[NumberSize];
    Number = Input.Number;
    NumberDigits = Input.NumberDigits;
}

BigInt::~BigInt(){
    delete Number;
}

void BigInt::Zero(){
    if(Size > 0){
        NumberDigits = 1;
        Number[0] = 0;
    }else{
        Number = new int[100];
        Size = 100;
        Zero();
    }
    return;
}

void BigInt::ResizeSize(const int ArraySize){
    Number = (int*)realloc(Number, (ArraySize + 1) * sizeof(int));
    Size = ArraySize + 1;
    return;
}

void BigInt::InputNumber(string InputNumber1){
    int Start = 0;
    int AddDigit;
    {
        for(int Counter = 0;InputNumber1[Counter] == '0';Start += 1){
            Counter++;
        }
        AddDigit = InputNumber1.size() - Start;
    }
    if(Size < AddDigit){
        ResizeSize(AddDigit);
    }
    for(int Counter = Start;Counter< AddDigit + Start;Counter++){
        Number[Counter - Start] = InputNumber1[Counter] - '0';
    }
    NumberDigits = AddDigit;
    return;
}

void BigInt::InputNumber(int Input){
    int number = Input;
    int AddDigit = 0; do { number /= 10; AddDigit++; } while (number != 0);
    if(Size < AddDigit){
        ResizeSize(AddDigit);
    }
    number = Input;
    for(int Counter = AddDigit - 1;Counter >= 0;Counter--){
        Number[Counter] = Input % 10;
        Input /= 10;
    }
    NumberDigits = AddDigit;
    return;
}

void BigInt::Add(BigInt & Number2){
    LargeInt Input = Number2.GetBigInt();
    if(Size < Input.NumberDigits){
        ResizeSize(Input.NumberDigits);
    }
    if(NumberDigits >= Input.NumberDigits){
        int CarryOut = 0;
        int Counter1 = NumberDigits - 1;
        int Counter2 = Input.NumberDigits - 1;
        for(;Counter2 >= 0; Counter1--, Counter2--){
            Number[Counter1] = Number[Counter1] + Input.Number[Counter2]+ CarryOut;
            CarryOut = IsCarryOut(Number[Counter1]);
        }
        while(CarryOut == 1){
            Number[Counter1] = Number[Counter1] + CarryOut;
            CarryOut = IsCarryOut(Number[Counter1]);
            Counter1--;
        }
    }else{
        int CarryOut = 0;
        int Counter1 = NumberDigits - 1;
        int Counter2 = Input.NumberDigits - 1;
        for(;Counter1 >= 0; Counter1--, Counter2--){
            Input.Number[Counter2] = Number[Counter1] + Input.Number[Counter2] + CarryOut;
            CarryOut = IsCarryOut(Input.Number[Counter2]);
        }
        while(CarryOut == 1){
            Input.Number[Counter2] = Input.Number[Counter2] + CarryOut;
            CarryOut = IsCarryOut(Input.Number[Counter2]);
            Counter2 -= 1;
        }
        for(int Counter = 0;Counter < Input.NumberDigits;Counter++){
            Number[Counter] = Input.Number[Counter];
        }
        NumberDigits = Input.NumberDigits;
    }
}

void BigInt::Add(string ANumber){
    int Start = 0;
    int AddDigit;
    {
        for(int Counter = 0;ANumber[Counter] == '0';Start += 1){
            Counter++;
        }
        AddDigit = ANumber.size() - Start;
    }
    string AddNumber = ANumber;
    if(Size < AddDigit){
        ResizeSize(AddDigit);
    }
    if(NumberDigits >= AddDigit){
        int CarryOut = 0;
        int Counter1 = NumberDigits - 1;
        int Counter2 = AddDigit - 1;
        for(;Counter2 >= 0; Counter1--, Counter2--){
            Number[Counter1] = Number[Counter1] + AddNumber[Counter2] - '0'+ CarryOut;
            CarryOut = IsCarryOut(Number[Counter1]);
        }
        while(CarryOut == 1){
            Number[Counter1] = Number[Counter1] + CarryOut;
            CarryOut = IsCarryOut(Number[Counter1]);
            Counter1--;
        }
    }else{
        int CarryOut = 0;
        int Counter1 = NumberDigits - 1;
        int Counter2 = AddDigit - 1;
        for(;Counter1 >= 0; Counter1--, Counter2--){
            AddNumber[Counter2] = Number[Counter1] + AddNumber[Counter2]+ CarryOut;
            CarryOut = IsCarryOut(AddNumber[Counter2]);
        }
        while(CarryOut == 1){
            AddNumber[Counter2] = AddNumber[Counter2] + CarryOut;
            CarryOut = IsCarryOut(AddNumber[Counter2]);
            Counter2--;
        }
        for(int Counter = Start;Counter < AddDigit + Start;Counter++){
            Number[Counter] = AddNumber[Counter] - '0';
        }
        NumberDigits = AddDigit;
    }
}

void BigInt::Add(int Input){
    int number = Input;
    int AddDigit = 0; do { number /= 10; AddDigit++; } while (number != 0);
    int AddNumber[AddDigit + 1];
    if(Size < AddDigit){
        ResizeSize(AddDigit);
    }
    number = Input;
    for(int Counter = AddDigit - 1;Counter >= 0;Counter--){
        AddNumber[Counter] = Input % 10;
        Input /= 10;
    }
    if(NumberDigits >= AddDigit){
        int CarryOut = 0;
        int Counter1 = NumberDigits - 1;
        int Counter2 = AddDigit - 1;
        for(;Counter2 >= 0; Counter1--, Counter2--){
            Number[Counter1] = Number[Counter1] + AddNumber[Counter2]+ CarryOut;
            CarryOut = IsCarryOut(Number[Counter1]);
        }
        while(CarryOut == 1){
            Number[Counter1] = Number[Counter1] + CarryOut;
            CarryOut = IsCarryOut(Number[Counter1]);
            Counter1 -= 1;
        }
    }else{
        int CarryOut = 0;
        int Counter1 = NumberDigits - 1;
        int Counter2 = AddDigit - 1;
        for(;Counter1 >= 0; Counter1--, Counter2--){
            AddNumber[Counter1] = Number[Counter1] + AddNumber[Counter2] + CarryOut;
            CarryOut = IsCarryOut(AddNumber[Counter2]);
        }
        while(CarryOut == 1){
            AddNumber[Counter2] = AddNumber[Counter2] + CarryOut;
            CarryOut = IsCarryOut(AddNumber[Counter2]);
            Counter2 -= 1;
        }
        for(int Counter = 0;Counter < AddDigit;Counter++){
            Number[Counter] = AddNumber[Counter];
        }
        NumberDigits = AddDigit;
    }
}

int IsCarryOut(int & AdjustData){
    if(AdjustData > 9){
        AdjustData -= 10;
        return 1;
    }else return 0;
}

int IsCarryOut(char & AdjustData){
    if(AdjustData - '0' > 9){
        AdjustData -= 10;
        return 1;
    }else return 0;
}

void BigInt::PrintValue(){
    for(int Counter = 0;Counter < NumberDigits;Counter++){
        cout<<Number[Counter];
    }
    cout<<endl;
    return;
}

LargeInt BigInt::GetBigInt(){
    LargeInt Temp;
    Temp.Number = new int[NumberDigits];
    for(int Counter = 0;Counter < NumberDigits;Counter++){
        Temp.Number[Counter] = Number[Counter];
    }
    Temp.NumberDigits = NumberDigits;
    Temp.Size = Size;
    return Temp;
}
