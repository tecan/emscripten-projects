#include <iostream>
#include <fstream>

//emcc directoryList.cpp -o test.html

static void list_dir(const char *path)
{
    struct dirent *entry;
    DIR *dir = opendir(path);
    if (dir == NULL) {
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n",entry->d_name);
    }

    closedir(dir);
}


int main()
{

	if((f_trans != stdout) && (f_trans != stderr))
		fclose(f_trans);  // needed for WinCe

mkdir("/test");

//    fstream fs;
//    fs.open("/test", ios::out);
//    fs << "Writing this to a file.\n";
//    fs.close();

list_dir("/");

}
