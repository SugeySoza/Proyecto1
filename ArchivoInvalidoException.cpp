//
// Created by gabriel on 26/4/26.
//

#include "ArchivoInvalidoException.h"

ArchivoInvalidoException::ArchivoInvalidoException(const string &msg) : runtime_error(msg){}
