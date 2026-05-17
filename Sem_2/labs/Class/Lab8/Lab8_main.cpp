#include <clocale>

#include "Dialog.h"

int main() {
    setlocale(LC_ALL, "");

    Dialog dialog;
    dialog.Execute();

    return 0;
}
