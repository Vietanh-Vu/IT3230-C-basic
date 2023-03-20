///////////////////////////////////////////////////
// stable sort : nếu có 2 phần tử có giá trị bằng nhau thì thứ tự đc bảo toàn
// Bubble Sort, Insertion Sort, and Selection Sort, Merge Sort
// non stable
// Heap Sort, Quick Sort

///////////////////////////////////////////////////
// Bubble Sort 
// Nếu phần lớn đầu vào được sắp xếp và không gian bổ sung bị hạn chế, 
// thì Bubble Sort hoặc shaker sort có thể là một lựa chọn tốt 
// vì chúng hoạt động tốt trên đầu vào đã được sắp xếp hoặc sắp xếp gần hết.
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

///////////////////////////////////////////////////
// Insertion Sort 
// Nếu đầu vào nhỏ hoặc được sắp xếp một phần, Insertion Sort là một lựa chọn tốt 
// vì nó có chi phí thấp và hiệu quả đối với đầu vào nhỏ.
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

///////////////////////////////////////////////////
// Selection Sort 

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

///////////////////////////////////////////////////
// Quick Sort 
// Nếu kích thước đầu vào lớn và bộ nhớ không phải là vấn đề đáng lo ngại, 
// thì quicksort là một lựa chọn tốt 
// vì nó có hiệu suất trung bình tốt và hiệu quả đối với đầu vào lớn.

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

///////////////////////////////////////////////////
// Merge Sort 
// Nếu cần quan tâm đến bộ nhớ và dữ liệu đầu vào lớn, 
// thì sắp xếp hợp nhất là một lựa chọn tốt 
// vì đây là thuật toán sắp xếp ổn định sử dụng chiến lược chia để trị và nó có chi phí hoạt động thấp.

void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int leftArray[n1], rightArray[n2];
    for (i = 0; i < n1; i++) leftArray[i] = arr[left + i];
    for (j = 0; j < n2; j++) rightArray[j] = arr[middle + 1 + j];
    i = 0; j = 0; k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        }
        else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

// Định nghĩa cấu trúc Node bằng typedef struct
typedef struct Node Node;

struct Node {
    int val;
    Node *next;
};

// Hàm merge hai danh sách liên kết đã được sắp xếp
Node* merge(Node* l1, Node* l2) {
    // Tạo một nút giả làm đầu danh sách đã sắp xếp
    Node* dummy = (Node*)malloc(sizeof(Node));
    Node* tail = dummy;
    
    // Ghép hai danh sách liên kết bằng cách chọn phần tử nhỏ hơn ở mỗi bước
    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    
    // Nối các nút còn lại từ hai danh sách vào danh sách đã sắp xếp
    tail->next = l1 ? l1 : l2;
    
    // Giải phóng bộ nhớ sử dụng bởi nút giả và trả về danh sách đã sắp xếp
    Node* result = dummy->next;
    free(dummy);
    return result;
}

// Hàm thực hiện thuật toán merge sort cho một danh sách liên kết
Node* mergeSort(Node* head) {
    // Trường hợp cơ bản: nếu danh sách rỗng hoặc chỉ có một phần tử, nó đã được sắp xếp
    if (!head || !head->next) {
        return head;
    }
    
    // Chia danh sách thành hai nửa bằng cách sử dụng các con trỏ slow và fast
    Node *slow = head, *fast = head->next;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Tách danh sách thành hai phần và đệ quy sắp xếp từng phần
    Node *mid = slow->next;
    slow->next = NULL;
    
    Node *l1 = mergeSort(head);
    Node *l2 = mergeSort(mid);
    
    // Ghép hai danh sách đã sắp xếp
    return merge(l1, l2);
}


///////////////////////////////////////////////////
// Heap Sort 
// Nếu bạn cần stable sort và bộ nhớ không phải là vấn đề đáng lo ngại, 
// thì Heap Sort  là một lựa chọn tốt 
// vì nó hiệu quả trong việc sắp xếp dữ liệu lớn, nó có hiệu suất trung bình tốt 
// và nó không phải là thuật toán sắp xếp dựa trên so sánh.
// MAX
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int i;
    for (i = n/2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (i = n-1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

// MIN
void heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] < arr[smallest]) smallest = left;
    if (right < n && arr[right] < arr[smallest]) smallest = right;
    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        heapify(arr, n, smallest);
    }
}

void heapSort(int arr[], int n) {
    int i;
    for (i = n/2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (i = n-1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

// Nếu bạn cần sắp xếp ổn định và bộ nhớ là một mối quan tâm, 
// TimSort là một lựa chọn tốt vì nó kết hợp Insertion sort and Merge sort, 
// nó hiệu quả trong việc sắp xếp dữ liệu nhỏ và lớn


   
