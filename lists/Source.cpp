#include "MyVector.h"
#include "TwoWayList.h"
#include <ctime>
#include <iostream>

int  main() {
	unsigned long long int i = 1;
	while (i <= 1000000000000000000) {
		MyVector mvector;
		cout << i << ": ";
		unsigned int start_time = clock();
		int z=i;
		while (z--) {
			int j;
			if (mvector.size() < mvector.capacity())
				j = mvector.size();
			else j = mvector.size() + 1;
			mvector.additem(j, z);
		}
		unsigned int stop_time = clock();
		cout << (stop_time - start_time) << endl;
		i *= 10;
	}
	system("Pause");
	return 0;
}