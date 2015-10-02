/*
 * utilities.h
 *
 *  Created on: Sep 30, 2015
 *      Author: jb
 *      Description: This is a source file for utility functions
 *      for the dircat program
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <string>
#include <stdio.h>
#include <iostream>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

// Function declarations
string parseDir(const string iPath);
string parseFile(const string iPath);
string fileType(const string iPath);
string getCurrDir();


#endif /* UTILITIES_H_ */
