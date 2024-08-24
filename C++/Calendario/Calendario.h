#pragma once
#include <string>

class Calendario {
    private:
        int Mes, Anio;
    public:
        Calendario(int Mes, int Anio);
        Calendario(){}

        bool EsBisiesto();
        int ObtenerDiasDelMes();
        std::string ImprimirMes(int Numero);
        int ObtenerPrimerDiaDeSemana();
        void ImprimirCalendario();
};