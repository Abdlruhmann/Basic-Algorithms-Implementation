#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct student {
    int id ;
    char name[30];
    int grade;
};
// Array of students



struct student fill_student() {

    struct student std1 ;
    printf("Enter id of the student: \n");
    scanf("%d", &std1.id);

    printf("Enter name of the student: \n");
    scanf("%s",std1.name);

    printf("Enter the grade of the student: \n");
    scanf("%d",&std1.grade);

    return std1;
}

void print_all(struct student ar[],int size) {
    for(int i = 0 ; i < size ; i++) {
        printf("------ STD %d ------\n", i + 1);
        printf("Student id : %d\n", ar[i].id);
        printf("Student name : %s\n", ar[i].name);
        printf("Student grade : %d\n",ar[i].grade);
        printf("___________________\n");
    }
}


// Bubble sort
void BubbleSort(struct student ar[], int size) {
    int i,j;
    struct student temp;

    for(i=0; i < size ; i++) {
        for (j= i+1 ; j < size ; j++) {
            if(ar[j].id < ar[i].id) {
                temp = ar[i];
                ar[i]= ar[j];
                ar[j]= temp;
            }
        }
    }
}


// Merge Sort
void MergeSort(struct student ar[], int LB , int UB) {
    int mid ;
    if(LB < UB) {
        mid = (UB + LB)/2;
        MergeSort(ar,LB,mid);
        MergeSort(ar,mid+1,UB);
        Merge(ar,LB,mid,UB);
    }
}

// Merge
void Merge(struct student ar[], int LB , int mid , int UB) {

    struct student temp[MAX];
    int l1,l2,i;
    l1 = LB;
    l2 = mid+1;
    i  = LB;

    while(l1 <= mid && l2 <= UB) {
        if(ar[l1].id < ar[l2].id) {
            temp[i] = ar[l1];
            l1++;
            i++;
        }else {
            temp[i] = ar[l2];
            l2++;
            i++;
        }
    }

    while(l1 <= mid) {
        temp[i] = ar[l1];
        l1++;
        i++;
    }

    while(l2 <= UB) {
        temp[i] = ar[l2];
        l2++;
        i++;
    }

    for(int i = LB ; i <= UB ; i++) {
        ar[i] = temp[i];
    }
}


// Binary Search
int Binary_Search(struct student ar[], int LB, int UB, int target) {
    int mid;
    int loc = -1;
    MergeSort(ar,LB,UB);
    while(loc == -1 && LB <= UB) {
        mid = (UB + LB)/2;
        if(ar[mid].id == target) {
            loc = mid ;
        }else if (ar[mid].id > target) {
            UB = mid - 1 ;
        }else {
            LB = mid + 1;
        }
    }
    return loc;
}

void Menu() {
    printf("1. Fill Students: \n");
    printf("2. Merge Sort: \n");
    printf("3. Bubble Sort: \n");
    printf("4. Binary Search: \n");
    printf("5. Print All: \n");
    printf("6. Exit: \n");
}

int main()
{
    struct student ar[MAX];
    int running=1;
    int choice;
    int size=0;

    do {
        Menu();
        printf("Please Enter Your Choice: \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: {

            printf("Please enter size of arr: \n");
            scanf("%d", &size);

            for(int i = 0 ; i < size ; i++) {
                printf("Enter details of std %d: \n", i + 1);
                printf("----------------------\n");
                struct student std;
                std = fill_student();
                ar[i] = std;
            }
            printf("_____OUTPUT_____\n");
            printf("Array is filled with data successfully.\n");
            printf("Use Print all function to test.\n");
            printf("________________\n");
            break;
            
        }

        case 2: {
            MergeSort(ar,0,size-1);
            printf("_____OUTPUT_____\n");
            printf("Array is now sorted using merge sort: \n");
            printf("Use print all function to see the result. \n");
            printf("________________\n");
            break;
        }

        case 3: {
            BubbleSort(ar,size);
            printf("_____OUTPUT_____\n");
            printf("Array is now sorted using bubble sort: \n");
            printf("Use print all function to see the result. \n");
            printf("________________\n");
            break;
        }

        case 4: {
            int target;
            printf("Please enter an ID to search student: \n");
            scanf("%d", &target);

            int found = Binary_Search(ar,0,size-1,target);

            if(found == -1){
                printf("_____OUTPUT_____\n");
                printf("Student with given id: %d, NOT FOUND!\n", target);
                printf("________________\n");
                break;
            }else {
                printf("_____OUTPUT_____\n");
                printf("Found=> Student name : %s , Index: %d \n", ar[found].name, found);
                printf("________________\n");
            }
            break;
        }

        case 5: {
            printf("_____OUTPUT_____\n");
            print_all(ar,size);
            printf("________________\n");
        }
        case 6:
        printf("Exiting the program..\n");
        running=0;
        break;

        default:
            printf("Invalid Choice!\n");
            break;
        }

    }while(running);

    return 0;
}
