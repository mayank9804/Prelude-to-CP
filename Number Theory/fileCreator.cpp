#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main(int argc, char const *argv[]){
    
    if(argc!=2){
        cout<<"Too few arguments\n";
        cout<<"Usage: ./filecreate [FILENAME]\n";
        return 0;
    }else{
        string fileName = argv[1];
        fileName+=".cpp";
        string temp =   "/* Author: Mayank Sharma\n\
email: mayank04111998@gmail.com\n\
*/\n\
#include <bits/stdc++.h>\n\
using namespace std;\n\
#define FAST ios_base::sync_with_stdio(false);\\\n\
cin.tie(NULL);\n\
#define TEST int T;\\\n\
cin>>T;\n\
#define FORI(i,a,b) for(int i=a;i<b;i++)\n\
#define FORD(i,a,b) for(int i=a;i>=b;i--)\n\
#define ci pair<char,int>\n\
#define pb push_back\n\
typedef unsigned long long ull;\n\n\n\
int main(int argc, char const *argv[]){\n\
\n\n\
    return 0;\n\
}\n";
        fstream o(fileName,ios::out);
        o<<temp;
        o.close();
        string tempFileName="";
        for(int i=0;i<fileName.size();i++){
            if(fileName[i]!=32){
                tempFileName+=fileName[i];
            }else{
                tempFileName+="\\ ";
            }
        }
        
        string cmd = "code "+tempFileName;

        system(cmd.c_str());
    }
    return 0;
}

