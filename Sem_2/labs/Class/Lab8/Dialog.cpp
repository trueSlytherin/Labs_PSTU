#include "Dialog.h"

#include <cstdlib>
#include <iostream>

Dialog::Dialog(void) : List() {
    EndState = 0;
}

Dialog::~Dialog(void) {
}

void Dialog::GetEvent(TEvent& event) {
    string s;
    string param;
    char code;

    cout << endl;
    cout << "Commands:" << endl;
    cout << "m size - create group" << endl;
    cout << "+      - add object" << endl;
    cout << "-      - delete last object" << endl;
    cout << "s      - show group" << endl;
    cout << "? num  - show object" << endl;
    cout << "q      - quit" << endl;
    cout << ">";

    cin >> s;
    code = s[0];

    event.what = evMessage;
    event.command = 0;
    event.a = 0;

    switch (code) {
    case 'm':
        event.command = cmMake;
        break;
    case '+':
        event.command = cmAdd;
        break;
    case '-':
        event.command = cmDel;
        break;
    case 's':
        event.command = cmShow;
        break;
    case '?':
        event.command = cmGet;
        break;
    case 'q':
        event.command = cmQuit;
        break;
    default:
        event.what = evNothing;
        return;
    }

    if (s.length() > 1) {
        param = s.substr(1, s.length() - 1);
        event.a = atoi(param.c_str());
    } else if (event.command == cmMake || event.command == cmGet) {
        cin >> event.a;
    }
}

int Dialog::Execute() {
    TEvent event;

    do {
        EndState = 0;
        GetEvent(event);
        HandleEvent(event);

        if (event.what != evNothing) {
            EventError(event);
        }
    } while (Valid());

    return EndState;
}

void Dialog::HandleEvent(TEvent& event) {
    if (event.what == evMessage) {
        switch (event.command) {
        case cmMake:
            Make(event.a);
            ClearEvent(event);
            break;
        case cmAdd:
            Add();
            ClearEvent(event);
            break;
        case cmDel:
            Del();
            ClearEvent(event);
            break;
        case cmShow:
            Show();
            cout << "Group size = " << operator()() << endl;
            ClearEvent(event);
            break;
        case cmGet:
            ShowElement(event.a);
            ClearEvent(event);
            break;
        case cmQuit:
            EndExec();
            ClearEvent(event);
            break;
        default:
            List::HandleEvent(event);
            break;
        }
    }
}

void Dialog::ClearEvent(TEvent& event) {
    event.what = evNothing;
}

int Dialog::Valid() {
    if (EndState == 0) {
        return 1;
    }

    return 0;
}

void Dialog::EndExec() {
    EndState = 1;
}

void Dialog::EventError(TEvent& event) {
    cout << "Wrong command" << endl;
    ClearEvent(event);
}
