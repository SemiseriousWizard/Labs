#pragma once
using namespace std;
const int evNothing = 0;
const int evMessage = 100;
const int cmCreateGroup = 1;
const int cmAddElementInGroup = 2;
const int cmRemoveElementFromGroup = 3;
const int cmShowAllElements = 4;
const int cmGetElementName = 5;
const int cmQuit = 6;
int save_list_size;
//класс-событие
struct TEvent {
    int what;
    union {
        int command;
        struct {
            int message;
            int attribute;
        };
    };
};