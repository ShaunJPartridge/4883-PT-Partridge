#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point;

int c, n;
vector<Point>points;
int x,y;

struct Point{
  int x, y;
  Point(): x{0}, y{0}{}
  Point(int x,int y):x{x},y{y}{}
  
};

bool cmp(Point &a, Point &b){
  return a.x < b.x;
}

void printPoints(){
  for(int i = 0;i < points.size();i++){
    cout << "(" << points[i].x << "," << points[i].y << ")" << " ";
  }
  cout << endl;
}

int main() {

  freopen("infile","r",stdin);
  freopen("outfile","w",stdout);
  cin >> c;
  while(c--){
    cin >> n;
    while(n--){
      cin >> x >> y;
      points.push_back(Point(x,y));
    }
    // process vector here !!!!!
    //printPoints();
    sort(points.begin(),points.end(),cmp);
    //printPoints();
    int max = 0;
    double distance = 0 , sum = 0;
    for(int i = points.size()-1;i >= 0;i--){
      if(points[i].y > max){
        distance = sqrt(pow(points[i].x - points[i+1].x,2)+pow(points[i].y - points[i+1].y,2));
        sum += distance * (points[i].y - max) / (points[i].y - points[i+1].y);
        max = points[i].y;
      }
    }
    cout << fixed << setprecision(2) << sum << endl;
    points.clear();
  }
   
}