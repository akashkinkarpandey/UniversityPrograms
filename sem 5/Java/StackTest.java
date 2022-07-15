class Stack{
    int arr[];
    int capacity;
    int top;
    boolean isPush;

    Stack(int size) {
       arr = new int[size];
       capacity = size;
       top = -1;
    }

    void push(int x) {
        if(isFull()) System.out.println("Overflow!!");
        
        System.out.println(x+" inserted.");
        arr[++top]=x;
        isPush=true;
        display(this.top, isPush);
    }

    void display(int top, boolean ispushed) {  
        System.out.println("Stack contents: ");
        if(ispushed){
            while(top >= 0){
                System.out.println(arr[top]+" ");
                top--;   
            }
        }
        else{
            while(top > 0) {
                System.out.println(arr[top-1]+" ");
                top--; 
            }
        }
        System.out.println();
    }

    int pop() {
        if(isEmpty()){
            System.out.println("Underflow!!");
            return -404;
        } 
        
        System.out.println("Removed "+p());
        isPush=false;
        display(top, isPush);
        return arr[top--]; 
    }

    int p() {
        if(!isEmpty()) return arr[top];
        return -1;
    }

    int getSize(){
        return top+1;
    }

    boolean isFull() {
        return (top == capacity-1);
    }

    boolean isEmpty() {
        return top == -1;
    }
  
}

public class StackTest {
    public static void main(String [] args)
    {
        Stack s = new Stack(10);
        s.push(5);
        s.push(8);
        s.pop();
        s.push(10);
        s.push(11);
        s.push(10);
        s.push(1);
        s.pop();
        s.pop();
        s.pop();
        System.out.println("The size of the stack:"+s.getSize());
        System.out.println("The top element is "+s.p());
        s.pop();
        if(s.isEmpty())
        {
            System.out.println("the Stack is empty");
        }
        else{
            System.out.println("the Stack is not empty");
        }
        System.out.println();
    }
    
}
