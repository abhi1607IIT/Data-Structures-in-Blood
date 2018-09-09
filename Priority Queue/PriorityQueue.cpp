#include <bits/stdc++.h>
using namespace std;


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
	if(index>=pq.size()){
		return;
	}
	swap(pq[index],pq[pq.size()-1]);
	pq.pop_back();
	int elementpos = index;
	int leftchild = elementpos*2;
	int rightchild = elementpos*2 + 1;
	while(leftchild < pq.size() || rightchild < pq.size()){
		int replace = min(pq[elementpos],min(pq[leftchild],pq[rightchild]));
		if(replace == pq[leftchild]){
			swap(pq[elementpos],replace);
			elementpos = leftchild;
			leftchild = elementpos*2;
			rightchild = elementpos*2 + 1;
		}
		else if(replace == pq[rightchild]){
			swap(pq[elementpos],replace);
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
    for(int i=0;i<n;i++){
    	int num;
    	cin>>num;
    	InsertElement(pq,num);
    }
    for(int i=1;i<pq.size();i++){
    	cout<<pq[i]<<" ";
    }
    cout<<endl;

    DeleteElement(pq,2);
    for(int i=1;i<pq.size();i++){
    	cout<<pq[i]<<" ";
    }
    cout<<endl;
}