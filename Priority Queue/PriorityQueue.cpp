#include <bits/stdc++.h>
using namespace std;




void inplaceHeapSort(int input[], int n){

	for (int i=0;i<n;i++){
		int elementpos=i;
		int parentpos=(elementpos-1)/2;
		while(parentpos>=0){
			if(input[elementpos]<input[parentpos]){
				swap(input[elementpos],input[parentpos]);
			}
			else{
				break;
			}
			elementpos = parentpos;
			parentpos = (parentpos-1)/2;
		}
	}

	for(int i=0;i<n;i++){
		cout<<input[i]<<" ";
	}
	cout<<endl;

	for(int i=0;i<n;i++){
		swap(input[0],input[n-1-i]);
		int elementpos = 0;
		int leftchild = elementpos*2 +1;
		int rightchild = leftchild + 1;
		while(leftchild < n-i-1 && rightchild < n-i-1){
			int replace = min(input[elementpos],min(input[leftchild],input[rightchild]));
			if(replace == input[leftchild]){
				swap(input[elementpos],input[leftchild]);
				elementpos = leftchild;
				leftchild = elementpos*2 +1;
				rightchild = leftchild + 1;
			}
			else if(replace == input[rightchild]){
				swap(input[elementpos],input[rightchild]);
				elementpos = rightchild;
				leftchild = elementpos*2 +1;
				rightchild = leftchild + 1;
			}
			else{
				break;
			}
		}

		if(leftchild < n-i-1 && rightchild >= n-i-1 && input[elementpos] > input[leftchild]){
			swap(input[elementpos],input[leftchild]);
			elementpos = leftchild;
			leftchild = elementpos*2 +1;
			rightchild = leftchild + 1;
		}

	}
	for(int i=0;i<n;i++){
		cout<<input[i]<<" ";
	}
	cout<<endl;
}



int GetMin(vector<int>pq){
	if(pq.size()>=1){
		return pq[1];
	}
	else{
		return -1;
	}
}

void InsertElement(vector<int>& pq,int element){   //O(h)   where h is height of order log n
	pq.push_back(element);
	int elementpos=pq.size()-1;
	int parentpos=elementpos/2;
	while(parentpos>0){
		if(pq[elementpos]<pq[parentpos]){
			swap(pq[elementpos],pq[parentpos]);
		}
		else{
			break;
		}
		elementpos = parentpos;
		parentpos = parentpos/2;
	}
}

void DeleteElement(vector<int>& pq,int index){
	if(index>pq.size()){
		return;
	}
	swap(pq[index],pq[pq.size()-1]);
	pq.pop_back();
	int elementpos = index;
	int leftchild = elementpos*2;
	int rightchild = leftchild + 1;
	while(leftchild < pq.size() && rightchild < pq.size()){
		int replace = min(pq[elementpos],min(pq[leftchild],pq[rightchild]));
		if(replace == pq[leftchild]){
			swap(pq[elementpos],pq[leftchild]);
			elementpos = leftchild;
			leftchild = elementpos*2;
			rightchild = leftchild + 1;
		}
		else if(replace == pq[rightchild]){
			swap(pq[elementpos],pq[rightchild]);
			elementpos = rightchild;
			leftchild = elementpos*2;
			rightchild = elementpos*2 + 1;
		}
		else{
			break;
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
    
    vector<int> pq;
    pq.push_back(-1);
    int n;
    cin>>n;
    int*arr= new int [n];
    for(int i=0;i<n;i++){
    	int num;
    	cin>>num;
    	arr[i]=num;
    	InsertElement(pq,num);
    }
    for(int i=1;i<pq.size();i++){
    	cout<<pq[i]<<" ";
    }
    cout<<endl;
    inplaceHeapSort(arr,n);
    DeleteElement(pq,1);
    for(int i=1;i<pq.size();i++){
    	cout<<pq[i]<<" ";
    }
    cout<<endl;
}

