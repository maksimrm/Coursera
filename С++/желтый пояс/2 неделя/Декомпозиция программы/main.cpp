#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
    string tp;
    is >> tp;
    if (tp == "NEW_BUS"){
        q.type = QueryType::NewBus;
        int n;
        is >> q.bus >> n;
        q.stops = {};
        for (int i = 0; i < n; i++){
            string stop;
            is >> stop;
            q.stops.push_back(stop);
        }
        q.stop = "";
    } else if (tp == "BUSES_FOR_STOP"){
        q.type = QueryType::BusesForStop;
        is >> q.stop;
        q.stops = {};
        q.bus = "";
    }else if (tp ==  "STOPS_FOR_BUS"){
        q.type = QueryType::StopsForBus;
        is >> q.bus;
        q.stops = {};
        q.stop = "";
    }else if (tp == "ALL_BUSES"){
        q.type = QueryType::AllBuses;
        q.stops = {};
        q.stop = "";
        q.bus = "";
    }
    return is;
}

struct BusesForStopResponse {
    string buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    os << r.buses ;
    return os;
}

struct StopsForBusResponse {
    string stops;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    os << r.stops ;
    return os;
}

struct AllBusesResponse {
    string all;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    os << r.all ;
    return os;
}

class BusManager {
private:

    map<string, vector<string>> buses_to_stops, stops_to_buses;


public:
    void AddBus(const string& bus, const vector<string>& stops) {
        int stop_count = stops.size();
        for (int i = 0; i < stop_count; i++) {
            buses_to_stops[bus].push_back(stops[i]);
            stops_to_buses[stops[i]].push_back(bus);
        }
    }

    BusesForStopResponse GetBusesForStop(const string& stop) const {
        BusesForStopResponse buses;
        if (stops_to_buses.count(stop) == 0) {
            buses.buses = "No stop";
        } else {
            for (const string& bus : stops_to_buses.at(stop)) {
                buses.buses += bus +" ";
            }
            buses.buses += "\n";
        }
        return buses;
    }

    StopsForBusResponse GetStopsForBus(const string& bus) const {
        StopsForBusResponse st;
        if (buses_to_stops.count(bus) == 0) {
            st.stops += "No bus";
        } else {
            for (const string& stop : buses_to_stops.at(bus)) {
                st.stops += "Stop " + stop +": ";
                if (stops_to_buses.at(stop).size() == 1) {
                    st.stops += "no interchange";
                } else {
                    for (const string& other_bus : stops_to_buses.at(stop)) {
                        if (bus != other_bus) {
                            st.stops += other_bus + " ";
                        }
                    }
                }
                st.stops += "\n";
            }
        }
        return st;
    }

    AllBusesResponse GetAllBuses() const {
        AllBusesResponse all;
        if (buses_to_stops.empty()) {
            all.all +=  "No buses";
        } else {
            for (const auto& bus_item : buses_to_stops) {
                all.all +=  "Bus " + bus_item.first + ": ";
                for (const string& stop : bus_item.second) {
                    all.all +=  stop + " ";
                }
                all.all += "\n";
            }
        }
        return all;
    }
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
    int query_count;
    Query q;

    cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        cin >> q;
        switch (q.type) {
            case QueryType::NewBus:
                bm.AddBus(q.bus, q.stops);
                break;
            case QueryType::BusesForStop:
                cout << bm.GetBusesForStop(q.stop) << endl;
                break;
            case QueryType::StopsForBus:
                cout << bm.GetStopsForBus(q.bus) << endl;
                break;
            case QueryType::AllBuses:
                cout << bm.GetAllBuses() << endl;
                break;
        }
    }

    return 0;
}

