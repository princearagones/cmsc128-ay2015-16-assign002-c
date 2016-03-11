#include "bioinformatics.h"

main(){
	/*getHammingDistance() test cases:*/

	getHammingDistance("AACCTT","GGCCTT"); //return 2
	getHammingDistance("TCGGA","AAAAG"); //returns 5
	getHammingDistance("A","AG"); //error message prompt returns 0

	/*countSubstrPattern() test cases:*/
	countSubstrPattern("AATATATAGG","GG");// returns 1
	countSubstrPattern("AATATATAGG","ATA");// returns 3
	countSubstrPattern("AATATATAGG","ACTGACTGACTG");// returns 0

	/*isValidString() test cases:*/
	isValidString("AAGGCTATGC","ACGT");//returns 1 / true
	isValidString("AAGGCTATGa","ACGT");// returns 0 / false
	isValidString("ACGT","ACGT");// returns 1 / true
	isValidString("ACGT101_","ACGT");// returns 0 / false
	isValidString("091212345","0123456789");// returns 1 / true

	/*getSkew() test cases:*/
	getSkew("GGCCAC", 1);// returns 1
	getSkew("GGCCAC", 2);// returns 2
	getSkew("GGCCAC", 3);// returns 1
	getSkew("GGCCAC", 4);// returns 0
	getSkew("GGCCAC", 5);// returns 0

	/*getMaxSkewN() test cases:*/
	getMaxSkewN("GGCCAC", 1);// returns 1
	getMaxSkewN("GGCCAC", 2);// returns 2
	getMaxSkewN("GGCCAC", 3);// returns 2
	getMaxSkewN("GGCCAC", 4);// returns 2
	getMaxSkewN("GGCCAC", 5);// returns 2

	/*getMinSkewN() test cases:*/
	getMinSkewN("GGCCAC", 1);// returns 1
	getMinSkewN("GGCCAC", 2);// returns 1
	getMinSkewN("GGCCAC", 3);// returns 1
	getMinSkewN("GGCCAC", 4);// returns 0
	getMinSkewN("GGCCAC", 5);// returns 0

}
