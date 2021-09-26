#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <map>
#include <io.h>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <sstream>
using namespace std;

map<string,string>id2name;

int main(){
    string indpath;
    string path2findPdfs;
    string pathOfPdfs;
    ifstream indfile;

    cout << "输入序号文件所在路径（包含文件名）：" << endl;
    cin >> indpath;
    while(indfile.open(indpath.c_str()), !indfile){
        cout << "文件打开失败，请重新输入序号文件所在路径（包含文件名）：" <<endl;
        cin >> indpath;
    }

    
    string nums, names;
    int ind = 1;
    while(!indfile.eof()){
        nums = "";
        indfile >> names;
        stringstream ss;
        ss << ind;
        ss >> nums;
        cout << names << "'s id is " << nums << endl;
        id2name[nums] = names;
        ++ind;
    }

    cout << "输入pdf文件所在目录路径：" << endl;
    cin >> pathOfPdfs;
    pathOfPdfs = pathOfPdfs;
    if(pathOfPdfs[pathOfPdfs.length()-1] != '\\'){
        pathOfPdfs.append("\\");
    }
    path2findPdfs = pathOfPdfs + "*";

    intptr_t handle;
    _finddata_t findData;
    handle = _findfirst(path2findPdfs.c_str(), &findData);
    while(handle == -1){
        cout << "pdf路径有误！请重新输入pdf文件所在目录路径：" << endl;
        cin >> path2findPdfs;
        if(path2findPdfs[path2findPdfs.length()-1] != '\\'){
            path2findPdfs.append("\\");
        }
        path2findPdfs.append("*");

        intptr_t handle;
        _finddata_t findData;
        handle = _findfirst(path2findPdfs.c_str(), &findData);
    }

    do{
        if(!strcmp(findData.name, ".") || !strcmp(findData.name, "..")){continue;}

        string pdfnames(findData.name);
        string filetype = pdfnames.substr(pdfnames.find_last_of('.')+1);
        string orifiletype(filetype);
        transform(filetype.begin(), filetype.end(), filetype.begin(), ::toupper);

        if(!strcmp(filetype.c_str(), "PDF")){
            cout << "处理" << pdfnames << "中...";
            int numIndS = pdfnames.find_first_of('_')+1, numIndE = pdfnames.find_last_of('_');
            string nameNum = pdfnames.substr(numIndS, numIndE-numIndS);
            cout << "num is " << nameNum << endl;
            string newName = id2name[nameNum] + "." + orifiletype;
            if(_access((pathOfPdfs+pdfnames).c_str(), 0)){cout << "file not exits" << endl;}
            rename((pathOfPdfs+pdfnames).c_str(), (pathOfPdfs+newName).c_str());
            cout << "已重命名为：" << newName << "。" << endl;
        }

    }while(_findnext(handle, &findData) != -1);
    _findclose(handle);
    cout << "Over."<<endl;

    system("pause");
    return 0;
}