//  Kelci Jenkins
//  project3_Jenkins_kdj0022.cpp
//  Used class slides for help.
// Used https://www.geeksforgeeks.org/sorting-a-vector-in-c/ to help understand sorting vectors.
// Used https://stackoverflow.com/questions/69863023/how-to-put-numbers-from-txt-file-into-vector-in-c to help with adding numbers from txt file to vector; led me to pushback, used https://www.geeksforgeeks.org/vectorpush_back-vectorpop_back-c-stl/ to help understand.
// Used https://stackoverflow.com/questions/3177241/what-is-the-best-way-to-concatenate-two-vectors to help with mergining vectors
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> //for the sort section

using namespace std;

/* declaring user-defined functions*/
bool check_file(string); //checks file
vector<int> read_file(string); //reads file
void write_file(string, vector<int>);
vector<int> merge(vector<int>, vector<int>);
void to_string(vector<int>);

int main() {
    /* Declaring variables */
    string file1;
    string file2;
    string file3;
    vector<int> numbers1;
    vector<int> numbers2;
    vector<int> numbers3;
    
    /*welcome interface*/
    cout << "*** Welcome to Kelci's sorting program ***" << endl;
    
    /* File 1 section */
    // Getting the name of file 1
    do {
        cout << "Enter the first input file name: "; //prompting user for file name
        cin >> file1; //user inputs file name
    } while (cin.fail() || !check_file(file1));
    
    numbers1 = read_file(file1); //Getting numbers from file 1
    cout << "The list of " << numbers1.size() << " numbers in the file " + file1 + " is:\n"; //displaying number
    to_string(numbers1);
    
    /* File 2 section */
    do {
        cout << "Enter the second input file name: "; //prompts user for file name
        cin >> file2; //user inputs file name
    } while (cin.fail() || !check_file(file2));
    
    numbers2 = read_file(file2); //Getting numbers from file 2
    cout << "The list of " << numbers2.size() << " numbers in the file " + file2 + " is:\n"; //displaying number
    to_string(numbers2);
    
    /* Combining vectors and displaying sorted results */
    numbers3 = merge(numbers1, numbers2); //combining vectors
    cout << "The sorted list of " << numbers3.size() << " numbers is: ";
        for (unsigned int i=0; i < numbers3.size(); i++) {
            cout << numbers3.at(i) << " ";
        }
        cout << endl;
    
    /* File 3 | Output section */
    do {
        cout << "Enter the output file name: "; //prompting user for file name
        cin >> file3; //inputs file name
    } while (cin.fail());
    
    write_file(file3, numbers3); //write combined vector to output file
    cout << "*** Please check the new file - " + file3 + " ***" << endl;
    cout << "*** Goodbye. *** ";
    
    return 0;
}

bool check_file(string file) {
    /* Input file stream. (ifstream)*/
    ifstream stream;
    
    /* Check whether file exists. */
    stream.open(file.c_str());
    if (stream.fail()) {
        stream.close();
        return false;
    }
    stream.close();
    
    return true; //returns true if file exists
}

vector<int> read_file(string file) {
    ifstream stream; //input file stream
    vector<int> v; //contains number from file
    int i; //int read from file
    
    /* Add each number in the file to a vector. */
    stream.open(file.c_str());
    while (stream.good()){
        stream >> i;
        v.push_back(i); //moves i to the end of vector
    }
    v.pop_back(); //moves i from the end
    stream.close();
    
    return v;
}

void write_file(string file, vector<int> v){
    ofstream stream;//output file stream.
    stream.open(file.c_str());
    for (unsigned int i=0; i < v.size(); i++) {
        stream << v.at(i) << endl;
        
    }
    stream.close();
}

vector<int> merge(vector<int> v1, vector<int> v2) {
    vector<int> v3;
    // used stackoverflow to help with this portion
    // combines + compares vectors and sorts it
        v3 = v1;
        v3.insert(v3.end(), v2.begin(), v2.end());
        sort(v3.begin(), v3.end());

        return v3;
}

void to_string (vector<int> v) {
    unsigned short i; //vector interator number
    
    /* Displays the numbers contained in a vector*/
    for (unsigned int i=0; i < v.size(); i++) {
        cout << v.at(i) << endl;
    }
    cout << endl;
}
