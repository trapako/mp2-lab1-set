// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

// Fake variables used as placeholders in tests
static const int FAKE_INT = -1;
static TBitField FAKE_BITFIELD(1);

TBitField::TBitField(int len)
{
    if (len <= 0) throw - 1;
    BitLen = len;
    MemLen = len / sizeof(TELEM) + 1;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++) {
        pMem[i] = 0;
    }
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
}

TBitField::~TBitField()
{
    delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    if ((n < 0) || (n >= BitLen)) {
        throw - 1;
    }
    int FAKE_INT = n / 32;
    return FAKE_INT;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    TELEM mask = 1;
    mask = mask << (n % 32);
    return mask;
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return FAKE_INT;
}

void TBitField::SetBit(const int n) // установить бит
{
    int i = GetMemIndex(n);
    TELEM j = GetMemMask(n);
    pMem[i] = pMem[i] | j;
}

void TBitField::ClrBit(const int n) // очистить бит
{
}

int TBitField::GetBit(const int n) const // получить значение бита
{
  return FAKE_INT;
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    return FAKE_BITFIELD;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
  return FAKE_INT;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
  return FAKE_INT;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
    return FAKE_BITFIELD;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    return FAKE_BITFIELD;
}

TBitField TBitField::operator~(void) // отрицание
{
    return FAKE_BITFIELD;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
    return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
    return ostr;
}
