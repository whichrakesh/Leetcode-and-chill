#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

struct Node 
{
    Node(int w, int dishIndex){
        this->maxWeight = w;
        this->dishes = list<int>();
        this->dishes.push_back(dishIndex);
    }
    int maxWeight;
    list<int> dishes;
};

int main() {
	// your code goes here
	int T, N, Q;
	cin >> T;
	while(T--){
	    cin >> N;
	    vector<int> weights = vector<int>(N, 0), dishToOwnerMap = vector<int>(N, 0);
	    vector<Node*> dishesForOwner = vector<Node*>(N, NULL);
	    for(int i=0; i<N; i++){
	        cin >> weights[i];
	    }
	    
	    for(int i=0; i<N; i++){
	        dishToOwnerMap[i] = i;
	        dishesForOwner[i] = new Node(weights[i], i);
	    }
	    cin >> Q;
	    for(int i=0; i<Q; i++){
	        int op, x, y;
	        cin >> op;
	        if(op == 0){
	            cin >> x >> y;
	            x--;
	            y--;
	            int o1 = dishToOwnerMap[x];
	            int o2 = dishToOwnerMap[y];
	            if(o1 == o2){
	                cout << "Invalid query!" << endl;
	            } else {
	                Node* d1 = dishesForOwner[o1];
    	            Node* d2 = dishesForOwner[o2];
    	            if(d1->maxWeight > d2->maxWeight){
    	                d1->dishes.insert(d1->dishes.end(), d2->dishes.begin(), d2->dishes.end());
    	                for(auto it = d2->dishes.begin(); it != d2->dishes.end(); it++){
    	                    dishToOwnerMap[*it] = o1; 
    	                }
    	                dishesForOwner[o2] = NULL;
    	                delete d2;
    	            } else if(d1->maxWeight < d2->maxWeight){
    	                d2->dishes.insert(d2->dishes.end(), d1->dishes.begin(), d1->dishes.end());
    	                for(auto it = d1->dishes.begin(); it != d1->dishes.end(); it++){
    	                    dishToOwnerMap[*it] = o2; 
    	                }
    	                dishesForOwner[o1] = NULL;
    	                delete d1;
    	            } 
	            }
	            
	        } else {
	            cin >> x;
	            cout << dishToOwnerMap[x-1]+1 << endl;
	        } 
	    }
	}
	return 0;
}
