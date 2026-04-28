#include <iostream>
#include <vector>
using namespace std;

// Function to partition the array according 
// to pivot index element




//logic: all the smaller elements than pivot goes left and the rest go right


//Hoare's partitioning algorithm is an efficient way to partition an array around a pivot. It’s based on two pointers that start at opposite ends of the array and move toward each other until they find elements that need to be swapped.
//Hoare's Partition Algorithm is generally faster than Lomuto's because it performs fewer swaps and makes only one traversal of the array, leading to better time complexity in practice.
void partition(vector<int> &arr) {
  	int n = arr.size();
  	int pivot = arr[0];
  	
  	int i = -1, j = n;
  	while (true) {
      
      	// find next element larger than pivot 
      	// from the left
      	do {
          	i++;
        } while (arr[i] < pivot);
      	
      	// find next element smaller than pivot 
      	// from the right
      	do {
          	j--;
        } while (arr[j] > pivot);
      	
      	// if left and right crosses each other
      	// no swapping required
      	if (i > j) break;
      	
      	// swap larger and smaller elements
      	swap(arr[i], arr[j]);
    }
}

int main() {
    vector<int> arr = {5, 3, 8, 4, 2, 7, 1, 10};
  	partition(arr);
  	
  	for (int i = 0; i < arr.size(); i++) 
      	cout << arr[i] << " "; 
    return 0;
}