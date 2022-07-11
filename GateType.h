#pragma once
#include <string>
#include <vector>
#include "TruthTable.h"

class GateType
{
public:
	GateType() : m_type(""), m_truthTable(nullptr), m_delay(0) {}
	GateType(const std::string &type, const TruthTable* truthTable, int delay) 
		: m_type(type), m_truthTable(truthTable), m_delay(delay) {}
	int GetOutput(const std::vector<int> &inputs) const { return m_truthTable->GetOutput(inputs); }
	int GetDelay() const { return m_delay; }
	std::string GetTruthTableName() const { return m_truthTable->GetName(); }
	std::string GetType() const { return m_type; }
private:
	std::string m_type;
	const TruthTable* m_truthTable;
	int m_delay;
};