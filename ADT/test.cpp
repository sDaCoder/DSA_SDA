#include<iostream>
#include<stdlib.h>
using namespace std;

class test
{
    private:
        /* data */
    public:
        test(int *arr, int size);
        test(int *arr, int size, int element);
        ~test();
};

test::test(int *arr, int size)
{
    cout<<"The elements of the array are:"<<endl;
    for (int i = 0; i < size ; i++)
    {
        cout<<(*(arr + i))<<"\t";
    }
    
}

test::test(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            cout<<"The element "<<element<<" is available at the index "<<i<<endl;
        }
        break;
        // else
        // {
        //     break;
        // }
        
        
    }
    cout<<"The element "<<element<<" is not present in the array"<<endl;
    
}
test::~test()
{
}


int main(){
    system("cls");
    // cout<<"Hello World\n";
    int arr[] = {1, 29, 59, 2027, 2929};
    int size = (sizeof(arr)/sizeof(int));
    test(arr, size);
    
    int element;
    cout<<endl<<"Which element you wanna search???"<<endl;
    cin>>element;
    test(arr, size, element);
    return 0;
}