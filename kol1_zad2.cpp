#include <iostream>

struct ElListy
{
    int klucz;
    ElListy *nast = nullptr;
};

struct Lista
{
    ElListy *glowa = nullptr;
};

void dodajNaKoncu(Lista *l, int klucz)
{
    ElListy *nowyEl = new ElListy();
    nowyEl->klucz = klucz;

    if (l->glowa == nullptr)
    {
        l->glowa = nowyEl;
        return;
    }

    ElListy *ostatni = l->glowa;
    while (ostatni->nast != nullptr)
    {
        ostatni = ostatni->nast;
    }

    ostatni->nast = nowyEl;
}

ElListy *pozycjaNajmniejszego(Lista *l)
{
    ElListy *obecny = l->glowa;

    if (obecny == nullptr)
    {
        return nullptr;
    }

    ElListy *ostatniNajmniejszy = obecny;

    while (obecny->nast != nullptr)
    {
        obecny = obecny->nast;
        if (obecny->klucz < ostatniNajmniejszy->klucz)
        {
            ostatniNajmniejszy = obecny;
        }
    }

    return ostatniNajmniejszy;
}

void przestawNajmniejszyNaPoczatek(Lista *l)
{
    ElListy *najmnijeszy = pozycjaNajmniejszego(l);

    if (najmnijeszy == nullptr || l->glowa == najmnijeszy)
    {
        return;
    }

    ElListy *przedNajmniejszym = l->glowa;
    while (przedNajmniejszym->nast != najmnijeszy)
    {
        przedNajmniejszym = przedNajmniejszym->nast;
    }
    przedNajmniejszym->nast = przedNajmniejszym->nast->nast;

    najmnijeszy->nast = l->glowa;
    l->glowa = najmnijeszy;
}

int main() 
{
    Lista l = Lista();
    dodajNaKoncu(&l, 2);
    dodajNaKoncu(&l, 1);
    dodajNaKoncu(&l, 4);
    dodajNaKoncu(&l, 3);

    Lista pusta = Lista();

    ElListy *doNajmniejszegoL = pozycjaNajmniejszego(&l);
    ElListy *doNajmniejszegoPusta = pozycjaNajmniejszego(&pusta);

    przestawNajmniejszyNaPoczatek(&l);
    przestawNajmniejszyNaPoczatek(&pusta);

    return 0;
}