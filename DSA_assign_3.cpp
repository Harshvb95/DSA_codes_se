#include <iostream>
using namespace std;

int cqueue[5];
int front = -1, rear = -1, n=5;

void insertCQ(int val) 
{
   if ((front == 0 && rear == n-1) || (front == rear+1)) 
   {
      cout<<"\nQueue Overflow \n";
      return;
   }
   if (front == -1) //queue is empty
   {
      front = 0;
      rear = 0;
   } 
   else 
   {
      if (rear == n - 1) // R at last position
      rear = 0;
      else
      rear = rear + 1;
   }
   cqueue[rear] = val ;
}
void deleteCQ() 
{
   if (front == -1) 
   {
      cout<<"\nQueue Underflow\n";
      return ;
   }
   cout<<"\nElement deleted from queue is : "<<cqueue[front]<<endl;

   if (front == rear) //Only one element is present in queue
   {
      front = -1;
      rear = -1;
   } 
   else 
   {
      if (front == n - 1)
      front = 0;
      else
      front = front + 1;
   }
}



void displayCQ_forward() 
{
   int f = front, r = rear;
   if (front == -1) 
   {
      cout<<"\nQueue is empty"<<endl;
      return;
   }
   cout<<"\nQueue elements are :\n";
   if (f <= r) 
   {
      while (f <= r)
      {
         cout<<cqueue[f]<<" ";
         f++;
      }
   } 
   else 
   {
       while (f <= n - 1) 
      {
        cout<<cqueue[f]<<" ";
        f++;
      }
      f = 0;
      while (f <= r) 
      {
         cout<<cqueue[f]<<" ";
         f++;
      }
   }
   cout<<endl;
}


void displayCQ_reverse() {
   int f = front, r = rear;
   if (front == -1)
    {
      cout<<"\nQueue is empty"<<endl;
      return;
    }
   cout<<"\nQueue elements are :\n";
   if (f <= r) 
   {
      while (f <= r)
      {
        cout<<cqueue[r]<<" ";
        r--;
      }
   } 
   else 
   {
      while (r>=0) 
      {
         cout<<cqueue[r]<<" ";
         r--;
      }
      r=n-1;
      while (r>=f) 
      {
         cout<<cqueue[r]<<" ";
         r--;
      }
   }
   cout<<endl;
}

int main() {

   int ch, val;
   cout << "Welcome to the Program ..... " << endl ;
   cout << "What operations would you like to perform ? " << endl;
   
   do {
      cout<<"\n1)Insert\n";
      cout<<"2)Delete\n";
      cout<<"3)Display forward\n";
      cout<<"4)Display reverse\n";
      cout<<"5)Exit\n";
      cout<<"\nEnter choice : "<<endl;
      cin>>ch;
      switch(ch) {
         case 1:
         cout<<"Input for insertion: "<<endl;
         cin>>val;
         insertCQ(val);
         break;
         case 2:
         deleteCQ();
         break;
         case 3:
         displayCQ_forward();
         break;
		case 4:
         displayCQ_reverse();
         break;
         case 5:
         cout<<"Exit\n";
         break;
         default: cout<<"Incorrect!\n";
      }
   } while(ch != 5);
   return 0;
}