#include <bits/stdc++.h>
using namespace std;

class student
{
public:
    int roll;
    string id, name, year, contractInfo, pass, username, sl;

    // Constructor to easily create a student object
    student(int r, const string &i, const string &n, const string &y, const string &c, const string &p, const string &u, const string &s)
        : roll(r), id(i), name(n), year(y), contractInfo(c), pass(p), username(u), sl(s) {}
};

// Function to merge two halves of the vector
void merge(vector<student> &Student, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary vectors
    vector<student> L(n1), R(n2);

    // Copy data to temporary vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = Student[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = Student[mid + 1 + j];

    // Merge the temporary vectors back into Student[left..right]
    int i = 0;    // Initial index of first subarray
    int j = 0;    // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2)
    {
        if (L[i].roll <= R[j].roll)
        {
            Student[k] = L[i];
            i++;
        }
        else
        {
            Student[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1)
    {
        Student[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2)
    {
        Student[k] = R[j];
        j++;
        k++;
    }
}

// Function to implement merge sort
void mergeSort(vector<student> &Student, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(Student, left, mid);
        mergeSort(Student, mid + 1, right);

        // Merge the sorted halves
        merge(Student, left, mid, right);
    }
}

int main()
{
    vector<student> Student;

    // Adding some students for demonstration
    Student.push_back(student(3, "ID3", "Alice", "2023", "info1", "pass1", "user1", "sl1"));
    Student.push_back(student(1, "ID1", "Bob", "2021", "info2", "pass2", "user2", "sl2"));
    Student.push_back(student(2, "ID2", "Charlie", "2022", "info3", "pass3", "user3", "sl3"));

    // Sorting students by roll number using merge sort
    mergeSort(Student, 0, Student.size() - 1);

    // Displaying sorted students
    for (const auto &s : Student)
    {
        cout << "Roll: " << s.roll << ", Name: " << s.name << endl;
    }

    return 0;
}
