#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct Stu{
    int score;
};
struct Question{
    string answer;
    int score;
    int errornum;
};
typedef struct Stu stu;
typedef struct Question ques;
int main() {
    int n,m;
    cin>>n>>m;
    vector<stu> stud(n);
    vector<ques> que(m);
    for(int i=0;i<m;i++){
        int totalsel,rightsel;
        string ch;
        cin>>que[i].score>>totalsel>>rightsel;
        for(int j=0;j<rightsel;j++){
            cin>>ch;
            que[i].answer+=ch;
        }
    }
    for(int i=0;i<n;i++){
        stud[i].score=0;
        for(int j=0;j<m;j++){
            que[i].errornum=0;
            int num;
            string ans;
            scanf("(%d ",&num);
            for(int m=0;m<num;m++){
                string ans_single;
                cin>>ans_single;
                ans+=ans_single;
                if(ans==que[i].answer){
                    stud[i].score+=que[i].score;
                }
                else{
                    que[j].errornum++;
                }
            }
            scanf(")");
        }
    }
    for(int i=0;i<n;i++){
        cout<<stud[i].score<<endl;
    }

    return 0;
}
