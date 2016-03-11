/*
Author: Prince Karlo C. Aragones
Section: CMSC128 AB-3L
Description: Assign 002: Programming a Simple Bioinformatics Library
*/

#include<stdio.h>
#include<string.h>


/*
Given two strings str1 and str2 of same length (length must never be 0 or
negative!), the Hamming Distance of those two strings are the number of inversions per
character need to transform str1 to str2 or vise-versa. Simply put, the Hamming Distance
of two strings is the number of characters that differ in ith position from position 1 to
strlen(str1).
*/
int getHammingDistance(char* str1, char* str2){
	int count = 0,i;
	if(strlen(str1)!=strlen(str2)){ // skips compare when string length of two strings are not equal
		printf("Error! String are not equal!\n");
	}
	else {
		for(i = 0; i < strlen(str1);i++){
			if(str1[i] != str2[i]) count++; //count iterates every non matching letters in same indexes
		}
	}
	return count;
}

/*
Given a string original and pattern, we will count the number of occurrence
of pattern in original.
*/
int countSubstrPattern(char* original, char* pattern){
	int i, count = 0;
	char temp[strlen(original)];
	strcpy(temp, original); //clones original to a temp string

	if(strlen(pattern) > strlen(original)) return count; //if pattern is longer than the original, skip compare, prompt error

	while(temp[0] != '\0'){ //while temp holds a char/string
		if((strstr(temp,pattern)) != NULL){ //if there exist a sub string of temp by pattern
		count++; 							//count iterates
		strcpy(temp ,strstr(temp, pattern)+1); //the new original will be the substring less the first letter
		}
		else break; //since there are no substring found in temp. exit loop
	}
	return count;
}
/*
Given an alphabet string where all letters are assumed to be unique, this
function returns true if the string str is a valid string based on the letters of alphabet.
*/
int isValidString(char* str, char* alphabet){
	int i,j, result; //let result be the flag for boolean 1 - true 0 - false
	for(i = 0 ; i < strlen(str); i++){
		result = 0; //set flag to false
		for(j = 0 ; j < strlen(alphabet); j++){
			if(str[i] == alphabet[j]) result = 1; //if one of the alphabet match the char in str, set flag to true
		}
		if(result == 0){ //if the alphabet is traverse and str[i] did not match any, str is invalid string
			printf("false\n");
			return result;
		} 
	}
	printf("true\n");
	return result;
}

/*
Given a genome str of some length q (where q>0), it returns the number of
Gs minus the number of Cs in the first n nucleotides (q>=n). The value can be zero,
negative or positive. The first position is one (1) not zero(0) as we typically associate with
string implementations.
*/

int getSkew(char* str, int n){
	int count = 0,i;
	if(n > strlen(str) || n < 1){ //n should be positive and around the range of the length of str
		printf("Error! index out of bounds\n");
		return -1;
	} 
	for(i = 0 ; i< n; i++){
		if(str[i] == 'G') count++; 
		else if(str[i] == 'C') count--;
	}
	return count;
}

/*
Given a genome str of some length q (where q>0), it returns the maximum
value of the number of Gs minus the number of Cs in the first n nucleotides (q>=n). The
value can be zero, negative or positive. The first position is one (1) not zero(0) as we
typically associate with string implementations.
*/
int getMaxSkewN(char* str, int n){
	int count = 0, i, maxCount;
	if(n > strlen(str) || n < 1){
		printf("Error! index out of bounds\n");
		return -1;
	} 
	maxCount = getSkew(str,1);
	for(i = 1; i < n; i++){
		count = getSkew(str,i+1);
		if(count > maxCount) maxCount = count; //if the newly found count is greater than the current count, change max
	}
	printf("Max skew is %i\n", maxCount);
	return maxCount;
}
/*
Given a genome str of some length q (where q>0), it returns the minimum
value of the number of Gs minus the number of Cs in the first n nucleotides (q>=n). The
value can be zero, negative or positive. The first position is one (1) not zero(0) as we
typically associate with string implementations.
*/
int getMinSkewN(char* str, int n){
	int count = 0, i, minCount;
	if(n > strlen(str) || n < 1){
		printf("Error! index out of bounds\n");
		return -1;
	} 
	minCount = getSkew(str,1);
	for(i = 1; i < n; i++){
		count = getSkew(str,i+1);
		if(count < minCount) minCount = count; //if the newly found count is lesser than the current count, change min
	}
	printf("Min skew is %i\n", minCount);
	return minCount;
}
