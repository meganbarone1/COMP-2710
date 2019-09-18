#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

const int MAX_SIZE = 100;

int readFile(int inputArray[], ifstream& inStream);
void merge(int aSize, int bSize, int a[], int b[], int c[]);
void writeFile(int outputArray[], int outputArray_size, ofstream& outStream);


int main() {
    ifstream inStream1;
    ifstream inStream2;
    ofstream outStream;
    string filename1, filename2, filename3;
    int iArray1_size;
    int iArray1[MAX_SIZE];
    int iArray2_size;
    int iArray2[MAX_SIZE];
    int finalArray_size;
    int finalArray[MAX_SIZE];

    cout << "*** Unit Test Cases ***\n";





   cout << "*** Welcome to Megan's sorting program ***\n";
   cout << "Enter the first input file name: ";
   getline(cin, filename1);
   string fn = ".txt";
       inStream1.open(filename1.c_str());

       if (inStream1.fail()) {
           cout << "File failed to open.\n";
       } else {
           int n = 0;
           while (!inStream1.eof()) {
               inStream1 >> iArray1[n];
               n++;
           }
       }

       iArray1_size = readFile(iArray1, inStream1);
       cout << "The list of " << iArray1_size << " in file " << filename1 << " is : \n"
       ;for (int i = 0; i < iArray1_size; i++) {
           cout << iArray1[i] << "\n";
       }
       inStream1.close();




    cout << "Enter the second input file name: ";
    getline(cin, filename2);
        inStream2.open(filename2.c_str());

        if (inStream2.fail()) {
            cout << "File failed to open.\n";
        } else {
            int n = 0;
            while (!inStream2.eof()) {
                inStream2 >> iArray2[n];
                n++;
            }
        }

        iArray2_size = readFile(iArray2, inStream2);
        cout << "The list of " << iArray2_size << " in file " << filename2 << " is : \n"
                ;for (int i = 0; i < iArray2_size; i++) {
            cout << iArray2[i] << "\n";
        }
        inStream2.close();

        merge(iArray1_size, iArray2_size, iArray1, iArray2, finalArray);
        finalArray_size = iArray1_size + iArray2_size;

        cout << "The sorted list of " << finalArray_size << "numbers is: ";
        for(int i = 0; i < finalArray_size; i++) {
            cout << finalArray[i] << " ";
        }

        writeFile(finalArray, finalArray_size,outStream);
        cout << "Enter the output filename: ";
        cin >> filename3;
        cout << "*** Please check the new file - " << filename3 << " ***\n";
        cout << "*** Goodbye. ***";













    return 0;
}





int readFile(int inputArray[], ifstream& inStream) {
    int index = 0;


    inStream >> inputArray[index];
    while (!inStream.eof()) {
        inStream >> inputArray[index];
        index++;

    }
    return index;
}

void merge(int aSize, int bSize, int a[], int b[], int c[]) {
    int i, j, k;
    i = 0;
    j = 0;
    k = 0;
    while (i< aSize && j < bSize) {
        if (a[i] <= b[j]) {
            c[k] = a[i];
            i++;
        }
        else {
            c[k] = b[j];
            j++;
        }
        k++;
    }
    if (i < aSize) {
        for (int p = i; p < aSize; p++) {
            c[k] = a[p];
            k++;
        }
    }
    else {
        for (int p = j; p < bSize; p++) {
            c[k] = b[p];
            k++;
        }
    }

}

void writeFile(int outputArray[], int outputArray_size, ofstream& outStream) {

}
