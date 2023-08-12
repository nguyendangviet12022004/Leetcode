#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
#define ff(i,a,b,s) for(int i = a;i <= b;i += s)
int main(){
    int n,k;
    cin >> n >> k;
    int arr[n+1];
    int sum[n+1];
    int beginId = 0;
    int smallestLenght = n +1 ;

    unordered_map<int,int> mp;

    sum[0] = 0 ;

    // Create Array Which Caculate Sum
    ff(i,1,n,1) {
        cin >> arr[i];
        sum[i] = sum[i-1] + arr[i];
    }
    // Find If Sum Array Has (Sum[i] - k)

    ff(i,1,n,1){

        int check = sum[i] - k;
        if(mp.count(check)){
            if(i - mp[check] < smallestLenght){
                smallestLenght = i - mp[check];
                beginId = mp[check] + 1;
            }
        }
        mp[sum[i]] = i;
    }

    if(beginId != 0 )cout<<beginId<<" "<<smallestLenght;
    else cout<<-1;
}
