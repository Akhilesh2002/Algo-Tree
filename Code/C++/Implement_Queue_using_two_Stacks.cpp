//We can implement a queue using two stacks :- 
//1) Enqueue the elements in stack1.
//2) We need to pop all the elements from stack1 and keep adding them in the stack2. So, the bottom element of the stack1 will be the top element of stack2. Now if we pop an
//   element from the stack2, we popped the bottom element of stack1. So, that’s our dequeue operation. After the operation is done, we should put the elements back in the stack1
//   again. 

// CPP program to implement Queue using two stacks
#include <iostream>
#include <stack>
using namespace std; 
  
struct Queue 
{ 
    stack<int> st1, st2; 
  
    // Enqueue item to the queue 
    void enq(int x) 
    { 
        // Push into the first stack 
        st1.push(x); 
    } 
  
    // Dequeue an item from the queue 
    int deq() 
    { 
        // if both stacks are empty then exit
        if (st1.empty() && st2.empty()) 
        { 
            cout << "Queue is empty"; 
            exit(0); 
        } 
        // if st2 is empty, move elements from st1 to st2
        if (st2.empty()) { 
            while (!st1.empty()) { 
                st2.push(st1.top()); 
                st1.pop(); 
            } 
        } 
        // return the top item from st2 
        int x = st2.top(); 
        st2.pop(); 
        return x; 
    } 
}; 
  
// main function
int main() 
{ 
    Queue q; 
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin>>num;
        q.enq(num);
    }
    for(int i = 0; i < n; i++)
    {
        cout << q.deq() << '\n'; 
    }
	  return 0; 
} 

/*
Sample Input : 
1
2
3

Sample Output : 
1
2
3

Explanation : 
When We input 1,2,3 then they will be stored as: 3 2 1 where 3 is top element of stack. and we know that in queue we delete from opposite side. Therefore first 1 is deleted
and displayed then 2 and then 3. therefore these two stacks work together as a single queue.

Time Complexity  : O(n^2) since dequeue take O(n) and its being called under for loop so total complexity will be O(n*n).
Space Complexity : O(2n)  since we are using two stacks of same size so there is 2*n space required for n elements.
*/

