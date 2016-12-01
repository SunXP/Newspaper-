#include "justify.h"


int main() {
	unsigned int result;
	unsigned int width;
	string input;
	vector<string> output;

	while (1) {
		// first clear the output string
		output.clear();
		cout << endl<< "Welcome to pretty printing!" << endl << endl;
		cout << "Enter the column width (between " << MIN_COL_WIDTH << " and " << MAX_COL_WIDTH << ", or 0 to exit): ";
		cin >> width;
		if (width == 0)
			break;
		cout << "Enter the string to justify below:" << endl << endl;

		// read in the input string
		cin.ignore();

		getline(cin, input);

		// justify the input for given column width
		result = justify(width, input, output);

		switch(result) {
			case ERROR_NONE:
				cout << "The justified string is:" << endl << endl;
				for (unsigned int i = 0; i < output.size(); i++)
					cout << output[i] << endl;
				break;
			case ERROR_NO_CHARS:
				cout << "ERROR: No characters in input text!" << endl;
				break;
			case ERROR_ILLEGAL_WIDTH:
				cout << "ERROR: Column width out of range!" << endl;
				break;
			default:
				cout << "ERROR: Internal error!" << endl;
				break;
		}
	} // enter interactive loop
}
