#include<iostream>
#include<vector>

using namespace std;
vector<int> strToVector(string date)
{

    int year = stoi(date.substr(0,4));
    int month = stoi(date.substr(5,2));
    int day = stoi(date.substr(8,2));

    return {year,month,day};
}

bool isLeap(int year)
{
    return (year % 100 != 0 && year % 4 ==0) || (year % 100 == 0 && year % 400 ==0);
}

int daysBetweenDates(vector<int> d1 , vector<int> d2)
{
    vector<int> date = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(isLeap(d1[0])) date[2] = 29;
    bool change = false;
    if(d1[0] > d2[0]) swap(d1,d2);
    else if(d1[1] > d2[1]) swap(d1,d2);
    else if(d1[2] > d2[2]) swap(d1,d2);
    // block of code below will ensure that d1 is sonner than d2

    if(d1[0] == d2[0] && d1[1] == d2[1]) return d2[2] - d1[2];

    if(d1[0] == d2[0]) {
        int add = date[d1[1]] - d1[2] + 1;
        for(int i = d1[1] + 1;i <= d2[1]-1;i ++) add += date[i];
        return add + d2[2];
    }

    return  daysBetweenDates(d1,{d1[0],12,31}) + 1 + daysBetweenDates({d1[0] + 1, 1,1} , d2);
}
int main()
{
    cout << daysBetweenDates({2020,1,15},{2019,12,31});
}
