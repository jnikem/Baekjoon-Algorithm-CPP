#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int cnt[10] = {0};
    while(N > 0){
        cnt[N % 10]++;
        N /= 10;
    }
    // 6의 개수와 9의 개수의 평균을 반올림해서 cnt[6]에 저장
    cnt[6] += cnt[9];
    cnt[6] = (cnt[6] + 1) / 2;
    int maxVal = *max_element(cnt, cnt+9);
    cout << maxVal;
    
    return 0;
}