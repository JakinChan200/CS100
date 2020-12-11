#ifndef VISITOR_HPP
#define VISITOR_HPP

using namespace std;


class Visitor {
    public:
        Visitor(){};
        void visit(){
            counter++;
        }

        int getCounter(){
            return counter;
        }

    private:
        int counter = 0;
};

#endif