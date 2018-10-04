#include "utils.h"

void err(int status, const char* text){
    fscanf(stderr, "%s", text);
    exit(status);
}