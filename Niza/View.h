#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <map>
#include "Admin.h"

using namespace std;

class View{
    private:
        Admin edificio;
    public:
        View();
        void mostrarMenu();
};

#endif