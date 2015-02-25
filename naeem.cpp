 /*
  * Prog Tools for Scits Engrs - CIVL 8903/7903 001
  * Prof. Ricardo Taborda
  * Homework 4
  * Written by : Naeem Khoshnevis (nkhshnvs@memphis.edu)
  * Feb 21 , 2015 
  * https://github.com/Naeemkh/ProgTools-HMWRK4.git
  */

 #include <iostream>
 #include <fstream>
 #include <string>
 #include <iomanip>
 #include <sstream>
 #include <cstdlib>

 using namespace std;

 /***************************** function prototypes *************************************/

 void print_output(ofstream&, ostream&,  string);
 void open_input(ifstream&, ofstream&, string);
 void open_output(ofstream&, ofstream&, string);
 void open_output(ofstream&, string);

/********************************* main function ****************************************/

 int main() {
     
     int N,M,i,j,W,BS,NC;
     
     string Fp,Ns;
     
     unsigned long long int F_1=0, F_2=1, F_3;
  
     ifstream inputfile;
     ofstream outputfile;
     ofstream errorfile;
           
     open_input(inputfile,errorfile,"naeem.in");
     open_output(outputfile,errorfile,"naeem.out");
     
     // read the from file.
     inputfile >> Ns;
          
     // convert the string to integer
     N = atoi(Ns.c_str());
     
     // convert the integer to string
     ostringstream os1;
     os1 << N;
     string Ns2 = os1.str();
         
     if (Ns.size() != Ns2.size() || N < 1){
         
         open_output(errorfile, "naeem.err");
         print_output(errorfile, cout,"Input parameter is not valid. Try a number greater than 1.\n");
         errorfile.close();
         exit(1);
     }
     
     M=N*10;
     
     string par_1="I was able to compile this code using the HPC at the University of Memphis."
                  " When I compiled it there, it did not produce any warning message." 
                  " The HPC uses a GNU C++ compiler that can be considered a good up-to-date standard." 
                  " I also version-controlled this code using git, and used a remote repository hosted "  
                  "by github. If I can do this, so can you!!!";

     string par_2 = "I am so cool, that I was also able to write a code that produces the first ";
     string par_3 = " numbers of the Fibonacci sequence. Here they are: ";
     
     ostringstream os2;
     os2 << M;
     string ss = os2.str();     
     
     print_output(outputfile, cout, "\n");
     print_output(outputfile, cout, par_1);
     print_output(outputfile, cout, "\n\n");
     print_output(outputfile, cout, par_2);
     print_output(outputfile, cout, ss);
     print_output(outputfile, cout, par_3);
     print_output(outputfile, cout, "\n\n");
     
     // I came up with the number 5 through try and error.
     W = (M/5+2);
     
     for (i = 0; i < M; i++) {
         
         if (i < 2) {
             F_3 = i;
         } else {
             F_3 = F_1 + F_2;
         }
    
     if (i%10 == 0) {
         print_output(outputfile, cout,  "\n");
     }
     
      
     ostringstream os3;
     os3 << F_3;
     string Fp = os3.str();

     NC = Fp.size();
     print_output(outputfile, cout, Fp);
     BS = W - NC;
     
     for (j=0; j<BS; j++) {
         print_output(outputfile, cout," ");
     }
         
         F_1 = F_2;
         F_2 = F_3;
     }
     
     print_output(outputfile, cout, "\n");
     
     // Closing files
     inputfile.close();
     outputfile.close();
     
     return 0;

 }

/********************************* function definition **********************************/

void print_output(ofstream & output1, ostream & output2, string string1) {
    
    output1  <<  string1;
    output2  <<  string1;
}

void open_input(ifstream & inputfile, ofstream & errorfile, string inputfilename){
    
    inputfile.open(inputfilename.c_str());
    if (!inputfile.is_open()) {
        
        open_output(errorfile, "naeem.err");
        print_output(errorfile, cout,"Cannot open input file: ");
        print_output(errorfile, cout, inputfilename);
        print_output(errorfile, cout, "\n");
        errorfile.close();
        exit(1);
    }
}

void open_output(ofstream& outputfile,ofstream& errorfile, string outputfilename){

    outputfile.open(outputfilename.c_str());
    if (!outputfile.is_open()) {
        
        open_output(errorfile, "naeem.err");
        print_output(errorfile, cout,"Cannot open input file: ");
        print_output(errorfile, cout, outputfilename);
        print_output(errorfile, cout, "\n");
        errorfile.close();
        exit(1);
    }
}

void open_output(ofstream& errorfile, string errorfilename){

    errorfile.open(errorfilename.c_str());
    if (!errorfile.is_open()) {
 	
        cout << "Cannot open error file: " << errorfilename;
       
    }
}

