# dircat
A C++ command that concatenates all or a selected set of files within a directory into one file.

Author:
Jonathon Bowring

Date:
1st October 2015

Usage:
dircat DIRECTORY... OUTPUT...

Notes:
- The DIRECTORY argument also works with wild cards to select certain files for concatenation. Tested with Ubuntu 14.04.

Installation:
1. Download all of the files into one directory.
2. Execute the "make" command.
3. Copy the executable to the appropriate bin directory. E.g. "cp dircat /usr/bin".
 
Examples:
- dircat dir/ output.out
- dircat dir output.out
- dircat dir/ dir/output.out
- dircat dir dir/output.out
- dircat dir/*.txt output.out
