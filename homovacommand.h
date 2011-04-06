#ifndef HOMOVACOMMAND_H
#define HOMOVACOMMAND_H

/*
 *  homovacommand.h
 *  mothur
 *
 *  Created by westcott on 2/8/11.
 *  Copyright 2011 Schloss Lab. All rights reserved.
 *
 */


#include "command.hpp"

//class GlobalData;
class GroupMap;

class HomovaCommand : public Command {
	
public:
	HomovaCommand(string);
	HomovaCommand();
	~HomovaCommand(){}
	
	vector<string> setParameters();
	string getCommandName()			{ return "homova";					}
	string getCommandCategory()		{ return "Hypothesis Testing";		}
	string getHelpString();	
	
	int execute();
	void help() { m->mothurOut(getHelpString()); }	
	
private:
	double runHOMOVA(ofstream& , map<string, vector<int> >, double);
	double calcSigleSSWithin(vector<int>);
	double calcBValue(map<string, vector<int> >, vector<double>&);
	map<string, vector<int> > getRandomizedGroups(map<string, vector<int> >);

	bool abort;
	vector<string> outputNames;

	string outputDir, inputDir, designFileName, phylipFileName;
	GroupMap* designMap;
	vector< vector<double> > distanceMatrix;
	int iters;
	double experimentwiseAlpha;
};

#endif
