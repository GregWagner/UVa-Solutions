#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>

struct Point { double x, y; };

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::ostringstream out;
    int T;
    if(!(std::cin>>T)) return 0;
    const double EPS=1e-9;
    for(int tc=0; tc<T; ++tc){
        int xV,yV,xL,yL;
        std::cin>>xV>>yV;
        std::cin>>xL>>yL;
        int n; std::cin>>n;
        std::vector<Point> lepPts(n);
        for(int i=0;i<n;++i) std::cin>>lepPts[i].x>>lepPts[i].y;
        int m; std::cin>>m;
        std::vector<Point> villPts(m);
        for(int i=0;i<m;++i) std::cin>>villPts[i].x>>villPts[i].y;

        std::vector<Point> lepPath; lepPath.reserve(n+1);
        lepPath.push_back({(double)xL,(double)yL});
        for(auto &p: lepPts) lepPath.push_back(p);
        std::vector<Point> villPath; villPath.reserve(m+1);
        villPath.push_back({(double)xV,(double)yV});
        for(auto &p: villPts) villPath.push_back(p);

        int Ls=lepPath.size(), Vs=villPath.size();
        std::vector<double> tL(Ls,0), tV(Vs,0);
        for(int i=1;i<Ls;++i){
            double dx=lepPath[i].x-lepPath[i-1].x;
            double dy=lepPath[i].y-lepPath[i-1].y;
            tL[i]=tL[i-1]+std::hypot(dx,dy);
        }
        for(int i=1;i<Vs;++i){
            double dx=villPath[i].x-villPath[i-1].x;
            double dy=villPath[i].y-villPath[i-1].y;
            tV[i]=tV[i-1]+std::hypot(dx,dy);
        }
        double totalL=tL.back();
        bool caught=false;
        for(int i=0;i+1<Ls && !caught;++i){
            double t0=tL[i], t1=tL[i+1];
            if(t1<=t0+EPS) continue;
            Point A=lepPath[i], B=lepPath[i+1];
            double vLx=(B.x-A.x)/(t1-t0);
            double vLy=(B.y-A.y)/(t1-t0);
            for(int j=0;j+1<Vs && !caught;++j){
                double s0=tV[j], s1=tV[j+1];
                if(s1<=s0+EPS) continue;
                Point C=villPath[j], D=villPath[j+1];
                double vVx=(D.x-C.x)/(s1-s0);
                double vVy=(D.y-C.y)/(s1-s0);
                double tLow=std::max(t0,s0);
                double tHigh=std::min(t1,s1);
                if(tLow>tHigh+EPS) continue;
                double ax=vLx - vVx;
                double ay=vLy - vVy;
                double bx=A.x - vLx*t0 - C.x + vVx*s0;
                double by=A.y - vLy*t0 - C.y + vVy*s0;
                double meetT=tLow;
                bool meet=false;
                if(std::fabs(ax)<EPS && std::fabs(ay)<EPS){
                    if(std::fabs(bx)<EPS && std::fabs(by)<EPS){
                        meet=true;
                        meetT=tLow;
                    }
                }else if(std::fabs(ax)<EPS){
                    if(std::fabs(bx)>EPS){ /* no meet */ }
                    else{
                        if(std::fabs(ay)<EPS){
                            meet=true; meetT=tLow;
                        }else{
                            double tCand=-by/ay;
                            if(tCand>=tLow-EPS && tCand<=tHigh+EPS){ meet=true; meetT=tCand; }
                        }
                    }
                }else if(std::fabs(ay)<EPS){
                    if(std::fabs(by)>EPS){ }
                    else{
                        if(std::fabs(ax)<EPS){ meet=true; meetT=tLow; }
                        else{
                            double tCand=-bx/ax;
                            if(tCand>=tLow-EPS && tCand<=tHigh+EPS){ meet=true; meetT=tCand; }
                        }
                    }
                }else{
                    double tx=-bx/ax;
                    double ty=-by/ay;
                    if(std::fabs(tx-ty)<1e-7){
                        double tCand=(tx+ty)*0.5;
                        if(tCand>=tLow-EPS && tCand<=tHigh+EPS){ meet=true; meetT=tCand; }
                    }
                }
                if(meet){
                    if(meetT < totalL - EPS){
                        caught=true;
                    }
                    // if meet at or after arrival, safe
                }
            }
        }
        out << (caught ? "No" : "Yes");
        if(tc+1!=T) out << "\n\n";
    }
    std::cout << out.str() << "\n";
    return 0;
}
