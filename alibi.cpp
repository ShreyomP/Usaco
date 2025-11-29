
#include <algorithm>
using namespace std;

int main() {
	long long g,n;
    cin>>g>>n;
    vector<pair<long long,pair<long long,long long>>> grazings(g);
    vector<pair<long long,pair<long long,long long>>> alibis(n);
    for (long long x=0; x<g; x++) {
        cin>>grazings[x].second.first>>grazings[x].second.second>>grazings[x].first;
    }
    for (long long x=0; x<n; x++) {
        cin>>alibis[x].second.first>>alibis[x].second.second>>alibis[x].first;
    }
    sort(grazings.begin(),grazings.end());
    long long counter=0;
    for (long long x = 0; x < n; x++) {
        long long t = alibis[x].first;
        long long low = 0, high = g-1;
        long long best = -1;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (grazings[mid].first == t) {
                best = mid;
                break;
            }
            if (grazings[mid].first < t) {
                best = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        long long left = best;
        long long right = best + 1;
        pair<long long, pair<long long, long long>> firstClosest, secondClosest;
        bool gotFirst = false, gotSecond = false;
        for (long long i = 0; i < 2; i++) {
            if (left >= 0 && (right >= g || abs(grazings[left].first - t) <= abs(grazings[right].first - t))) {
                if (!gotFirst) {
                    firstClosest = grazings[left];
                    gotFirst = true;
                } else {
                    secondClosest = grazings[left];
                    gotSecond = true;
                }
                left--;
            } else if (right < g) {
                if (!gotFirst) {
                    firstClosest = grazings[right];
                    gotFirst = true;
                } else {
                    secondClosest = grazings[right];
                    gotSecond = true;
                }
                right++;
            }
        }
        long long ax = alibis[x].second.first;
        long long ay = alibis[x].second.second;
        long long gx = firstClosest.second.first;
        long long gy = firstClosest.second.second;
        double spatialDistance = sqrt((gx - ax) * 1LL * (gx - ax) + (gy - ay) * 1LL * (gy - ay));
        if (abs(t-firstClosest.first)<spatialDistance) {
            counter++;
        }
        ax = alibis[x].second.first;
        ay = alibis[x].second.second;
        gx = secondClosest.second.first;
        gy = secondClosest.second.second;
        spatialDistance = sqrt((gx - ax) * 1LL * (gx - ax) + (gy - ay) * 1LL * (gy - ay));
        if (abs(t-firstClosest.first)>=spatialDistance && abs(t-secondClosest.first)<spatialDistance) {
            counter++;
        }
        //cout<<firstClosest.first<<" "<<secondClosest.first<<" "<<spatialDistance<<endl;
    }
    cout<<counter;
}

