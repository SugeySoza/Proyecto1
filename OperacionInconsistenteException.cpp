//
// Created by gabriel on 26/4/26.
//

#include "OperacionInconsistenteException.h"

OperacionInconsistenteException::OperacionInconsistenteException(const string& msg) : runtime_error(msg) {}
