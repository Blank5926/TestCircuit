#pragma once
#include <string>
#include <map>
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include "TruthTable.h"
#include "GateType.h"
#include "Gate.h"

class Circuit
{
public:
	void AddTruthTable(const std::string &type, const std::vector<int> &outputs);
	void AddGateType(const std::string &name, const std::string &truthTableName, int delay);
	void AddGate(const std::string &name, const std::string &typeName, const std::vector<std::string> &inputNames);
	void AddProbe(const std::string &gateName);
	Gate* GetGate(const std::string &gateName) { return &(m_gates[gateName]); }
	std::vector<Gate*> ProbeAllGates();
	boost::property_tree::ptree GetJson();
private:
	std::map<std::string, TruthTable> m_truthTables;
	std::map<std::string, GateType> m_gateTypes;
	std::map<std::string, Gate> m_gates;
};