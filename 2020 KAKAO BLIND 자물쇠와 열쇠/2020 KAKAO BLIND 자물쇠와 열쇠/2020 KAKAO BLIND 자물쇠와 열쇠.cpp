#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<pair<int,int>>> RotateKey(vector<vector<int>> key)
{
    vector<pair<int, int>> keyCoord[4];
    vector<vector<pair<int, int>>> rotateKeyCoords;
    for (int i = 0; i < key.size(); ++i)
    {
        for (int j = 0; j < key.size(); ++j)
        {
            if (key[i][j] == 1)
			{
                keyCoord[0].push_back(make_pair(i, j));
                keyCoord[1].push_back(make_pair(-j, i));
                keyCoord[2].push_back(make_pair(-i, -j));
                keyCoord[3].push_back(make_pair(j, -i));
            }
        }
    }
    
    for (int i = 0; i < 4; ++i)
    {
        int a = keyCoord[i].front().first;
        int b = keyCoord[i].front().second;
        for (int j = 0; j < keyCoord[0].size(); ++j)
        {
            keyCoord[i][j].first -= a;
            keyCoord[i][j].second -= b;
        }
        rotateKeyCoords.push_back(keyCoord[i]);
    }
    return rotateKeyCoords;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) 
{
    bool answer = true;

    int N = lock.size();
    vector<pair<int, int>> lockCoords;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (lock[i][j] == 0)
            {
                lockCoords.push_back(make_pair(i, j));
            }
        }
    }

    vector<vector<pair<int,int>>> rotateKeyCoords = RotateKey(key);


    for (int i = 0; i < lockCoords.size(); ++i)
    {
        int a = lockCoords.front().first;
        int b = lockCoords.front().second;
        lockCoords[i].first -= a;
        lockCoords[i].second -= b;
    }

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 1; j < rotateKeyCoords[0].size(); ++j)
        {
            int foundKey = 1;
            for (int k = 1; k < lockCoords.size(); ++k)
            {
                if (lockCoords[k] == rotateKeyCoords[i][j])
                {
                    ++foundKey;
                }
			}

			if (foundKey == lockCoords.size())
			{
				return true;
			}
        }
    }

    return false;
}

int main()
{

    std::cout << "Hello World!\n";
}