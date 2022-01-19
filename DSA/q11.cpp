#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    stack<int> S1;
    stack<int> S2;
    queue<int> Q;
    int N;
    cin>>N;
    int arr[N];
    for(int i=0; i<N; i++)
    {
        cin>>arr[i];
    }
    
    for(int i=0; i<N; i++)
    {
        if(S1.empty() || arr[i]<S1.top())
        {
            S1.push(arr[i]);
        }
        else if(S2.empty() || arr[i]>S2.top())
        {
            S2.push(arr[i]);
        }
        else
        {
            int a= arr[i]-S1.top();
            int b= S2.top()-arr[i];
            if(a<b)
            {
                while(S1.top()<arr[i])
                {
                    int x=S1.top();
                    S1.pop();
                    Q.push(x);
                }
                S1.push(arr[i]);
                while(!Q.empty())
                {
                    int x=Q.front();
                    Q.pop();
                    S1.push(x);
                }
            }
            else
            {
                while(S2.top()>arr[i])
                {
                    int x=S2.top();
                    S2.pop();
                    Q.push(x);
                }
                S2.push(arr[i]);
                while(!Q.empty())
                {
                    int x=Q.front();
                    Q.pop();
                    S2.push(x);
                }
            }
        }
    }
    stack<int> S3;
    while(!S1.empty())
    {
        int x=S1.top();
        S1.pop();
        S3.push(x);
    }
    
    while(!S1.empty() || !S2.empty())
    {
        if(S1.top()<S2.top())
        {
            int x= S1.top();
            S1.pop();
            Q.push(x);
        }
        else
        {
            int x= S2.top();
            S2.pop();
            Q.push(x);
        }
    }
    while(!Q.empty())
    {
        cout<<Q.front();
        Q.pop();
    }
	return 0;
}