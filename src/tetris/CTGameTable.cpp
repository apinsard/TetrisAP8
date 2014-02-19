#include "CTGameTable.h"

CTGameTable::CTGameTable(int width, int height) {
	Case uneCase = Case();

	TGameRow uneLgn(width, uneCase);

	m_GameTable = vector<TGameRow>(height, uneLgn);
}

/****************************************/
ostream& operator<< (ostream& out, const CTGameTable& tab) {
	unsigned int i,j;

	for (i=0; i<tab.m_GameTable.size(); i++) {
		for (j=0; j<tab.m_GameTable[i].size(); j++)
			out << tab.m_GameTable[i][j].m_used <<  " ";

		out << endl;
	}

	return out;
}

/****************************************/
void CTGameTable::setCase(unsigned int x, unsigned int y, Case newCase) {
	if( m_GameTable.size() > 0
		  && m_GameTable.size() >= y-1
		  && m_GameTable[0].size() >= x-1)
	{
		m_GameTable[y][x] = newCase;
	} else
		throw logic_error("This cord x:" + x + " y:" + y + " it's outted");
}

vector<TGameRow>& CTGameTable::GetGameTable() { return m_GameTable; }

