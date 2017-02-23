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

std::ostream& operator << (std::ostream& stream, coord &p)
{
    stream << p.x<<"/"<<p.y;
    return stream;
}

std::ostream& operator << (std::ostream& stream, std::list<int> &p)
{
    for (int i = 0; i < p.size(); ++i) {
        stream << p.front();
        p.pop_front();
    }
    return stream;
}

class graph{
private:
    int **map;
    int **distances;
    coord **sources;
    coord dim;
public:
    graph(const int maxYpassed,const int maxXpassed, const unsigned char* pMap){
        dim.x = maxXpassed;
        dim.y = maxYpassed;
        map = new int*[dim.y];
        distances = new int*[dim.y];
        sources = new coord*[dim.y];
        int index = 0;
        for(int y = 0; y < dim.y; y++) {
            map[y] = new int[dim.x];
            distances[y] = new int[dim.x];
            sources[y] = new coord[dim.x];
            for (int x = 0; x < dim.x; x++) {
                map[y][x] = static_cast<int>(pMap[index]);
                distances[y][x] = std::numeric_limits<int>::max();
                sources[y][x] = coord{-1,-1};
                index++;
            }
        }
    }

    ~graph(){
        for(int i =0 ; i < dim.y; i++) {
            delete[](map[i]);
            delete[](distances[i]);
            delete[](sources[i]);
        }
        delete[](map);
        delete[](distances);
        delete[](sources);
    }

    int getDistance(coord c) const {
        return distances[c.y][c.x];
    }

    void setDistance(coord c, int distance) {
        graph::distances[c.y][c.x] = distance;
    }

    coord getSource(coord c) const {
        return sources[c.y][c.x];
    }

    void setSource(coord c, coord source) {
        graph::sources[c.y][c.x] = source;
    }

    int indexTransform(coord c){
        return c.x+c.y*dim.x;
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

int FindPath(const int nStartX, const int nStartY,
             const int nTargetX, const int nTargetY,
             const unsigned char* pMap, const int nMapWidth, const int nMapHeight,
             int* pOutBuffer, const int nOutBufferSize){
    coord start = coord{nStartX, nStartY};
    coord target = coord{nTargetX, nTargetY};
    graph* fico = new graph(nMapHeight, nMapWidth, pMap);
    fico->setSource(start, start);
    fico->setDistance(start, 0);

    std::list<coord> coda;                  //TODO: let coda be a set (no duplicates)
    coda.push_back(start);

    while(!coda.empty()){
        coord vertex = coda.front();
        coda.pop_front();
        if(vertex == target){
            break;
        } else{
            std::list<coord> adj;
            fico->findAdj(vertex, OUT &adj);
            for (long i = adj.size(); i > 0 ; i--) {
                coord nextVertex = adj.front();
                adj.pop_front();
                if(fico->getSource(nextVertex) == vertex){
                    continue;
                }
                else if(fico->getDistance(nextVertex) > fico->getDistance(vertex)+1)
                {
                    fico->setDistance(nextVertex, fico->getDistance(vertex)+1);
                    fico->setSource(nextVertex, vertex);
                    adj.push_back(nextVertex);
                }
            }
            coda.splice(coda.end(), adj);
        }
    }
//    KNOW WHAT I HAVE
//    for (int i = 0; i < nMapHeight; ++i) {
//        for (int j = 0; j < nMapWidth; ++j) {
//            coord ori = coord{j,i};
//            coord source = fico->getSource(ori);
//            std::cerr<<ori<<"{"<<source<<"}"<<fico->indexTransform(ori)<<"\t";
//        }
//        std::cerr<<std::endl;
//    }
    coord support = target;
    std::list<int> street;
    while(true){
        street.push_back(fico->indexTransform(support));
        if(support == start) break;
        support = fico->getSource(support);
    }
    if(street.size() > nOutBufferSize)
        return -1;
    else {
        long size = street.size();
        for (int k = 0; k < (nOutBufferSize - size); ++k) {
            street.push_front(0);
        }
    }
    int index = 0;
    for (long j = street.size(); j > 0; j--) {
        pOutBuffer[index] = street.back();
        street.pop_back();
        index++;
    }
    return 0;


}

int main(){
    unsigned char pMap[] = {1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1};
    int pOutBuffer[12];
    FindPath(0, 0, 1, 2, pMap, 4, 3, pOutBuffer, 12);

    for (int i = 0; i < 12; ++i) {
        std::cout<<pOutBuffer[i]<<" ";
    }
    return 0;
}
//1, 1, 1, 1,
// 0, 1, 0, 1,
// 0, 1, 1, 1