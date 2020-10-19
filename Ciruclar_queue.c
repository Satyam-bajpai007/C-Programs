#include <stdio.h>
#include <windows.h>
#include <unistd.h>
#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

int isFull() {
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) return 1;
  return 0;
}

int isEmpty() {
  if (front == -1) return 1;
  return 0;
}

void enQueue(int element) {
  if (isFull())
   {
    	printf("\n Queue is full!! \n");
    	sleep(3);
    }
  else {
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    items[rear] = element;
  }
}

int deQueue() {
  int element;
  if (isEmpty()) {
    printf("\n Queue is empty !! \n");
    sleep(3);
    return (-1);
  } else {
    element = items[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } 
    else {
      front = (front + 1) % SIZE;
    }
    return (element);
  }
}

void display() {
  int i;
  if (isEmpty())
    printf(" Empty Queue\n");
  else {
    printf(" Front -> %d ", front);
    printf("\n\t\t\t\t    Items -> ");
    for (i = front; i != rear; i = (i + 1) % SIZE) {
      printf("%d ", items[i]);
    }
    printf("%d ", items[i]);
    printf("\n\t\t\t\t    Rear -> %d \n", rear);
  }
}

int main() {
	int a,b,c;
	do{
		system("cls");
		system("COLOR 04");
		printf("\t\t\t DISPLAY ->");display();
		printf("\nEnter->\n\t1) To enqueue\n\t2) To dequeue\n\t3) To exit\n\t");
	    scanf("%d",&a);
	    switch(a)
	    {
	    	case 1:
	    	{
	    		printf("\nInsert Element ->");
	    		scanf("%d",&b);
	    		enQueue(b);
	    		break;
			}
			case 2:
			{
	    		deQueue();
	    		break;
			}
			case 3:
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_GREEN);
				printf("********** THANK YOU **********");
			}
		}
	}while(a!=3);
 	return 0;
}
