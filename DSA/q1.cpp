#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void stack_input(int arr[],int n){
    stack<int> s1,s2,s3;
    queue<int> q1,q2,q;
    s1.push(arr[0]);

    for(int i=1;i<n;i++){
        if(arr[i]<s1.top()){
            s1.pop();
        }
        else if(s2.empty()){
            s2.push(arr[i]);
        }
        else if(arr[i]>s2.top()){
            s2.push(arr[i]);
        }
        else {
            int a = arr[i] - s1.top();
            int b = s2.top() - arr[i];
            if(a>b){
                while(arr[i]>s2.top()){
                    q1.push(s2.top());
                    s2.pop();
                }
                s2.push(arr[i]);
                while(!q1.empty()){
                    int x = q1.front();
                    q2.push(x);
                    q1.pop();
                }
                while(!q2.empty()){
                    s2.push(q2.front());
                    q2.pop();
                }
            }
            else {
                while(arr[i]<s1.top() && s1.size()>0){
                    q1.push(s1.top());
                    s1.pop();
                }
            s1.push(arr[i]);
            // while(!q1.empty()){
            //     q2.push(q1.top());
            //     q1.pop();
            // }
            while(!q1.empty()){
                s1.push(q1.front());
                q1.pop();
            }
        }
        }

        // queue<int> q;
        while(!s2.empty()){
            s3.push(s2.top());
            s2.pop();
        }
        }
        int s1_size = s1.size();
        int s2_size = s3.size();
        if(s1_size>s2_size){
            while(!s3.empty()){
                if(s1.top()<s3.top()){
                     q.push(s1.top());
                     s1.pop();
                 }
                 else {
                     q.push(s3.top());
                     s3.pop();
                 }
            }
            while(!s1.empty()){
                q.push(s1.top());
                s1.pop();
            }
        } else {
            while(!s1.empty()){
               if(s1.top()<s3.top()){
                     q.push(s1.top());
                     s1.pop();
                 }
                 else {
                     q.push(s3.top());
                     s3.pop();
                 }
            }
             while(!s3.empty()){
                q.push(s3.top());
                s3.pop();
            } 

            }
        while(!q.empty()){
            cout<<" "<<q.front();
            q.pop();
        }
        
    }

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    stack_input(arr,n);

    return 0;
}