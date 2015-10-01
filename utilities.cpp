/*
 * utilities.cpp
 *
 *  Created on: Sep 30, 2015
 *      Author: jb
 *      Description: This is a source file for utility functions
 *      for the dircat program
 */

#include "utilities.h"

// This function parses the directory from the string
string parseDir(const string iPath) {

   // Variable declarations
   string oPath = "";
   int k;
   bool dirFlag = false;

   // Working backwards get the last directory
   for(k = (iPath.length() - 1); k >= 0; k--) {

      // Check if the first next has been found
      if(iPath[k] == '/') {
         dirFlag = true;
      }

      // Check if you can start building the path
      if(dirFlag == true) {
         oPath = iPath[k] + oPath;
      }
   }
   return oPath;
}

// This function parses the file from the string
string parseFile(const string iPath) {

   // Variable declarations
   string oPath = "";
   int k;

   // Working backwards get the last directory
   for(k = (iPath.length() - 1); k >= 0; k--) {

      // Check if the first next has been found
      if(iPath[k] == '/') {
         break;
      }

      // Build the filename
      oPath = iPath[k] + oPath;
   }
   return oPath;
}

// This returns the type of the input file
string fileType(const string iPath) {

   // Variable declaration
   struct stat s;

   // Attempt to open the stat and check for errors
   if(stat(iPath.c_str(), &s) == 0) {

      // Check the type
      if(s.st_mode & S_IFDIR) {
         return "Directory";
      }
      else if(s.st_mode & S_IFREG) {
         return "File";
      }
      else if(s.st_mode & S_IFBLK) {
         return "Block Special";
      }
      else if(s.st_mode & S_IFCHR) {
         return "Character Special";
      }
      else if(s.st_mode & S_IFIFO) {
         return "FIFO Special";
      }
      else if(s.st_mode & S_IFLNK) {
         return "Symbolic Link";
      }
      else if(s.st_mode & S_IFSOCK) {
         return "Socket";
      }
      else {
         return "Error: Unable to Determine Type";
      }
   }
   else {
      return "Error: Unable to Determine Type";
   }

}


