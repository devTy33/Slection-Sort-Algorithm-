#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;
void printVector(vector <int> &vec) {
  int size = vec.size();
  for (int i = 0; i < size; ++i) {
    cout << "  " << vec[i];
  }
  cout << "\n";
}
void selectionSort (vector <int> &vec){
    int j, minIndex;
    // For loop to loop through the indexes we will compare to the rest of the values (vec.size() - 1 because the last value would have nothing to compare to)
    for(int i = 0; i < vec.size()-1; i++){
        // initialy set our first index to min
        minIndex = i;
        // print out right after the first for loop because they are initial conditions 
        cout << "Step "<<i+1<<" :"<< endl;
        cout << "Selected index: " << "vec["<< i<<"]"<<" = "<<vec[i] << endl;
        // finds the minimum value by looping through the rest of the values (j = i+1) 
        for(j = i+1; j < vec.size(); j++) {
          // Every vec[j] value that is smaller than out initial index will be the new minimum
            if(vec[j] < vec[minIndex]){

                minIndex = j;
            }
        }
        cout << "vec["<<minIndex<<"]"<<" = "<< vec[minIndex] << " is the minimum." << endl;
        // If our selected index is also the minimum, or equal to the minimum, than don't swap
        if( vec[i] == vec[minIndex]) {
          cout << "No swap. The selected index is the minimum." << endl;
        }
         else {cout << "SWAP." << endl;}
        // swaps the values 
        int temp;
        temp = vec[i];
        vec[i] = vec[minIndex];
        vec[minIndex] = temp;
        // Use a for loop to print out the changes at the end of all the steps before we move to another index from main for loop.
        cout << "Vector after Step " << i+1 << " :" << endl;
        for(int x = 0; x < vec.size(); x++){
          cout << vec[x] << " ";
        }
        cout << endl;

    }

}
int main() {
  vector <int> data;
  ifstream fin;
  int n;
  // Read in the data from the file and use a while loop to pushback any integer data into the vector 
  fin.open("sample2.txt");
  while( fin >> n) {
  data.push_back(n);
  }
cout << "Beginning Vector:\n";
  printVector(data);
  selectionSort(data);

  cout << "Sorted Array in Ascending Order:\n";
  printVector(data);
    fin.close();
  return 0;
}
