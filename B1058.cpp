#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
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
	int maxerror=-1;
	for(int i=0;i<m;i++)que[i].errornum=0;

    for(int i=0;i<n;i++){
        stud[i].score=0;
		scanf("\n");
        for(int j=0;j<m;j++){
            
            int num;
            string ans;
            scanf("(%d ",&num);
            for(int m=0;m<num;m++){
                char ans_single;
                //cin>>ans_single;
				scanf(" %c",&ans_single);
                ans+=ans_single;
                
            }
			scanf(")");
			if(j<m-1)scanf(" ");
			if(ans==que[j].answer){
                stud[i].score+=que[j].score;
            }
            else{
                que[j].errornum++;
				maxerror=max(que[j].errornum,maxerror);
            }
            
        }
    }
	vector<int> v;
    for(int i=0;i<n;i++){
        cout<<stud[i].score<<endl;
    }
	if(maxerror==-1){
		cout<<"Too simple"<<endl;
	}
	else{
		cout<<maxerror<<' ';
		for(int i=0;i<m;i++){
			if(que[i].errornum==maxerror)v.push_back(i+1);
		}
		for(int i=0;i<v.size();i++){
			cout<<v[i];
			if(i<v.size()-1)cout<<' ';
			else cout<<'\n';
		}
	}
    return 0;
}
