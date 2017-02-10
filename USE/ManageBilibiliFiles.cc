#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	string root;
	cin >> root;
	vector<string>files;
	GetAllFiles(root, files);
	return 0;
}
void move(char src[], char dest[]) {
	cmd[600];
	char copy[] = "move";
	gets(src);
	gets(dest);
	strcpy(cmd, copy);
	strcat(cmd, " \"");
	strcat(cmd, src);
	strcat(cmd, "\" \"");
	strcat(cmd, dest);
	strcat(cmd, "\"");
	system(cmd);
}



//获取所有的文件名
void GetAllFiles( string path, vector<string>& files)
{

	long   hFile   =   0;
	//文件信息
	struct _finddata_t fileinfo;//用来存储文件信息的结构体
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) !=  -1) //第一次查找
	{
		do
		{
			// if ((fileinfo.attrib &  _A_SUBDIR)) //如果查找到的是文件夹
			// {
			// 	if (strcmp(fileinfo.name, ".") != 0  &&  strcmp(fileinfo.name, "..") != 0) //进入文件夹查找
			// 	{
			// 		files.push_back(p.assign(path).append("\\").append(fileinfo.name) );
			// 		GetAllFiles( p.assign(path).append("\\").append(fileinfo.name), files );
			// 	}
			// }
			// else //如果查找到的不是是文件夹
			// {
			// 	files.push_back(p.assign(fileinfo.name) );  //将文件路径保存，也可以只保存文件名:    p.assign(path).append("\\").append(fileinfo.name)
			// }

			files.push_back(p.assign(fileinfo.name) );

		} while (_findnext(hFile, &fileinfo)  == 0);

		_findclose(hFile); //结束查找
	}

}

//获取特定格式的文件名
void GetAllFormatFiles( string path, vector<string>& files, string format)
{
	//文件句柄
	long   hFile   =   0;
	//文件信息
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*" + format).c_str(), &fileinfo)) !=  -1)
	{
		do
		{
			if ((fileinfo.attrib &  _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0  &&  strcmp(fileinfo.name, "..") != 0)
				{
					//files.push_back(p.assign(path).append("\\").append(fileinfo.name) );
					GetAllFormatFiles( p.assign(path).append("\\").append(fileinfo.name), files, format);
				}
			}
			else
			{
				files.push_back( p.assign(fileinfo.name));  //将文件路径保存，也可以只保存文件名:    p.assign(path).append("\\").append(fileinfo.name)
			}
		} while (_findnext(hFile, &fileinfo)  == 0);

		_findclose(hFile);
	}
}
