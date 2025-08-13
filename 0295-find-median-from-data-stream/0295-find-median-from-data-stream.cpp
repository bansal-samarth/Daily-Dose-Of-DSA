class MedianFinder {
public:
    priority_queue<int> mx;
    priority_queue<int, vector<int>, greater<int>> mn;

    MedianFinder() {}
    
    void addNum(int num) {
        if(mx.size() == 0) {
            mx.push(num);
            return;
        }

        if(mx.top() >= num)
            mx.push(num);
        else
            mn.push(num);
        
        if(mn.size() > mx.size()) {
            int x = mn.top();
            mn.pop();
            mx.push(x);
        } else if (mx.size() - mn.size() > 1){
            int x = mx.top();
            mx.pop();
            mn.push(x);
        }

        return;
    }
    
    double findMedian() {
        
        if(mx.size() > mn.size())
            return (mx.top() / 1.0);
        
        return (mx.top() + mn.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */