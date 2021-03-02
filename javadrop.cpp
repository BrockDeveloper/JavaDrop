/*
* Brock DEV
* See LICENSE file.
*
* Developed by
* Brock DEV (https://github.com/BrockDeveloper).
*
*
* This source code is distributed under the CC BY-NC-SA 4.0 license:
* https://creativecommons.org/licenses/by-nc-sa/4.0/
* you are FREE to SHARE and ADAPT UNDER THE FOLLOWING TERMS:
* 
* ATTRIBUTION You must give appropriate credit, provide a link to the
* license, and indicate if changes were made.
*
* NON COMMERCIAL You may not use the material for commercial purposes.
*
* SHARE ALIKE If you remix, transform, or build upon the material, you
* must distribute your contributions under the same license as the original.
*
*
* This source code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY.
*/

#include <iostream>
using namespace std;

//extension of a valid executable file
const string VALID_EXT = "jar";

//verify that the file is executable, i.e. that the extension is correct
bool file_is_valid(string );

//the file is received as an argument argv[1]
int main(int argc, char *argv[])
{
    //check that there is an argument
    if(argv[1]!=NULL)
    {
        //converting the file path to a string
        string file_path(argv[1]);

        //if the file extension is valid
        if(file_is_valid(file_path))
        {
            //builds the command to execute the file
            string cmd = "java -jar \"";
            cmd.append(file_path);
            cmd.append("\"");

            //executes the command
            system(cmd.c_str());

            //at the end of the execution, it notifies the end of the program
            cout<<endl;
            cout<<"JavaDrop: Execution finished."<<endl;
            system("pause");
        }
        else
        {
            //if the file extension is not valid
            cout<<"JavaDrop: No jar file was found to run."<<endl;
            system("pause");
        }
    }
    else
    {
        //if there isn't an argument
        cout<<"JavaDrop: No jar file was found to run."<<endl;
        system("pause");
    }
}


bool file_is_valid(string file_path)
{
    //searches for the beginning of the file extension
    int index = file_path.find_last_of('.');

    //if there is no extension, the file is invalid
    if(index == -1)
        return false;

    //gets the file extension
    string ext = file_path.substr(index+1,file_path.length());

    //if the extension is valid, the file can be executed
    return (ext == VALID_EXT) ? true : false;
}
