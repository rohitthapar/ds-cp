#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class priorityQueue{
    vector<int> pq;
    public:
    priorityQueue(){
    }
// };

    bool isEmpty(){
        return pq.size()==0;
    }
    int getSize(){
        return pq.size();
    }
// minimum priority queue
    int getMin(){
        if(isEmpty()){
            return 0;
        }
        else return pq[0];
    }
// insertion of minimum priortiy queue
    void insert(int element){
        pq.push_back(element);

        int chI = pq.size()-1;
        while(chI>0){
            int pI = (chI-1)/2;
            if(pq[chI] < pq[pI]){
                int temp = pq[chI];
                pq[chI] = pq[pI];
                pq[pI] = temp;
            }
        else break;
        chI = pI;
        }
    }
// deletion/removal of minimum element 
    int removeMin(){
        if(isEmpty()){
            return 0;
        }
    int ans = pq[0];
    pq[0] = pq[pq.size()-1];
    pq.pop_back();
    
    int pI = 0;
    int lci = 2*pI +1;
    int rci = 2*pI +2;

    while(lci < pq.size()){
        int minIndex = pI;
        if(pq[minIndex] > pq[lci]){
            minIndex = lci;
        }
        if(rci < pq.size() && pq[minIndex] > pq[rci]){
            minIndex = rci;
        }
        if(minIndex == pI){
            break;
        }
        int temp = pq[minIndex];
        pq[minIndex] = pq[pI];
        pq[pI] = temp;

        pI = minIndex;
         lci = 2*pI +1;
         rci = 2*pI +2;
        
    }
    return ans;
    }
};
