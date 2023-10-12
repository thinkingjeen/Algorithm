#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> busSchedule;
vector<int> crewSchedule;
vector<int> boardableTime;

string main(int n, int t, int m, vector<string> timetable)
{
    string answer = "";

    busSchedule.push_back(9*60);
    for (int i = 0; i < n - 1; ++i)
    {
        busSchedule.push_back(540 + t * (i + 1));
    }

    for (int i = 0; i < timetable.size(); ++i)
    {
        crewSchedule.push_back(((timetable[i][1] * 10 + timetable[i][2]) * 60) + (timetable[i][4] * 10 + timetable[i][5]));
    }
    sort(crewSchedule.begin(), crewSchedule.end());

    int arrivePerson = 0;

    for (int i = 0; i < n; ++i)
    {
        int thisBusPerson = 0;

        for (int j = 0; j < crewSchedule.size(); ++j)
        {
            if (crewSchedule[j] <= busSchedule[i] && j < (m + arrivePerson - 1))
            {
                ++thisBusPerson;
                ++arrivePerson;
            }
            else if (crewSchedule[j] <= busSchedule[i] && j == (m + arrivePerson - 1))
            {
                boardableTime.push_back(crewSchedule[j] - 1);
            }
            else if (crewSchedule[j] > busSchedule[i] && thisBusPerson < m-1)
            {
                boardableTime.push_back(busSchedule[i]);
            }
        }
    }
    sort(boardableTime.begin(), boardableTime.end());
    string answerH;
    string answerM;

    if ((boardableTime.back() / 60) <= 9)
    {
        answerH = ( "0"+ to_string(boardableTime.back() / 60));
    }
    else
    {
        answerH = (to_string(boardableTime.back() / 60));
    }

    if ((boardableTime.back() % 60 <= 9))
    {
        answerM = ("0" + to_string(boardableTime.back() % 60));
    }
    else
    {
        answerM = (to_string(boardableTime.back() % 60));
    }

    answer = answerH + ":" + answerM;

    return answer;
}