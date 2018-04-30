#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>
#include<cstdlib>

using namespace std;

int main() {
		int n = 1000;
		srand(time(0));
		int r = 0;
		cout<<n<<" "<<n<<" "<<n<<endl;
		for(int j = 0; j<1000; j++) {
			for(int i = 0; i< 1000; i++) {
					r = (rand()%10000) + 1;
					cout<<r<<" ";
			}
			cout<<endl;
		}

		for(int j = 0; j<1000; j++) {
			for(int i = 0; i< 1000; i++) {
					r = (rand()%10) + 1;
					cout<<r<<" ";
			}
			cout<<endl;
		}
}
