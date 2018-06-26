//
//  main.cpp
//  CS235_10_New_Map
//
//  Created by Mauricio Takashi Kiyama on 6/26/18.
//  Copyright © 2018 Marcio Kazuo Kiyama. All rights reserved.
//

#include <iostream>
#include <map>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;
typedef map<string, int> Map;
typedef map<string, int>::reverse_iterator MapIterator;
typedef multimap<int, string>::reverse_iterator MultiMapIterator;

int main(int argc, const char * argv[]) {
    
    
    string userInput;
    int numberOfWords = 0;
    
    cout << "Enter filename: ";
    cin >> userInput;
    
    ifstream fin;
    fin.open(userInput.c_str());
    
    if (fin.fail()) {
        cout << "Error: Unable to open file";
        return 0;
    }
    
    Map myMap;
    string word;
    
    while (fin >> word) {
        
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        string noPunWord = "";
        
        for (int i = 0; i < word.length(); i++) {
            if (!ispunct(word[i]) || word[i] != '-')
                noPunWord += word[i];
        }
        
        myMap[noPunWord]++;
        numberOfWords++;
    }

    
    fin.close();
    

    cout << "Number of words processed: " << numberOfWords;
    
    multimap<int, string> megaMap;
    
    
    
    
    
    
    return 0;
}
