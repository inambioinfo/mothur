#ifndef DEUNIQUESEQSCOMMAND_H
#define DEUNIQUESEQSCOMMAND_H
/*
 *  deuniqueseqscommand.h
 *  Mothur
 *
 *  Created by westcott on 10/19/10.
 *  Copyright 2010 Schloss Lab. All rights reserved.
 *
 */

#include "command.hpp"

/* This command is the reverse of unique.seqs */ 

class DeUniqueSeqsCommand : public Command {

public:
	DeUniqueSeqsCommand(string);
	DeUniqueSeqsCommand();
	~DeUniqueSeqsCommand() {}
	
	vector<string> setParameters();
	string getCommandName()			{ return "deunique.seqs";		}
	string getCommandCategory()		{ return "Sequence Processing";		}
	string getHelpString();	
	
	int execute(); 
	void help() { m->mothurOut(getHelpString()); }	
	
	
private:

	string fastaFile, nameFile, outputDir;
	vector<string> outputNames;
	bool abort;
	
	map<string, string> nameMap;
	
	int readNamesFile();
	
};

#endif

