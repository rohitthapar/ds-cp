template <typename T>
class QueueArray{
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

    public:
    QueueArray(int s){
        data = new T[s];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = s;
    }

    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
    void enqueue(T element){
        if(size == capacity){
            std::cout<<"Queue Full ";
            return;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex+1)%5;
        if(firstIndex == -1){
            firstIndex=0;
        }
        size++;
   }
   T front(){
       if(isEmpty()){
           std::cout<<"Queue is empty ";
           return 0;
       }
       return data[firstIndex];
   }
   T dequeue(){
         if(isEmpty()){
           std::cout<<"Queue is empty ";
           return 0;
       }
       T ans = data[firstIndex];
       firstIndex=(firstIndex+1)%capacity;
       size--;
       if(size == 0){
           firstIndex=-1;
           nextIndex=0;
       }
       return ans;
   }
};