/*
Author: Dharshini Mahesh
Compiler: GNU GCC
Date: 3/3/2023
Purpose of program: This program manages students’ records. Each student’s record consists of a netID, a major and a GPA,
maintained in a structure. The structures are elements of an array. The program will read students’ data from a file and
loop on displaying the following menu of choices:

List the top n students
Search for a student
Exit the program.
If the user chooses 1, the user will be prompted for the value of n, and the netID, major and GPA of the top n students will be listed, starting with the student with highest GPA and going down.
If the user chooses 2, user will be prompted to enter the student’s netID. If the netID is found in a structure of the array, the array index, major and GPA of the student are displayed. If the student is not found, a “Student not found” message is displayed.
If the user chooses 3, the program prints “Exiting\n” and terminates.
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>

using namespace std;

//structure holds the netID, major, and GPA from parallel arrays
struct Student
{
    int netID;
    string major;
    double GPA;
};//closes struct definition, global

// This function sorts the array of Student structures according to netID
void modifiedSortID(Student array2[], int size);

// This function sorts the array of Student structures according to GPA
void modifiedSortGPA(Student array1[], int size);

// This function sorts the array of Student structures according to GPA to show the top n of students that the user inputs
void selectionTop(Student studArraysortedbyGPA[], int size);

//This function implements linear search to find a student that the user enters with netID
int linearSearchID(Student arr[], int numElems, int value, int &nIter);

// This function implements binary search to find a student that the user enters with netID
int binarySearchID(Student arr[], int numElems, int value, int &nIter);

/*Prompt the user for a file name. Open the file and read the data to initialize the netID, major and GPA arrays.
If the file cannot be opened, prints “Could not open file” and “Exiting\n” and terminate.
Display the contents of all the arrays. Display the menu of choices, and perform the action selected
by the user on the menu (search, list the top n students, or quit). If the user chooses “search”,
the main function calls both the linear search and binary search functions, and displays the result of both searches,
along with the number of iterations. The main function loops on displaying the menu as long as the user
does not choose to quit. If the user chooses to quit, the program prints “Exiting\n” and terminate.
 */
int main()
{
   const int NUM_ELMTS = 18;// max amount of elements in an array

   Student studArray[NUM_ELMTS]; // Original array of Student structures
   Student studArraysortedbyGPA[NUM_ELMTS];// Array sorted by GPA
   Student studArraysortedbyID[NUM_ELMTS];// Array sorted by netID

   int lineCount = 0;//counts the number of lines in a file

   string file_name;
   cout << "Enter file name: ";
   cin >> file_name;

   ifstream inputFile;
   inputFile.open(file_name);

   string line;

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
         inputFile >> studArray[i].netID;
         inputFile >> studArray[i].major;
         inputFile >> studArray[i].GPA;

      }//closes for loop to read in structure data from array
   } //closes if loop for input file
   else
   {
      cout << "Could not open file" << "\n";
      cout << "Exiting" << "\n";
      return 0;
   }//closes else if no file
   cout << "Original array:" << "\n" << "---------------" << "\n";
   cout << fixed << left;
   cout << setw(7) << "index" << setw(7) << "netID" << setw(8) << "major" << setw(6) << "GPA";
   cout << setw(7) << "index" << setw(7) << "netID" << setw(8) << "major" << setw(6) << "GPA" << endl;

   for (int i = 0; i < lineCount; i++)
   {
      cout << fixed << right << setw(5) << i << setw(7) << studArray[i].netID << setw(7) << studArray[i].major
           << setw(6)
           << setprecision(2) << studArray[i].GPA << "   ";

      if ((i + 1) % 2 == 0)
         cout << endl;
   }//closes for loop for original array
   cout << "\n";

   modifiedSortGPA(studArray, lineCount);

   cout << "Array sorted by GPA:" << "\n" << "--------------------" << "\n";
   cout << fixed << left;
   cout << setw(7) << "index" << setw(7) << "netID" << setw(8) << "major" << setw(6) << "GPA";
   cout << setw(7) << "index" << setw(7) << "netID" << setw(8) << "major" << setw(6) << "GPA" << endl;

   for (int i = 0; i < lineCount; i++)
   {
      cout << fixed << right << setw(5) << i << setw(7) << studArray[i].netID << setw(7) << studArray[i].major
           << setw(6)
           << setprecision(2) << studArray[i].GPA << "   ";

      if ((i + 1) % 2 == 0)
         cout << endl;
   }//closes for loop for modified GPA array
   cout << "\n";
   modifiedSortID(studArray, lineCount);

   cout << "Array sorted by netID: " << "\n" << "----------------------" << "\n";
   cout << fixed << left;
   cout << setw(7) << "index" << setw(7) << "netID" << setw(8) << "major" << setw(6) << "GPA";
   cout << setw(7) << "index" << setw(7) << "netID" << setw(8) << "major" << setw(6) << "GPA" << endl;

   for (int i = 0; i < lineCount; i++)
   {
      cout << fixed << right << setw(5) << i << setw(7) << studArray[i].netID << setw(7) << studArray[i].major
           << setw(6)
           << setprecision(2) << studArray[i].GPA << "   ";

      if ((i + 1) % 2 == 0)
         cout << endl;
   }//closes for loop for modified ID array

   cout << "\n";
   int answer;//answer for user input in menu
   int inputNum;//find top number of students
   int searchFor;//search for student by netID
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

         // int sortedNetIDbyGPA[18];
         // string sortedMajorbyGPA[18];
         // double sortedGPAbyGPA[18];

         if (inputNum > lineCount)
         {
            for (int i = 0; i < lineCount; i++)
            {
               studArraysortedbyGPA[i].netID = studArray[i].netID;
               studArraysortedbyGPA[i].major = studArray[i].major;
               studArraysortedbyGPA[i].GPA = studArray[i].GPA;
            } //closes for loop to copy array structs

            for (int i = 0; i < lineCount; i++)
            {
               inputFile >> studArraysortedbyGPA[i].netID;
               inputFile >> studArraysortedbyGPA[i].major;
               inputFile >> studArraysortedbyGPA[i].GPA;

            }//closes for loop to get data from array struct
            selectionTop(studArraysortedbyGPA, lineCount);


            for (int i = 0; i < lineCount; i++)
            {
               cout << setw(7) << "netID: " << studArraysortedbyGPA[i].netID << ", " << setw(7) << "major: "
                    << studArraysortedbyGPA[i].major << ", " << setw(5) << setprecision(2) << "GPA: "
                    << studArraysortedbyGPA[i].GPA;
               cout << endl;
            }   //closes for loop for studArraysortedbyGPA array and formats

            cout << "\n";

         } //closes for loop for top n students
         else
         {
            for (int i = 0; i < lineCount; i++)
            {
               studArraysortedbyGPA[i].netID = studArray[i].netID;
               studArraysortedbyGPA[i].major = studArray[i].major;
               studArraysortedbyGPA[i].GPA = studArray[i].GPA;
            } //closes for loop to copy array struct
            for (int i = 0; i < lineCount; i++)
            {
               inputFile >> studArraysortedbyGPA[i].netID;
               inputFile >> studArraysortedbyGPA[i].major;
               inputFile >> studArraysortedbyGPA[i].GPA;

            }//closes for loop to get data from array struct
            selectionTop(studArraysortedbyGPA, lineCount);

            for (int i = 0; i < inputNum; i++)
            {
               cout << setw(7) << "netID: " << studArraysortedbyGPA[i].netID << ", " << setw(7) << "major: "
                    << studArraysortedbyGPA[i].major << ", " << setw(5) << setprecision(2) << "GPA: "
                    << studArraysortedbyGPA[i].GPA;
               cout << endl;
            }//closes for lop to format top n
            cout << "\n";
         }//closes else

      } //closes if user inputs 1 for menu
      else if (answer == 2)
      {
         for (int i = 0; i < lineCount; i++)
         {
            inputFile >> studArray[i].netID;
            inputFile >> studArray[i].major;
            inputFile >> studArray[i].GPA;

         }//closes reading in file data for loop

         cout << "Enter netID: ";
         cin >> searchFor;
         int index = linearSearchID(studArray, lineCount, searchFor, runs);
         if (index == -1)
         {
            cout << "Result of linear search:\n" << "------------------------\n";

            cout << "Student not found\n" << "It took " << runs << " iterations" << endl << "\n";
         }//closes if index is not found
         else
         {
            cout << "Result of linear search:\n" << "------------------------\n"
                 << "Student found at index " << index << ", major is " << studArray[index].major << ", " << "GPA is "
                 << studArray[index].GPA
                 << "\n" << "It took " << runs << " iterations" << endl << "\n";
         }//closes if linear index is found
         for (int i = 0; i < lineCount; i++)
         {
            studArraysortedbyID[i].netID = studArray[i].netID;
            studArraysortedbyID[i].major = studArray[i].major;
            studArraysortedbyID[i].GPA = studArray[i].GPA;

         }//closes for copying array struct
         for (int i = 0; i < lineCount; i++)
         {
            inputFile >> studArraysortedbyID[i].netID;
            inputFile >> studArraysortedbyID[i].major;
            inputFile >> studArraysortedbyID[i].GPA;

         }//closes reading in file data
         int index1 = binarySearchID(studArraysortedbyID, lineCount, searchFor, counters);

         if (index1 == -1)
         {
            cout << "Result of binary search:\n" << "------------------------\n";
            cout << "Student not found\n" << "It took " << counters << " iterations" << endl << "\n";
         }// closes if index not found
         else
         {
            cout << "Result of binary search:\n" << "------------------------\n"
                 << "Student found at index " << index1 << ", major is " << studArray[index].major << ", GPA is "
                 << studArraysortedbyID[index].GPA
                 << "\n" << "It took " << counters << " iterations" << endl << "\n";
         }//closes if binary index is found

      }//closes if user inputs 2 in menu
      else
      {
         cout << "Exiting\n";
         inputFile.close();
         return 0;

      }//closes if user does not input 1 or 2

   } //closes do loop for menu
   while (true);

   {
      inputFile.close();
      return 0;
   }//closes do while loop

}//closes main function

/* This function sorts the array of Student structures according to netID, size used to get length of array
*/
void modifiedSortID(Student array2[], int size)
{
   int minIndex;//minIndex starts the sort and keeps track of the index the value is
   for (int start = 0; start < (size - 1); start++)
   {
      minIndex = start;
      for (int index = start + 1; index < size; index++)
      {
         if (array2[index].netID < array2[minIndex].netID)
         {
            minIndex = index;

         }//end if (array2[index] < minValue)
      }//end for (int index = start + 1; index < size; index++)
      Student temp = array2[minIndex];
      array2[minIndex] = array2[start];
      array2[start] = temp;
   }//end for loop for selection sort


}//end function modifiedSortID

/* This function sorts the array of Student structures according to GPA size used to get length of array
*/
void modifiedSortGPA(Student array1[], int size)
{
   int minIndex;//minIndex starts the sort and keeps track of the index the value is
   for (int start = 0; start < (size - 1); start++)
   {
      minIndex = start;
      for (int index = start + 1; index < size; index++)
      {
         if (array1[index].GPA < array1[minIndex].GPA)
         {
            minIndex = index;

         }//end if (array1[index] < minValue)
      }//end for (int index = start + 1; index < size; index++)
      Student temp = array1[minIndex];
      array1[minIndex] = array1[start];
      array1[start] = temp;
   }//end for loop for selection sort

}//end modifiedSortGPA function

/* This function selection sorts the array studArraysortedbyGPA by highest to lowest GPA, uses size to get lenth of array

*/
void selectionTop(Student studArraysortedbyGPA[], int size)
{
   int minIndex;//minIndex starts the sort and keeps track of the index the value is,
   double minValue;//minvalue us the smallest element in the array
   for (int start = 0; start < (size - 1); start++)
   {
      minIndex = start;
      minValue = studArraysortedbyGPA[start].GPA;
      for (int index = start + 1; index < size; index++)
      {
         if (studArraysortedbyGPA[index].GPA > minValue)
         {
            minValue = studArraysortedbyGPA[index].GPA;
            minIndex = index;

         }//end if (studArraysortedbyGPA[index] > minValue)
      }//end for (int index = start + 1; index < size; index++)
      Student temp = studArraysortedbyGPA[minIndex];
      studArraysortedbyGPA[minIndex] = studArraysortedbyGPA[start];
      studArraysortedbyGPA[start] = temp;
   }//end for loop for selection sort

}//end selectionTop function

/* This function implements linear search on a Struct Student  arr. It takes the following arguments:
 the array, numElems: number of elements of array,
value: search value, and nIter. nIter is a reference variable used
to pass the number of iterations back to the calling function.
The function returns the index where the match is found, -1 if no
match is found
int size is the size of the array
*/
int linearSearchID(Student arr[], int numElems, int value, int &nIter)
{
   nIter = 0;//reference variable used to keep track of iterations
   for (int i = 0; i < numElems; i++)
   {
      nIter++;
      if (arr[i].netID == value)
      {
         return i;
      }//closes if (arr[i] == value)
   }//closes for loop
   return -1;
}//closes linearSearchID function

/* This function implements binary search on Struct Student arr. It takes the following arguments:
arr: the array, numElems: number of elements of array,
value: search value, and nIter. nIter is a reference variable used
to pass the number of iterations back to the calling function.
The function returns the index where the match is found, -1 if no
match is found
 int size is the size of the array
*/
int binarySearchID(Student arr[], int numElems, int value, int &nIter)
{
   int start = 0;//start sort from beginning of array
   int finish = numElems - 1;//start sort from end of ar
   int middle;//splits array in half to find value
   nIter = 0;//reference variable used to keep track of iterations

   while (start <= finish)
   {
      middle = (start + finish) / 2;
      nIter++;
      if (arr[middle].netID == value)
      {
         return middle;
      }//closes if (arr[middle] == value)
      else if (arr[middle].netID > value)
      {
         finish = middle - 1;
      } //closes else if  (arr[middle] > value)
      else
         start = middle + 1;
   }//closes else
   return -1;
}// closes binarySearchID function