//
//  main.cpp
//  Fixed Rec to Delimited File
//  This program takes in a fixed rec file, a spec file, a delimiter
//  and creates a delimited file
//  Created by Atul Saurav on 4/2/14.
//  Copyright (c) 2014 Atul Saurav. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct recSpec {
  string fieldname;
  int offset;
  int length;
  recSpec(string f, int o, int l): fieldname(f), offset(o), length(l) {}
};

vector<recSpec> readSpecFile (string);

int main(int argc, const char * argv[])
{
  cout << "Hello World!" << endl;
  string specfile, infile, outfile;
  char delim;
  cout << "Enter the specfile name: ";
  cin >> specfile;
  cout << "Enter the input file name: ";
  cin >> infile;
  cout << "Enter the outfile name: ";
  cin >> outfile;
  cout << "Enter the delimiter ";
  cin >> delim;
  vector<recSpec> fields;
  fields = readSpecFile(specfile);
  for (auto reci: fields)
    cout << "Field: " <<reci.fieldname <<" , offset: " << reci.offset << " , length: " << reci.length << endl;
  return 0;
}

vector<recSpec> readSpecFile (string sFile ) {
  ifstream ist(sFile);
  vector<recSpec> fields;
  string fieldname;
  int a, b, offset = 0;
  if (!ist) {
    cout << "Error reading specfile" << endl;
  }
  else {
    while (ist >> fieldname >> a >> b ) {
      fields.push_back(recSpec(fieldname, offset, a+b));
      offset = offset + a + b;
    }
  }
  return fields;
}
