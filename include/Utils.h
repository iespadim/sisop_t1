#ifndef UTILS_H
#define UTILS_H
#include <vector>
#include <string>
#include <Process.h>
using namespace std;

class Utils
{
    public:
        Utils();
        virtual ~Utils();
        static vector<string> readFile(const string& filename);
        static Process parseAssemblyFile(const string& filePath, int processId);

    protected:

    private:
};
#endif // UTILS_H
