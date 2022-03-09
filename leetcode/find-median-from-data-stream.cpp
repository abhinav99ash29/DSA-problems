class MedianFinder {
    priority_queue<int> first;
    priority_queue<int,vector<int>,greater<int>> second;
    int size;
public:
    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {
        if (first.size() == 0) {
            first.push(num);
        } else {
            if (num > first.top()) {
                second.push(num);
                first.push(second.top());
                second.pop();
            } else {
                first.push(num);
            }
        } else {
            if (num > first.top()) {
                second.push(num);
            } else {
                first.push(num);
                second.push(first.top());
                first.pop();   
            }
        }
        size++;
    }
    
    double findMedian() {
        if (size%2 != 0) {
            return first.top();
        }
        return (double)(first.top()+second.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
