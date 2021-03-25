#include<bits/stdc++.h>
using namespace std;

class process{
  public:
  int PID,priority,at,bt,rbt,lrt,status=0;
  int rt,wt=0,tat,running=0;
  //at=arrival time
  //bt=burst time
  //rbt=remaining burst time
  //lrt=last running time
  //status=0 for no started,1 means started ,2 means finished
  //rt=response time
  //wt=waiting time
  //tat=turn around time
};

void draw(vector<process> a){
  int TAT=0,RT=0,WT=0;
  int n=a.size();
  cout<<"\n";
  cout<<"-----------------------------------------------------\n";
  cout<<"| PID | Priority |  A_t |  B_t |  R_T |  W_T |  TAT |\n";    
  cout<<"-----------------------------------------------------\n";
  for(auto i : a){
    printf("| %2d  | %5d    | %3d  | %3d  | %3d  | %3d  | %3d  |\n",i.PID,i.priority,i.at,i.bt,i.rt,i.wt,i.tat);
    TAT+=i.tat;
    RT+=i.rt;
    WT+=i.wt;    
  }
   cout<<"-----------------------------------------------------\n";
  printf("|                  Average =   | %2.2f | %2.2f | %2.2f |\n",(float)RT/n,(float)WT/n,(float)TAT/n);
   cout<<"-----------------------------------------------------\n";
}

bool comp_by_a_time(process a,process b){
  return b.at-a.at>0;
}
bool comp_by_b_time(process a,process b){
  return b.bt-a.bt>0;
}
bool comp_by_prio(process a,process b){
  return b.priority-a.priority>0;
}
bool comp_by_pid(process a,process b){
  return b.PID-a.PID>0;
}

void FCFS(vector<process> a){
  cout<<"\n------------------- FCFS Algorithm ------------------\n";
  sort(a.begin(),a.end(),comp_by_a_time);
  int T=a[0].at;
  cout<<"Gantt chart (by PID):\n";
  for(int i=0;i<a.size();i++){   
     a[i].rt=T;
     a[i].wt=T-a[i].at;
     a[i].tat=a[i].wt+a[i].bt;
     T=a[i].at+a[i].tat;
     cout<<" "<<a[i].PID;
  }
  
  sort(a.begin(),a.end(),comp_by_pid);
  draw(a);
}

void SJF(vector<process> a){
  cout<<"\n-------------------- SJF Algorithm ------------------\n";
  sort(a.begin(),a.end(),comp_by_b_time);
  int T=0;
  bool running=false;
  int count=0;
  cout<<"Gantt chart (by PID):\n";
  while(true){
    if(count>1000){
      break;
    }
    count++;
    
      for(int i=0;i<a.size();i++){   
        if(T>=a[i].at && a[i].status==0){
          a[i].rt=T;
          a[i].wt=T-a[i].at;
          a[i].tat=a[i].wt+a[i].bt;
          a[i].status=1;
          T+=a[i].bt;
          cout<<" "<<a[i].PID;
        }
      } 
  }

  sort(a.begin(),a.end(),comp_by_pid);
  draw(a);
}


void SRTF(vector<process> a){
  cout<<"\n------------------- SRTF Algorithm ------------------\n";
  sort(a.begin(),a.end(),comp_by_b_time);
  int T=0;
  bool running=false;
  int count=0;
  cout<<"Gantt chart (by PID):\n";
  while(true){
    if(count>1000){
      break;
    }
    count++;
    
      for(int i=0;i<a.size();i++){   
        if(T>=a[i].at ){
          if( a[i].status==0){
            //first time
            a[i].rt=T;
            a[i].wt=T-a[i].at;
            a[i].status=1;
            a[i].rbt--;
            if(a[i].rbt==0){
              a[i].status=2;//done
              a[i].tat=a[i].wt+a[i].bt;  
            }
            T++;
            a[i].lrt=T;
            cout<<" "<<a[i].PID;
            break;
          }
          else if(a[i].status==1){
            //running 
            a[i].wt+=T-a[i].lrt;
            a[i].rbt--;
            if(a[i].rbt==0){
              a[i].status=2;//done
              a[i].tat=a[i].wt+a[i].bt;
            }
            T++;
            a[i].lrt=T;
            cout<<" "<<a[i].PID;
            break;
          }
        }
      } 
  }

  sort(a.begin(),a.end(),comp_by_pid);
  draw(a);
}

void PRIO_NONPREEM(vector<process> a){
  cout<<"\n--------- Priority (non-primtive) Algorithm ---------\n";
  sort(a.begin(),a.end(),comp_by_prio);
  int T=0;
  bool running=false;
  int count=0;
  cout<<"Gantt chart (by PID):\n";
  while(true){
    if(count>1000){
      break;
    }
    count++;
    
      for(int i=0;i<a.size();i++){   
        if(T>=a[i].at && a[i].status==0){
          a[i].rt=T;
          a[i].wt=T-a[i].at;
          a[i].tat=a[i].wt+a[i].bt;
          a[i].status=1;//done
          T+=a[i].bt;
          cout<<" "<<a[i].PID;
        }
      }     
  }

  sort(a.begin(),a.end(),comp_by_pid);
  draw(a);
}


void PRIO_PREEM(vector<process> a){
  cout<<"\n----------- Priority (primtive) Algorithm -----------\n";
  sort(a.begin(),a.end(),comp_by_prio);
  int T=0;
  bool running=false;
  int count=0;
  cout<<"Gantt chart (by PID):\n";
  while(true){
    if(count>1000){
      break;
    }
    count++;
    
      for(int i=0;i<a.size();i++){   
        if(T>=a[i].at ){
          if( a[i].status==0){
            //first time
            a[i].rt=T;
            a[i].wt=T-a[i].at;
            a[i].status=1;
            a[i].rbt--;
            if(a[i].rbt==0){
              a[i].status=2;//done
              a[i].tat=a[i].wt+a[i].bt;  
            }
            T++;
            a[i].lrt=T;
            cout<<" "<<a[i].PID;
            break;
          }
          else if(a[i].status==1){
            //running
            
            a[i].wt+=T-a[i].lrt;
            a[i].rbt--;
            if(a[i].rbt==0){
              a[i].status=2;//done
              a[i].tat=a[i].wt+a[i].bt;
            }
            T++;
            a[i].lrt=T;
            cout<<" "<<a[i].PID;
            break;
          }
        }
      }
  }

  sort(a.begin(),a.end(),comp_by_pid);
  draw(a);
}


void RR(vector<process> a,int time_block){
  cout<<"\n--------------- Round Robin Algorithm ---------------\n";
  cout<<"Time interval :"<<time_block<<"\n";
  sort(a.begin(),a.end(),comp_by_a_time);
  int T=0;
  int count=0;
  cout<<"Gantt chart (by PID):\n";
  while(true){
    if(count>1000){
      break;
    }
    count++;
    
      for(int i=0;i<a.size();i++){   
        if(T>=a[i].at){
          if( a[i].status==0){
            //first time
            a[i].rt=T;
            a[i].wt=T-a[i].at;
            a[i].status=1;
            T++;
            a[i].rbt--;
            a[i].lrt=T;
            cout<<" "<<a[i].PID;
            for(int j=0;j<time_block-1;j++){
              
              if(a[i].rbt==0){
                a[i].status=2;//done
                a[i].tat=a[i].wt+a[i].bt;
                break;  
              }
              a[i].wt+=T-a[i].lrt;
              a[i].rbt--;
              T++;
              a[i].lrt=T;
              cout<<" "<<a[i].PID;
            }
          }
          else if(a[i].status==1){
            //running
            for(int j=0;j<time_block;j++){
              
              if(a[i].rbt==0){
                a[i].status=2;//done
                a[i].tat=a[i].wt+a[i].bt;
                break;  
              }
              a[i].wt+=T-a[i].lrt;
              a[i].rbt--;
              T++;
              a[i].lrt=T;
              cout<<" "<<a[i].PID;
            }     
          }
        }
      }
  }

  sort(a.begin(),a.end(),comp_by_pid);
  draw(a);
}






int main()
{
    cout << "CPU scheduling simulation\n";
    vector< process > arr;
    
    int n;
    cout<<"Enter no. of process\n";
    cin>>n;
    
    for(int i=0;i<n;i++){
      
      int pid=i+1,prio,a_time,b_time;
      cout<<"\nEnter Priority(lower number -> higher priority) :";
      cin >>prio;
      cout<<"\nArrival time :";
      cin>>a_time;
      cout<<"\nBurst time :";
      cin>>b_time;
      if(prio<0){
        cout<<"Priority can not be negative.\n";
        exit(0);
      }
      process temp;
      temp.PID=pid;
      temp.priority=prio;
      temp.at=a_time;
      temp.bt=b_time;
      temp.rbt=b_time;
      temp.status=0;//0 means not done yet;
      arr.push_back(temp);
    }
    
    cout<<"\n\n";
    FCFS(arr);
    cout<<"\n\n";
    SJF(arr);
    cout<<"\n\n";
    SRTF(arr);
    cout<<"\n\n";
    PRIO_NONPREEM(arr);
    cout<<"\n\n";
    PRIO_PREEM(arr);
    cout<<"\n\n";
    RR(arr,3);
    cout<<"\n\n";
    RR(arr,10);
}

/*
  
  
3
1 2 3
4 5 6
2 5 8
 
 
4
5 0 7
2 2 4
1 4 1
8 5 4


output:

CPU scheduling simulation
Enter no. of process
4

Enter Priority(lower number -> higher priority) :5
Arrival time :0
Burst time :7

Enter Priority(lower number -> higher priority) :2
Arrival time :2
Burst time :4

Enter Priority(lower number -> higher priority) :1
Arrival time :4
Burst time :1

Enter Priority(lower number -> higher priority) :8
Arrival time :5
Burst time :4



------------------- FCFS Algorithm ------------------
Gantt chart (by PID):
 1 2 3 4
-----------------------------------------------------
| PID | Priority |  A_t |  B_t |  R_T |  W_T |  TAT |
-----------------------------------------------------
|  1  |     5    |   0  |   7  |   0  |   0  |   7  |
|  2  |     2    |   2  |   4  |   7  |   5  |   9  |
|  3  |     1    |   4  |   1  |  11  |   7  |   8  |
|  4  |     8    |   5  |   4  |  12  |   7  |  11  |
-----------------------------------------------------
|                  Average =   | 7.50 | 4.75 | 8.75 |
-----------------------------------------------------



-------------------- SJF Algorithm ------------------
Gantt chart (by PID):
 1 3 2 4
-----------------------------------------------------
| PID | Priority |  A_t |  B_t |  R_T |  W_T |  TAT |
-----------------------------------------------------
|  1  |     5    |   0  |   7  |   0  |   0  |   7  |
|  2  |     2    |   2  |   4  |   8  |   6  |  10  |
|  3  |     1    |   4  |   1  |   7  |   3  |   4  |
|  4  |     8    |   5  |   4  |  12  |   7  |  11  |
-----------------------------------------------------
|                  Average =   | 6.75 | 4.00 | 8.00 |
-----------------------------------------------------



------------------- SRTF Algorithm ------------------
Gantt chart (by PID):
 1 1 2 2 3 2 2 4 4 4 4 1 1 1 1 1
-----------------------------------------------------
| PID | Priority |  A_t |  B_t |  R_T |  W_T |  TAT |
-----------------------------------------------------
|  1  |     5    |   0  |   7  |   0  |   9  |  16  |
|  2  |     2    |   2  |   4  |   2  |   1  |   5  |
|  3  |     1    |   4  |   1  |   4  |   0  |   1  |
|  4  |     8    |   5  |   4  |   7  |   2  |   6  |
-----------------------------------------------------
|                  Average =   | 3.25 | 3.00 | 7.00 |
-----------------------------------------------------



--------- Priority (non-primtive) Algorithm ---------
Gantt chart (by PID):
 1 4 3 2
-----------------------------------------------------
| PID | Priority |  A_t |  B_t |  R_T |  W_T |  TAT |
-----------------------------------------------------
|  1  |     5    |   0  |   7  |   0  |   0  |   7  |
|  2  |     2    |   2  |   4  |  12  |  10  |  14  |
|  3  |     1    |   4  |   1  |  11  |   7  |   8  |
|  4  |     8    |   5  |   4  |   7  |   2  |   6  |
-----------------------------------------------------
|                  Average =   | 7.50 | 4.75 | 8.75 |
-----------------------------------------------------



----------- Priority (primtive) Algorithm -----------
Gantt chart (by PID):
 1 1 2 2 3 2 2 1 1 1 1 1 4 4 4 4
-----------------------------------------------------
| PID | Priority |  A_t |  B_t |  R_T |  W_T |  TAT |
-----------------------------------------------------
|  1  |     5    |   0  |   7  |   0  |   5  |  12  |
|  2  |     2    |   2  |   4  |   2  |   1  |   5  |
|  3  |     1    |   4  |   1  |   4  |   0  |   1  |
|  4  |     8    |   5  |   4  |  12  |   7  |  11  |
-----------------------------------------------------
|                  Average =   | 4.50 | 3.25 | 7.25 |
-----------------------------------------------------



--------------- Round Robin Algorithm ---------------
Time interval :3
Gantt chart (by PID):
 1 1 1 2 2 2 3 4 4 4 1 1 1 2 4 1
-----------------------------------------------------
| PID | Priority |  A_t |  B_t |  R_T |  W_T |  TAT |
-----------------------------------------------------
|  1  |     5    |   0  |   7  |   0  |   9  |  16  |
|  2  |     2    |   2  |   4  |   3  |   8  |  12  |
|  3  |     1    |   4  |   1  |   6  |   2  |   3  |
|  4  |     8    |   5  |   4  |   7  |   6  |  10  |
-----------------------------------------------------
|                  Average =   | 4.00 | 6.25 | 10.25 |
-----------------------------------------------------



--------------- Round Robin Algorithm ---------------
Time interval :10
Gantt chart (by PID):
 1 1 1 1 1 1 1 2 2 2 2 3 4 4 4 4
-----------------------------------------------------
| PID | Priority |  A_t |  B_t |  R_T |  W_T |  TAT |
-----------------------------------------------------
|  1  |     5    |   0  |   7  |   0  |   0  |   7  |
|  2  |     2    |   2  |   4  |   7  |   5  |   9  |
|  3  |     1    |   4  |   1  |  11  |   7  |   8  |
|  4  |     8    |   5  |   4  |  12  |   7  |  11  |
-----------------------------------------------------
|                  Average =   | 7.50 | 4.75 | 8.75 |
-----------------------------------------------------

Process finished.
 
*/
