//
// Created by gabriel on 26/4/26.
//

#include "FormatoInvalidoException.h"

FormatoInvalidoException::FormatoInvalidoException(const string &msg) : runtime_error(msg){}
