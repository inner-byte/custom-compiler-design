// Test file to verify compiler functionality

// Test struct definition
struct Point {
    int x;
    int y;
};

// Test array and pointer
int numbers[10];
int* ptr;

// Test function declaration with multiple parameters
int calculate(int a, float b, char c) {
    return a + (int)b + (int)c;
}

// Test control flow
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Test loops and array manipulation
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Test string manipulation and standard library
void stringTest(char* str) {
    printf("String: %s\n", str);
    int len = strlen(str);
    printf("Length: %d\n", len);
}

// Test type casting and arithmetic
float complexCalculation(int x, float y) {
    float result = (float)x * y + x / (int)y;
    return result;
}

// Main function to test everything
int main() {
    // Test variable declarations
    int a = 10;
    float b = 20.5;
    char c = 'A';
    
    // Test struct
    struct Point p;
    p.x = 5;
    p.y = 10;
    
    // Test function calls
    int calc_result = calculate(a, b, c);
    printf("Calculate result: %d\n", calc_result);
    
    // Test fibonacci
    int fib_result = fibonacci(10);
    printf("Fibonacci(10): %d\n", fib_result);
    
    // Test array and sorting
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Test string
    char str[] = "Hello, Compiler!";
    stringTest(str);
    
    // Test complex calculation
    float complex_result = complexCalculation(10, 2.5);
    printf("Complex calculation result: %f\n", complex_result);
    
    return 0;
}
