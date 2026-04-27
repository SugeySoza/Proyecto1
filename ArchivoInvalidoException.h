//
// Created by gabriel on 26/4/26.
//

#ifndef PROYECTO1_ARCHIVOINVALIDOEXCEPTION_H
#define PROYECTO1_ARCHIVOINVALIDOEXCEPTION_H

#include <stdexcept>
#include <iostream>

using namespace std;

class ArchivoInvalidoException : public runtime_error{
public:
    ArchivoInvalidoException(const string& msg);
};


#endif //PROYECTO1_ARCHIVOINVALIDOEXCEPTION_H