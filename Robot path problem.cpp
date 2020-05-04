#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define pii pair<int,int>

class pipe {
public:
    pii start,end;
    int time;
};

int ans = 0;

void minTime(pii dest, const vector < pipe > &v, int r, int c, vector < vector < bool > > &visited, int count) {

    if(r<0 || c<0 || r>2000 || c>2000) {
        return;
    }

    if(r == dest.ff && c == dest.ss) {
        ans = min(ans,count);
        return ;
    }

    if(visited[r][c]) {
        return;
    }

    visited[r][c] = true;

    for (int i = 0; i < v.size(); ++i) {
        if(r == v[i].start.ff and c == v[i].start.ss) {
            minTime(dest,v,v[i].end.ff,v[i].end.ss,visited,count+v[i].time);
        }
    }

    minTime(dest,v,r+1,c,visited,count+1);
    minTime(dest,v,r-1,c,visited,count+1);
    minTime(dest,v,r,c+1,visited,count+1);
    minTime(dest,v,r,c-1,visited,count+1);

    visited[r][c] = false;
}

int robotPath(pii src, pii dest, vector < pipe > v) {
    vector < vector < bool > > visited (2005, vector < bool > (2005, false)) ;

    cout << "ok";
    ans = 0 ;

    minTime(dest,v,src.ff,src.ss,visited,0);

    return ans;
}

int main() {
    int testCases;
    cin >> testCases;
    for (int test_i = 1; test_i <= testCases ; test_i++) {
        int n;
        cin >> n;
        pii source;
        cin >> source.ff >> source.ss;
        pii dest;
        cin >> dest.ff >> dest.ss;
        vector < pipe > v(n);
        for (int i = 0; i < n; ++i) {
            pipe temp;
            cin >> temp.start.ff >> temp.start.ss >> temp.end.ff >> temp.end.ss >> temp.time;
            v[i] = temp;
        }

        cout << "#" << test_i << " : " << robotPath(source,dest,v) << endl;
    }

    return 0;
}
