#ifndef UTIL_FS_H
#define UTIL_FS_H

#include <string>
#include <sstream>
#include <stdio.h>

namespace util::fs{

static bool file_exists(const std::string& filename){
    FILE* fp=fopen(filename.c_str(),"r");
    if(fp){
        fclose(fp);
        return true;
    }
    return false;
}

static bool service_file_exists(const std::string& service_name){
    std::stringstream ss;
    ss<<"/etc/systemd/system/"<<service_name<<".service";
    return file_exists(ss.str());
}

}
#endif // UTIL_FS_H
