//
// Created by gabriel on 26/4/26.
//

#ifndef PROYECTO1_OPERACIONINCONSISTENTEEXCEPTION_H
#define PROYECTO1_OPERACIONINCONSISTENTEEXCEPTION_H

#include <stdexcept>
#include <iostream>

using namespace std;

class OperacionInconsistenteException : public runtime_error{
public:
    OperacionInconsistenteException(const string& msg);
};


#endif //PROYECTO1_OPERACIONINCONSISTENTEEXCEPTION_H