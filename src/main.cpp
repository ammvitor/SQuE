#include <iostream>
#include<vector>
#include<iostream>
#include<fstream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<time.h>
#include <iostream>
#include <iomanip>
#include<algorithm>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <getopt.h>
#include "xvg_parser.h"

using namespace std;

int main(int argc, char *argv[])
{
    int c;
    double bin_width;
    string inputfile_set;

    while ((c = getopt(argc, argv, "i:b:h")) != -1){



            switch (c){
            case 'i':
                inputfile_set = string(optarg);
                break;
            case 'h':
                printf("Usage -i <2dproj_list> -b <bin_size> \n");
                exit(1);
            case 'b':
                bin_width = stod(string(optarg));
                break;
            }

    }
if (argc < 2){
                printf("Usage -i <2dproj_list> -b <bin_size> \n");
            exit(1);
}
    ifstream counter(inputfile_set.c_str());
    string line;
    vector <double > entropy_per_PC;
    double main_max_pca=0;
    double main_min_pca=0;

    double total_entropy = 0;
    int index_line=0;
    while(getline(counter, line)){
        xvg_Parser* PCA_object = new xvg_Parser(line,bin_width,index_line,main_max_pca,main_min_pca);
        entropy_per_PC.push_back(PCA_object->s_2dproj_n);
        total_entropy = total_entropy+PCA_object->s_2dproj_n ;
        cout << PCA_object->s_2dproj_n << endl;
        main_max_pca = PCA_object->max_pca;
        main_min_pca = PCA_object->min_pca;
        index_line++;
    }
    cout<< "Entropy Calculated S= " << total_entropy << endl;
    cout<< "K*T*S= " << 0.001987*300*total_entropy << endl;

    return 0;
}
