class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> stonesq;
        for(int i=0; i<stones.size(); i++){
         stonesq.push(stones[i])  ;
        }
        if(stonesq.size() == 1){
            return stonesq.top();
        }
        while(!stonesq.empty()){
            int x = stonesq.top();
            stonesq.pop();
            int y = stonesq.top();
            stonesq.pop();
            if(x != y){
                stonesq.push(abs(x-y));
            }    
            
            if(stonesq.size() == 1){
                return stonesq.top();
            }
        }
        return 0;
    }
};