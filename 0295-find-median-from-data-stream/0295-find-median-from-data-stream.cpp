class MedianFinder {
public:
priority_queue<int, vector<int>, greater<int>> largest; //min heap to stpre the largest
priority_queue<int> smallest; //max heap to store the smallest number

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        smallest.push(num);
        if(!smallest.empty() && !largest.empty() && smallest.top() > largest.top()){
            int val1 = smallest.top();
            smallest.pop();
            largest.push(val1);
        }

        if(smallest.size() > largest.size()+1){
            int val1 = smallest.top();
            smallest.pop();
            largest.push(val1);
        }

        if(largest.size() > smallest.size()){
            int val1 = largest.top();
            largest.pop();
            smallest.push(val1);
        }
    }
    
    double findMedian() {
        if(smallest.size()==largest.size()){
            return (double)(smallest.top()+largest.top())/2;
        }
        if(smallest.size()>largest.size()){
            return smallest.top();
        }
        return largest.top();
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */