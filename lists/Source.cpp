#include "MyVector.h"
#include "TwoWayList.h"
#include <ctime>
#include <iostream>

const int max_element = 13;

void print_vector(MyVector& mvector) {
	for (int i = 0; i < mvector.size(); i++) {
		cout << mvector[i] << " ";
	}
	cout << endl;
}

int  main() {
	unsigned long long int i = 1;
	MyVector mvector;
	while (i <= max_element) {
		mvector.push_back(i);
		/*cout << i << ": ";
		unsigned int start_time = clock();*/
		/*int z=i;
		while (z--) {
			int j;
			if (mvector.size() < mvector.capacity())
				j = mvector.size();
			else j = mvector.size() + 1;
			mvector.insert(j, z);
		}*/
		/*unsigned int stop_time = clock();
		cout << (stop_time - start_time) << endl;*/
		i += 1;
	}
	print_vector(mvector);
	mvector.insert(0, 100);
	print_vector(mvector);
	mvector.insert(ceil(mvector.size()/2), 100);
	print_vector(mvector);
	mvector.push_back(100);
	print_vector(mvector);
	mvector.erase(0);
	print_vector(mvector);
	mvector.erase(ceil(mvector.size() / 2));
	print_vector(mvector);
	mvector.pop_back();
	print_vector(mvector);

	system("Pause");
	return 0;
}