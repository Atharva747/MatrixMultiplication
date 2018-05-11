#include<iostream>
#include<algorithm>
#include<vector>
#include<thread>

using namespace std;

int n,k,m;
vector<int> a;
vector<int> b;
vector<int> c;


void calc(int i) {
	if(i<n) {
		for(int j = 0; j<m; j++) {
				int entry = 0;
				for(int y = 0; y<k; y++) {
						entry+=(a[i*k + y]*b[y*m + j]);
				}
				c[i*m+j] = entry;
		}
	}
	return;
}

int main() {
		ios_base::sync_with_stdio(false);
		cin>>n>>k>>m;
		a.assign(n*k,0);
		b.assign(k*m,0);
		c.assign(n*m,0);
#pragma omp parallel for //faster inputs
		for(int i = 0; i<n; i++) {
				for(int j = 0; j<k; j++) {
						cin>>a[i*k + j];
				}
		}
#pragma omp parallel for //faster inputs
		for(int i = 0; i<k; i++) {
				for(int j = 0; j<m; j++) {
						cin>>b[i*m + j];
				}
		}

		int numthreads = 100;

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
						cout<<c[i*m+j]<<"\t";
				}
				cout<<"\n";
		}
}
