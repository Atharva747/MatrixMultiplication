#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>
#include<cstdlib>

using namespace std;

int main() {
		int n;
        cin>>n;
		srand(time(0));
		int r = 0;
		cout<<n<<endl;
		for(int j = 0; j<n; j++) {
			for(int i = 0; i<n; i++) {
					r = (rand()%100) + 1;
					cout<<r<<" ";
			}
			cout<<endl;
		}
}
