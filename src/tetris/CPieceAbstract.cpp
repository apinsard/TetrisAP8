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

CPieceAbstract::CPieceAbstract ( unsigned int dim, int iX, int iY,
    const CVector3& color )
{
  TPieceRow rows = TPieceRow ( dim, 0 );

  this->m_dim      = dim;
  this->m_table    = TPieceTable ( dim, rows );
  this->m_state    = S_Top;
  this->m_colIndex = iX;
  this->m_rowIndex = iY;
  this->m_color    = color;
}

CPieceAbstract::~CPieceAbstract()
{
}

void CPieceAbstract::TurnRight() {
  TPieceTable  curTab  = this->m_table;

  for (unsigned int row = 0; row < this->m_dim; row++) {
    for (unsigned int col = 0; col < this->m_dim; col++)
      this->m_table[row][col] = curTab[col][this->m_dim-row-1];
  }

  this->m_state = static_cast<State>((this->m_state - 1) % 4);
}

void CPieceAbstract::TurnLeft() {
  TPieceTable  curTab  = this->m_table;

  for (unsigned int row = 0; row < this->m_dim; row++) {
    for (unsigned int col = 0; col < this->m_dim; col++)
      this->m_table[row][col] = curTab[this->m_dim-col-1][row];
  }

  this->m_state = static_cast<State>((this->m_state + 1) % 4);
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

unsigned int CPieceAbstract::GetDim() {
  return this->m_dim;
}

const CVector3& CPieceAbstract::GetColor() {
  return this->m_color;
}

ostream& operator<<(ostream& flux, const CPieceAbstract& p) {
  unsigned int tabSize = p.m_table.size();

  for (int row = tabSize-1; row >= 0; row--) {
    for (unsigned int col = 0; col < tabSize; col++)
      flux << " " << p.m_table[row][col];
    flux << endl;
  }

  return flux;
}

