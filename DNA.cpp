#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <algorithm>
#define _USE_MATH_DEFINES

using namespace std;

double gaussianLength (double mean, double deviation){
    double aRand = ((double) rand() / (RAND_MAX));
    double bRand = ((double) rand() / (RAND_MAX));
    // Create two random values in a double type

    // Mimics the muller formula detailed in the assignment description
    double muller = sqrt(-2*log10(aRand));

    // Mimics the distrubtion formula detailed in the assignment description
    double distribution = deviation*muller + mean;
    return distribution;
}

int main()
{
  int cont = 1;
  int first = 0;
  while (cont == 1) // Loop for asking user if they want to continue
  {
    // VARIABLE DECLARATIONS
    ifstream inFile; // Taking in the File
    ofstream myFile ("alexrigl.out"); // Outputting a file with strings
    // Relative distributions of nucleotides, and their bigrams
    double A = 0;
    double T = 0;
    double G = 0;
    double C = 0;
    double AT = 0;
    double AG = 0;
    double AC = 0;
    double AA = 0;
    double TA = 0;
    double TG = 0;
    double TT = 0;
    double TC = 0;
    double GA = 0;
    double GC = 0;
    double GT = 0;
    double GG = 0;
    double CA = 0;
    double CT = 0;
    double CC = 0;
    double CG = 0;
    double random = 0; // definining two random variables
    double random2 = 0;

    int stringLength = 0; // the length of a specific string
    int totalLength = 0; // the added up lengths of the strings
    int stringCounter = 0; // the amount of strings aka the amount of lines
    int lineSize;
    double deviation = 0; // standard deviation
    double variance = 0; // variance
    double mean; // mean
    string fileName;
    // END OF VARIABLE DECLARATION

    //cout << "Please enter the txt file you want to parse" << endl;
    //cin >> fileName;
    // inFile.open (fileName);
    inFile.open("dnastrings.txt"); //opens a file in my directory
    if (!inFile) {
      cerr << "Unable to open file dnastrings.txt" << endl;;
      exit(1);
    }

    for( std::string line; getline( inFile, line ); ) // parse through each line in the text file
    {
      for (int i = 0; i < line.length(); i++){ // go through the length of the line
        transform(line.begin(), line.end(), line.begin(), ::toupper);
        if (line[i] == 'A'){ // checks the index of the string
          A++;
          stringLength++;
          if (line[i+1] == 'T'){ // checks the next index of the string
            AT++; // counts the number of times for the bigram
            T++;
            i++; // adds more to the counter, since we used i + 1
            stringLength++; // counts the number of characters, which will be added onto later
          }
          if (line[i+1] == 'G'){
            AG++;
            G++;
            i++;
            stringLength++;
          }
          if (line[i+1] == 'C'){
            AC++;
            C++;
            i++;
            stringLength++;
          }
          if (line[i+1] == 'A'){
            AA++;
            A++;
            i++;
            stringLength++;
          }
        }
        // Does the same process for all of the nucleotides, and their bigrams
        if (line[i] == 'T'){
          T++;
          stringLength++;
          if (line[i+1] == 'A'){
            TA++;
            i++;
            A++;
            stringLength++;
          }
          if (line[i+1] == 'T'){
            TT++;
            i++;
            T++;
            stringLength++;
          }
          if (line[i+1] == 'G'){
            TG++;
            i++;
            G++;
            stringLength++;
          }
          if (line[i+1] == 'C'){
            TC++;
            i++;
            C++;
            stringLength++;
          }
        }
        if (line[i] == 'G'){
          G++;
          stringLength++;
          if (line[i+1] == 'A'){
            GA++;
            i++;
            A++;
            stringLength++;
          }
          if (line[i+1] == 'T'){
            GT++;
            i++;
            T++;
            stringLength++;
          }
          if (line[i+1] == 'G'){
            GG++;
            i++;
            G++;
            stringLength++;
          }
          if (line[i+1] == 'C'){
            GC++;
            i++;
            C++;
            stringLength++;
          }
        }
        if (line[i] == 'C'){
          C++;
          stringLength++;
          if (line[i+1] == 'A'){
            CA++;
            i++;
            A++;
            stringLength++;
          }
          if (line[i+1] == 'T'){
            CT++;
            i++;
            T++;
            stringLength++;
          }
          if (line[i+1] == 'G'){
            CG++;
            i++;
            G++;
            stringLength++;
          }
          if (line[i+1] == 'C'){
            CC++;
            i++;
            C++;
            stringLength++;
          }
        }
      }
      totalLength = totalLength + stringLength; // adds the length of the strings together, becomes the sum
      stringCounter = stringCounter + 1; // counts the number of strings
      mean = totalLength / stringCounter; // divides the sum by the amount of strings
      variance += pow(((stringLength - mean)),2); // adds the variances of all the stings together
      stringLength = 0; // resets the string length
    }
    deviation = sqrt(variance); // standard deviation, simply just the square root of the variance

    /// Finds the probabilities of the nucleotides by dividing the count of each one by the total amount
    A = A / totalLength;
    T = T / totalLength;
    G = G / totalLength;
    C = C / totalLength;

    // finds the probabilities of the nucleotide bigrams by dividing the count of each one by the amount of bigrams
    AT = AT / (totalLength/2);
    AA = AA / (totalLength/2);
    AG = AG / (totalLength/2);
    AC = AC / (totalLength/2);
    GT = GT / (totalLength/2);
    GA = GA / (totalLength/2);
    GG = GG / (totalLength/2);
    GC = GC / (totalLength/2);
    CT = CT / (totalLength/2);
    CA = CA / (totalLength/2);
    CG = CG / (totalLength/2);
    CC = CC / (totalLength/2);
    TA = TA / (totalLength/2);
    TT = TT / (totalLength/2);
    TG = TG / (totalLength/2);
    TC = TC / (totalLength/2);

    // Print out summary statistics and information to the file
    myFile << "Name: Alex Rigl" << endl << "ID: 2300146" << endl << "Class CPSC350" << endl;
    myFile << "Section: 2" << endl << "Date due: 9/13/2018" << endl;
    myFile << "A= " << A << " T= " << T << " G= " << G << " C= " << C << endl;
    myFile << "AA = " << AA << " AT = " << AT << " AG = " << AG << " AC = " << AC << endl;
    myFile << "GT = " << GT << " GA = " << GA << " GG = " << GG << " GC = " << GC << endl;
    myFile << "CT = " << CT << " CA = " << CA << " CC = " << CC << " CG = " << CG << endl;
    myFile << "TA = " << TA << " TT = " << TT << " TG = " << TG << " TC = " << TC << endl;
    myFile << "The sum is " << totalLength << endl;
    myFile << "The mean is " << mean << endl;
    myFile << "The standard deviation is " << deviation << endl;
    myFile << "The variance is " << variance << endl;

    //// CREATING THE OUTPUT STRINGS /////
    /// Changes the bigrams so that all the 'A' bigrams, etc., will add up to 100
    AT = (AT*100)/(A*100);
    AA = (AA*100)/(A*100);
    AG = (AG*100)/(A*100);
    AC = (AC*100)/(A*100);
    TT = (TT*100)/(T*100);
    TA = (TA*100)/(T*100);
    TG = (TG*100)/(T*100);
    TC = (TC*100)/(T*100);
    GT = (GT*100)/(G*100);
    GA = (GA*100)/(G*100);
    GG = (GG*100)/(G*100);
    GC = (GC*100)/(G*100);
    CT = (CT*100)/(C*100);
    CA = (CA*100)/(C*100);
    CG = (CG*100)/(C*100);
    CC = (CC*100)/(C*100);

    for (int i = 0; i < 1000; i++){ // Creates 1000 random strings based on the probabilties
      int length = gaussianLength(mean, deviation);
      string DNA = string(length, '*');

      for (int i = 0; i < length; i++){
        random =  (double)rand() / (double)RAND_MAX ; // random double for nucleotides
        random2 = (double)rand() / (double)RAND_MAX ; // random double for bigrams
        //cout << "Random: " << random << endl;

        if (A > random){ // if the probabilty of A is greater than the random number use A
          DNA[i] = 'A';
          if (AT > random2){ // do the same with a different random number for the bigrams
            DNA[i+1] = 'T';
            i++;
            continue;
          }
          if (AT + AA > random2){
            DNA[i+1] = 'A';
            i++;
            continue;
          }
          if (AT + AA + AG > random2){
            DNA[i+1] = 'G';
            i++;
            continue;
          }
          else{
            DNA[i+1] = 'C';
            i++;
            continue;
          }
          i++;
          // end loop if hit
          continue;
        }
        if (A + G > random){ // if the probability of A + G is greater than the random number, use G
          DNA[i] = 'G';
          if (GT > random2){
            DNA[i+1] = 'T';
            i++;
            continue;
          }
          if (GT + GA > random2){
            DNA[i+1] = 'A';
            i++;
            continue;
          }
          if (GT + GA + GG > random2){
            DNA[i+1] = 'G';
            i++;
            continue;
          }
          else{
            DNA[i+1] = 'C';
            i++;
            continue;
          }
          i++;
          continue;
        }
        if (A + G + T > random){ // if the probability of A + G + T is greater than the random number, use T
          DNA[i] = 'T';
          if (TT > random2){
            DNA[i+1] = 'T';
            i++;
            continue;
          }
          if (TT + TA > random2){
            DNA[i+1] = 'A';
            i++;
            continue;
          }
          if (TT + TA + TG > random2){
            DNA[i+1] = 'G';
            i++;
            continue;
          }
          else{
            DNA[i+1] = 'C';
            i++;
            continue;
          }
          i++;
          continue;
        }

        else{ // if the probability of A + G + T + C is greater than the random number, use C ; this accounts of anything else
          DNA[i] = 'C';
          if (CG > random2){
            DNA[i+1] = 'G';
            i++;
            continue;
          }
          if (CG + CA > random2){
            DNA[i+1] = 'A';
            i++;
            continue;
          }
          if (CG + CA + CT > random2){
            DNA[i+1] = 'T';
            i++;
            continue;
          }
          else{
            DNA[i+1] = 'C';
            i++;
            continue;
          }
          i++;
          continue;
        }
    } // first for loop
    myFile << DNA << endl; // prints the DNA string to the file
   } // second for loop
   cout << "Would you like to try with another file? 0 for no, 1 for yes" << endl; // asks if you would like to continue with another file
   cin >> cont;
  }
  return 0;
} // int main
