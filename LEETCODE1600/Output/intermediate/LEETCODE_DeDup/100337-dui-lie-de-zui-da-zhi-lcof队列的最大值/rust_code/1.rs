Java []
class MaxQueue {

    int[] queue = new int[10001];
    int QueueHead = 0;
    int QueueTail = 0;
    
    int[] maxQueue = new int[10001];
    int MaxQueueHead = 0;
    int MaxQueueTail = 0;
    
    public MaxQueue() {

    }
    
    public int max_value() {
        if (MaxQueueHead == MaxQueueTail) return -1;
        else return maxQueue[MaxQueueHead]; 
    }
    
    public void push_back(int value) {
        queue[QueueTail++] = value;
        while(MaxQueueHead != MaxQueueTail && maxQueue[MaxQueueTail-1] < value){
            MaxQueueTail--;
        }
        maxQueue[MaxQueueTail++] = value;
    }
    
    public int pop_front() {
        if (QueueHead == QueueTail) return -1;
        if(queue[QueueHead] == maxQueue[MaxQueueHead])
            MaxQueueHead++;
        return queue[QueueHead++];

    }
}

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue obj = new MaxQueue();
 * int param_1 = obj.max_value();
 * obj.push_back(value);
 * int param_3 = obj.pop_front();
 */