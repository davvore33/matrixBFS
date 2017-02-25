// Program to find shortest path using BFS Algorithm
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

    int getMap(coord c) const {
        return map[c.y][c.x];
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
        coord check;
        if(c.x+1 < dim.x){
            check = {c.x+1, c.y};
            if(getMap(check) == 1)
                ret->push_back(check);}
        if(c.x-1 >= 0){
            check = {c.x-1, c.y};
            if(getMap(check) == 1)
                ret->push_back(check);}
        if(c.y+1 < dim.y){
            check = {c.x, c.y+1};
            if(getMap(check) == 1)
                ret->push_back(check);}
        if(c.y-1 >= 0){
            check = {c.x, c.y-1};
            if(getMap(check) == 1)
                ret->push_back(check);}
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

    std::list<coord> queue;                  //TODO: let queue be a set (no duplicates)
    queue.push_back(start);

//  Here I'm going to implement BFS algorithm:
//    watching for each "queue" nodes,
//    if watched node is the target, exit
//    else, take adjacents, there, update adj distances
//    and parents if needed (I'm looking for the sortest path

    while(!queue.empty()){
        coord vertex = queue.front();
        queue.pop_front();
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
            queue.splice(queue.end(), adj);
        }
    }
//    KNOW WHAT I HAVE (print "origin{source}index")
//    for (int i = 0; i < nMapHeight; ++i) {
//        for (int j = 0; j < nMapWidth; ++j) {
//            coord ori = coord{j,i};
//            coord next = fico->getSource(ori);
//            if ( next == coord{-1,-1}){
//                std::cerr<<"0 ";
//            } else
//            if (next.x < ori.x){
//                std::cerr<<"← ";
//            } else
//            if (next.x > ori.x){
//                std::cerr<<"→ ";
//            } else
//            if (next.y < ori.y){
//                std::cerr<<"↑ ";
//            } else
//            if (next.y > ori.y){
//                std::cerr<<"↓ ";
//            }
//        }
//        std::cerr<<"\n";
//    }

//    if BFS doesn't enrich the solution
    if(fico->getSource(target) == coord{-1,-1})
        return -1;

//    now I've climb my solution saved into my graph
    coord support = target;
    std::list<int> street;
    while(true){
        if(support == start) break;
        street.push_back(fico->indexTransform(support));
        support = fico->getSource(support);
    }
    int solLenght = fico->getDistance(target);//static_cast<int>(street.size()); they store the same information

//    if my street is longer that your buffer
    if(solLenght > nOutBufferSize)
        return solLenght;

//    the solution has to be reversed
    int index = 0;
    for (long j = street.size(); j > 0; j--) {
        pOutBuffer[index] = street.back();
        street.pop_back();
        index++;
    }
    return solLenght;
}

int main(){
    unsigned char pMap[] = {0, 0, 1, 0, 1, 1, 1, 0, 1};
    const int buffdim = 7;
    int pOutBuffer[buffdim];
    int len = FindPath(2, 0, 0, 2, pMap, 3, 3, pOutBuffer, 7);
    if(len != -1)
        for (int i = 0; i < 48; ++i) {
            std::cout<<pOutBuffer[i]<<" ";
        }
    std::cout<<std::endl;
    return len;
}