#include "CTGameTable.h"

CTGameTable::CTGameTable(int width, int height) {
  Case uneCase = Case();

  TGameRow uneLgn(width, uneCase);

  m_GameTable = vector<TGameRow>(height, uneLgn);
}

/****************************************/
ostream& operator<< (ostream& out, const CTGameTable& tab) {
  unsigned int i,j;

  for (i=tab.m_GameTable.size(); i>0; i--) {
    for (j=0; j<tab.m_GameTable[i-1].size(); j++)
      out << tab.m_GameTable[i-1][j].m_used <<  " ";

    out << endl;
  }

  return out;
}

/****************************************/
void CTGameTable::setCase(unsigned int x, unsigned int y, Case newCase) {
  if( m_GameTable.size() > 0
      && m_GameTable.size() > x
      && m_GameTable[0].size() > y)
  {
    m_GameTable[x][y] = newCase;
  }
}

vector<TGameRow>& CTGameTable::GetGameTable() { return m_GameTable; }

