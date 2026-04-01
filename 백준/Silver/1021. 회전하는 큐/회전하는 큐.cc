#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M, X, idx;
    int ans = 0;
    deque<int> DQ;
    
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++){
        DQ.push_back(i);
    }
    
    while(M--){
        cin >> X;
        for (int i = 0; i < DQ.size(); i++){
            if (DQ[i] == X){
                idx = i;
                break;
            }
        }

        if (idx <= DQ.size() / 2){
            while(1){
                if(DQ.front() == X){
                    DQ.pop_front();
                    break;
                }
                DQ.push_back(DQ.front());
                DQ.pop_front();
                ans++;
            }
        }

        else {
            while(1){
                if(DQ.front() == X){
                    DQ.pop_front();
                    break;
                }
                DQ.push_front(DQ.back());
                DQ.pop_back();
                ans++;
            }
        }
    }

    cout << ans;
    
    return 0;

}