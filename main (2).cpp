 // Author:           Harsh Gopalan
 //
 // Assignment:       Word Search Matrix
 //
 // Date:             February 22, 2021 (Started Making Changes)
 //                   February 28, 2021 (Finished Programming)
 //
 // Description:      This program will get the row and column from an input file, along with
 //                   the 2D matrix and the movie names, to ultimately find the list of movies
 //                   in the matrix. It will print out the location at which the movie is found and
 //                   in the direction at which it is found.
 //
 // Changelog:        February 22 - Made starting edits to the program. Added the spaceRemove function
 //                   and created the global variables.
 //                   February 24 - Created the smaller function in the program and added the logic parts that include the
 //                   skipLines and show and read Matrix functions.
 //                   February 26 - Started creating the movieSearch function and stated splitting it into smaller function
 //                   for readability.
 //                   February 28 - Made final edits and added other code to help finish the lab.
 //
 // Notes:             1) Used a special feature for searching and removing spaces in movie name
 //                    Bonus:
 //                    2) For the movie "RUR", the code includes the instance where it happens twice, as it is a palindrome
 //                    3) Included a word.length() statement when searching for each word in matrix
 // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //

#include <iostream>
#include <math.h>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <ctype.h>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

// Global Variables
ifstream infile;
ofstream outfile;
string fileName = "ComedyMovies-FINAL2.txt";
int rowNum, colsNum;
const int maxRows = 100;
const int maxCols = 100;
char matrix[maxRows][maxCols];
string direction;
vector<string> notfoundMovies;
// End of Global Variables


// Function Prototypes
string spaceRemove(string movieName);
void skipLines(ifstream &infile);
void readTheMatrix();
void showTheMatrix();
bool movieSearch(string movieName);
bool fileReading(ifstream &infile, string fileName);
void searchingNorthDir(string &movieName, int &numRow, int &numCols, int &i, int &j, bool &matchFound);
void searchingSouthDir(string &movieName, int &numRow, int &numCols, int &i, int &j, bool &matchFound);
void searchingEastDir(string &movieName, int &numRow, int &numCols, int &i, int &j, bool &matchFound);
void searchingWestDir(string &movieName, int &numRow, int &numCols, int &i, int &j, bool &matchFound);
void searchingSWDir(string &movieName, int &numRow, int &numCols, int &i, int &j, bool &matchFound);
void searchingSEDir(string &movieName, int &numRow, int &numCols, int &i, int &j, bool &matchFound);
void searchingNEDir(string &movieName, int &numRow, int &numCols, int &i, int &j, bool &matchFound);
void searchingNWDir(string &movieName, int &numRow, int &numCols, int &i, int &j, bool &matchFound);
// End of Function Prototypes

// This function gets rids of the space in the movie titles
string spaceRemove(string movieName)
{
   // Will remove the spaces from the movie names
   movieName.erase(remove_if(movieName.begin(), movieName.end(), ::isspace), movieName.end());

   return movieName;
} // end function spaceRemove(string movieName)

// This function will present just the matrix to the user
void showTheMatrix()
{
   for (int j = 0; j < rowNum; j++)
   {
      // Will not inlcude any comments that may be within
      // the matrix
      skipLines(infile);
      for (int k = 0; k < colsNum; k++)
      {
         cout << matrix[j][k];
      }
      cout << endl;
   }
   
   cout << endl;
} // end function showTheMatrix()

// Will skip comment lines and blank lines when reading the data in from the
// input file.
void skipLines(ifstream &infile)
{
   string textLine;
   char chars = infile.peek();
   while (chars == '#' || chars == '\n')
   {
      getline(infile,textLine);
      // Will peak at each line for first character
      chars = infile.peek();
   }
   
} // end function skipLines(ifstream &inFile)

// This function will read the matrix in while also reading in the number of columns and rows
void readTheMatrix()
{
   // Will print the number of rows and columns in the matrix, from the input file
   if (infile.good())
   {
      // Will skip comment lines and blank lines when reading the data in from the
      // input file
      skipLines(infile);
      infile >> rowNum >> colsNum;
      
      cout << "The Number of Rows in the Matrix: " << rowNum << " | The Number of Columns in the Matrix: " << colsNum << endl; // Will present to user
   }
   
   cout << endl;
   
   // The 2D matrix will be read in
   for (int j = 0; j < rowNum; j++)
   {
      // Will skip comment lines and blank lines when reading the data in from the
      // input file
      skipLines(infile);
      for (int k = 0; k < colsNum; k++)
      {
         infile >> matrix[j][k];
      }
   }
} // end function readTheMatrix()

// Searching the North Direction
void searchingNorthDir(string &movieName, int &numRow, int &numCols, int &i, int &j, bool &matchFound)
{
   // Traversing through each letter of movie
   for (int k = 1; k < movieName.length(); k++)
   {
      // Formula for going North
      if (matrix[i-k][j] == movieName[k])
      {
         if (k == (movieName.length() - 1))
         {
            direction = "N";
            if (direction != "" && (numRow >= 0 && numCols >= 0))
            {
               // User will be informed
               matchFound = true;
               cout << movieName << fixed << setw(3) << " was found at " << numRow + 1 << ", " << numCols + 1 << ": ";
               cout << fixed << setw(3) << " | (Direction = " << direction << ")" << endl;
               
            }
            
            break; // breaks once found
            
         }
          
      }
      else
      {
         direction = "";
         break;
      }
   }
} // end function searchingNorthDir

// Searching the South Direction
void searchingSouthDir(string &movieName, int &numRow, int &numCols, int &i, int &j, bool &matchFound)
{
   // Traversing through each letter of movie
   for (int k = 1; k < movieName.length(); k++)
   {
      // Formula for going South
      if (matrix[i+k][j] == movieName[k])
      {
         if (k == movieName.length() - 1)
         {
            direction = "S";
            if (direction != "" && (numRow >= 0 && numCols >= 0))
            {
               // User will be informed
               matchFound = true;
               cout << movieName << setw(3) << " was found at " << numRow + 1 << ", " << numCols + 1 << ": ";
               cout << fixed << setw(3) << " | (Direction = " << direction << ")" << endl;
            }
               break; // breaks once found
            }
          
         }
      else
      {
         direction = "";
         break;
      }
      
   }
} // end function searchingSouthhDir

// Searching the East Direction
void searchingEastDir(string &movieName, int &numRow, int &numCols, int &i, int &j, bool &matchFound)
{
   // Traversing through each letter of movie
   for (int k = 1; k < movieName.length(); k++)
   {
      // Formula for going East
       if (matrix[i][j+k] == movieName[k])
       {
          if (k == movieName.length() - 1)
          {
             direction = "E";
             if (direction != "" && (numRow >= 0 && numCols >= 0))
             {
                matchFound = true;
                // User will be informed
                cout << movieName << setw(3) << " was found at " << numRow + 1 << ", " << numCols + 1 << ": ";
                cout << fixed << setw(3) << " | (Direction = " << direction << ")" << endl;
             }
                break; // breaks once found
             
          }
           
       }
       else
       {
          direction = "";
          break;
       }
   }
} // end function searchingEastDir

// Searching the West Direction
void searchingWestDir(string &movieName, int &numRow, int &numCols, int &i, int &j, bool &matchFound)
{
   // Traversing through each letter of movie
   for (int k = 1; k < movieName.length(); k++)
   {
      // Formula for going West
      if (matrix[i][j-k] == movieName[k])
      {
         if (k == movieName.length() - 1)
         {
            direction = "W";
            if (direction != "" && (numRow >= 0 && numCols >= 0))
            {
               matchFound = true;
               // User will be informed
               cout << movieName << setw(3) << " was found at " << numRow + 1 << ", " << numCols + 1 << ": ";
               cout << fixed << setw(3) << " | (Direction = " << direction << ")" << endl;
            }
               break; // breaks once found
            }
          
         }
      else
      {
         direction = "";
         break;
      }
   }
} // end function searchingWestDir

// Searching the SE Direction
void searchingSEDir(string &movieName, int &numRow, int &numCols, int &i, int &j, bool &matchFound)
{
   // Traversing through each letter of movie
   for (int k = 1; k < movieName.length(); k++)
   {
      // Formula for going SE
       if (matrix[i+k][j+k] == movieName[k])
       {
          if (k == movieName.length() - 1)
          {
             direction = "SE";
             if (direction != "" && (numRow >= 0 && numCols >= 0))
             {
                // User will be informed
                matchFound = true;
                cout << movieName << setw(3) << " was found at " << numRow + 1 << ", " << numCols + 1 << ": ";
                cout << fixed << setw(3) << " | (Direction = " << direction << ")" << endl;
             }
                break; // breaks once found
             
          }
           
       }
       else
       {
          direction = "";
          break;
       }
   }
   
} // end function searchingSEDir

// Searching the SW Direction
void searchingSWDir(string &movieName, int &numRow, int &numCols, int &i, int &j, bool &matchFound)
{
   // Traversing through each letter of movie
   for (int k = 1; k < movieName.length(); k++)
   {
      // Formula for going SW
       if (matrix[i+k][j-k] == movieName[k])
       {
          if (k == movieName.length() - 1)
          {
             direction = "SW";
             if (direction != "" && (numRow >= 0 && numCols >= 0))
             {
                // User will be informed
                matchFound = true;
                cout << movieName << setw(3) << " was found at " << numRow + 1 << ", " << numCols + 1 << ": ";
                cout << fixed << setw(3) << " | (Direction = " << direction << ")" << endl;
             }
                break; // breaks once found
             
          }
           
       }
       else
       {
          direction = "";
          break;
       }
   }
} // end function searchingSWDir

// Searching the NE Direction
void searchingNEDir(string &movieName, int &numRow, int &numCols, int &i, int &j, bool &matchFound)
{
   // Traversing through each letter of movie
   for (int k = 1; k < movieName.length(); k++)
   {
      // Formula for going NE
       if (matrix[i-k][j+k] == movieName[k])
       {
          if (k == movieName.length() - 1)
          {
             direction = "NE";
             if (direction != "" && (numRow >= 0 && numCols >= 0))
             {
                // User will be informed
                matchFound = true;
                cout << movieName << setw(3) << " was found at " << numRow + 1 << ", " << numCols + 1 << ": ";
                cout << fixed << setw(3) << " | (Direction = " << direction << ")" << endl;
             }
                break; // breaks once found
             }
           
          }
       else
       {
          direction = "";
          break;
       }
   }
   
} // end function searchingNEDir

// Searching the NW direction
void searchingNWDir(string &movieName, int &numRow, int &numCols, int &i, int &j, bool &matchFound)
{
   // Traversing through each letter of movie
   for (int k = 1; k < movieName.length(); k++)
   {
      // Formula for going NW
       if (matrix[i-k][j-k] == movieName[k])
       {
          if (k == movieName.length() - 1)
          {
             direction = "NW";
             if (direction != "" && (numRow >= 0 && numCols >= 0))
             {
                // User will be informed
                matchFound = true;
                cout << movieName << setw(3) << " was found at " << numRow + 1 << ", " << numCols + 1 << ": ";
                cout << fixed << setw(3) << " | (Direction = " << direction << ")" << endl;
             }
                break; // breaks once found
             
          }
          
       }
       else
       {
          direction = "";
          break;

       }
      
   }
   
} // end function searchingNWDir

// Will check each character of the moviename and will compare to see
// if the movie name is found.
bool movieSearch(string movieName)
{
   
   bool matchFound = false; // set to false
   
   int numRow = 0, numCols = 0;
   
   // Movie name will not have space
   movieName = spaceRemove(movieName);
   
   // Traverseing the 2D matrix to find the match
   // Rows
   for (int i = 0; i < rowNum; i++)
   {
      // Traversing the columns
      for (int j = 0; j < colsNum; j++)
      {
         // Check if the first letter of movie equals the matrix letter
         if (matrix[i][j] == movieName[0])
         {
            // Will be used when printing the final statements
            numRow = i;
            numCols = j;
            
            direction = ""; // Set to Null
            
            // Functions call for each direction
            searchingNorthDir(movieName, numRow, numCols, i, j, matchFound); // N
            searchingSouthDir(movieName, numRow, numCols, i, j, matchFound); // S
            searchingEastDir(movieName, numRow, numCols, i, j, matchFound); // E
            searchingWestDir(movieName, numRow, numCols, i, j, matchFound); // W
            searchingSEDir(movieName, numRow, numCols, i, j, matchFound); //SE
            searchingSWDir(movieName, numRow, numCols, i, j, matchFound); // SW
            searchingNEDir(movieName, numRow, numCols, i, j, matchFound); // NE
            searchingNWDir(movieName, numRow, numCols, i, j, matchFound); // NW
            
         }
               
      }
      
   }
   
   // The movies that are not found will get pushed back to the vector
   if (matchFound == false)
   {
      // Will get pushed back to the vector
      notfoundMovies.push_back(movieName);
   }
   
   // Will return the status of matchFound (t/f)
   return matchFound;
   
} // end function bool movieSearch(string movieName)

// This function will be called from main to check
// if the file has been opened correctly, and if not,
// it will notify the user and allow the user to enter another fileName.
bool fileReading(ifstream &infile, string fileName)
{
   infile.open(fileName);

   if (infile.good())
   {
      return true; // If file opens correctly
   }
   // If file does not...
   else
   {
      // User is reported the error and is asked to enter the file again
      // Using perror, as instricted by prof.
      perror("The Input File cannot be opened!");
   
      
      cout << "The file " << fileName << " could not be opened" << endl;
      cout << "Please enter another file name or press 'x' to exit: ";

      getline(cin, fileName);
      
      if (fileName == "x")
      {
         cout << "This program will exit!" << endl;
         exit(0);
         
         return false; // Will return false
      
      }
      // Gives an option to quit the program
      else
      {
         cout << "The New FileName that will be opened is: " << fileName << endl << endl;
         // Will return if file was opened
         
         // Will call function again
         bool fileOpen = fileReading(infile,fileName);
         
         return fileOpen;
      }
   }
} // end function fileReading(ifstream &infile, string fileName)

// Main function
int main()
{
   
   // Call to fileReading
   fileReading(infile,fileName);
   
   // Call to readMatrix
   readTheMatrix();
   
   // Call to showMatrix
   showTheMatrix();
   
   cout << "Movies FOUND in the Matrix" << endl;
   
   cout << endl;
   
   string movieName;
   
   // Will run when the file has opened and operating correctly
   while (infile.good())
   {
      skipLines(infile);
      getline(infile,movieName);
      movieSearch(movieName);
   }
   
   cout << endl;
   cout << endl;
   
   cout << "Movies NOT FOUND in the Matrix: " << endl;
   
   cout << endl;
   
   for (int v = 0; v < notfoundMovies.size(); v++)
   {
       cout << notfoundMovies.at(v) << endl;
   }

   cout << endl;
   
   infile.close(); // Closing the input file
   
   return 0; // Program returns 0
   
} // end function main();
   
