#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    vector<int> infected(4);  
    vector<int> highrisk(4); 

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] > 1) {  
                infected[grid[i][j]-2]++;
            }
            else if (grid[i][j] == 1) {  
                int max_infection = 0;
            
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        int ni = i + di, nj = j + dj;
                        if (ni >= 0 && ni < N && nj >= 0 && nj < N && grid[ni][nj] > 1) {
                            max_infection = max(max_infection, grid[ni][nj]);
                        }
                    }
                }
                if (max_infection > 0) {
                    highrisk[max_infection-2]++;
                }
            }
        }
    }

for (int i = 0; i < 4; i++) {
    cout << infected[i] << " ";
}
cout << endl;
for (int i = 0; i < 4; i++) {
    cout << highrisk[i] << " ";
}
cout << endl;

    return 0;
}
