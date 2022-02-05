#include<iostream>
#include<vector>
using namespace std;
void findingSubset(char *input,char *output,int i,int j){
    //base case
    if(input[i] == '\0'){
        output[j] = '\0';//to prevent garbage getting printed
        if(output[0] == '\0'){
            cout<<"NULL";
        }
        cout<<output<<endl;
        return;
    }
    //rec case
    //include ith letter
    output[j] = input[i];
    findingSubset(input,output,i+1,j+1);
    //exclude the ith letter
    //overwriting
    findingSubset(input,output,i+1,j);


}
int main(){
    char input[100];
    char output[100];
    cin>>input;
    findingSubset(input,output,0,0);
    return 0;
}

//input -> abc

// abc
// ab
// ac
// a
// bc
// b
// c
// NULL