class MyCircularQueue {
    int count;
    vector<int> arr;
    int n;
    int front;
    int last;
public:
    MyCircularQueue(int k) {
        arr.resize(k,-1);
        count=0;
        n=k;
        front=-1;
        last = -1;
    }
    
    bool enQueue(int value) {
        if (count==n) return false;
        last = last+1==n ? (last+1)%n : (last+1);
        if (count==0) front=last;
        arr[last] = value;
        count++;
        return true;
    }
    
    bool deQueue() {
        if (count==0) return false;
        front = front+1==n ? (front+1)%n : (front+1);
        count--;
        if (count==0) last=front;
        return true;
    }
    
    int Front() {
        if (count>0) return arr[front];
        return -1;
    }
    
    int Rear() {
        if (count>0) return arr[last];
        return -1;
        
    }
    
    bool isEmpty() {
        return count==0;
    }
    
    bool isFull() {
        return count==n;
    }
};
