#ifndef MERGEGROUPSCOMMAND_H
#define MERGEGROUPSCOMMAND_H

/*
 *  mergegroupscommand.h
 *  mothur
 *
 *  Created by westcott on 1/24/11.
 *  Copyright 2011 Schloss Lab. All rights reserved.
 *
 */

#include "command.hpp"
#include "inputdata.h"
#include "sharedrabundvector.h"

class MergeGroupsCommand : public Command {
	
public:
	MergeGroupsCommand(string);
	MergeGroupsCommand();
	~MergeGroupsCommand() {}
	
	vector<string> setParameters();
	string getCommandName()			{ return "merge.groups";	}
	string getCommandCategory()		{ return "General";			}
	string getHelpString();	
	
	int execute(); 
	void help() { m->mothurOut(getHelpString()); }	
	
private:
	GroupMap* designMap;
	vector<SharedRAbundVector*> lookup;
	
	bool abort, allLines, pickedGroups;
	set<string> labels; //holds labels to be used
	string groups, label, outputDir, inputDir, designfile, sharedfile;
	vector<string> Groups, outputNames;
		
	int process(vector<SharedRAbundVector*>&, ofstream&);
};

#endif

