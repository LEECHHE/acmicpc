#include<cstdio>
#include<cstring>
#include<string>
#include<utility>
#include<vector>
using namespace std;
typedef pair<int,string> album;
album list[25] = {
    album(1967,"DavidBowie"),
    album(1969,"SpaceOddity"),
    album(1970,"TheManWhoSoldTheWorld"),
    album(1971,"HunkyDory"),
    album(1972,"TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"),
    album(1973,"AladdinSane"),
    album(1973,"PinUps"),
    album(1974,"DiamondDogs"),
    album(1975,"YoungAmericans"),
    album(1976,"StationToStation"),
    album(1977,"Low"),
    album(1977,"Heroes"),
    album(1979,"Lodger"),
    album(1980,"ScaryMonstersAndSuperCreeps"),
    album(1983,"LetsDance"),
    album(1984,"Tonight"),
    album(1987,"NeverLetMeDown"),
    album(1993,"BlackTieWhiteNoise"),
    album(1995,"1.Outside"),
    album(1997,"Earthling"),
    album(1999,"Hours"),
    album(2002,"Heathen"),
    album(2003,"Reality"),
    album(2013,"TheNextDay"),
    album(2016,"BlackStar")
};
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int a,b; scanf("%d%d",&a,&b);
        vector<album> ret;
        for( int i = 0 ; i < 25 ; ++i ){
            if( a <= list[i].first && list[i].first <= b ){
                ret.push_back(list[i]);
            }
        }
        printf("%d\n",(int)ret.size());
        for( auto al : ret ){
            printf("%d %s\n", al.first, al.second.c_str());
        }
    }
    return 0;
}