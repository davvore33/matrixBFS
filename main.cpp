// Program to find Dijkstra's shortest path using STL set
#include<iostream>
#include <algorithm>
#include <list>
#define OUT

struct coord{
    int x;
    int y;
};

bool operator==(const coord& lhs, const coord& rhs)
{
    if(lhs.x == rhs.x && lhs.y == rhs.y)
        return true;
    else
        return false;
}
class graph{
private:
    int **map;
    int **distances;
    coord **source;
    coord dim;
public:
    graph(const int maxYpassed,const int maxXpassed, const unsigned char* pMap){
        dim.x = maxXpassed;
        dim.y = maxYpassed;
        map = new int*[dim.y];
        distances = new int*[dim.y];
        source = new coord*[dim.y];
        int index = 0;
        for(int y = 0; y < dim.y; y++) {
            map[y] = new int[dim.x];
            distances[y] = new int[dim.x];
            source[y] = new coord[dim.x];
            for (int x = 0; x < dim.x; x++) {
                map[y][x] = static_cast<int>(pMap[index]);
                distances[y][x] = -1;
                source[y][x] = coord{-1,-1};
                index++;
            }
        }
    }

//    graph(coord c, const unsigned char* pMap){
//        dim = c;
//        map = new int*[dim.y];
//        int index = 0;
//        for(int y = 0; y < dim.y; y++) {
//            map[y] = new int[dim.x];
//            for (int x = 0; x < dim.x; x++) {
//                map[y][x] = pMap[index];
//                index++;
//            }
//        }
//    }

    ~graph(){
        for(int i =0 ; i < dim.y; i++)
            delete[](map[i]);
        delete[](map);
    }

    void findAdj(coord c, std::list<coord>* ret){
        if(c.x+1 < dim.x)
            if(map[c.y][c.x+1] == 1)
                ret->push_back(coord{c.x+1, c.y});
        if(c.x-1 >= 0)
            if(map[c.y][c.x-1] == 1)
                ret->push_back(coord{c.x+1, c.y});
        if(c.y+1 < dim.y)
            if(map[c.y+1][c.x] == 1)
                ret->push_back(coord{c.x, c.y+1});
        if(c.y-1 >= 0)
            if(map[c.y-1][c.x] == 1)
                ret->push_back(coord{c.x, c.y-1});
    }
};

void printCoord(coord lhs){
    std::cout<<"x "<<lhs.x<<" ";
    std::cout<<"y "<<lhs.y<<" "<<std::endl;
}

int FindPath(const int nStartX, const int nStartY,
             const int nTargetX, const int nTargetY,
             const unsigned char* pMap, const int nMapWidth, const int nMapHeight,
             int* pOutBuffer, const int nOutBufferSize){
    coord start = coord{nStartX, nStartY};
    coord target = coord{nTargetX, nTargetY};
    graph* fico = new graph(nMapHeight, nMapWidth, pMap);
    std::list<coord> coda;                  //TODO: let coda be a set (no duplicates)
    coda.push_back(start);

    while(!coda.empty()){
        coord vertex = coda.front();
        coda.pop_front();
        std::cout<<"sono al "<<vertex.x<<" "<<vertex.y<<std::endl;
        if(vertex == target){
            break;
        } else{
            std::list<coord> adj;
            fico->findAdj(vertex, OUT &adj);
            std::cout<<"i miei vicini sono ";
            std::for_each(adj.begin(), adj.end(), printCoord);
            std::cout<<std::endl;
            coda.splice(coda.end(), adj);
        }
    }

//    KNOW WHAT I HAVE
//    for (int i = 0; i < nMapHeight; ++i) {
//        for (int j = 0; j < nMapWidth; ++j) {
//            coord dim = coord{j,i};
//            std::cout<< fico->getElem(dim);
//        }
//        std::cout<<std::endl;
//    }

}

int main(){
    unsigned char pMap[] = {1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1};
    int pOutBuffer[12];
    FindPath(0, 0, 1, 2, pMap, 4, 3, pOutBuffer, 12);

    return 0;
}
//1, 1, 1, 1,
// 0, 1, 0, 1,
// 0, 1, 1, 1