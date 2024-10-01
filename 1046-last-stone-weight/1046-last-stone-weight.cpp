class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0; i<stones.size(); i++){  // inserting all stones into pq i.e  max heap 
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int first = pq.top(); // takes the largest stone from the top of the priority queue.
            pq.pop(); // removes that stone from the priority queue.
            int second = pq.top(); // takes the other largest stone from top of pq.
            pq.pop(); // again removes stone from pq 
            int x =first-second;  // if the weight is different then again put bhack into heaP.
            if (x > 0) {    // if  the two stones are not the same size the difference x is pushed back into the priority queue.
                pq.push(x);
            }
        }
        if(pq.size() > 0) 
        return pq.top(); // if element exist we access top if not then return 0. 
        else return 0;
    }
};


// LARGEST STONE  ARE SMASHED TOGETHER