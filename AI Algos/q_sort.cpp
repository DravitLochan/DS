#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> a;
int n;

int partition(int l, int r){
	int pivot = l;
        int i = l +1;
        int j = r;
        while(i<j)
        {
            while(i<=j && a[pivot]>=a[i])
            {
                i++;
            }
            while(j>=i && a[pivot]<a[j])
            {
                j--;
            }
            if(i < j && a[i]>a[j])
            {
                swap(a[i++],a[j--]);
            }
        }
        if(a[pivot] > a[j]){
            swap(a[j], a[pivot]);
        }
        return j;
}

void q_sort(int l, int r){
	if(l <= r){
		int p = partition(l, r);
		q_sort(l, p - 1);
		q_sort(p + 1, r);
	}
}

void print(){
	for(int i = 0; i < n; ++i)	cout << a[i] << " ";
}

int main(){
	int i;
	cin >> n;
	a.resize(n);
	for(i = 0; i < n; ++i)	cin >> a[i];
	q_sort(0, n - 1);
	print();
	return 0;
}