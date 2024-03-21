#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int N = 0;
string name;
int grade;
string names[7] = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
map<string, int> students;
vector<pair<int, string>> grades;
 
int main() {
    cin >> N;
       
    // for(int i=0; i<7; i++) {
    //     students[names[i]] = 0;
    // }

    for(int i=0; i<N; i++) {
        cin>>name>>grade;
        students[name]+=grade;
    }

    for(int i=0; i<7; i++) {
        grades.push_back({students[names[i]],names[i]});
    }

    sort(grades.begin(), grades.end());

    int minGrade = grades[0].first;

    int secondMinGrade = 0;
    string answer;

    for(int i=1; i<7; i++) {
        if(minGrade != grades[i].first and secondMinGrade == 0) {
            secondMinGrade = grades[i].first;
            answer = grades[i].second;
        }
        else if(secondMinGrade != 0) {
            if(secondMinGrade == grades[i].first) {
                cout<<"Tie"<<"\n";
            } else {
                cout<<answer<<"\n";
            }
            break;
        }
    }

    if(secondMinGrade == 0) { //다 동점인 경우
        cout<<"Tie"<<"\n";
    } else if(answer.size()==0){
        cout<<grades[6].second<<"\n";
    }

    return 0;
}