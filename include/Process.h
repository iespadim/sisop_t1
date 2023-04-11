#ifndef PROCESS_H
#define PROCESS_H
#include<vector>
#include<string>

using namespace std;
class Process
{
    public:
        Process();
        Process(int processId, vector<string> code,vector<string> data, int executionTime)
      : processId_(processId), code_(code),data_(data), executionTime_(executionTime) {}


        int processId_;
        vector<string> code_;
        vector<string> data_;
    protected:

    private:
        int executionTime_;
};

#endif // PROCESS_H
