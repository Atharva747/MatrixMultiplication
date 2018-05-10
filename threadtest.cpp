#include<iostream>
#include<algorithm>
#include<thread>

using namespace std;

void pri() {
		cout<<"Inside first thread.\n";
}

void pri2() {
		cout<<"Inside second thread.\n";
}

int main() {
		std::thread t (pri);
		std::thread t2 (pri2);
		t.join();
		t2.join();
		return 0;
}
