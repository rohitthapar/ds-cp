  #include <algorithm>
  #include <bitset>
  #include <complex>
  #include <deque>
  #include <exception>
  #include <fstream>
  #include <functional>
  #include <iomanip>
  #include <ios>
  #include <iosfwd>
  #include <iostream>
  #include <istream>
  #include <iterator>
  #include <limits>
  #include <list>
  #include <locale>
  #include <map>
  #include <memory>
  #include <new>
  #include <numeric>
  #include <ostream>
  #include <queue>
  #include <set>
  #include <sstream> 
  #include <stack>
  #include <stdexcept>
  #include <streambuf>
  #include <string>
  #include <typeinfo>
  #include <utility>
  #include <valarray>
  #include <vector>

  #if __cplusplus >= 201103L
  #include <array>
  #include <atomic>
  #include <chrono>
  #include <condition_variable>
  #include <forward_list>
  #include <future>
  #include <initializer_list>
  #include <mutex>
  #include <random>
  #include <ratio>
  #include <regex>
  #include <scoped_allocator>
  #include <system_error>
  #include <thread>
  #include <tuple>
  #include <typeindex>
  #include <type_traits>
  #include <unordered_map>
  #include <unordered_set>
  #endif
  #include<iostream>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n],b[n];
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];

        sort(a,a+n);
        // for(int k=0;k<n;k++)cout<<a[k]<<" ";
        sort(b,b+n);
        // cout<<endl;
        // for(int k=0;k<n;k++)cout<<b[k]<<" ";
        reverse(b,b+n);
        // cout<<endl;
        // for(int k=0;k<n;k++)cout<<b[k]<<" ";
        // cout<<endl;
        int s=0,c[n];
        int i=0,j=n-1;
        // while(j<=0){
        //     c[i] = a[i] + b[j];
        //     i++,j--;
        // }
        for(int k=0;k<n;k++){
            c[k] = a[i] + b[j];
            i++,j--; 
        }
        // for(int k=0;k<n;k++)cout<<c[k]<<" ";
        s = max_element(c,c+n) - c;
        cout<<c[s];
    }
}
