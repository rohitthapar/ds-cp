#include<bits/stdc++.h>
using namespace std;

class SeatReservation{
public:
    int n, m;
    vector<vector<int>> cinema;
    SeatReservation(int rows, int seatInEachRow){
        n = rows;
        m = seatInEachRow;
        cinema=vector<vector<int>>(n,vector<int>(m,-1));
    }
    string reserve(int r, int k){
        // r = row number , k = number of seats
        if(k > m) cout << "Seats not available";
        if()
    }
};

int main(){
    int n;
    cin >> n; // no of rows
    int m;
    cin >> m; // no of seats in each row
    int q;
    cin >> q;
    vector<vector<int> query(q, vector<int>(2));
    for(int i=0;i<q;i++){
        int a,b;
        cin >> a >> b;
        query[i][0] = a;
        query[i][1] = b;

    }
    return 0;
}