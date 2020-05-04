/*
CROSSWORD
You are given a dictionary consisting of N words each containing lowercase letters 'a'-'z'. You also have MxM crossword consisting of lowercase letters 'a'-'z'. You want to print all possible words that can be formed by a sequence of adjacent characters. Note that you can move to any of 8 adjacent characters, but a word should not have multiple instances of same cell. Note :- if a word is present in crossword more than once print it once.

Input Format
First line contains integer N. Then follow N space seperated words. Next line contains integer M. Then you have M characters each in next M lines forming MxM grid.

Constraints
1 <= N <= 10 1 <= M <= 5

Output Format
Print all words of dictionary present in crossword with space between words.

Sample Input
2
a aa
2
aa
aa
Sample Output
a aa
*/
#include <bits/stdc++.h>
using namespace std;

string dictionary[12];

bool findInGrid(const string &word, const vector < vector < char > > &grid ,int r, int c, vector < vector < bool > > &visited) {

    if(word.length() == 0) {
        return true;
    }
    
    if(r<0 || c<0 || r>=grid.size() || c>=grid.size()) {
        return false;
    }
    
    if(visited[r][c]) {
        return false;
    }

    if(word[0] != grid[r][c]) { 
        return false;
    }

    

    visited[r][c] = true;
    string ros = word.substr(1);
    bool upSuccess = findInGrid(ros,grid,r-1,c,visited);
    bool rightSuccess = findInGrid(ros,grid,r,c+1,visited);
    bool downSuccess = findInGrid(ros,grid,r+1,c,visited);
    bool leftSuccess = findInGrid(ros,grid,r,c-1,visited);

    if(upSuccess || rightSuccess || downSuccess || leftSuccess) {
        return true;
    }

    bool topRightSuccess = findInGrid(ros,grid,r-1,c+1,visited);
    bool topLeftSuccess = findInGrid(ros,grid,r-1,c-1,visited);
    bool bottomRightSuccess = findInGrid(ros,grid,r+1,c+1,visited);
    bool bottomLeftSuccess = findInGrid(ros,grid,r+1,c-1,visited);

    if(topLeftSuccess || topRightSuccess || bottomLeftSuccess || bottomRightSuccess) {
        return true;
    }

    visited[r][c] = false;

    return false ;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> dictionary[i];
    }

    int m;
    cin >> m;

    vector < vector < char > > grid (m, vector < char > (m));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j]; 
        }
    }


    set<string> foundSet ;

    for (int i = 0; i < n; ++i) {
        string word = dictionary[i];
        bool found = false;
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < m; ++k) {
                if(grid[j][k] == word[0]) {
                    //If the first character matches , check in all 8 directions
                    vector < vector < bool > > visited (m, vector < bool > (m,false));
                    if(findInGrid(word,grid,j,k,visited)) {
                        foundSet.insert(word);
                        found = true;
                        break;
                    }
                }
            }
            if(found) {
                break;
            }
        }
    }

    for (auto x : foundSet) {
        cout << x << " " ;
    }

    return 0;
}
