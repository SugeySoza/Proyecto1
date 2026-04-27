//
// Created by gabriel on 26/4/26.
//

#ifndef PROYECTO1_FORMATOINVALIDOEXCEPTION_H
#define PROYECTO1_FORMATOINVALIDOEXCEPTION_H

#include <stdexcept>
#include <iostream>

using namespace std;

class FormatoInvalidoException : public runtime_error {
    FormatoInvalidoException(const string& msg);
};


#endif //PROYECTO1_FORMATOINVALIDOEXCEPTION_H