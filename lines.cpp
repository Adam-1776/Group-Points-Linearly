#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

float mostFrequent(float arr[], int n){
  unordered_map<float, float> hash;
  for(int i=0;i<n;i++)
    hash[arr[i]]++;
  int max_count=0,res=-1;
  for(auto i:hash){
    if(max_count<i.second){
      res = i.first;
      max_count = i.second;
    }
  }
  return res;
}

float findSlope(int x[], int y[], int index1, int index2){
  if(index1==index2) return 0;
  if(x[index1]==x[index2]) return 99999;
  float v=y[index2]-y[index1];
  float h=x[index2]-x[index1];
  float ans=v/h;
  //if(ans<0) return float(ans*-1);
  //else return ans;
  return ans;
}

int groupPoints(int cnt, int x[], int y[]){
  float arr[cnt]={0};
  int count=0;
  int biggestCount=0;
  for(int i=0;i<cnt;++i){
    for(int j=0;j<cnt;++j){
      arr[j]=findSlope(x,y,i,j);
    }
    int freqSlope=mostFrequent(arr,cnt);
    for(int i=0;i<cnt;++i){
      if(arr[i]==freqSlope) ++count;
    }
    if(count>biggestCount) biggestCount=count;
    count=0;
  }
  return biggestCount+1;
}

int main(int argc, char **argv){
  if(argc<2) {cout<<"Provide the input file as a command line argument"; return 0;}
  ifstream is(argv[1]);
  int cnt=0;
  int temp=0;
  is>>cnt;
  int x[cnt]={0};
  int y[cnt]={0};
  for(int i=0;i<cnt;++i){
    is>>temp;
    x[i]=temp;
    is>>temp;
    y[i]=temp;
  }
  is.close();
  int ans=groupPoints(cnt,x,y);
  cout<<"Maximum number of points on one line is "<<ans<<endl;
  return 0;

}
