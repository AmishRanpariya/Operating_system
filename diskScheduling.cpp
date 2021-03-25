#include <iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


void moved(int x,int y){
  if(x==y){
    return;
  }else{
    printf("Head moved from %4d to %4d location.\n",x,y);
  }
}




void FCFS(vector<int> a,int max){
  int seek=0;
  cout<<"\n---- FCFS Algorithm ----\n";
  
  for(int i=1;i<a.size();i++){
    moved(a[i-1],a[i]);
    seek+=abs(a[i]-a[i-1]);
  }
  
  cout<<"Total seek time :"<<seek<<"\n";
  cout<<"Average seek time :"<<(float)seek/(a.size()-1)<<"\n";
}





void SSTF(vector<int> a,int max){
  int queue_size=a.size();
  cout<<"\n---- SSTF Algorithm ----\n";
  
  vector<pair<int,int>> q;
  for(int i=0;i<queue_size;i++){
    q.push_back(pair<int,int>{a[i],0});
  }
  
  int head=q[0].first;
  q[0].second=1;
  int seek=0;
  
  for(int i=1;i<queue_size;i++){
    int min=max;
    int mini=0;
    for(int j=0;j<queue_size;j++){
      if(q[j].second==0 && abs(q[j].first-head)<=min){
        min=abs(q[j].first-head);
        mini=j;
      }  
    }
    q[mini].second=1;
    seek+=min;
    moved(head,q[mini].first);
    head=q[mini].first;
  }
  
  cout<<"Total seek time :"<<seek<<"\n";
  cout<<"Average seek time :"<<(float)seek/(queue_size-1)<<"\n";
}




void SCAN(vector<int> a,int max){
  int queue_size=a.size();
  cout<<"\n---- SCAN Algorithm ----\n";
  int head=a[0];
  sort(a.begin()+1,a.end());
  
  int seek=0;
  int pivot=head;
  for(int i=1;i<queue_size;i++){
    if(a[i]>=pivot){
      seek+=abs(a[i]-head);
      moved(head,a[i]);
      head=a[i];
    }
  }
  
  seek+=abs(max-head);
  moved(head,max);
  head=max;
    
  for(int i=queue_size-1;i>0;i--){
    if(a[i]<pivot){
      seek+=abs(a[i]-head);
      moved(head,a[i]);
      head=a[i];
    }
  }
  seek+=abs(head-0);
  moved(head,0);
  head=0;
   
  cout<<"Total seek time :"<<seek<<"\n";
  cout<<"Average seek time :"<<(float)seek/(queue_size-1)<<"\n";   
}




void CSCAN(vector<int> a,int max){
  int queue_size=a.size();
  cout<<"\n---- CSCAN Algorithm ----\n";
  int head=a[0];
  sort(a.begin()+1,a.end());
  
  int seek=0;
  int pivot=head;
  for(int i=1;i<queue_size;i++){
    if(a[i]>=pivot){
      seek+=abs(a[i]-head);
      moved(head,a[i]);
      head=a[i];
    }
  }
  
  seek+=abs(max-head);
  moved(head,max);
  head=max;
  
  seek+=abs(head-0);
  moved(head,0);
  head=0;
  
  for(int i=1;i<queue_size;i++){
    if(a[i]<pivot){
      seek+=abs(a[i]-head);
      moved(head,a[i]);
      head=a[i];
    }
  }
    
  cout<<"Total seek time :"<<seek<<"\n";
  cout<<"Average seek time :"<<(float)seek/(queue_size-1)<<"\n";    
}





void LOOK(vector<int> a,int max){
  int queue_size=a.size();
  cout<<"\n---- LOOK Algorithm ----\n";
  int head=a[0];
  sort(a.begin()+1,a.end());
  
  int seek=0;
  int pivot=head;
  for(int i=1;i<queue_size;i++){
    if(a[i]>=pivot){
      seek+=abs(a[i]-head);
      moved(head,a[i]);
      head=a[i];
    }
  }
      
  for(int i=queue_size-1;i>0;i--){ 
    if(a[i]<pivot){
      seek+=abs(a[i]-head);
      moved(head,a[i]);
      head=a[i];
    }
  }
      
  cout<<"Total seek time :"<<seek<<"\n";
  cout<<"Average seek time :"<<(float)seek/(queue_size-1)<<"\n"; 
}




void CLOOK(vector<int> a,int max){
  int queue_size=a.size();
  cout<<"\n---- CLOOK Algorithm ----\n";
  int head=a[0];
  sort(a.begin()+1,a.end());
  
  int seek=0;
  int pivot=head;
  for(int i=1;i<queue_size;i++){
    if(a[i]>=pivot){
      seek+=abs(a[i]-head);
      moved(head,a[i]);
      head=a[i];
    }
  }
  
  for(int i=1;i<queue_size;i++){
    if(a[i]<pivot){
      seek+=abs(a[i]-head);
      moved(head,a[i]);
      head=a[i];
    }
  }
     
  cout<<"Total seek time :"<<seek<<"\n";
  cout<<"Average seek time :"<<(float)seek/(queue_size-1)<<"\n"; 
}



int main()
{
    cout << "Hello, Dcoder!\n";
    vector<int> arr;
  
    int MAX_DISK_SIZE;
    cout<<"Enter the Maximum disk size\n";
    cin>>MAX_DISK_SIZE;
    
    int n;
    cout<<"Enter no. of locations\n";
    cin>>n;
    
    int head;
    cout<<"Enter HEAD location\n";
    cin>>head;
    if(head>MAX_DISK_SIZE||head<0){
      cout<<"Disk location out of bound\n";
      exit(0);
    }
    arr.push_back(head);
    
    while(n--){
      int loc;
      cout<<"Enter locations\n";
      cin>>loc;
      if(loc>MAX_DISK_SIZE||loc<0){
        cout<<"Disk location out of bound\n";
        exit(0);
      }
      arr.push_back(loc);
    }
    
    for(int i : arr){
      cout<<i<<"\t";
    }
    cout<<"\n\n\n";
    
    FCFS(arr,MAX_DISK_SIZE);
    cout<<"\n\n\n";
    SSTF(arr,MAX_DISK_SIZE);
    cout<<"\n\n\n";
    SCAN(arr,MAX_DISK_SIZE);
    cout<<"\n\n\n";
    CSCAN(arr,MAX_DISK_SIZE);
    cout<<"\n\n\n";
    LOOK(arr,MAX_DISK_SIZE);
    cout<<"\n\n\n";
    CLOOK(arr,MAX_DISK_SIZE);
    cout<<"\n\n\n";
   
}
