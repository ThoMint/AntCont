#ifndef SFFIPS
#define SFFIPS

#include "Arduino.h"
#include <FS.h>
#include <SPIFFS.h>

void initSpiffs(boolean formatSpiffsIfFailed);
File openFile(fs::FS &fs, const char* path);
String getText(fs::FS &fs, const char* path);
void listDir(fs::FS &fs, const char * dirname, uint8_t levels);
void readFile(fs::FS &fs, const char * path);
void writeFile(fs::FS &fs, const char * path, String message);
void appendFile(fs::FS &fs, const char * path, const char * message);
void renameFile(fs::FS &fs, const char * path1, const char * path2);
void deleteFile(fs::FS &fs, const char * path);

//listDir(SPIFFS, "/", 0);
//writeFile(SPIFFS, "/hello.txt", "Hello ");
//appendFile(SPIFFS, "/hello.txt", "World!\r\n");
//readFile(SPIFFS, "/hello.txt");
//renameFile(SPIFFS, "/hello.txt", "/foo.txt");
//deleteFile(SPIFFS, "/foo.txt");

#endif
