#include "xvg_parser.h"

xvg_Parser::xvg_Parser(string input_2dproj_name, double dx, int index, double max_pca_in, double min_pca_in)
{
    this->index_line = index;
    this->inputfile_set = input_2dproj_name;
    ifstream counter(inputfile_set.c_str());
    string line;
    vector < double> vec_temp;
    double X1, X2;
    if(!counter) {
      cout << "Cannot open input file.\n";
       exit (EXIT_FAILURE);
    }
    string a  ;
    while(getline(counter, line)) {
        a = line.at(0);
       if ( a != "#" && a != "@" ){
        stringstream ss(line.c_str());
        ss >>  X1 >> X2 ;
        vec_temp.push_back(X1);
        vec_temp.push_back(X2);
        this->dproj.push_back(vec_temp);
        vec_temp.clear();
        }
    }
    counter.close();
    this->Binner(dx,max_pca_in,min_pca_in);
    this->integrator();

}

void xvg_Parser::Binner (double dx, double max_pca_in, double min_pca_in){
   //if(true){

    for(int i =0; i < this->dproj.size(); i++){
        if(i ==0){
            this->max_pca = this->dproj[0][0];
            this->min_pca = this->dproj[0][0];
        }
        else if(this->dproj[i][0] > max_pca){
            this->max_pca = this->dproj[i][0];
        }
        else if(this->dproj[i][0] < min_pca){
            this->min_pca = this->dproj[i][0];
        }
    }

   //else{
   //   this->max_pca = max_pca_in;
   //    this->min_pca = min_pca_in;

   //}
   cout  << this->max_pca << " " << this->min_pca << endl;
    double number_of_bins= (this->max_pca-this->min_pca)/dx;
    for(int k =0; k < number_of_bins; k++){
        this->probability.push_back(0);
    }


    for(int k =0; k < this->dproj.size(); k++){
        this->probability[floor((dproj[k][0]-this->min_pca)/dx)] = this->probability[floor((dproj[k][0]-this->min_pca)/dx)] + 1;
    }

    for(int k =0; k < number_of_bins; k++){
        this->probability[k] = this->probability[k]/this->dproj.size();
    }


}


void xvg_Parser::integrator (){

    this->s_2dproj_n =0;



    for(int i =0; i < this->probability.size(); i++){
            if(this->probability[i] != 0){
            s_2dproj_n = s_2dproj_n + this->probability[i]*log(this->probability[i]);
            }

    }
    s_2dproj_n = -s_2dproj_n;
    //cout << "entropy " << s_2dproj_n << endl;

}
