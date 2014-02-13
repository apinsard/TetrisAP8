//========================================================================
// Projet C/C++
//
//------------------------------------------------------------------------
// Copyright (c) 2013-2014 Equipe SEASIDE (T. LE NAOUR, J.F KAMP)
// IRISA - UBS  / IUT Informatique Vannes
//========================================================================

#include "CPieceAbstract.h"

//-------------------------------------------------------------------------------------------------------------------
//
// classe CPieceAbstract
//
//-------------------------------------------------------------------------------------------------------------------

CPieceAbstract::CPieceAbstract ( unsigned int dim, int iX, int iY, const CVector3& color ) {

  m_dim = dim;
  TPieceRow rows = TPieceRow ( dim, 0 );
  m_table = TPieceTable ( dim, rows );
  m_state = S_Top;
  m_colIndex = iX;
  m_rowIndex = iY;
  m_color = color;
}

CPieceAbstract::~CPieceAbstract()
{
}

void CPieceAbstract::TurnRight() {
  this->m_state = static_cast<State>((this->m_state + 1) % 4);
}

void CPieceAbstract::TurnLeft() {
  this->m_state = static_cast<State>((this->m_state - 1) % 4);
}

TPieceTable& CPieceAbstract::GetTable() {
  return this->m_table;
}

void CPieceAbstract::SetTable(const TPieceTable& table) {
  this->m_table = table;
}

int CPieceAbstract::GetColIndex() {
  return this->m_colIndex;
}

int CPieceAbstract::GetRowIndex() {
  return this->m_rowIndex;
}

void CPieceAbstract::SetIncDecRowIndex(int val) {
  this->m_rowIndex += val;
}

void CPieceAbstract::SetIncDecColIndex(int val) {
  this->m_colIndex += val;
}

void CPieceAbstract::SetColIndex(int newColIndex) {
  this->m_colIndex = newColIndex;
}

void CPieceAbstract::SetRowIndex(int newRowIndex) {
  this->m_rowIndex = newRowIndex;
}

const CVector3& CPieceAbstract::GetColor() {
  return this->m_color;
}

ostream& operator<<(ostream& flux, const CPieceAbstract& p) {
  for (unsigned int row = 0; row < p.m_table.size(); row++) {
    for (unsigned int col = 0; col < p.m_table[row].size(); col++)
      flux << " " << p.m_table[row][col];
    flux << endl;
  }
  return flux;
}

