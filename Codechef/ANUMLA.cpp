#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	// your code goes here
	int t, n, num;
	cin >> t;
	while(t--){
	    cin >> n;
	    vector<int> vec = vector<int>(), sumvec = vector<int>();
	    priority_queue<int, vector<int>, greater<int>> q1 = priority_queue<int, vector<int>, greater<int>>(), 
	    q2 = priority_queue<int, vector<int>, greater<int>>();
    	for(int i = 0; i< pow(2, n); i++){
    	   cin >> num;
    	   q1.push(num);
    	}
    	q1.pop();
    	
    	for(int i=0; i<n; ){
    	    if(q2.empty() || q2.top() != q1.top()){
    	        int q1top = q1.top();
    	        cout << q1top << " ";
    	        q1.pop();
    	        
    	        vector<int> this_sum = vector<int>();
    	        this_sum.push_back(q1top);
    	        for(int j=0; j<sumvec.size(); j++){
    	            this_sum.push_back(sumvec[j] + q1top);
    	            q2.push(sumvec[j] + q1top);
    	        }
    	        sumvec.insert(sumvec.end(), this_sum.begin(), this_sum.end());
    	        i++;
    	    } else {
                q2.pop();
    	        q1.pop();
    	    }
    	}
    	cout << endl;
	}
	return 0;
}
