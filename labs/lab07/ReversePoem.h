/*
 * ReversePoem.h
 *
 *  Created on: Apr 5, 2021
 *      Author: Sam
 */

#ifndef REVERSEPOEM_H_
#define REVERSEPOEM_H_

#include "Stack.h"

typedef int Item;

class ReversePoem {
	friend class ReversePoemTester;
public:
	ReversePoem(const string& filename);
	virtual ~ReversePoem();
	string getTitle() const;
	string getAuthor() const;
	string getBody() const;
	string getBodyReversed() const;
	string myTitle;
	string myAuthor;
	string myBody;
	string myBodyReversed;

private:

};

#endif /* REVERSEPOEM_H_ */
