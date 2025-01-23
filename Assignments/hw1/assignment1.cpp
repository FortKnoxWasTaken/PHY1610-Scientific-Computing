/*
    Created by Anuj C

    PHY1610 Scientific Computing for Physicists
    Assignment 1: C++ Coding

    Question: Write a program that can take 2d data sampled at discrete time points and compute a moving average of the norm of the 2d points as a function of time.

    -> The data comes from a file with 3 columns, where the first column is time `t` and the second and third columns `x(t)` and `y(t)` are 2  coordinates.
    
    -> The program should compute the norm ($\sqrt{x^{2}+y^{2}}$), and then its moving average over `n` points. I.e. for each array element, it should compute the average of it and the preveeding `n`-1 elements. `n` will be an input parameter.
    
    -> Perform this moving average also for the time values.  Write the result in two-column form to a file.    
   
    -> The program should take commmand line arguments that correspond to the input file name, the output file name and the width n of the running average.

    Your code should be in a simple `.cpp` file and have three or more functions in addition to the main function, and should be commented. 

    
    Soltuion and Assumptions:
    -> Read from in.dat
    -> Compute norm of each row in the file
    -> Compute moving average of the norm values with window n=5 (assuming moving average of values<n are computed considering previous values=0)
    -> Similarly compute moving average of times
    -> Write to output.txt


    Requirements:
    1) in.dat
    2) assignment1.cpp
    in the same working directory
    
    
    Usage:
    -> g++ -o assignment1 assignment1.cpp
    ->  ./assignment1 in.dat output.txt 5 (./assignment1 input_file_name output_file_name width=n)
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<sstream>
using namespace std;

// read function
bool read_data(string &filename, vector<double> &ts, vector<double>& x_ts, vector<double> &y_ts){
    
    ifstream infile(filename);

    double t, x, y;
    while(infile >> t >> x >> y){
        ts.push_back(t);
        x_ts.push_back(x);
        y_ts.push_back(y);
    }

    infile.close();
    return true;
}

// functoin for norm
vector<double> compute_norm(vector<double> &x_ts, vector<double> &y_ts){
    
    vector<double> norms;

    // looping through the input values of x(t), y(t)
    for(int i=0; i<x_ts.size(); i++){
        norms.push_back(sqrt(x_ts[i]*x_ts[i] + y_ts[i]*y_ts[i]));
    }

    return norms;
}

// function for moving average
vector<double> compute_moving_average(vector<double> &data, int n){

    vector<double> moving_avg;
    
    double sum = 0.0;
    int cnt = 0;

    for(int i=0; i<data.size(); i++){
        sum+=data[i];
        cnt++;

        // moving sum if cnt>=n=5, remove 0th [* X X X X] element in the window
        if(cnt>=n){
            moving_avg.push_back(sum/n);
            sum-=data[i-(n-1)];
        } else{
            moving_avg.push_back(sum/cnt); // moving avg assuming previous window elements = 0
        }
    }

    return moving_avg;
}

// function for output file dump
bool write_data(string &filename, vector<double> &norms,  vector<double> &ts){
    
    ofstream outfile(filename);

    outfile << "Moving Avg Norms" << "\t" << "Moving Average Times" << "\n";
    for(int i = 0; i < ts.size(); ++i){
        outfile << norms[i] << "\t\t\t" << ts[i] << "\n";
    }

    outfile.close();
    return true;
}

// main
int main(int argc, char* argv[]){

    // input data initialization
    string input_file = argv[1];
    string output_file = argv[2];
    int n = stoi(argv[3]);

    // initializing t, x(t), y(t)
    vector<double> ts, x_ts, y_ts;

    // file not empty
    if(!read_data(input_file, ts, x_ts, y_ts)){
        return 1;
    }

    // compute norm and moving averages
    vector<double> norms = compute_norm(x_ts, y_ts);
    vector<double> avg_norms = compute_moving_average(norms, n);
    vector<double> avg_times = compute_moving_average(ts, n);

    // writing to output.txt
    if(!write_data(output_file, avg_norms, avg_times)){
        return 1;
    }

    // program run completion
    cout << "Execution complete. Results saved." << endl;
    return 0;
}
