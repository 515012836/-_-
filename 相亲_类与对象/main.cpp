#include <iostream>
#include <Windows.h>
#include <vector>
#include "Boy.h"
#include "Girl.h"
#include "DATABS.h"

int main(void) {
	DATABS T1;
	T1.inti();
	T1.print();
	T1.autopair();
	T1.Greatpair();

	/*Boy k;
	k.inputboy(k);
	T1.addOne(k);*/

	system("pause");
}
/*
20 紫霞 90
18 如花 80
30 小美 98
0
25 小王 30000
20 小龙 8000
18 小胖 6000
0
*/
