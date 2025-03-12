#include <stdio.h>
#include <stdlib.h>

int mutex=1,full=0,empty=3,x=0;

int wait(int);
int singel(int);
void producer();
void consumer();

int main()
{
    int n;
    printf("\n1.producer\n2.consumer\n3.exit\n");

    while(1)

    {
        printf("\nenter your choice");
        scanf("%d",&n);

        switch(n)
        {
            case 1:if(mutex==1&& empty!=0)
                   {
                     producer();
                    }
                    else{

                       printf("\nbuffer is full");
                      }
                        break;

        case 2: if(mutex==1&& full!=0){
                   consumer();
                  }

                  else{
                        printf("\nbuffer is empty");    
                  }
                    break;
       case 3:
                exit(0);
                break;
                
            
        
        default:
        {
            printf("wrong choice");
        }
    }
}
}
int wait (int s)
{
    return  (--s);
}
int singel(int s)
{
    return (++s);
}


void producer()
{
    mutex=wait(mutex);
    full=singel(full);
    empty=wait(empty);
    x++;
    printf("\nproducer produces the item %d",x);
    mutex=singel(mutex);
}

void consumer()
{
    mutex=wait(mutex);
    full=wait(full);
    empty=singel(empty);
    printf("\nconsumer consumes item %d",x);
    x--;
    mutex=singel(mutex);
}