#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector<ll> a;
ll k ;

ll f(ll x) {
    ll n = a.size();
    ll sum = 0;
    for (ll i = 0; i < k; ++i) {
        ll index = (x+n-i)%n ;
        // cout << "index = " << index << endl;
        // cout << "a[index] = " << a[index] << endl;
        sum += a[index];
    }

    return sum;
}

class SegmentTree {
private:
    ll n;
    vector < ll > tree;
    vector < ll > lazy;

    void makeTree(const vector<ll> &v, ll index, ll s, ll e) {
        //Leaf Node
        if(s == e) {
            tree[index]= f(s);
            return ;
        }

        ll mid = (s+e)/2;
        makeTree(v, 2*index, s, mid);
        makeTree(v, 2*index+1, mid+1, e);

        tree[index] = tree[2*index] + tree[2*index+1];
    }

    ll query(ll s, ll e, ll qs, ll qe, ll index) {
        //Complete overlap
        if(qs <= s && e <= qe) {
            return tree[index];
        }

        //No Overlap
        if(qe < s || qs > e) {
            return 0;
        }

        //Partial Overlap
        ll mid = (s+e)/2;

        ll leftAns = query(s, mid, qs, qe, 2*index);
        ll rightAns = query(mid+1, e, qs, qe, 2*index+1);

        return leftAns + rightAns;
    }

    ll queryLazy(ll s, ll e, ll qs, ll qe, ll index) {

        if(lazy[index] != 0) {
            tree[index] += (e-s+1)*lazy[index];
            if(s != e) {
                lazy[2*index+1] += lazy[index];
                lazy[2*index] += lazy[index];
            }
            lazy[index] = 0;
        }

        //No Overlap
        if(qe < s || qs > e) {
            return 0;
        }

        //Complete overlap
        if(qs <= s && e <= qe) {
            return tree[index];
        }

        //Partial Overlap
        ll mid = (s+e)/2;

        ll leftAns = queryLazy(s, mid, qs, qe, 2*index);
        ll rightAns = queryLazy(mid+1, e, qs, qe, 2*index+1);

        return leftAns + rightAns;
    }

    void updateNode(ll s, ll e, ll i, ll val, ll index) {
        //Out of bounds - No Overlap
        if(i > e || i < s) {
            return;
        }

        //Leaf Node
        if(s == e) {
            a[i] = val;
            tree[index] = f(s);
            return;
        }

        //Partial Overlap
        ll mid = (s+e)/2;
        updateNode(s, mid, i, val, 2*index);
        updateNode(mid+1, e, i, val, 2*index+1);
        tree[index] = tree[2*index] + tree[2*index+1];

        return;
    }

    void updateLazy(ll s, ll e, ll l, ll r,ll inc, ll index) {
        
        if(lazy[index] != 0) {
            //First resolve lazy value
            tree[index] += lazy[index];

            if(s!=e) {
                lazy[2*index] += lazy[index];
                lazy[2*index+1] += lazy[index];
            }

            lazy[index] = 0;
        }

        //Out of bounds - No Overlap
        if(s > r || l > e) {
            return;
        }

        if(s >= l && e <= r) {
            // cout << "updating " << index << endl;
            tree[index] += (e-s+1)*inc;

            //Pass lazy value to children
            if(s != e) {
                lazy[2*index] += inc;
                lazy[2*index+1] += inc;
            }
            return;
        }

        ll mid = (s+e)/2;
        updateLazy(s, mid, l, r, inc, 2*index);
        updateLazy(mid+1, e, l, r, inc, 2*index+1);

        tree[index] = tree[2*index] + tree[2*index+1];
    }


    void makeTreeUsingSum(const vector<ll> &sum, ll index, ll s, ll e) {
        //Leaf Node
        if(s == e) {
            tree[index] = sum[s];
            return ;
        }

        ll mid = (s+e)/2;
        makeTreeUsingSum(sum, 2*index, s, mid);
        makeTreeUsingSum(sum, 2*index+1, mid+1, e);

        tree[index] = tree[2*index] + tree[2*index+1];
    }

    
public:
    SegmentTree(ll n = 0) {
        this->n = n;
        tree.resize(4*n+1, 0);
        lazy.resize(4*n+1, 0);
    }


    void buildTree(const vector<ll> &v) {
        makeTree(v, 1, 0, v.size()-1) ;
    }

    void buildUsingSum(const vector<ll> &v) {
        vector<ll> sum(v.size(), 0);
        ll currentSum = 0;
        for (ll i = 0; i < k; ++i) {
            currentSum += v[i];
        }
        sum[k-1] = currentSum;
        for (ll i = k; i < n; ++i) {
            currentSum = currentSum - v[i-k] + v[i];
            sum[i] = currentSum;
        }

        for (ll i = 0; i < k-1; ++i) {
            currentSum = currentSum + v[i] - v[i-k+n];
            sum[i] = currentSum;
        }


        makeTreeUsingSum(sum, 1 ,0, sum.size()-1);
    }


    ll query(ll l, ll r) {
        // return query(0, n-1, l-1, r-1, 1);
        return queryLazy(0, n-1, l-1, r-1, 1);
    }

    void update(ll x, ll val) {
        // updateNode(0, n-1, i-1, val, 1);
        x--;
        ll diff = val - a[x];
        ll l = x ;
        ll r = x + k - 1;

        // cout << "l = " << l << "    r = " << r << "   diff = " << diff << endl;

        if(r >= n) {
            //Circular update
            updateLazy(0, n-1, l, n-1, diff, 1);
            updateLazy(0, n-1, 0, r-n, diff, 1);
        }
        else {
            updateLazy(0, n-1, l, r, diff, 1);
        }
    }

    void buildLazy(const vector<ll> &v) {
        for (ll i = 0; i < v.size(); ++i) {
            ll l = i ;
            ll r = i + k - 1;
            if(r >= n) {
                //Circular update
                updateLazy(0, n-1, l, n-1, v[i], 1);
                updateLazy(0, n-1, 0, r-n, v[i], 1);
            }
            else {
                updateLazy(0, n-1, l, r, v[i], 1);
            }
        }
    }

    void print() {
        for (ll i = 1; i < tree.size(); ++i) {
            if(tree[i] == 0 && lazy[i] == 0)    break;
            cout << "tree["<<i<<"] = " << tree[i] << "  lazy["<<i<<"] = " << lazy[i] << "\n";
        }
        cout << endl;
    }
};

int main() {
    sync;
    ll n ;
    cin >> n >> k;

    ll noOfQueries;
    cin >> noOfQueries;

    a.resize(n);

    SegmentTree t(n);

    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // t.buildTree(a);
    // t.buildLazy(a);
    t.buildUsingSum(a);

    // cout << "k = " << k << endl;
    // cout << f(3);

    // t.print();

    while(noOfQueries--) {
        ll q,x,y;
        cin >> q >> x >> y;
        if(q == 1) {
            //Update 
            t.update(x,y);
            // t.print();
        }
        else {
            //Query
            cout << t.query(x,y) << endl;
        }
        
    }

    // t.print();
    
    return 0;
}
