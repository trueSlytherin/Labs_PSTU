#pragma once

#include <string>

#include "List.h"

using namespace std;

class Dialog : public List {
public:
    Dialog(void);
    virtual ~Dialog(void);

    virtual void GetEvent(TEvent& event);
    virtual int Execute();
    virtual void HandleEvent(TEvent& event);
    virtual void ClearEvent(TEvent& event);
    virtual int Valid();
    virtual void EndExec();
    virtual void EventError(TEvent& event);

protected:
    int EndState;
};
