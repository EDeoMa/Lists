#include <ctime>
#include <iostream>
#include "MyVector.h"
#include "TwoWayList.h"
#include "TwoWayListTests.h"

using namespace std;

const int max_element = 100000000;

void print_vector(MyVector& mvector) {
	for (int i = 0; i < mvector.size(); i++) {
		cout << mvector[i] << " ";
	}
	cout << endl;
}

void print_list(TwoWayList& mlist) {
	for (int i = 0; i < mlist.size(); i++) {
		cout << mlist[i] << " ";
	}
	cout << endl;
}

void printall(MyVector& mvector, TwoWayList& mlist) {
	cout << "New:" << endl << "Vector: ";
	print_vector(mvector);
	cout << "List: ";
	print_list(mlist);
}

int  main() {
    run_list_tests();

    {
		MyVector mvector;
		TwoWayList mlist;
		int start_clock, time_passed;
		start_clock = clock();
		for (int i = 0; i <= max_element; i++) {
			mvector.push_back(i);
		}
		time_passed = clock() - start_clock;
		cout << "Vector took: " << time_passed << "\nList took: ";
		start_clock = clock();
		for (int i = 0; i <= max_element; i++) {
			mlist.push_back(i);
		}
		time_passed = clock() - start_clock;
		cout << time_passed << endl;

		/*cout << "Starting with:" << endl<<"Vector: ";
		print_vector(mvector);
		cout << "List: ";
		print_list(mlist);*/

		cout << "Front insert:" << endl;
		start_clock = clock();
		mvector.insert(0, 100);
		time_passed = clock() - start_clock;
		cout << "Vector took: " << time_passed << "\nList took: ";
		start_clock = clock();
		mlist.push_front(100);
		time_passed = clock() - start_clock;
		cout << time_passed << endl;

		//printall(mvector, mlist);

		cout << "Middle insert:" << endl;
		start_clock = clock();
		mvector.insert(ceil(mvector.size() / 2), 100);
		time_passed = clock() - start_clock;
		cout << "Vector took: " << time_passed << "\nList took: ";
		start_clock = clock();
		mlist.insert(ceil(mlist.size() / 2), 100);
		time_passed = clock() - start_clock;
		cout << time_passed << endl;

		//printall(mvector, mlist);

		cout << "Back insert:" << endl;
		start_clock = clock();
		mvector.push_back(100);
		time_passed = clock() - start_clock;
		cout << "Vector took: " << time_passed << "\nList took: ";
		start_clock = clock();
		mlist.push_back(100);
		time_passed = clock() - start_clock;
		cout << time_passed << endl;

		//printall(mvector, mlist);

		cout << "Front erase:" << endl;
		start_clock = clock();
		mvector.erase(0);
		time_passed = clock() - start_clock;
		cout << "Vector took: " << time_passed << "\nList took: ";
		start_clock = clock();
		mlist.pop_front();
		time_passed = clock() - start_clock;
		cout << time_passed << endl;

		//printall(mvector, mlist);

		cout << "Middle erase:" << endl;
		start_clock = clock();
		mvector.erase(ceil(mvector.size() / 2));
		time_passed = clock() - start_clock;
		cout << "Vector took: " << time_passed << "\nList took: ";
		start_clock = clock();
		mlist.erase(ceil(mlist.size() / 2));
		time_passed = clock() - start_clock;
		cout << time_passed << endl;

		//printall(mvector, mlist);

		cout << "Back erase:" << endl;
		start_clock = clock();
		mvector.pop_back();
		time_passed = clock() - start_clock;
		cout << "Vector took: " << time_passed << "\nList took: ";
		start_clock = clock();
		mlist.pop_back();
		time_passed = clock() - start_clock;
		cout << time_passed << endl;

		//printall(mvector, mlist);
	}
	system("Pause");
	return 0;
}