#include "justify.h"
#include <cmath>

unsigned int justify(unsigned int width, string in, vector<string> & out) {

int x=0;	// counter to keep order of the string after character additions
int i=0;	// counter for the for loop
string str; // string to separate the string into the correct width and push_back to a vector

if (in.size()==0){	// if input string has no characters
	return 1;
	}

else if (width < 10 || width > 60){	// if input width is outside bounds
	return 2;
	}

else {

	for (i = 1; ceil(in.size() / width) >= i; i++){

		if (in.at(width*i+x-1) == ' '){		//if the character at width is a space
			str = in.substr(width*(i-1)+x, width);	// takes string from position of the string and adds the width of it
			out.push_back(str);	//push into the vector string

		}
		if ((in.at(width*i+x-1) == '.') || (in.at(width*i+x-1) == ',')){
			in.erase(in.begin()+width*i+x);	//remove the space after width
			str = in.substr(width*(i-1)+x, width); // takes string from position of the string and adds the width of it
			out.push_back(str);	// push into the vector string

		}

		if (isalpha(in[(width*i+x-1)])){	//if at the width, there is alphabet char

			if (in.at(width*i+x) == '.' || in.at(width*i+x) == ','){	//if there is punctuation after width

				str = in.substr(width*(i-1)+x, width+1);	// // takes string from position of the string and adds the width of it +1 to account for increased string index
				in.erase(in.begin()+width*i+x); // erase the space after the width
				x++; //adds counter if punctuation after width, so that the rest of string keeps correct width
				out.push_back(str); // push into vector string

			}

			else if (in.at(width*i+x-2) == ' ') { //if there is a space before last character
				in.insert(width*i+x-1, " ");	//insert a space right after the space
				str = in.substr(width*(i-1)+x, width); // takes string from position of the string and adds the width of it
				out.push_back(str); // push into vector string

			}

			else if (isalpha(in[(width*i+x)])){	//if character is present after width
				in.insert(width*i+x-1, "-"); // insert "-" where the last character of width is
				str = in.substr(width*(i-1)+x, width);  // takes string from position of the string and adds the width of it
				out.push_back(str); // push into vector string

			}

			else if (in.at(width*i+x) == ' '){	//if there is a space after width
				in.erase(in.begin()+width*i+x);	//remove the space after width
				str = in.substr(width*(i-1)+x, width); // takes string from position of the string and adds the width of it
				out.push_back(str); // push into vector string

			}

		}

	}

	out.push_back(in.substr(width*(i-1)+x, in.length()-width*(i-1)+x)); // push the last remaining characters of the string

	return 0;
}

}

