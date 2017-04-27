#include "BigInt.h"

int main(){
    BigInt x, y("1234"), z("000009876054321");
	x.PrintValue();
	y.PrintValue();
	z.PrintValue();
	y.Add(z);
	y.PrintValue();
	BigInt i(444, 2);
	i.PrintValue();
	BigInt j(i);
	j.PrintValue();
	i.Add(78);
	i.PrintValue();
	i.Add("98765");
	i.PrintValue();
	i.Add(j);
	i.PrintValue();
	system("pause");
	return 0;
}
