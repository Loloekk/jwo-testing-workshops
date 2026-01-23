#include <bits/stdc++.h> //!!!
using namespace std; //!!!

long long compute(vector<int> row){
    int n = row.size();
    long long product = 1;
    for(int i = 0; i < n; i++){
        if(row[i] == 13) //!!!
            row[i]++;

        if(row[i] % 17 == 0){
            row[i] -= 7;
            row[i] *= 2; //!!!
        }

        if(row[i] % 7 == 0) //!!!
            row[i] += 17;

        if((row[i] & 1) == 0)
            product *= (long long)row[i];
    }
    return product; //!!!
}

int main(){
    int n;
    cin>>n; // !!!
    vector<int> tab[n];

    for(int i = 0; i < n; i++){ //!!!
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++){ //!!!
            int x;
            cin >> x;
            tab[i].push_back(x);
        }
    }

    for(int i = 0; i < n; i++){
        vector<int> row = tab[i];
        int size = row.size();
        long long sum = 0; //!!!
        for(int j = 1; j < size; j++){ //!!!
            int d = gcd(row[j-1], row[j]);
            sum += d;
        }
        long long product = compute(row);
        if(sum == 0) sum = 1; //!!!
        long long answer = product / sum; //!!!
        cout << answer << endl;
    }

    return 0;
}