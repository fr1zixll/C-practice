#include <iostream>
#include <string>

void array_int(int* arr, int size) {
    if (size <= 0) return;
    int sumDivisible = 0, countDivisible = 0;
    int sumNotDivisible = 0, countNotDivisible = 0;
    for (int* ptr = arr; ptr < arr + size; ++ptr) {
        if (*ptr % 2 == 0) {
            sumDivisible += *ptr;
            countDivisible++;
        } 
        else {
            sumNotDivisible += *ptr;
            countNotDivisible++;
            
        }
    }
    
    if (countDivisible > 0) {
        std::cout << "Average of paired numbers: " << static_cast<double>(sumDivisible) / countDivisible << std::endl;
    }
    else {
        std::cout << "There are no even numbers." << std::endl;
    }
    if (countNotDivisible > 0) {
        std::cout << "The mean of odd numbers: " << static_cast<double>(sumNotDivisible) / countNotDivisible << std::endl;
    } 
    else {
        std::cout << "There are no odd numbers." << std::endl;
        
    }
}

void min_max_str(std::string* arr, int size) {
  
    if (size <= 0) return;
    std::string* maxStr = arr;
    std::string* minStr = arr;
    
    for (std::string* ptr = arr; ptr < arr + size; ++ptr) {
      
        if (ptr->length() > maxStr->length()) {
            maxStr = ptr;
        }
        
        if (ptr->length() < minStr->length()) {
            minStr = ptr;
        }
    }
    
    std::cout << "The longest: \"" << *maxStr << "\" (Size: " << maxStr->length() << ")" << std::endl;
    std::cout << "The shortest: \"" << *minStr << "\" (Size: " << minStr->length() << ")" << std::endl;
    
}

void sum_reverse(double* arr, int size) {
    if (size <= 0) return;
    double totalSum = 0;
    
    std::cout << "Elements in reverse order: ";
    
    for (double* ptr = arr + size - 1; ptr >= arr; --ptr) {
        std::cout << *ptr << " ";
        totalSum += *ptr;
        
    }
    std::cout << "\nTotal sum: " << totalSum << std::endl;
    
}

int main() {
    int a;
    std::cout << "Enter the number of integers: ";
    if (!(std::cin >> a)) return 1;
    int* intArr = new int[a];
    
    for (int i = 0; i < a; ++i) {
        std::cout << "Number [" << i << "]: ";
        std::cin >> *(intArr + i);
        
    }
    array_int(intArr, a);
    std::string words[] = {"Computer", "Always", "Salvia", "Korn"};
    int b = sizeof(words) / sizeof(words[0]);
    min_max_str(words, b);
    double prices[] = {5.50, 25.20, 47.30, 3.14};
    int c = sizeof(prices) / sizeof(prices[0]);
    sum_reverse(prices, c);
    delete[] intArr;
    return 0;
    
}