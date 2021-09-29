#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// create a struct for a team here??
struct Team{
  string name = "";
  int rank = 0, points = 0, gamesPlayed = 0;
  int wins = 0, ties = 0, losses = 0;
  int goalDifference = 0, goalsScored = 0, goalsAgainst = 0, gpg = 0;

  Team(string n){
    name = n;
    rank = 0, points = 0, gamesPlayed = 0;
    wins = 0, ties = 0, losses = 0;
    goalDifference = 0, goalsScored = 0, goalsAgainst = 0;
  }

  bool myGame(string game){

    bool played = false;
    string score1 = game.substr(game.find('#')+1,game.find('@'));
    string score2 = game.substr(game.find('@')+1,game.find('#'));
    string ss1 = game.substr(0,game.find('#'));
    string ss2 = game.substr(game.find('#')+1,game.find('\n'));
    //int tmp_p = 0;

    if(name == ss1 || name == ss2){
      played = true;
    }
    if(played){
      gamesPlayed++;
      gpg = (name == ss1) ? stoi(score1) : stoi(score2);
      //goalsAgainst += (name == ss1) ? stoi(score2) : stoi(score1);
      //points += gpg;
      goalsScored += gpg;
      //goalDifference += goalsScored - goalsAgainst;
    }
    //cout << name << " " << goalsScored << " " << goalsAgainst << " "<< gamesPlayed << endl;
    return played;
  }
  
  void getWinner(Team t){
    goalsAgainst += t.gpg;
    t.goalsAgainst += gpg;
    if(gpg == t.gpg) {
      ties++; 
      t.ties++;
      goalsScored -= gpg;
      t.goalsScored -= t.gpg;
    }
    else if(gpg > t.gpg) {
      wins++;
      t.losses++;
    }
    else {
      losses++; 
      t.wins++;
    }
  }
};

void printResults(vector<Team>Teams){
  for(int i = 0;i < Teams.size();i++){
      Teams[i].rank = i + 1;
      cout << Teams[i].rank << ") " << Teams[i].name << " " << Teams[i].points << "p, " << 
      Teams[i].gamesPlayed << "g " << "(" << Teams[i].wins << "-" <<
      Teams[i].ties << "-" << Teams[i].losses << "), " << Teams[i].goalDifference << "gd " << "(" << Teams[i].goalsScored << "-" << Teams[i].goalsAgainst << ")" << endl;
    }
    //cout << endl;
}

bool cmp(Team t1,Team t2){
  if(t1.name.compare(0,t2.name.size(),t2.name) == 0 || t2.name.compare(0,t1.name.size(),t1.name) == 0) return t1.name.size() > t2.name.size();
  else return t1.name < t2.name;
}

bool compareTeams(Team t1, Team t2){
  return t1.points > t2.points || t1.points == t2.points
  && (t1.wins > t2.wins || t1.wins == t2.wins
  && (t1.goalDifference > t2.goalDifference || t1.goalDifference == t2.goalDifference 
  && (t1.goalsScored > t2.goalsScored || t1.goalsScored == t2.goalsScored 
  && (t1.gamesPlayed < t2.gamesPlayed || t1.gamesPlayed == t2.gamesPlayed 
  && (transform(t1.name.begin(),t1.name.begin()+2,t1.name.begin(),::tolower) < transform(t2.name.begin(),t2.name.begin()+2,t2.name.begin(),::tolower)
  //|| transform(t1.name.begin(),t1.name.end(),t1.name.begin(),::tolower) < transform(t2.name.begin(),t2.name.end(),t2.name.begin(),::tolower)
  ))))); //|| tolower(t1.name[0]) == tolower(t2.name[0]))))));
}

int main() {
  int N;

  freopen("uDebug", "r", stdin);
  freopen("outfile.txt", "w", stdout);
  cin >> N;
  cin.ignore();

  while(N--){
    
    int amtTeams = 0;
    string tournName = "", team = "", game="";
    vector<Team> Teams;

    int gamesPlayed = 0;
    vector<string>games;
    
    getline(cin,tournName);
    cout << tournName << endl;

    cin >> amtTeams;
    cin.ignore();
    for(int i = 0;i < amtTeams;i++){
      getline(cin,team);
      //cout << team << " ";
      Teams.push_back(Team(team));
    }
    //cout <<endl;
    
    cin >> gamesPlayed;
    cin.ignore();
    //if(gamesPlayed == 0){
      //sort(Teams.begin(),Teams.end(),compareTeams);
      //printResults(Teams);
      //cout << endl;
    //}
    //else{
      for(int i = 0;i < gamesPlayed;i++){
        getline(cin,game);
        //cout << game << " ";
        string t1, t2;
        int tmp = 0, count = 0;
        t1 = game.substr(0,game.find('@'));
        t2 = game.substr(game.find('@')+1,game.find('\n'));
        //cout << t1 << " " << t2;
        for(int j = 0;j < Teams.size();j++){
          if(Teams[j].myGame(t1) || Teams[j].myGame(t2)) {
            count++;
            if(count == 1){
              tmp = j;
            }
            if(count == 2){
              count = j;
              break;
            }
          }
        }
      
        Teams[tmp].goalsAgainst += Teams[count].gpg;
        Teams[count].goalsAgainst += Teams[tmp].gpg;

        if(Teams[tmp].gpg > Teams[count].gpg){
          Teams[tmp].wins++;
          Teams[tmp].points += 3;
          Teams[count].losses++;
        }
        else if(Teams[count].gpg > Teams[tmp].gpg){
          Teams[count].wins++;
          Teams[count].points += 3;
          Teams[tmp].losses++;
        }
        else{
          Teams[count].ties++;
          Teams[tmp].ties++;
          Teams[count].points++;
          Teams[tmp].points++;
        }
      } 
      //cout << endl;
      for(int i = 0;i < Teams.size();i++){
        Teams[i].goalDifference = Teams[i].goalsScored - Teams[i].goalsAgainst;
      }

      //sort(Teams.begin(),Teams.end(),[](const Team& lhs,const Team& rhs){
      //return (lhs.points > rhs.points) || (lhs.wins > rhs.wins); //|| (lhs.goalDifference > rhs.goalDifference);// , (lhs.goalsScored > rhs.goalsScored) || (lhs.gamesPlayed < rhs.gamesPlayed);
      //});
      sort(Teams.begin(),Teams.end(),compareTeams);
      printResults(Teams);
      //cout << "\n";
      // process vectors here???
      if(N != 0) cout << endl;
    }
  //}
  return 0;
}