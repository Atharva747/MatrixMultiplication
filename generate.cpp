#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>
#include<cstdlib>

using namespace std;

int main() {
		int n,k,m;
        cin>>n>>k>>m;
		srand(time(0));
		int r = 0;
		cout<<n<<" "<<k<<" "<<m<<endl;
		for(int j = 0; j<n; j++) {
			for(int i = 0; i<k; i++) {
					r = (rand()%10000) + 1;
					cout<<r<<" ";
			}
			cout<<endl;
		}

		for(int j = 0; j<k; j++) {
			for(int i = 0; i<m; i++) {
					r = (rand()%10) + 1;
					cout<<r<<" ";
			}
			cout<<endl;
		}
}
