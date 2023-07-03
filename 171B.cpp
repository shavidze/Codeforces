#include <iostream>

using namespace std;
int n;
long t;
int nums[100000];
int main(){
    cin >> n >> t;
    int p = 0;
    int sum = 0;
    int j = 0;
    for (int i = 0; i < n; i++)cin >> nums[i];
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        p++;
        if (sum>t){
            sum -= nums[j];
            j++;
            p--;
        }
    }
    cout << p;
    return 0;
