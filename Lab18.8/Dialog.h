#pragma once
#include "List.h"
class Dialog :public List {
public:
    Dialog() :List() {
        EndState = 0;
    }
    virtual ~Dialog() {};
    virtual void GetEvent(TEvent& event) {
        string OperationsCodes = "m+-szq"; //m<кол-во элементов группы>, z<номер элемента группы>
        string operation;
        string parameters;
        char code;
        cout << "Введите команду: ";
        cin >> operation;
        code = operation[0];
        int indexOfFoundedOperation = OperationsCodes.find(code);
        if (indexOfFoundedOperation >= 0) {
            event.what = evMessage;
            switch (code)
            {
            case 'm':
                event.command = cmCreateGroup;
                break;
            case '+':
                event.command = cmAddElementInGroup;
                break;
            case '-':
                event.command = cmRemoveElementFromGroup;
                break;
            case 's':
                event.command = cmShowAllElements;
                break;
            case 'z':
                event.command = cmGetElementName;
                break;
            case 'q':
                event.command = cmQuit;
                break;
            }
            if (operation.length() > 1) {
                parameters = operation.substr(1, operation.length() - 1);
                int Attribute = atoi(parameters.c_str());
                event.attribute = Attribute;
            }
        }
        else
            event.what = evNothing;
    }
    virtual int Execute() {
        TEvent event;
        do {
            EndState = 0;
            GetEvent(event);
            HandleEvent(event);
        } while (!Valid());
        return EndState;
    }
    virtual void HandleEvent(TEvent& event)
    {
        if (event.what == evMessage)
        {
            switch (event.command)
            {
            case cmCreateGroup:
                list_size = event.attribute;
                save_list_size = event.attribute;
                begin = new Object * [list_size];
                current_position = 0;
                ClearEvent(event);
                break;
            case cmAddElementInGroup:
                Add();
                ClearEvent(event);
                break;
            case cmRemoveElementFromGroup:
                Delete();
                ClearEvent(event);
                break;
            case cmShowAllElements:
                cout << "Всего элементов в группе: " << size() << endl;
                Show();
                indexOfPrintedElement = 0;
                ClearEvent(event);
                break;
            case cmGetElementName:
                Show_Title(event.attribute);
                break;
            case cmQuit:
                EndExecution();
                ClearEvent(event);
                break;
            default:
                HandleEvent(event);
                break;
            };
        };
    }
    virtual void ClearEvent(TEvent& event) {
        event.what = evNothing;
    }
    int Valid() {
        if (EndState == 0)
            return 0;
        else
            return 1;
    }
    void EndExecution() {
        EndState = 1;
    };

protected:
    int EndState;
};