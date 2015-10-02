/*
 * driver.cpp
 *
 *  Created on: Sep 22, 2015
 *      Author: jb
 *      Description: This program concatenates multiple
 *      files in a directory into one
 *      Usage: dircat DIRECTORY... OUTPUT...
 */

#include "driver.h"

int main(int argc, char* argv[])
{
      // Variable declarations
      DIR* dir;
      struct dirent* entry;
      stringstream ss;
      int i = 1, argEnd = argc - 1;
      unsigned char isFile =0x8;
      string dirarg, dirname, dirwild, outname = argv[argEnd];

      // Validate the usage
      if(argc < 3)
      {
         cout << "dircat: missing operand\n"
               << "Usage: dircat DIRECTORY... OUTPUT...\n";
               return 1;
      }

      // If the first argument is a directory assign it directly
      if(fileType(argv[1]) == "Directory") {
         dirname = argv[1];
      }
      // Else if the files are in the current directory get the current directory
      else if(parseDir(argv[1]) == "") {
         dirname = getCurrDir();
      }
      // Else parse the directory from the first argument
      else {
         dirname = parseDir(argv[1]);
      }

      // Try to open the directory
      dir = opendir(dirname.c_str());

      // If the directory doesn't exist exit and return an error
      if(!dir)
      {
         perror("opendir");
         return 1;
      }

      // If the first arg is a directory concatenate all contents
      if(fileType(argv[1]) == "Directory") {
         while((entry = readdir(dir)) != NULL) {

            // Check if it's a file
            if(entry->d_type == isFile)
            {
               // Clear the string stream and build the cat command
               ss.str(string());
               ss << "cat " << dirname << "/" << entry->d_name << " >> " << outname << "\n";

               // Convert the string to a c-string
               const string tmpstr = ss.str();
               const char* cstr = tmpstr.c_str();

               // Execute the command
               system(cstr);
               cout << "Concatenating: " << entry->d_name << "\n";
            }
         }
      }
      // Else if the first argument is a file check for wild cards and concatenate
      else {
         for(i = 1; i < argEnd; i++) {

            // If it is allowed then concatenate the file
            if(fileType(argv[i]) == "File") {
               // Clear the string stream and build the cat command
               ss.str(string());
               ss << "cat " << argv[i] << " >> " << outname << "\n";

               // Convert the string to a c-string
               const string tmpstr = ss.str();
               const char* cstr = tmpstr.c_str();

               // Execute the command
               system(cstr);
               cout << "Concatenating: " << parseFile(argv[i]) << "\n";
            }
         }
      }

      // Close the directory
      if(closedir(dir) == -1)
      {
         perror("closedir");
         return 1;
      }

      // Exit the program
      return 0;
}


