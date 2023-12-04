#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>


//1task
void swapMinMax(int arr[], int size) {
    if (size <= 0) {
        std::cout << "Massive is empty." << std::endl;
        return;
    }

    int minIndex = 0;
    int maxIndex = 0;
    int minValue = arr[0];
    int maxValue = arr[0];

    // Знаходимо індекси найменшого та найбільшого елементів
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minValue) {
            minIndex = i;
            minValue = arr[i];
        }
        if (arr[i] > maxValue) {
            maxIndex = i;
            maxValue = arr[i];
        }
    }

    // Заміна місцями найбільшого та найменшого елементів
    int temp = arr[minIndex];
    arr[minIndex] = arr[maxIndex];
    arr[maxIndex] = temp;
}

//2task
int countElementsGreaterThanA(int arr[], int size, int A) {
    int count = 0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] > A) {
            count++;
        }
    }

    return count;
}

//3task

int findSecondLargest(int arr[], int size) {
    if (size < 2) {
        std::cout << "Масив має бути не менше двох елементів." << std::endl;
        return -1;
    }

    // Знаходимо найбільший елемент
    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Шукаємо другий за величиною елемент, відмінний від найбільшого
    int secondMax = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < max && arr[i] > secondMax) {
            secondMax = arr[i];
        }
    }

    return secondMax;
}

//4task

int findFirstZeroIndex(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == 0) {
            return i;
        }
    }
    return -1; // Повертаємо -1, якщо нульових елементів немає
}



int main() {

    //1task
    const int arraySize = 10; // Розмір масиву
    int array[arraySize];

    // Ініціалізація генератора випадкових чисел
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Заповнення масиву випадковими числами
    std::cout << "Random massive: ";
    for (int i = 0; i < arraySize; ++i) {
        array[i] = std::rand() % 100 - 50; // Генеруємо випадкові числа в діапазоні від -50 до 49
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    swapMinMax(array, arraySize);

    // Вивід зміненого масиву
    std::cout << "New massive: ";
    for (int i = 0; i < arraySize; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    //2task


    const int array1Size = 5;
    int array1[arraySize];


    std::srand(static_cast<unsigned int>(std::time(nullptr)));


    std::cout<<"****************************************"<<std::endl;
    std::cout << "\nRandom massive: ";
    for (int i = 0; i < arraySize; ++i) {
        array[i] = std::rand() % 100; // Генеруємо випадкові числа в діапазоні від 0 до 99
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    int A;
    std::cout << "\nEnter number A: ";
    std::cin >> A;

    int count = countElementsGreaterThanA(array, arraySize, A);
    std::cout << "Elements with bigger value then number " << A << " in massive: " << count << std::endl;


    //3task

    const int array2Size = 10; // Розмір масиву
    int array2[arraySize];


    std::srand(static_cast<unsigned int>(std::time(nullptr)));


    std::cout<<"****************************************"<<std::endl;
    std::cout << "Random massive: ";
    for (int i = 0; i < arraySize; ++i) {
        array[i] = std::rand() % 100; // Генеруємо випадкові числа в діапазоні від 0 до 99
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    int secondLargest = findSecondLargest(array, arraySize);

    if (secondLargest != -1) {
        std::cout << "\nThe second largest element in the array: " << secondLargest << std::endl;
    } else {
        std::cout << "It is impossible to find the second largest element in an array." << std::endl;
    }

    //4task

    const int array3Size = 10;
    int array3[arraySize];
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout<<"****************************************"<<std::endl;
    std::cout << "Random massive: ";
    for (int i = 0; i < arraySize; ++i) {
        array[i] = std::rand() % 11 - 5;
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    int firstZeroIndex = findFirstZeroIndex(array, arraySize);

    if (firstZeroIndex != -1) {
        std::cout << "Number first null element in massive: " << firstZeroIndex << std::endl;
    } else {
        std::cout << "Massive doesnt own null elements." << std::endl;
    }

    return 0;


}
