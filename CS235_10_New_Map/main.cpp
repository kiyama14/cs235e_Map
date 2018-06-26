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
        cout << "Error: Unable to open file" << endl;
        return 0;
    }
    
    Map myMap;
    string word;
    
    while (fin >> word) {
        
        
        string noPunWord = "";
        
        for (int i = 0; i < word.length(); i++) {
            if (!ispunct(word[i]) || word[i] == '-')
                noPunWord += word[i];
        }
        
        transform(noPunWord.begin(), noPunWord.end(), noPunWord.begin(), ::tolower);
        
        myMap[noPunWord]++;
        numberOfWords++;
    }

    
    fin.close();
    
    cout << endl;
    cout << "Number of words processed: " << numberOfWords << endl;
    cout << "100 most common words found and their frequencies:" << endl;
    multimap<int, string> megaMap;
    pair<int, string> myPair;
    
    for (MapIterator it = myMap.rbegin(); it != myMap.rend(); it++) {
        myPair.first = it->second;
        myPair.second = it->first;
        megaMap.insert(myPair);
    }
    
    int i =  0;
    for (MultiMapIterator it = megaMap.rbegin(); i < 100; it++) {
        cout << setw(23) << it->second << " - " << it->first << endl;
        i++;
    }
    
    
    
    return 0;
}
