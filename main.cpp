#include <iostream>
using namespace std;

template <typename T> class GenericArray {
    int v_size = 0;
    T* numbers = nullptr;
    public:
    GenericArray(){}
    ~GenericArray() {
        delete[] numbers;
    }

    void add(T number) {
        v_size++;
        T* temp = new T[v_size];
        for (int i = 0; i < v_size-1; i++) {
            temp[i] = numbers[i];
        }
        temp[v_size-1] = number;
        numbers = temp;
        delete[] temp;
    }

    T at(int index) {
        return numbers[index];
    }

    int size() const {
        return v_size;
    }

    T sum() const {
        T sum = 0;
        for (int i = 0; i < v_size; i++) {
            sum += numbers[i];
        }
        return sum;
    }

    T max() const {
        T max = numbers[0];
        for (int i = 0; i < v_size; i++) {
            if (numbers[i] > max) {
                max = numbers[i];
            }
        }
        return max;
    }

    T min()const {
        T min = numbers[0];
        for (int i = 0; i < v_size; i++) {
            if (numbers[i] < min) {
                min = numbers[i];
            }
        }
        return min;
    }

    T* slice(int start, int end) {
        if(end<start) {
            cerr << "Err in .slice() : Start should be less than end" << endl;
            return nullptr;
        }

        if(start<0) {
            cerr << "Err in .slice() : Start should be positive integer" << endl;
            return nullptr;
        }
        if(start>v_size) {
            cerr << "Err in .slice() : Start should be less than size" << endl;
            return nullptr;
        }
        if(end>v_size) {
            cerr << "Err in .slice() : End should be less than size" << endl;
            return nullptr;
        }


        T* temp = new T[end - start];
        for (int i = start; i < end; i++) {
            temp[i] = numbers[i];
        }
        return temp;
    }
};


int main() {
    GenericArray<int> numbers;
    for(int i = 0; i < 100; i++) {
        numbers.add(i);
    }
    cout << numbers.sum() << endl;
    cout << numbers.max() << endl;
    cout << numbers.min() << endl;
    cout << numbers.at(50) << endl;
    int *num = numbers.slice(40,50);
    for (int i = 0; i < 10; i++) {
        cout << num[i] << endl;
    }

    return 0;
}