#ifndef XVG_PARSER_H
#define XVG_PARSER_H
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
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;


class xvg_Parser
{
public:
    xvg_Parser(string input_2dproj_name, double dx, int index ,double max_pca_in, double min_pca_in);
    int index_line;
    string inputfile_set;
    vector < vector < double > > dproj;
    double max_pca;
    double min_pca;
    vector < double > probability;
    void integrator ();
    void Binner (double dx, double max_pca_in, double min_pca_in);
    double s_2dproj_n;
    double s_2dproj_n_trapezoidal;


};

#endif // XVG_PARSER_H
