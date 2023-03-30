#include <iostream>
#include <cstring>

using namespace std;

struct Employee{
    char name[55];
    int salary;
};

void bubble_sort(Employee* arr, int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr[j].salary > arr[j+1].salary){
                swap(arr[j], arr[j+1]);
            }
            else if(arr[j].salary == arr[j+1].salary){
                if(strcmp(arr[j].name, arr[j+1].name) > 0){
                    swap(arr[j], arr[j+1]);
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    Employee arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i].name >> arr[i].salary;
    }
    bubble_sort(arr, n);
    for(int i = 0; i < n; i++){
        cout << arr[i].name << " " << arr[i].salary << endl;
    }
    return 0;
}
