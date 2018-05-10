#include<iostream>
#include<algorithm>
#include<vector>
#include<thread>

using namespace std;

int n,k,m;
vector<int> a;
vector<int> b;
vector<vector<int> > c;


void clac(int i, int j) {
	if(j<m) {
		int entry = 0;
		for(int y = 0; y<k; y++) {
				entry+=(a[i*k + y]*b[y*m + j]);
		}
		c[i][j] = entry;
	}
}


void calc(int i) {
	if(i<n) {
		int numthreads = 5;
		std::thread threads[numthreads];
		for(int j = 0; j<m; j+=numthreads) {
				for(int index = 0; index<numthreads; index++) {
						threads[index] = std::thread(clac,i,j+index);
				}
				for(int index = 0; index<numthreads; index++) {
						threads[index].join();
				}
		}
	}
	return;
}


int main() {
		ios_base::sync_with_stdio(false);
		cin>>n>>k>>m;
		a.assign(n*k,0);
		b.assign(k*m,0);
		c.assign(n, vector<int> (m,0));

		for(int i = 0; i<n; i++) {
				for(int j = 0; j<k; j++) {
						cin>>a[i*k + j];
				}
		}
		for(int i = 0; i<k; i++) {
				for(int j = 0; j<m; j++) {
						cin>>b[i*m + j];
				}
		}

		int numthreads = 1000;

		std::thread threads[numthreads];
		for(int i = 0; i<n; i+=numthreads) {
				for(int index = 0; index<numthreads; index++) {
						threads[index] = std::thread(calc,i+index);
				}
				for(int index = 0; index<numthreads; index++) {
						threads[index].join();
				}
		}


		for(int i = 0; i<n; i++) {
				for(int j = 0; j<m; j++) {
						cout<<c[i][j]<<"\t";
				}
				cout<<endl;
		}
}
