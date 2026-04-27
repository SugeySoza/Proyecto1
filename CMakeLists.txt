cmake_minimum_required(VERSION 4.1)
project(Proyecto1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto1 main.cpp
        Equipo.cpp
        Equipo.h
        Incidencia.cpp
        Incidencia.h
        Severidad.h
        Laboratorio.cpp
        Laboratorio.h
        EstrategiaMantenimiento.cpp
        EstrategiaMantenimiento.h
        MantenimientoCorrectivo.cpp
        MantenimientoCorrectivo.h
        Simulador.cpp
        Simulador.h
        PCBasica.cpp
        Servidor.h
        Servidor.cpp
        Algoritmos.cpp
        Algoritmos.h
        OperacionInconsistenteException.cpp
        OperacionInconsistenteException.h
        ArchivoInvalidoException.cpp
        ArchivoInvalidoException.h
)
