#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

/*problem description:
https://www.hackerrank.com/contests/words-and-punctuation/challenges/words-and-punctuation*/

class NoMatchingBracketsException {
    string message_;
    public:
        NoMatchingBracketsException(string message) {
            message_ = message;
        }
        string get_message() {
            return message_;
        }
};

class NoSentencesOrWordsException {
    string message_;
    public:
        NoSentencesOrWordsException(string message) {
            message_ = message;
        }
        string get_message() {
            return message_;
        }
};

int calc_avr_length_of_the_words(vector<string> data);
int calc_avr_length_of_the_sentences(vector<string> data);
bool strict(vector<string> data);
void sentences_up_to(vector<string> data, int max_count_of_words);
int count_words_in_sentence(string data);

int main() {
    try {
        int avr_words_len = 0;
        int avr_sentences_len;
        vector<string> data;
        string input;
        while (input != "END") {
            getline(cin, input);
            if (data.empty() && input == "END") {
                throw NoSentencesOrWordsException("PROVIDE AT LEAST ONE SENTENCE OR WORD");
            }
            else {
                data.push_back(input);
            }
        }
        data.pop_back();
        reverse(data.begin(), data.end());
        string command;
        command.append(data.back());
        int max_count_of_words = 0;
        if (isdigit(command.back())) {
            string temp;
            for (int i = 0; i < command.length(); i++) {
                if (isdigit(command[i])) {
                    max_count_of_words = max_count_of_words * 10 + (command[i] - '0');
                }
            }
            if (command.length() > 20) {
                command.erase(command.begin() + 23, command.end());
            }
            else {
                command.erase(command.begin() + 16, command.end());
            }
        }
        if (command.compare("strict\n")) {
            if(!strict(data)) {
                throw NoMatchingBracketsException("PROVIDE MATCHING PARENTHESES");
            }
        }
        else if (command.compare("sentences-up-to:\n")) {
            int results[2];
             sentences_up_to(data, max_count_of_words);
        }
        else if (command.compare("strict sentences-up-to:\n")) {

        }
        else {
            if(!strict(data)) {
                throw NoMatchingBracketsException("PROVIDE MATCHING PARENTHESES");
            }
        }
        avr_sentences_len = calc_avr_length_of_the_sentences(data);
        avr_words_len = calc_avr_length_of_the_words(data);
        cout << avr_sentences_len << " " << avr_words_len << endl;
    }
    catch (NoSentencesOrWordsException e) {
        cout << "ERR: " << e.get_message() << endl;
    }
    catch (NoMatchingBracketsException e) {
        cout << "ERR: " << e.get_message() << endl;
    }
    return 0;
}

int calc_avr_length_of_the_sentences(vector<string> data) {
    int sentences_count = 0, words_count = 0;
    int dash_count = 0, additional_spaces = 0;
    if (data.size() > 1) {
        data.pop_back();
    }
    while (!data.empty()) {
        string temp = data.back();
        for (int i = 0; temp[i] != '\0'; i++) {
            if (temp[i] == '.') {
                sentences_count++;
            }
            else if (isspace(temp[i]) && temp[i + 1] == '-' && dash_count >= 2) {
                dash_count++;
                additional_spaces++;
            }
            else if (isspace(temp[i]) && temp[i + 1] == '-' && dash_count < 2) {
                dash_count++;
                words_count++;
            }
            else if (isspace(temp[i]) && temp[i - 1] == '-') {
                continue;
            }
            else if (isspace(temp[i])) {
                words_count++;
            }
        }
        words_count++;
        data.pop_back();
    }
    return (words_count - additional_spaces) / sentences_count;
}

int calc_avr_length_of_the_words(vector<string> data) {
    int avr_length = 0, words_count = 0;
    int dash_count = 0, additional_spaces = 0;
    if (data.size() > 1) {
        data.pop_back();
    }
    while (!data.empty()) {
        string temp = data.back();
        for (int i = 0; temp[i] != '\0'; i++) {
            if (isalpha(temp[i])) {
                avr_length++;
            }
            else if (isspace(temp[i]) && temp[i + 1] == '-' && dash_count >= 2) {
                additional_spaces++;
                dash_count++;
            }
            else if (isspace(temp[i]) && temp[i + 1] == '-' && dash_count < 2) {
                dash_count++;
                words_count += 2;
            }
            else if (isspace(temp[i]) && temp[i - 1] == '-') {
                continue;
            }
            else if (isspace(temp[i])) {
                words_count++;
            }
        }
        data.pop_back();
    }
    return avr_length / (words_count - additional_spaces);
}

bool strict(vector<string> data) {
    int opening_brackets = 0;
    int closing_brackets = 0;
    int state = 0;
    if (data.size() > 1) {
        data.pop_back();
    }
    while (!data.empty()) {
        string temp = data.back();
        for (int i = 0; i < temp.length(); i++) {
            if (temp[i] == '(') {
                opening_brackets++;
            }
            else if (temp[i] == ')') {
                closing_brackets++;
            }
            if (temp[i] == '.') {
                break;
            }
        }
        if (opening_brackets != closing_brackets) {
            state = 0;
        }
        else {
            state = 1;
            opening_brackets -= opening_brackets;
            closing_brackets -= closing_brackets;
        }
        data.pop_back();
    }
    if (state == 0) {
        return false;
    }
    else {
        return true;
    }
}

int count_words_in_sentence(string data) {
    int words_count = 0;
    int dash_count = 0, additional_spaces = 0;
    for(int i = 0; i < data.length(); i++) {
        if (isspace(data[i]) && data[i + 1] == '-' && dash_count >= 2) {
            dash_count++;
            additional_spaces++;
        }
        else if (isspace(data[i]) && data[i + 1] == '-' && dash_count < 2) {
            dash_count++;
            words_count++;
        }
        else if (isspace(data[i]) && data[i - 1] == '-') {
            continue;
        }
        else if (isspace(data[i])) {
            words_count++;
        }
    }
    words_count++;
    return words_count;
}

void sentences_up_to(vector<string> data, int max_count_of_words) {
    int avr_sentences_len = 0, avr_words_len = 0;
    int results[2];
    vector<string> filtered_data;
    while(!data.empty()) {
        string temp = data.back();
        if(count_words_in_sentence(temp) > max_count_of_words) {
            continue;
        }
        else {
            filtered_data.push_back(temp);
        }
        data.pop_back();
    }
    avr_sentences_len = calc_avr_length_of_the_sentences(filtered_data);
    avr_words_len = calc_avr_length_of_the_words(filtered_data);
    cout << avr_sentences_len << " " << avr_words_len << endl;
}
