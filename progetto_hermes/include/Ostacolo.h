#ifndef OSTACOLO_H
#define OSTACOLO_H

#include <Entita.h>


class Ostacolo : public Entita
{
    public:
        Ostacolo(int x, int y, int larghezza); //costruttore
        virtual ~Ostacolo();    //distruttore
};

#endif // OSTACOLO_H
