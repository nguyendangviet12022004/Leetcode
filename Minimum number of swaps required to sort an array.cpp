// find the count of cycle then caculus by formual : n-1;
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>

#define ff(i,a,b,s) for(int i = a;i <= b;i +=s)
#define fl(i,a,b,s) for(int i = a;i >= b;i -=s)
using namespace std;


void in(vector<pair<int,int>> &a)
{
    string s;
    getline(cin,s);
    stringstream dauvao(s);
    int x;
    int id = 0;
    while(dauvao >> x)
    {
        a.push_back({x,id});
        id++;
    }
}
void out(vector<pair<int,int>> a)
{
    ff(i,0,a.size()-1,1) cout << a[i].first << " ";
}

int minSwapToSortArray(vector<pair<int,int>> a)
{
    int l = a.size();
    vector<bool>vis(l,false);
    int ans = 0;
    ff(i, 0 , l -1 , 1)
    {
        if(vis[i] || i == a[i].second) continue;
        int add = 0;
        int j = i;
        while(!vis[j]) // while not end of cycle
        {
            vis[j] = true;
            j = a[j].second;
            add ++;
        }
        ans += add-1;
    }
    return ans;
}
int main()
{
    vector<pair<int,int>> a;
    in(a);
    sort(a.begin(),a.end());
    cout << minSwapToSortArray(a);

}
