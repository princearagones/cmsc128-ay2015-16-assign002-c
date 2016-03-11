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
	if(strlen(str1)!=strlen(str2)){
		printf("Error! String are not equal!\n");
	}
	else {
		for(i = 0; i < strlen(str1);i++){
			if(str1[i] != str2[i]) count++;
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
	strcpy(temp, original);

	if(strlen(pattern) > strlen(original)) return count;

	while(temp[0] != '\0'){
		if((strstr(temp,pattern)) != NULL){
		count++;
		strcpy(temp ,strstr(temp, pattern)+1); //the new original will be the substring less the first letter
		}
		else break;
	}
	return count;
}
/*
Given an alphabet string where all letters are assumed to be unique, this
function returns true if the string str is a valid string based on the letters of alphabet.
*/
int isValidString(char* str, char* alphabet){
	int i,j, result;
	for(i = 0 ; i < strlen(str); i++){
		result = 0;
		for(j = 0 ; j < strlen(alphabet); j++){
			if(str[i] == alphabet[j]) result = 1;
		}
		if(result == 0){
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
	if(n > strlen(str) || n < 1){
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
		if(count > maxCount) maxCount = count;
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
		if(count < minCount) minCount = count;
	}
	printf("Min skew is %i\n", minCount);
	return minCount;
}