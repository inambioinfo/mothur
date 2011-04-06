#ifndef MAKEFASTQCOMMAND_H
#define MAKEFASTQCOMMAND_H

/*
 *  makefastqcommand.h
 *  mothur
 *
 *  Created by westcott on 2/14/11.
 *  Copyright 2011 Schloss Lab. All rights reserved.
 *
 */


#include "command.hpp"

class MakeFastQCommand : public Command {
	
public:
	
	MakeFastQCommand(string);	
	MakeFastQCommand();
	~MakeFastQCommand(){}
	
	vector<string> setParameters();
	string getCommandName()			{ return "make.fastq";				}
	string getCommandCategory()		{ return "Sequence Processing";		}
	string getHelpString();	
	
	int execute(); 
	void help() { m->mothurOut(getHelpString()); }	
	
	
private:
	
	string fastafile, qualfile, outputDir;
	bool abort;
	vector<string> outputNames;
	
	string convertQual(vector<int>);
	
};

#endif


