
/*
Author: Dharshini Mahesh
Compiler: GNU GCC
Date: 2/3/2023
Purpose of program: This program manages students’records. Each student’s record consists of a netID, a major and a GPA,
maintained in parallel arrays. The program will read students’ data from a file and loop on displaying the following
menu of choices:

1. List the top n students
2. Search for a student
3. Exit the program.

The program prompts the user to input the file to use and then asks the user for input to display the answer from the menu
*/
#include <iostream>
using namespace std;
#include <iomanip>
#include <fstream>
#include<string>
/* This function sorts array2 and maintains the parallelism
of array1 and array3
Whenever elements of array2 are swapped, the elements of array 1
and array3 at the same indices are also swapped
 int size is the size of the array

*/
void modifiedSortID(int array2[], double array1[], string array3[], int size)
{
   int minIndex, minValue;//minIndex starts the sort and keeps track of the index the value is, minvalue us the smallest element in the array
   for (int start = 0; start < (size - 1); start++)
   {
      minIndex = start;
      minValue = array2[start];
      for (int index = start + 1; index < size; index++)
      {
         if (array2[index] < minValue)
         {
            minValue = array2[index];
            minIndex = index;

         }//end if (array2[index] < minValue)
      }//end for (int index = start + 1; index < size; index++)
      swap(array2[minIndex], array2[start]);
      swap(array3[minIndex], array3[start]);
      swap(array1[minIndex], array1[start]);
   }//end for loop for selection sort


}//end function modifiedSortID

/* This function sorts array1 and maintains the parallelism
of array2, and array3
Whenever elements of array1 are swapped, the elements of array 2
and array3 at the same indices are also swapped
 int size is the size of the array

*/
void modifiedSortGPA(double array1[], int array2[], string array3[], int size)
{

   int minIndex;//minIndex starts the sort and keeps track of the index the value is,
   double minValue;//minvalue us the smallest element in the array
   for (int start = 0; start < (size - 1); start++)
   {
      minIndex = start;
      minValue = array1[start];
      for (int index = start + 1; index < size; index++)
      {
         if (array1[index] < minValue)
         {
            minValue = array1[index];
            minIndex = index;

         }//end if (array1[index] < minValue)
      }//end for loop
      swap(array2[minIndex], array2[start]);
      swap(array3[minIndex], array3[start]);
      swap(array1[minIndex], array1[start]);
   }//end for loop for selection sort

}//end modifiedSortGPA function

/* This function sorts the array sortedGPAbyGPA and maintains the parallelism
of sortedNetIDbyGPA, and sortedMajorbyGpa
Whenever elements of sortedGPAbyGPA are swapped, the elements of sortedMajorbyGpa
and sortedNetIDbyGPA at the same indices are also swapped
This function returns the top number of students that the user inputs based on GPA
 int size is the size of the array

*/
void selectionTop(int sortedNetIDbyGPA[], string sortedMajorbyGpa[], double sortedGPAbyGPA[], int size)
{

   int minIndex;//minIndex starts the sort and keeps track of the index the value is,
   double minValue;//minvalue us the smallest element in the array
   for (int start = 0; start < (size - 1); start++)
   {
      minIndex = start;
      minValue = sortedGPAbyGPA[start];
      for (int index = start + 1; index < size; index++)
      {
         if (sortedGPAbyGPA[index] > minValue)
         {
            minValue = sortedGPAbyGPA[index];
            minIndex = index;

         }
      }
      swap(sortedNetIDbyGPA[minIndex], sortedNetIDbyGPA[start]);
      swap(sortedMajorbyGpa[minIndex], sortedMajorbyGpa[start]);
      swap(sortedGPAbyGPA[minIndex], sortedGPAbyGPA[start]);
   }

}

/* This function implements linear search on an array. It takes the following arguments:
arr: the array, numElems: number of elements of array,
value: search value, and nIter. nIter is a reference variable used
to pass the number of iterations back to the calling function.
The function returns the index where the match is found, -1 if no
match is found
 int size is the size of the array

*/
int linearSearchID(int arr[], int numElems, int value, int &nIter)
{
   nIter = 0;//reference variable used to keep track of iterations


   for (int i = 0; i < numElems; i++)
   {
      nIter++;
      if (arr[i] == value)
      {
         return i;
      }//closes if (arr[i] == value)
   }//closes for loop
   return -1;
}//closes linearSearchID function

/* This function implements binary search on an array. It takes the following arguments:
arr: the array, numElems: number of elements of array,
value: search value, and nIter. nIter is a reference variable used
to pass the number of iterations back to the calling function.
The function returns the index where the match is found, -1 if no
match is found
 int size is the size of the array

*/
int binarySearchID(int arr[], int numElems, int value, int &nIter)
{
   int start = 0;//start sort from beggining of array
   int finish = numElems - 1;//start sort from end of ar
   int middle;//splits array in half to find value
   nIter = 0;//reference variable used to keep track of iterations


   while (start <= finish)
   {
      middle = (start + finish) / 2;
      nIter++;
      if (arr[middle] == value)
      {
         return middle;
      }//closes if (arr[middle] == value)
      else if (arr[middle] > value)
      {
         finish = middle - 1;
      } //closes else if  (arr[middle] > value)
      else
         start = middle + 1;
   }//closes else
   return -1;
}// closes binarySearchID function

/*Prompt the user for a file name. Open the file and read the data to initialize the netID, major and GPA arrays.
If the file cannot be opened, prints “Could not open file” and “Exiting\n” and terminate.
Display the contents of all the arrays. Display the menu of choices, and perform the action selected
by the user on the menu (search, list the top n students, or quit). If the user chooses “search”,
the main function calls both the linear search and binary search functions, and displays the result of both searches,
along with the number of iterations. The main function loops on displaying the menu as long as the user
does not choose to quit. If the user chooses to quit, the program prints “Exiting\n” and terminate.
 */

int main ()
{
   const int NUM_ELMTS = 18;// max amount of elements in an array

// netID, major and GPA are parallel arrays
   int netID[NUM_ELMTS]; // Original netID array
   string major[NUM_ELMTS]; // Original major array
   double GPA[NUM_ELMTS]; // Original GPA array

// sortedGPAbyGPA is sorted by GPA, and sortedNetIDbyGPA and sortedMajorbyGPA are parallel arrays
   double sortedGPAbyGPA[NUM_ELMTS]; // GPA array, sorted by GPA
   int sortedNetIDbyGPA[NUM_ELMTS];
   string sortedMajorbyGPA[NUM_ELMTS];

// sortedNetIDbyID is sorted by netID, and sortedMajorbyID and sortedGPAbyID are parallel arrays
   int sortedNetIDbyID[NUM_ELMTS]; // netID array,sorted by netID
   string sortedMajorbyID[NUM_ELMTS];
   double sortedGPAbyID[NUM_ELMTS];


   string file_name;
   cout << "Enter file name: ";
   cin >> file_name;

   ifstream inputFile;
   inputFile.open(file_name);

   // ofstream outputFile;
   // outputFile.open("output.txt");
   string line;
   int lineCount = 0;//counts the number of lines in a file

   while (getline(inputFile, line))
   {
      lineCount++;
   }//closes getline While

   inputFile.close();
   inputFile.open(file_name);

   if (inputFile)
   {
      for (int i = 0; i < lineCount; i++)
      {
         inputFile >> netID[i];
         inputFile >> major[i];
         inputFile >> GPA[i];

      }//closes for loop
   } //closes if loop for input file
   else
   {
      cout << "Could not open file" << "\n";
      cout << "Exiting" << "\n";
      return 0;
   }//closes else if no file

   cout << "Original arrays:" << "\n" << "----------------" << "\n";
   cout << fixed << left;
   cout << setw(7) << "index" << setw(7) << "netID" << setw(8) << "major" << setw(6) << "GPA";
   cout << setw(7) << "index" << setw(7) << "netID" << setw(8) << "major" << setw(6) << "GPA" << endl;

   for (int i = 0; i < lineCount; i++)
   {
      cout << fixed << right << setw(5) << i << setw(7) << netID[i] << setw(7) << major[i] << setw(6)
           << setprecision(2) << GPA[i] << "   ";

      if ((i + 1) % 2 == 0)
         cout << endl;
   }//closes for loop for original array
   cout << "\n";
   modifiedSortGPA(GPA, netID, major, lineCount);

   cout << "Arrays sorted by GPA:" << "\n" << "---------------------" << "\n";
   cout << fixed << left;
   cout << setw(7) << "index" << setw(7) << "netID" << setw(8) << "major" << setw(6) << "GPA";
   cout << setw(7) << "index" << setw(7) << "netID" << setw(8) << "major" << setw(6) << "GPA" << endl;

   for (int i = 0; i < lineCount; i++)
   {
      cout << fixed << right << setw(5) << i << setw(7) << netID[i] << setw(7) << major[i] << setw(6)
           << setprecision(2) << GPA[i] << "   ";

      if ((i + 1) % 2 == 0)
         cout << endl;
   }//closes for loop for modified GPA array
   cout << "\n";
   modifiedSortID(netID, GPA, major, lineCount);

   cout << "Arrays sorted by netID: " << "\n" << "-----------------------" << "\n";
   cout << fixed << left;
   cout << setw(7) << "index" << setw(7) << "netID" << setw(8) << "major" << setw(6) << "GPA";
   cout << setw(7) << "index" << setw(7) << "netID" << setw(8) << "major" << setw(6) << "GPA" << endl;

   for (int i = 0; i < lineCount; i++)
   {
      cout << fixed << right << setw(5) << i << setw(7) << netID[i] << setw(7) << major[i] << setw(6)
           << setprecision(2) << GPA[i] << "   ";

      if ((i + 1) % 2 == 0)
         cout << endl;
   }//closes for loop for modified ID array

   cout << "\n";
   int answer;//answer for user input in menu
   int inputNum;//find top number of students
   int searchFor;//search for student by netID
   int nIter;//counter for iterations
   int runs = 0;//counter for linear iterations
   int counters = 0;//counter for binary iterations

   do
   {
      cout << "***************\n";
      cout << "Menu of choices\n";
      cout << "***************\n";
      cout << "1 - List top n students\n";
      cout << "2 - Search on a netID\n";
      cout << "3 - Quit\n";
      cin >> answer;

      if (answer == 1)
      {

         cin >> inputNum;
         cout << "Enter n: " << "\n" << "Top " << lineCount << " students are:" << endl << "\n";

         int sortedNetIDbyGPA[18];
         string sortedMajorbyGPA[18];
         double sortedGPAbyGPA[18];

         if (inputNum > lineCount)
         {
            for (int i = 0; i < lineCount; i++)
            {
               sortedNetIDbyGPA[i] = netID[i];
               sortedMajorbyGPA[i] = major[i];
               sortedGPAbyGPA[i] = GPA[i];

            } //closes for loop to copy arrays
            for (int i = 0; i < lineCount; i++)
            {
               inputFile >> sortedNetIDbyGPA[i];
               inputFile >> sortedMajorbyGPA[i];
               inputFile >> sortedGPAbyGPA[i];

            }//closes for loop to get data from arrays
            selectionTop(sortedNetIDbyGPA, sortedMajorbyGPA, sortedGPAbyGPA, lineCount);


            for (int i = 0; i < lineCount; i++)
            {
               cout << setw(7) << "netID: " << sortedNetIDbyGPA[i] << ", " << setw(7) << "major: "
                    << sortedMajorbyGPA[i] << ", " << setw(5) << setprecision(2) << "GPA: " << sortedGPAbyGPA[i];
               cout << endl;
            }   //closes for loop for sortedNetID array and formats

            cout << "\n";


         } //closes for loop for top n students
         else
         {
            for (int i = 0; i < inputNum; i++)
            {
               sortedNetIDbyGPA[i] = netID[i];
               sortedMajorbyGPA[i] = major[i];
               sortedGPAbyGPA[i] = GPA[i];

            }//closes for loop to copy arrays
            for (int i = 0; i < inputNum; i++)
            {
               inputFile >> sortedNetIDbyGPA[i];
               inputFile >> sortedMajorbyGPA[i];
               inputFile >> sortedGPAbyGPA[i];

            }//closes for loop to input data
            selectionTop(sortedNetIDbyGPA, sortedMajorbyGPA, sortedGPAbyGPA, inputNum);


            for (int i = 0; i < inputNum; i++)
            {
               cout << setw(7) << "netID: " << sortedNetIDbyGPA[i] << ", " << setw(7) << "major: "
                    << sortedMajorbyGPA[i] << ", " << setw(5) << setprecision(2) << "GPA: " << sortedGPAbyGPA[i];
               cout << endl;
            }//closes for lop to format top n
            cout << "\n";
         }//closes else

      } //closes if user inputs 1 for menu
      else if (answer == 2)
      {
         for (int i = 0; i < lineCount; i++)
         {
            inputFile >> netID[i];
            inputFile >> major[i];
            inputFile >> GPA[i];

         }//closes reading in file data for loop

         cout << "Enter netID: ";
         cin >> searchFor;
         int index = linearSearchID(netID, lineCount, searchFor, runs);
         if (index == -1)
         {
            cout << "Result of linear search:\n" << "------------------------\n";

            cout << "Student not found\n" << "It took " << runs << " iterations" << endl << "\n";
         }//closes if index is not found
         else
         {
            cout << "Result of linear search:\n" << "------------------------\n"
                 << "Student found at index " << index << ", GPA is " << GPA[index]
                 << "\n" << "It took " << runs << " iterations" << endl << "\n";
         }//closes if linear index is found
         for (int i = 0; i < lineCount; i++)
         {
            sortedNetIDbyID[i] = netID[i];
            sortedMajorbyID[i] = major[i];
            sortedGPAbyID[i] = GPA[i];

         }//closes for copying arrays
         for (int i = 0; i < lineCount; i++)
         {
            inputFile >> sortedNetIDbyID[i];
            inputFile >> sortedMajorbyID[i];
            inputFile >> sortedGPAbyID[i];

         }//closes reading in file data
         int index1 = binarySearchID(sortedNetIDbyID, lineCount, searchFor, counters);

         if (index1 == -1)
         {
            cout << "Result of binary search:\n" << "------------------------\n";
            cout << "Student not found\n" << "It took " << counters << " iterations" << endl << "\n";
         }// closes if index not found
         else
         {
            cout << "Result of binary search:\n" << "------------------------\n"
                 << "Student found at index " << index1 << ", GPA is " << sortedGPAbyID[index]
                 << "\n" << "It took " << counters << " iterations" << endl << "\n";
         }//closes if binary index is found

      }//closes if user inputs 2 in menu
      else
      {
         cout << "Exiting\n";
         inputFile.close();
         return 0;

      }//closes if user doesnt input 1 or 2

   } //closes do loop for menu
   while (true);

   {
      inputFile.close();
      return 0;
   }//closes do while loop

}//closes main function


