/**
 * \file allapotgep.cpp
 *
 * Ebben a fájlban kell megvalósítania az Allapotgep osztály
 * metódusait, valamint mindazon további osztályokat, melyek szükségesek
 * a feladat megvalósításához.
 *
 * Ezt a fájlt be kell adni (fel kell tölteni) a megoldással.
 */

#include <iostream>
#include <fstream>

#include "allapotgep.h"
#include "memtrace.h"

#define NEPTUN "EM0G6P"

void Allapotgep::konfigural(const char* fajlnev) {
  std::ifstream f(fajlnev);
  if (!f.is_open()) {
    throw NEPTUN;
  }

  if(allapotok != NULL) delete[] allapotok;

  f >> allapotokSzama;
  allapotok = new Allapot[allapotokSzama];

  for (int i = 0; i < allapotokSzama; ++i) {
    char tipus;
    f >> tipus >> allapotok[i].nev;
    allapotok[i].elfogado = (tipus == 'I');
  }

  aktualisAllapot = &allapotok[0];

  for (int i = 0; i < allapotokSzama; ++i) {
    for (int j = 0; j < allapotokSzama; ++j) {
      char bazisok[5];
      f >> bazisok;
      for (int k = 0; k < 4; ++k) {
        switch (bazisok[k]) {
          case 'A':
            allapotok[i].atmenetek[Adenin] = static_cast<Bazis>(j);
            break;
          case 'C':
            allapotok[i].atmenetek[Citozin] = static_cast<Bazis>(j);
            break;
          case 'G':
            allapotok[i].atmenetek[Guanin] = static_cast<Bazis>(j);
            break;
          case 'T':
            allapotok[i].atmenetek[Timin] = static_cast<Bazis>(j);
            break;
        }
      }
    }
  }
}

const char* Allapotgep::aktualisallapot() {
  return aktualisAllapot->nev.c_str();
}

bool Allapotgep::elfogad() {
  return aktualisAllapot->elfogado;
}

void Allapotgep::atmenet(Bazis b) {
  aktualisAllapot = &allapotok[aktualisAllapot->atmenetek[b]];
}

bool Allapotgep::feldolgoz(const Bazis *b, int n) {
  for (int i = 0; i < n; ++i) {
    atmenet(b[i]);
  }
  return elfogad();
}

void Allapotgep::alaphelyzet() {
  aktualisAllapot = &allapotok[0];
}

Allapotgep::~Allapotgep(){
  if(allapotok != NULL) delete[] allapotok;
}

