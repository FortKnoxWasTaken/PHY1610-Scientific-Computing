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
            moving_avg.push_back(sum/cnt);
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
