#include<bits/stdc++.h>
using namespace std;

void FIFO(vector<int> a,int m){
  cout<<"\n-------- FIFO --------\n";
  
  int l=a.size();
  int p_faults=0;
  vector<int> q;
  for(int i=0;i<l;i++){
    bool exist=false;
    for(int x:q){
      if(x==a[i]){
        exist=true;
        break;
      }
    }
    if(!exist){
      p_faults++;
      if(q.size()<m){
        q.push_back(a[i]);
      }
      else{
        if(!q.empty()){
          q.erase(q.begin());
        }
        q.push_back(a[i]);
      }
    }
    
    for(int x : q){
      cout<<" "<<x;
    }
    cout<<"\n";
    
  }
  cout<<"No. of page faults :"<<p_faults;
  
}

void LRU(vector<int> a,int m){
  cout<<"\n-------- LRU --------\n";
  
  int l=a.size();
  int p_faults=0;
  vector<int> q;
  for(int i=0;i<l;i++){
    bool exist=false;
    for(int x:q){
      if(x==a[i]){
        exist=true;
        break;
      }
    }
    if(!exist){
      p_faults++;
      if(q.size()<m){
        q.push_back(a[i]);
      }
      else{
        if(!q.empty()){
          q.erase(q.begin());
        }
        q.push_back(a[i]);
      }
      
    }else{
      if(!q.empty()){
        q.erase(find(q.begin(),q.end(),a[i]));
      }
      q.push_back(a[i]);
    }
    
    for(int x : q){
      cout<<" "<<x;
    }
    cout<<"\n";
  }
  cout<<"No. of page faults :"<<p_faults;
  
}
void OPTIMAL(vector<int> a,int m){
  cout<<"\n-------- OPTIMAL --------\n";
  
  int l=a.size();
  int p_faults=0;
  vector<int> q;
  for(int i=0;i<l;i++){
    bool exist=false;
    for(int x:q){
      if(x==a[i]){
        exist=true;
        break;
      }
    }
    if(!exist){
      p_faults++;
      if(q.size()<m){
        q.push_back(a[i]);
      }
      else{
        map<int,int> ma;
        for(int x:q){
          for(int j=i+1;j<l;j++){
            if(x==a[j]){
              ma[x]=j;
              break;
            }
            ma[x]=INT_MAX;
          }
        }
        
        bool done=false;
        for(int x:q){
          if(ma[x]==INT_MAX){
            q.erase(find(q.begin(),q.end(),x));
            done=true;
            break;
          }
        }
        if(!done){
          int mini=INT_MAX;
          int num=-1;
          for(int x:q){
            if(ma[x]<mini){
              mini=ma[x];
              num=x;
            }
          }  
          q.erase(find(q.begin(),q.end(),num));          
        }
        q.push_back(a[i]);
      }
      
    }
    
    for(int x : q){
      cout<<" "<<x;
    }
    cout<<"\n";
  }
  cout<<"No. of page faults :"<<p_faults;
  
}


int main()
{
    cout << "Page Replacement Simulation\n";
    vector< int > arr;
    int m;
    cout<<"\nEnter page size :";
    cin>>m;
    
    int n;
    cout<<"\nEnter no. of pages :";
    cin>>n;
    
    for(int i=0;i<n;i++){
      int p;
      cout<<"\nEnter pageframe (integer) :";
      cin>>p;
      arr.push_back(p);
    }
    for(int i:arr){
      cout<<" "<<i;
    }
    cout<<"\n\n";
    FIFO(arr,m);
    cout<<"\n\n";
    LRU(arr,m);
    cout<<"\n\n";
    OPTIMAL(arr,m);
    cout<<"\n\n";
    
}

/*
  
  
3
8
2 3 4 5 6 2 5 8

4
8
2 3 4 5 6 2 5 8

3
12
1 2 3 4 1 2 5 1 2 3 4 5

4
12
1 2 3 4 1 2 5 1 2 3 4 5

2
12
1 2 3 4 1 2 5 1 2 3 4 5
 
*/
