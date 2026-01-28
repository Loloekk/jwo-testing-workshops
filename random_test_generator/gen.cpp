#include <bits/stdc++.h>

using namespace std;

int randInt(int l, int r, mt19937 & los)
{
    int d = r-l+1;
    return los()%d+l;
}

vector<int> getPerm(int n, mt19937 & los)
{
    vector<int> res;
    for(int i = 0 ;i <=n ;i ++)
        res.push_back(i);
    for(int i = 1; i <= n ;i ++)
    {
        int p = randInt(i,n,los);
        swap(res[i],res[p]);
    }

    // shuffle(res.begin()+1, res.end(),los);

    return res;
}

int main()
{
    int seed;
    cin>>seed;
    mt19937 los(seed);
    int n = 100, q = 100;
    vector<int> perm = getPerm(n,los);
    cout<<n<<'\n';
    for(int i = 2; i <=n ;i ++)
    {
        int p = randInt(max(i-20,1),i-1,los);
        cout<<perm[i]<<" "<<perm[p]<<'\n';
    }
    cout<<q<<'\n';
    for(int i = 0 ; i < q; i ++)
    {
        cout<<randInt(1,n,los)<<" "<<randInt(1,n,los)<<'\n';
    }
}