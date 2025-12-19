#include <iostream>
#include <climits>
#include <vector>
void display();

template <typename T>
class productOfArray
{
public:
    std::vector<T> arr;
    int size;

    productOfArray(int s) : size(s)
    {
        arr.resize(s);
    }
    
    void product(productOfArray<T> &obj)
    {
        int max_arr_size = std::max(this->size, obj.size);
        int min_arr_size = std::min(this->size, obj.size);

        for (int i = 0; i < min_arr_size; i++)
        {
            this->arr[i] *= obj.arr[i];
        }
        // assign remaining elements
        for (int i = min_arr_size; i < max_arr_size; i++)
        {
            this->arr[i] *= 1;
        }
        size = max_arr_size;
        arr.resize(size);
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << this->arr[i] << " ";
        }
    }
};

int main()
{
    int sizeX = 5;
    int sizeY = 5;
    productOfArray<int> obj1(sizeX);
    obj1.arr[0] = 2;
    obj1.arr[1] = 4;
    obj1.arr[2] = 6;
    obj1.arr[3] = 8;
    obj1.arr[4] = 10;

    productOfArray<int> obj2(sizeY);
    obj2.arr[0] = 1;
    obj2.arr[1] = 3;
    obj2.arr[2] = 5;
    obj2.arr[3] = 7;
    obj2.arr[4] = 9;

    obj1.product(obj2);
    obj1.display();

    return 0;
}
