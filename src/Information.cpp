#include "Information.h"

Information::Information() : m_levelCompleted(false),m_score(0) {}

void Information::setLevelFinish(const bool flag)
{
	m_levelCompleted = flag;
}

bool Information::getLevelFinish() const
{
	return m_levelCompleted;
}
