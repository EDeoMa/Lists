#include "MyVector.h"

int  main() {
	TwoWayList mlist;
	MyVector mvector;
	int inp, ans = 1;
	cout << "Continue?\n";
	cin >> ans;
	int i = 1000000000;
	while (i--) {
		//cout << "Add num: "<<i<<endl;
		int j;
		if (mvector.wrlen < mvector.len)
			j = mvector.wrlen;
		else j = mvector.wrlen + 1;
		mvector.additem(j, i);
		//cout << "Continue?\n";
		//cin >> ans;
	}
	/*for (int i = 0; i < 100; i++) {
		mlist.additem(i, i);
		mvector.additem(i, i);
	}*/
	
	system("Pause");
	return 0;
}