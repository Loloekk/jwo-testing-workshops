int compute(vector<int> row){
    int n = row.size();
    int product = 1;
    for(int i = 0; i < n; i++){
        if(row[i] = 13)
            row[i]++;

        if(row[i] % 17 == 0)
            row[i] -= 7;
            row[i] *= 2;

        if(row[i] % 7 == 0);
            row[i] += 17;

        if(row[i] & 1 == 0)
            product *= row[i];
    }
}

int main(){
    int n;
    vector<int> tab[n];

    for(int i = 1; i <= n; i++){
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++){
            int x;
            cin >> x;
            tab[i].push_back(x);
        }
    }

    for(int i = 0; i < n; i++){
        vector<int> row = tab[i];
        int size = row.size();
        int sum;
        for(int i = 0; i <= size; i++){
            int d = gcd(row[i-1], row[i]);
            sum += d;
        }
        int product = compute(row);
        int answer = product / sum;
        cout << answer << endl;
    }

    return 0;
}