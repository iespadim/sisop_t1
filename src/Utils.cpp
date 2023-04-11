#include "Utils.h"
#include <fstream>
#include <iostream>
#include "Process.h"
#include <string>
#include <sstream>
Utils::Utils()
{
    //ctor
}

Utils::~Utils()
{
    //dtor
}

vector<string> Utils::readFile(const string& filename) {
        vector<string> lines;
        ifstream file(filename);

        if (!file.is_open()) {
        cerr << "Nao foi possivel abrir o arquivo: " << filename << endl;
        return lines;
        }

        string line;
        while (getline(file, line)) {
            lines.push_back(line);
        }

        file.close();
        return lines;
    }

Process Utils::parseAssemblyFile(const string& filePath, int processId) {
    //Processo
    vector<string> data_;
    vector<string> code_;
    int executionTime = 0;

    //aux
    string line;
    bool isInCodeSection = false;
    bool isInDataSection = false;

    //err mgmt
    ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        throw runtime_error("Não foi possível abrir o arquivo: " + filePath);
    }

    //parse
    while (getline(inputFile, line)) {

        // Remove comentários da linha
        size_t commentPos = line.find('#');
        if (commentPos != string::npos) {
            line = line.substr(0, commentPos);
        }

        // Remove espaços em branco no início e no final da linha
        line.erase(0, line.find_first_not_of(" \t\n\r\f\v"));
        line.erase(line.find_last_not_of(" \t\n\r\f\v") + 1);


        //parse code
        if (line == ".code") {
            isInCodeSection = true;
            continue;
        }
        if (line == ".endcode") {
            isInCodeSection = false;
            continue;
        }
        if (!line.empty() && isInCodeSection) {
            cout << line << endl;
            code_.push_back(line);
        }


        //parse data
        if (line == ".data") {
            isInDataSection = true;
            continue;
        }
        if (line == ".enddata") {
            isInDataSection = false;
            continue;
        }
        if (!line.empty() && isInDataSection) {
            cout << line << endl;
            data_.push_back(line);
        }


    }

    inputFile.close();
    return Process(processId, code_,data_, executionTime);
}
