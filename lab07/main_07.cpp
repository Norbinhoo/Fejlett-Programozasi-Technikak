#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <utility>
using namespace std;

int main() {
    vector<string> fruits{
        "melon","strawberry","apple","banana","raspberry","berry"
    };
    auto it=find_if(fruits.begin(),fruits.end(),
                    [](const string& e) {
                        return e.find("berry")!=string::npos;
                    });
    cout<<*it;

    vector<int> szamok{2,4,6,8};
    auto isEven{
            [](int i)
            {
                return (i % 2) == 0;
            }
    };

    bool mindenParos = all_of(szamok.begin(), szamok.end(), isEven);
    cout<<endl;
    if (mindenParos)
        cout << "Minden elem paros." << endl;
    else
        cout << "Nem minden elem paros." << endl;

    for_each(szamok.begin(),szamok.end(),[](int i){
        return i=i*2;
    });

    for(int i=0;i<szamok.size();i++){
        cout<<szamok[i]<<" ";
    }
    cout<<endl;

    vector<string> months {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };

    cout<<count_if(months.begin(),months.end(),[](const string & s){
        return s.length()==5;
    });
    cout<<endl;

    vector<double> tomb{2.1,4.6,6.9,8.4,8.1};
    sort(tomb.begin(),tomb.end(),greater<double>());
    for(int i=0;i<tomb.size();i++){
        cout<<tomb[i]<<" ";
    }
    cout<<endl;


    vector<pair<string,double>> monthsatlag{
            {"January",11.5}, {"February",-22}, {"March",17}, {"April",-12}, {"May",11}, {"June",11}
    };

    sort(monthsatlag.begin(),monthsatlag.end(),[](const pair<string,double> &p1,const pair<string,double> &p2){
        return p1.second>p2.second;
    });
    for(double i=0;i<monthsatlag.size();i++){
        cout<<monthsatlag[i].first<<" "<<monthsatlag[i].second<<" ";
    }
    cout<<endl;

    vector<double> tomb2{2,-4.8,-2.2,6.2,8.4,8.1};
    sort(tomb2.begin(),tomb2.end(),[](const double & a,const double & b){
        return abs(a)< abs(b);
    });
    for(int i=0;i<tomb2.size();i++){
        cout<<tomb2[i]<<" ";
    }
    cout<<endl;

    for_each(months.begin(),months.end(),[](string & s){
        s[0]=tolower(s[0]);
    });

    for(int i=0;i<months.size();i++){
        cout<<months[i]<<endl;
    }


    return 0;
}