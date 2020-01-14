/*
Student Name:
Student Number:
Project Number: 5
Compile Status: [SUCCESS/FAIL]
Running Status: [SUCCESS/FAIL]
Notes: Anything you want to say about your code that will be helpful in the grading process.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <chrono>

using namespace std::chrono;

using namespace std;

int main(int argc, char* argv[]){
    auto start = high_resolution_clock::now();
    ifstream inFile(argv[1]);
    ofstream outFile(argv[2]);
    string line1,line2;
    getline(inFile, line1);
    string line11=line1.substr(0,line1.find(' '));
    string line12=line1.substr(line1.find(' '),line1.length());

    getline(inFile, line2);
    istringstream linestream(line2);
    long long int* prices=new long long int[stoi(line11)];
    int i=0;
    string price;
    while (getline(linestream, price, ' ')) {
        prices[i]=stoi(price);
        i++;
    }
    int p=stoi(line11);
    std::sort(prices,prices+p);
    int q=stoi(line12);
    long long int *total=new long long int[p];
    long long int *pre=new long long int [p];
    std::fill( pre, pre + sizeof( pre ), 0 );
    for (int i = 0; i <p ; ++i) {
        long long int curpricetotal=prices[i]+pre[i]+total[i];

        outFile<<curpricetotal<<" ";

        if(i+q<=p-1){
            pre[i+q]+=prices[i]+pre[i];
        }
        if(i+1<=p-1){
            total[i+1]=curpricetotal;
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

// To get the value of duration use the count()
// member function on the duration object
    cout<<endl;
    cout << duration.count()/1000000.0 <<"second"<< endl;
    return 0;
}

