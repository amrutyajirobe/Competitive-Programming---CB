/*
Expand the Pond
You are given a matrix with N rows and M columns. Each cell is either dry or has water. We say that two cells are neighbours if they share one of their four sides. A pond is a maximal subset of cells containing water such that any cell is accessible from any other cell by moving only along neighbours. You should add water to exactly one cell in order to maximise the size of the pond.

Input Format
The first line contains two integers N and M. Each of the next N lines contains M integers: 0 for a dry cell and 1 for a cell containing water.

Constraints
1 = N,M = 1000 There is at least one dry cell and one cell filled with water in the matrix.

Output Format
Print a single integer representing the largest possible size of the pond.

Sample Input
3 3
0 1 1
0 0 1
0 1 0
Sample Output
5
*/

#include <bits/stdc++.h>
using namespace std;

int expandPond(const vector< vector < int > > &v, const vector< vector < int > > &groupId, const vector < int > &groupSize) {
    int row = v.size();
    int col = v[0].size();
    int finalAns = 0 ;
    
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if(v[i][j] == 1) {
                continue;
            } else {
                //Insert the group no's of cells up , left , right and down to current cell in set to remove duplicates and add their sizes to compute the size of new pond formed by marking current cell as wet

                set < int > groupSet ;
                if(i > 0) {
                    groupSet.insert(groupId[i-1][j]);
                }
                if(j > 0) {
                    groupSet.insert(groupId[i][j-1]);
                }
                if(i < row-1) {
                    groupSet.insert(groupId[i+1][j]);
                }
                if(j < col-1) {
                    groupSet.insert(groupId[i][j+1]);
                }

                //Remove groupId = -1 from the set
                groupSet.erase(-1);


                //Iterate over the set and add the sizes of the groups and add one to it to count the current wet cell as well.
                int currentPondSize = 0;
                for(int x : groupSet) {
                    currentPondSize += groupSize[x];
                }

                currentPondSize++;

                finalAns = max(finalAns,currentPondSize);
            }
        }
    }


    return finalAns;
}


void assignGroupID(vector< vector < int > > &groupId, int r, int c, int id, const vector< vector < int > > &v) {
    if(r<0 || c<0 || r>=v.size() || c>=v[0].size() || v[r][c] == 0 || groupId[r][c] != -1) {
        return ;
    }

    groupId[r][c] = id;
    assignGroupID(groupId,r+1,c,id,v) ;
    assignGroupID(groupId,r-1,c,id,v) ;
    assignGroupID(groupId,r,c+1,id,v) ;
    assignGroupID(groupId,r,c-1,id,v) ;    
}

int main() {
    int row,col;
    cin >> row >> col;

    vector< vector < int > > v (row, vector<int> (col,0));

    int oneCount = 0 ;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cin >> v[i][j];
            oneCount += v[i][j];
        }
    }

    //When all cells are in pond
    if(oneCount == row*col) {
        cout << oneCount ;
        return 0;
    }

    //Sort all wet cells in different groups by assigning them different groupIDs
    vector < vector < int > > groupId(row, vector<int> (col,-1) ) ;
    
    int currentGroupNo = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if(v[i][j] == 1 and groupId[i][j] == -1)  {
                assignGroupID(groupId,i,j,currentGroupNo,v);
                currentGroupNo++;
            }
        }
    }

    //Vector to hold the sizes of each group
    vector < int > groupSize (currentGroupNo, 0);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if(groupId[i][j] != -1) {
                groupSize[groupId[i][j]]++;
            }
        }
    }


    int ans = expandPond(v,groupId,groupSize) ;

    cout << ans;

    return 0;
}
