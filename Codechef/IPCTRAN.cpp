#include <iostream>
#include <queue> 
#include <map> 
using namespace std;

struct Data {
    Data(int d, int t, int s){
        this->di = d;
        this->ti = t;
        this->si = s;
    }
  int di;
  int ti;
  int si;
};

int main() {
	// your code goes here
	int t, n, d, di, ti, si;
	cin >> t;
	while(t--){
	    priority_queue <int> q; 
	    cin >> n >> d;
	    map<int, vector<Data>> m = map<int, vector<Data>>();
	    // Seed Data
	    for(int i = 0; i< n; i++){
	        cin >> di >> ti >> si;
	        Data data = Data(di, ti, si);
	        if(m.find(di) == m.end()){
	            m[di] = vector<Data>();
	        } 
	        m[di].push_back(data);
	    }
	    
	    for(int i=0; i<d; i++){
	        if(m.find(i+1) != m.end()){
	            vector<Data> vec = m[i+1];
	            for(int k=0; k<vec.size(); k++){
	                for(int l=0; l<vec[k].ti; l++){
	                    q.push(vec[k].si);    
	                }
	            }
	        }
	        if(!q.empty()){
	            q.pop();    
	        }
	    }
	    long sum = 0;
	    while(!q.empty()){
	        sum += q.top();
	        q.pop();
	    }
	    cout << sum << endl;
	}
	return 0;
}
