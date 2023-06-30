#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Score {
    protected:
    double math;
    double literature;
    double english;
    public :
    Score(){}
    Score (double math, double literature, double english ){
        this -> math = math;
        this -> literature = literature;
        this -> english = english;
    }
    double getMath(){
        return  math;
    }
    double getLiterature(){
        return literature;
    }
    double getEnglish(){
        return english;
    }
    virtual double pointA(){
        return 0;
    }
    virtual double pointB(){
        return 0;
    }
    virtual double pointC(){
        return 0;
    }
    virtual double pointD(){
        return math+literature+english;
    }
    virtual double avgPoint()=0;
        virtual void display()
    {
        cout << "Avg = " << avgPoint() << endl;
    }

    static double getMaxavg( vector<Score *> vt){
        double max = vt[0]-> avgPoint();
        for (int i =0; i< vt.size();i++){
            if (vt[i]-> avgPoint() > max){
                max = vt[i]-> avgPoint();
            }
        }
        return max;
    }
    static double getMinavg( vector<Score *> vt){
        double min = vt[0]-> avgPoint();
        for (int i =0; i< vt.size();i++){
            if (vt[i]-> avgPoint() < min){
                min = vt[i]-> avgPoint();
            }
        }
        return min;
    }
    bool isPass(){
        if (avgPoint() > 5){
            return true;
        }
        else {
            return false;
        }
    }

      static double getMaxPointA( vector<Score *> vt){
        double max = vt[0]-> pointA();
        for (int i =0; i< vt.size();i++){
            if (vt[i]-> pointA() > max){
                max = vt[i]-> pointA();
            }
        }
        return max;
    }
    static double getMaxPointB( vector<Score *> vt){
        double max = vt[0]-> pointB();
        for (int i =0; i< vt.size();i++){
            if (vt[i]-> pointB() > max){
                max = vt[i]-> pointB();
            }
        }
        return max;
    }
    static double getMaxPointC( vector<Score *> vt){
        double max = vt[0]-> pointC();
        for (int i =0; i< vt.size();i++){
            if (vt[i]-> pointC() > max){
                max = vt[i]-> pointC();
            }
        }
        return max;
    }
    static double getMaxPointD( vector<Score *> vt){
        double max = vt[0]-> pointD();
        for (int i =0; i< vt.size();i++){
            if (vt[i]-> pointD() > max){
                max = vt[i]-> pointD();
            }
        }
        return max;
    }
};
class ScoreNatural : public Score {
    private :
    double physic ;
    double chemistry;
    double biology;
    public :
    ScoreNatural(){}
    ScoreNatural(double math, double literature, double english, double physic, double chemistry, double biology)
        : Score(math, literature, english), physic(physic), chemistry(chemistry), biology(biology) {}

    double getPhysic(){
        return physic;
    }
    double getBiology(){
        return biology;
    }
    double getChemistry(){
        return chemistry;
    }
    double pointA(){
        return math + chemistry + physic;
    }
    double pointB(){
        return math + chemistry + biology;
    }
    double pointNatural(){
        return physic + chemistry+ biology;
    }
    double avgPoint(){
        return (math + english + literature + physic + biology + chemistry)/6;
    }
};
class ScoreSocial : public Score
{
private:
    double ce;
    double geography;
    double history;

public:
    ScoreSocial() {}
    ScoreSocial(double math, double literature, double english, double ce, double geography, double history) : Score(math, literature, english), ce(ce), geography(geography), history(history) {}
    double getCe()
    {
        return ce;
    }
    double getGeography()
    {
        return geography;
    }
    double getHistory()
    {
        return history;
    }
    double pointC()
    {
        return literature + history + geography;
    }
    double pointSocial()
    {
        return literature + history + geography;
    }
    double avgPoint()
    {
        return (literature + history + geography + math + literature + english) / 6;
    }
};
int main()
{
    vector<ScoreNatural> naturals(3);
    naturals[0] = ScoreNatural(8,7,7,8,9,6);
    naturals[1] = ScoreNatural(8,8,8,8,8,8);
    naturals[2] = ScoreNatural(7,8,9,9,8,7);

    vector<ScoreSocial> socials(3);
    socials[0] = ScoreSocial(1, 1, 1, 1, 1, 1);
    socials[1] = ScoreSocial(2, 2, 2, 2, 2, 2);
    socials[2] = ScoreSocial(3, 3, 3, 3, 3, 3);

    for (auto &v : naturals)
        if (v.isPass())
            v.display();

    for (auto &v : socials)
        cout << v.avgPoint() << endl;

    vector<Score *> scores({&naturals[0], &naturals[1], &socials[0]});
    for (auto &v : scores)
        v->avgPoint();

    cout << "Trung binh lon nhat:" << Score::getMaxavg(scores) << endl;
    cout << "Trung binh nho nhat:" << Score::getMinavg(scores) << endl;
    cout << "Trung binh lon nhat khoi A:" << Score::getMaxPointA(scores) << endl;
    cout << "Trung binh lon nhat khoi B:" << Score::getMaxPointB(scores) << endl;
    cout << "Trung binh lon nhat khoi C:" << Score::getMaxPointC(scores) << endl;
    cout << "Trung binh lon nhat khoi D:" << Score::getMaxPointD(scores) << endl;
}




